#!/usr/bin/env bats

source functions.sh

@test "The addition of 4 and 5 results in 9" {
  run sum 4 5
  [ "$status" -eq 0 ]
  [ "${#lines[@]}" -eq 1 ]
  [ "${lines[0]}" = "9" ]
}

@test "The addition of -5 and 9 results in 4" {
  run sum -5 9
  [ "$status" -eq 0 ]
  [ "${#lines[@]}" -eq 1 ]
  [ "${lines[0]}" = "4" ]
}

@test "Bad number of parameters (1)" {
  run sum 10
  [ "$status" -eq 0 ]
  [ "${#lines[@]}" -eq 2 ]
  [ "${lines[0]}" = "Bad number of parameters" ]
  [ "${lines[1]}" = "Usage: sum <number 1> <number 2>" ]
}

@test "Bad number of parameters (3)" {
  run sum 10 11 12
  [ "$status" -eq 0 ]
  [ "${#lines[@]}" -eq 2 ]
  [ "${lines[0]}" = "Bad number of parameters" ]
  [ "${lines[1]}" = "Usage: sum <number 1> <number 2>" ]
}
