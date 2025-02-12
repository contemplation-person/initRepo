#!/bin/sh
set -e

ROOT_DIR=$(pwd)
DIR_NAME="$(/bin/date "+%Y-%m-%d")"
FILE_NAME="$(/bin/date "+%Y-%m-%d_%H")"
PROC_SET="
zsh
su
sh
"
$(echo "CMD RSS(kb)" > "$ROOT_DIR/$DIR_NAME/$FILE_NAME")
mkdir -p "$ROOT_DIR/$DIR_NAME"

for proc in $PROC_SET; do    
    ps -eo cmd,rss | awk -v proc="$proc" '$1 == proc && NF==2 {print $1, $2}' >> "$ROOT_DIR/$DIR_NAME/$FILE_NAME"
done
