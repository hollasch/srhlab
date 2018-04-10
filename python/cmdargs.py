#!/usr/local/bin/python3

import sys


if __name__ == "__main__":
    num_args = len(sys.argv)
    print ("{0} argument{1}" . format(num_args, "s" if (num_args != 1) else ""))

    index = 0

    for arg in sys.argv:
        print ("sys.argv[{0}]: \"{1}\"" . format(index,arg))
        index += 1
