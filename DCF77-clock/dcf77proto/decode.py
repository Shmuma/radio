# read uart received data, debounce it and decode

import sys

debounce = 35

low = 0
high = 0
s = 0

for l in sys.stdin:
    l = l.strip ()
    if len (l) == 0:
        continue
    t, dat = l.split (': ')
    l, h = map (int, dat.split (' '))
    s += l
    s += h
    low += l
    high += h

    if high > debounce:
        print s, low, high
        low = 0
        high = 0
