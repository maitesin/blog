#!/bin/bash

echo "Welcome to this example file"
    echo "This is badly formatted"




  VAR=$( pwd )

echo "This script is being ran from ${VAR}"



for item       in   $(seq 1 10)
do
  echo "Number ${item}"
done
