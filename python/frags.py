# Random collection of Python fragments

import os
import datetime

# Define variables
now = datetime.datetime.now()
the_date = now.strftime("%Y-%m-%d")
working_dir = os.getcwd()

# Print the text
print ("The date is {0}". format(the_date))
print ("The working dir is {0}".format(working_dir))

print ("I {0} the {1}".format("drove","car"))

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
print ("range(0,20,3) = " + printRange(range(0,20,3)))

# Substrings

print ("\"Klaatu barada nikto\" = \"" + "Klaatu barada nikto" + "\"")
print ("\"Klaatu barada nikto\"[7] = \"" + "Klaatu barada nikto"[7] + "\"")
print ("\"Klaatu barada nikto\"[7:] = \"" + "Klaatu barada nikto"[7:] + "\"")
print ("\"Klaatu barada nikto\"[7:13] = \"" + "Klaatu barada nikto"[7:13] + "\"")
print ("\"Klaatu barada nikto\"[:13] = \"" + "Klaatu barada nikto"[:13] + "\"")

# Dictionary

dow = { "Mo" : "Monday",
        "Tu" : "Tuesday",
        "We" : "Wednesday",
        "Th" : "Thursday",
        "Fr" : "Friday",
        "Sa" : "Saturday",
        "Su" : "Sunday" }

print ("Tu is %s and Fr is %s" % (dow["Tu"], dow["Fr"]))

# Sample Function

def add_one(x):
    return x + 1

# Calling a function

print ("Number is %d and %d+1 is %d" % (37, 37, add_one(37)))

# Concatenation of a list of strings separates with spaces.

print ("Example of print with comma:", "hello", "there", "world")

# Lists

print ("\nSample list:")
def printList(L):
    for item in L:
        print ("List item =", item)

L = ["a", "b", "zzz", "delta", "gamma"];
printList(L)

print ("\nAfter adding pi:")
L.append("pi")
printList(L)

print ("\nItems containing the letter 'a'")
print (list(filter(lambda e: 'a' in e, L)))
