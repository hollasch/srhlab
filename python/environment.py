# Accessing the OS Environment Variables

import os

# This will throw if the environment does not have the value USERNAME.
print("USERNAME is '{}'.".format(os.environ['USERNAME']))

editor = os.environ.get('EDITOR')
if editor is not None:
    print("EDITOR is '{}'.".format(editor))

bogus = os.environ.get('BOGUS_VAR_NAME')
if bogus is None:
    print("BOGUS_VAR_NAME is not defined.")
