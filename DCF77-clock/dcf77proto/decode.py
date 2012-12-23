# read uart received data bits, guess minute start

import sys


bits = []
prev_sec = None

for l in sys.stdin:
    l = l.strip ()
    if len (l) == 0:
        continue
    v = l.split (': ')
    if len (v) != 2:
        continue
    t, dat = v
    # second
    sec = int (t.split (',')[0])
    bit = dat.split (',')[0]

    if prev_sec == sec:
        if bits[-1] != bit:
            bits[-1] = '*'
    else:
        if prev_sec != None:
            if sec > prev_sec:
                count = sec - prev_sec - 1
            else:
                count = sec + 65 - prev_sec - 1
            bits += ['_'] * count
        bits.append (bit)
        prev_sec = sec

longest = 0
cur = 0

for b in bits:
    if b in ['0', '1']:
        cur += 1
    else:
        longest = max (longest, cur)
        cur = 0

print bits
print len (bits)
print longest
