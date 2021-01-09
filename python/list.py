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

