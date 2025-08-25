#!/bin/bash

# script to build all test functions
TEST_FUNCTIONS=$(cat src/test/test.c | grep -P '(?<=void )test_.+(?=\()' -o)
for test_function in $TEST_FUNCTIONS
do
    make TEST=$test_function
done
