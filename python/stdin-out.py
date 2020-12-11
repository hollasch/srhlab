# Stream reading and writing, stdin/stdout

import fileinput

for line in fileinput.input():
    print (">>>" + line + "<<<")
