#!/bin/sh
set -e

CURRENT_DIR=$(pwd)
CULUMS_LINE="$(top -b -n 1 |head -n 7)"
DIR_NAME="$(/bin/date "+%Y-%m-%d")"
FILE_NAME="$(/bin/date "+%Y-%m-%d_%H")"

PROC_SET="
zsh 
su
"

mkdir -p "$CURRENT_DIR/$DIR_NAME"

capture_top_data_from() {
    trim_word=$(echo $@ | awk '{$1=$1; print}')

    echo "$CULUMS_LINE" > $DIR_NAME/$FILE_NAME
    top -b -n 1 | grep -E "$(echo "$trim_word" | tr ' ' '|')" >> "$DIR_NAME/$FILE_NAME"
}

capture_top_data_from $PROC_SET