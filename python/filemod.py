#!/usr/local/bin/python3

# filemod.py
#
#   This example takes two arguments:
#
#       filemod.py <inputFile> <outputFile>
#
#   It reads in the first file line-by-line, and then prints to the output file the line number plus
#   the quoted input line.

import sys

input_name  = sys.argv[1]      # Input file name
output_name = sys.argv[2]      # Output file name

line_num = 1

with open (input_name, 'r') as in_file:
    with open (output_name, 'w') as numbered_file:
        for line in in_file:
            line = line[:-1]
            numbered_file.write ("{0:6d}| {1}\n" . format(line_num, line))
            line_num += 1
