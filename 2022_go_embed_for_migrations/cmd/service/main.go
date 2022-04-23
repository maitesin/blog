package main

import (
	"database/sql"
	"embed"
	"fmt"

	"github.com/golang-migrate/migrate/v4"
	"github.com/golang-migrate/migrate/v4/database/postgres"
	_ "github.com/lib/pq"
	"github/maitesin/blog/2022_go_embed_for_migrations/pkg/sql/migrations"
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

	migrations.RegisterMigrationDriver(migrationsFS)
	migrationsToRun, err := migrate.NewWithDatabaseInstance("embed://migrations", dbName, dbDriver)
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
