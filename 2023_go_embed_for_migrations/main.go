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

const dbName = "db_name"

//go:embed migrations/*.sql
var migrationsFS embed.FS

func main() {
	dbConn, err := sql.Open("postgres", fmt.Sprintf("postgres://postgres:postgres@localhost:54321/%s", dbName))
	if err != nil {
		fmt.Println(err)
		return
	}
	defer dbConn.Close()

	dbDriver, err := postgres.WithInstance(dbConn, &postgres.Config{})
	if err != nil {
		fmt.Println(err)
		return
	}

	err = migrationsToRun.Up()
	if err != nil && err.Error() != "no change" {
		fmt.Println(err)
		return
	}

	// Here goes your awesome code to get rich :D
}
