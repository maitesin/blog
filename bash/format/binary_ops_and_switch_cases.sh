#!/bin/bash

first_thing_to_be_run \
&& second_thing_to_be_run \
&& third_thing_to_be_run \
&& forth_and_last_thing_to_be_run

number=$RANDOM
case ${number} in
5)
echo "Lucky number"
;;
7)
echo "Lucky number"
;;
*)
echo "It may not be a lucky number"
;;
esac
