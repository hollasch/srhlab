#!/usr/bin/env python

import time
import sys

def countdown(secs):
    while (secs > 0):
        sys.stdout.write('\r%02d:%02d ' % (secs/60,secs%60))
        sys.stdout.flush()
        time.sleep(1)
        secs -= 1
    print '\rDone.'

countdown(75)
