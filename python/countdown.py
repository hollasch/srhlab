#!/usr/bin/env python

import time
import sys

seconds_remaining = int(sys.argv[1]) if (len(sys.argv) > 1) else 75

def countdown(secs):
    while (secs > 0):
        sys.stdout.write('\r%02d:%02d ' % (secs/60,secs%60))
        sys.stdout.flush()
        time.sleep(1)
        secs -= 1
    print ('\rDone.')

countdown(seconds_remaining)
