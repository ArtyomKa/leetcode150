#!/bin/bash
set +x

echo "Building ${1}"
output=$(basename -- "$1" .cpp)
echo "output ${output}"

g++ ${1} -g -o ${output}

