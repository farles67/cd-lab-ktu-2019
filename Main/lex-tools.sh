#!/usr/bin/env bash

lexrun() {
  if [ $# -ne 1 ]; then
    echo "Usage: lexrun <file.l>"
    return 1
  fi

  file="$1"

  if [ ! -f "$file" ]; then
    echo "Error: File '$file' not found."
    return 1
  fi

  echo "Running flex..."
  if ! flex "$file"; then
    echo "Flex failed."
    return 1
  fi

  exe="${file%.l}"

  echo "Compiling..."
  if ! gcc lex.yy.c -o "$exe" -lfl; then
    echo "Compilation failed."
    return 1
  fi

  echo "Running..."
  "./$exe"
}
