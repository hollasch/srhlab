def printRange(r):
    s = "["
    first = True
    for i in r:
        if first:
            first = False
        else:
            s += ", "
        s += "{0}".format(i)
    return s + "]"

print ("range(10) = " + printRange(range(10)))
print ("range(11,20) = " + printRange(range(11,20)))
print ("range(0,21,3) = " + printRange(range(0,20,3)))
