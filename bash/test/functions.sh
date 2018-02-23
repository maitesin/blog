#!/bin/bash

sum() {
  if [ ${#} -ne 2 ]; then
    echo "Bad number of parameters"
    echo "Usage: sum <number 1> <number 2>"
  else
    num1=${1}; shift
    num2=${1}; shift
    echo "${num1}+${num2}" | bc
  fi
}
