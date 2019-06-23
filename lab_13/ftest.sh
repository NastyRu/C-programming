#!/bin/sh

if diff -b out.txt file.txt; then
  echo OK
else
  echo FILES ARE DIFFERENT

fi
