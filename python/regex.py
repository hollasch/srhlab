# Example regular expressions in Python

import fileinput
import re

datePattern = re.compile('^D\d\d/\d\d/\d\d\d\d$')

for line in fileinput.input():
    line = line.rstrip()
    if datePattern.match(line):
        line = line[1:]
        (month, day, year) = line.split('/')
        print ('D{2}/{0}/{1}'.format(month,day,year))
    else:
        print (line)
