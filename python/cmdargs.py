#!/usr/local/bin/python3

import sys

index = 0

for arg in sys.argv[0:]:
    print ("sys.argv[{0}]: {1}".format(index,arg))
    index += 1
