print ('String Formatting')

print ('\n# Multiple arguments to print()')
print ("print()" , "with" , "multiple" , "arguments" , "are" , "concatenated" , "with" , "spaces.")

print ('\n# Numbered Argument Substitution')
name = "Fred"
print ("I {1} the {0}.".format("car","drove"))
print ("My name is {}.".format(name))

print ('\n# Parameterized Formatting')
sentenceSyntax = "The {subject} {verb} the {object}."
print (sentenceSyntax.format(object="treasure chest", subject="squid", verb="engulfed"))
print (sentenceSyntax.format(verb="defenestrates", subject="robot", object="intruder"))
print (sentenceSyntax.format(subject="platypus", object="captain", verb="lectured"))

print ('\n# String Interpolation')
a = 5
b = 10
print (f'a = {a}, b = {b}')
print (f'Five plus ten is {a + b} and not {2 * (a + b)}.')

print ('\n# Templated Strings (for user-supplied formatting)')
from string import Template
t = Template('Hey $name!')
print (t.substitute(name='Fred'))

print ('\n# Format Specs: alignment')
pi = 3.14159265359
print ('pi -> {:_<25}'.format(pi))
print ('pi -> {:_^25}'.format(pi))
print ('pi -> {:_>25}'.format(pi))

print ('\n# Format Specs: floats')
print ('pi {{:f}} = {:f}'.format(pi))
print ('pi {{:5f}} = {:5f}'.format(pi))
print ('pi {{:.4f}} = {:.4f}'.format(pi))
print ('pi {{:5.3f}} = {:5.3f}'.format(pi))
print ('pi {{:15.3f}} = {:15.3f}'.format(pi))

# -----
print ('\n* For more information, see https://realpython.com/python-formatted-output/')
