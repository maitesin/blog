Output examples/demo.gif

Require echo

Set Shell fish
Set FontSize 18
Set Width 1020
Set Height 730
Set Theme "Monokai Pro"

Type "docker-compose down" Sleep 500ms Enter

Sleep 1s

Type "docker-compose up -d" Sleep 500ms Enter

Sleep 1s

Type "psql -h 127.0.0.1 -U postgres -d examples -p 54321 -c '\dt public.*'" Sleep 500ms Enter

Sleep 0.5s

Type postgres Enter

Sleep 1s

Type "cat migrations/*.up.sql" Sleep 500ms Enter

Sleep 1s

Type "cat migrations/*.down.sql" Sleep 500ms Enter

Sleep 1s

Type "go run ./..." Sleep 500ms Enter

Sleep 1s

Type "psql -h 127.0.0.1 -U postgres -d examples -p 54321 -c '\dt public.*'" Sleep 500ms Enter

Sleep 0.5s

Type postgres Enter

Sleep 5s