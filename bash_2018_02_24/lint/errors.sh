#!/bin/sh

for file in $(ls *.py); do
	grep -qi wololo* $file \
		&& echo -e 'The file $file contains words that start with wololo'
done
