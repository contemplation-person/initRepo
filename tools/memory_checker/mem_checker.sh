#!/bin/sh

set -e

CURRENT_DIR=~/log/MEM_CHECK/
FILE_NAME="$(/bin/date "+%Y-%m-%d_%H-%M")".txt

mkdir -p "$CURRENT_DIR"

TOP_DATA=$(top -b -n 1)

echo "$TOP_DATA" | head -n 6 >>  $CURRENT_DIR/$FILE_NAME

printf "%-20s %-20s %s\n\n" "CMD" "MEM(kb)" "USER"  >>  $CURRENT_DIR/$FILE_NAME

echo "$TOP_DATA" | sed -n '8,$p' | awk '{printf "%-20s %-20s %s\n", $12, $6, $2}' >>  $CURRENT_DIR/$FILE_NAME

