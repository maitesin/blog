package migrations

import (
	"github.com/golang-migrate/migrate/v4/source"
	"github.com/golang-migrate/migrate/v4/source/httpfs"
	"io/fs"
	"net/http"
)

type MigrationDriver struct {
	httpfs.PartialDriver
	FS fs.FS
}

func RegisterMigrationDriver(migrationsFS fs.FS) {
	source.Register("embed", &MigrationDriver{
		FS: migrationsFS,
	})
}

func (md *MigrationDriver) Open(path string) (source.Driver, error) {
	err := md.PartialDriver.Init(http.FS(md.FS), path[len("embed://"):])
	if err != nil {
		return nil, err
	}

	return md, nil
}
