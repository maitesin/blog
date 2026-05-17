package main

import (
	"context"
	"errors"
	"fmt"
	"io"
	"log"
	"net/http"
	"strings"
)

var (
	ErrFailedToCreateRequest    = errors.New("failed to create request")
	ErrFailedToPerformRequest   = errors.New("failed to perform request")
	ErrFailedToReadBody         = errors.New("failed to read body")
	ErrStatusCodeInvalid        = errors.New("invalid status code")
	ErrBodyDoesNotContainWololo = errors.New("body does not contain wololo")
)

func main() {
	// Never use directly the http.DefaultClient. This is just to keep it short.
	res, err := GetValuesAndProcessThem(context.Background(), http.DefaultClient)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(res)
}

func GetValuesAndProcessThem(ctx context.Context, client *http.Client) ([]byte, error) {
	req, err := http.NewRequestWithContext(ctx, "GET", "http://wololo:1234/", nil)
	if err != nil {
		return nil, ErrFailedToCreateRequest
	}

	res, err := client.Do(req)
	if err != nil {
		return nil, ErrFailedToPerformRequest
	}
	defer res.Body.Close()

	if res.StatusCode != 200 {
		return nil, ErrStatusCodeInvalid
	}

	// Do not read the whole body at once like here. This is just to keep it short.
	body, err := io.ReadAll(res.Body)
	if err != nil {
		return nil, ErrFailedToReadBody
	}

	if !strings.Contains(string(body), "wololo") {
		return nil, ErrBodyDoesNotContainWololo
	}

	return body, nil
}
