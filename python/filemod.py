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

inputName  = sys.argv[1]      # Input file handle
outputName = sys.argv[2]      # Output file handle

inputFile = open (sys.argv[1])             # Open input file for reading (default)
outputFile = open (sys.argv[2], 'w')       # Open output file for writing

lineNum = 1

for line in inputFile:                     # Could also use inputFile.readlines()
    line = line[:-1]                       # Chop trailing newline
    outputFile.write ("{0}: \"{1}\"\n" . format(lineNum,line))
    lineNum += 1

inputFile.close()
outputFile.close()
