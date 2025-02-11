#!/bin/sh
set -e

CULUMS_LINE="$(top -b -n 1 |head -n 7)"

CHECK_SET="
zsh
"

CURRENT_DIR=$(pwd)
DIR_NAME="$(/bin/date "+%Y-%m-%d")"
FILE_NAME="$(/bin/date "+%Y-%m-%d_%H")"

mkdir -p "$CURRENT_DIR/$DIR_NAME"

echo "$CULUMS_LINE" > $DIR_NAME/$FILE_NAME

for proc in $CHECK_SET; do
	echo "$(top -b -n 1 | grep $proc >> $DIR_NAME/$FILE_NAME)"
done
