package main

import (
	"database/sql"
	"embed"
	"fmt"

	"github.com/golang-migrate/migrate/v4"
	_ "github.com/golang-migrate/migrate/v4/database/postgres"
	"github.com/golang-migrate/migrate/v4/source/iofs"
	_ "github.com/lib/pq"
)

const dbURL = "postgres://postgres:postgres@localhost:54321/examples?sslmode=disable"

//go:embed migrations/*.sql
var migrationsFS embed.FS

func main() {
	dbConn, err := sql.Open("postgres", dbURL)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer dbConn.Close()

	d, err := iofs.New(migrationsFS, "migrations")
	if err != nil {
		fmt.Println(err)
		return
	}

	migrations, err := migrate.NewWithSourceInstance("iofs", d, dbURL)
	if err != nil {
		fmt.Println(err)
		return
	}

	err = migrations.Up()
	if err != nil && err.Error() != "no change" {
		fmt.Println(err)
		return
	}

	// Here goes your awesome code to get rich :D
}
