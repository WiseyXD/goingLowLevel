#!/bin/bash
set -e

cmake .
make

echo "---- Running binary ----"
./HTTP

