# read uart received data bits, guess minute start

import sys


def decode_val (val):
    return ("{0:016b}".format (int (val, 16)))[::-1]


errors = 0
was_error = 0

bits = ""

# parse data into bit stream
for lno, l in enumerate (sys.stdin):
    if lno == 0:
        continue
    l = l.strip ()
    for idx in range (len (l) / 5):
        ofs = idx * 5
        val = l[ofs:ofs+4]
        if len (set (val).difference ('0123456789ABCDEF')):
            # replace error with FFFF
            val = 'FFFF'
            errors += 1
            if was_error:
                break
            was_error = 1
        else:
            was_error = 0
        # decode val string
        bits += decode_val (val)

#print "Replaced %d errors" % errors
#print "Decoded %d bits" % len (bits)

res = ""
for i in range (len (bits)/10):
    if i % 100 == 0:
        print res
        res = ""
    v = bits[i*10:(i+1)*10]
    if len (filter (lambda t: t == '1', v)) >= 5:
        res += '1'
    else:
        res += '0'

sys.exit (0)


def correlation (a, b):
    count = len (filter (lambda v: v[0] == v[1], zip (a, b)))
    return float (count) / len (a)


# phase detection
edge = '1'*800 + '0'*100
count = len (edge)
for ofs in range (0, len (bits)):
    if len (bits[ofs:]) < count:
        break
    corr = correlation (edge, bits[ofs:ofs+count])
#    if corr > 0.8:
    print ofs, corr

    if ofs > 10000:
        break
