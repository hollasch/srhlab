

#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# WARNING -- still to be worked out. In particular, there are Python2 vs Python3 issues below with `subprocess`.
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


# Launching subprocesses

import os
import subprocess

print 'Uh oh. This is Python 2.\n'

# Simple call
print("Printing UTC time (depends on 'timeprint').")
subprocess.call("timeprint -z UTC \"Current time is %H:%M:%S UTC\"")

# Executing a command and checking status. Useful for simple command-line scripts much like batch files.
cmd = 'dir bogus-dir\\bogus-file'
print("\nCalling os.system('{}').".format(cmd))

result = os.system(cmd)
print("Command returned {}.".format(result))

# Executing a command and processing the single-line output
cmd = ['findstr', '-c:"env"', 'README.md']
print("\nRunning '{}'.".format(cmd))
output = subprocess.run(cmd)
print("Command output is '{}'.".format(output.decode("utf-8")))
