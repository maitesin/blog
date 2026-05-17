package main_test

import (
	"bytes"
	"context"
	"errors"
	"io"
	"net/http"
	"testing"

	"github.com/stretchr/testify/require"
	"go.uber.org/mock/gomock"

	main "2026_go_http_unit_test"
	mock "2026_go_http_unit_test/mocks"
)

//go:generate go tool mockgen -destination mocks/http.go -package mock net/http RoundTripper
//go:generate go tool mockgen -destination mocks/io.go -package mock io Reader

func Test_getValuesAndProcessThem(t *testing.T) {
	tests := []struct {
		name      string
		ctx       context.Context
		mockSetup func(transport *mock.MockRoundTripper, reader *mock.MockReader)
		want      []byte
		wantErr   error
	}{
		{
			name: "success",
			ctx:  context.Background(),
			mockSetup: func(transport *mock.MockRoundTripper, _ *mock.MockReader) {
				transport.EXPECT().RoundTrip(gomock.Any()).Return(&http.Response{
					StatusCode: 200,
					Body:       io.NopCloser(bytes.NewBufferString("<h1>wololo</h1>")),
				}, nil)
			},
			want:    []byte("<h1>wololo</h1>"),
			wantErr: nil,
		},
		{
			name: "http request fails",
			ctx:  context.Background(),
			mockSetup: func(transport *mock.MockRoundTripper, _ *mock.MockReader) {
				transport.EXPECT().RoundTrip(gomock.Any()).Return(nil, errors.New("http request failed"))
			},
			want:    nil,
			wantErr: main.ErrFailedToPerformRequest,
		},
		{
			name: "http status code not 200",
			ctx:  context.Background(),
			mockSetup: func(transport *mock.MockRoundTripper, _ *mock.MockReader) {
				transport.EXPECT().RoundTrip(gomock.Any()).Return(&http.Response{
					StatusCode: 404,
					Body:       io.NopCloser(bytes.NewBufferString("<h1>Not found</h1>")),
				}, nil)
			},
			want:    nil,
			wantErr: main.ErrStatusCodeInvalid,
		},
		{
			name: "fails to read body",
			ctx:  context.Background(),
			mockSetup: func(transport *mock.MockRoundTripper, reader *mock.MockReader) {
				reader.EXPECT().Read(gomock.Any()).Return(0, errors.New("read body failed"))
				transport.EXPECT().RoundTrip(gomock.Any()).Return(&http.Response{
					StatusCode: 200,
					Body:       io.NopCloser(reader),
				}, nil)
			},
			want:    nil,
			wantErr: main.ErrFailedToReadBody,
		},
		{
			name: "body does not contain wololo",
			ctx:  context.Background(),
			mockSetup: func(transport *mock.MockRoundTripper, _ *mock.MockReader) {
				transport.EXPECT().RoundTrip(gomock.Any()).Return(&http.Response{
					StatusCode: 200,
					Body:       io.NopCloser(bytes.NewBufferString("<h1>try again</h1>")),
				}, nil)
			},
			want:    nil,
			wantErr: main.ErrBodyDoesNotContainWololo,
		},
		{
			name:      "ctx fails",
			ctx:       nil,
			mockSetup: func(transport *mock.MockRoundTripper, reader *mock.MockReader) {},
			want:      nil,
			wantErr:   main.ErrFailedToCreateRequest,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			t.Parallel()

			ctrl := gomock.NewController(t)
			defer ctrl.Finish()

			transport := mock.NewMockRoundTripper(ctrl)
			reader := mock.NewMockReader(ctrl)
			tt.mockSetup(transport, reader)

			got, err := main.GetValuesAndProcessThem(tt.ctx, &http.Client{Transport: transport})

			if tt.wantErr != nil {
				require.ErrorIs(t, err, tt.wantErr)
				require.Nil(t, got)
			} else {
				require.NoError(t, err)
				require.Equal(t, tt.want, got)
			}
		})
	}
}
