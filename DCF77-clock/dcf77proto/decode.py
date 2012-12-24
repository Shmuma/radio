# read uart received data bits, guess minute start

import sys


class Event (object):
    def __init__ (self, sec, usec, bit):
        self.sec = sec + int (usec / 1000)
        self.usec = usec % 1000
        self.bit = bit


    def __str__ (self):
        return "Event @%d,%d: %d" % (self.sec, self.usec, self.bit)


    def abs_time (self, cycle, prev_sec):
        """
        Turn event into absolute time, detecting wrap
        """
        inc = self.sec < prev_sec
        if inc:
            cycle += 1
        self.sec += cycle * 65
        self.usec += cycle * 536
        self.sec += int (self.usec / 1000)
        self.usec %= 1000
        return inc


    def distance (self, ev):
        """
        Return time distance between two events in miliseconds
        """
        dsec = self.sec - ev.sec
        dusec = self.usec - ev.usec
        return dsec * 1000 + dusec       


    @classmethod
    def parse (c, l):
        v = l.split (': ')
        if len (v) != 2:
            return None
        t = v[0].split (', ')
        if len (t) != 2:
            return None
        sec, usec = map (int, t)
        dat = v[1].split (', ')
        if len (dat) != 2:
            return None
        bit = int (dat[0])
        return c (sec, usec, bit)



# first - parse events
events = []
cycle = 0
prev_sec = None

for no, l in enumerate (sys.stdin):
    l = l.strip ()
    if len (l) == 0:
        continue
    ev = Event.parse (l)
    if ev != None:
        if prev_sec != None:
            sec = ev.sec
            if ev.abs_time (cycle, prev_sec):
                cycle += 1
            prev_sec = sec
        else:
            prev_sec = ev.sec
        events.append (ev)


def join_events (usecs, events):
    """
    Join events, nearer than given time together
    """
    start = events[0]
    joined = [start]
    
    for e in events[1:]:
        d = e.distance (start)
        if d < usecs:
            joined.append (e)
        else:
            yield start
            start = e
            joined = [e]


def bin2val (data):
    res = 0
    for v in data:
        res *= 2
        res += v
    return res


def decode (data, parity=False):
    # no undefined bits
    if any (map (lambda v: v == 7, data)):
        return None
    # check parity (assume even parity)
    if parity and len (filter (lambda v: v == 1, data)) % 2 == 1:
        return None
    return bin2val (data[:-1])


# bit stream with wildcards
res_bits = []

# join events, inserting wildcards
prev_e = None
for e in join_events (800, events):
    if prev_e == None:
        prev_e = e
        continue
    d = e.distance (prev_e)
    while d > 1500:
        res_bits.append (7)
        d -= 1000
    res_bits.append (e.bit)
    prev_e = e


hr_val = 0
min_val = 0
day_val = 0
mon_val = 0
year_val = 0
dow_val = 0

# trying to locate start of minute
for ofs in range (len (res_bits)):
    dat = res_bits[ofs:ofs+60]
    if len (dat) < 60:
        break
    # block always started with 0
    if dat[0] != 0:
        continue
    if dat[20] != 1:
        continue
#    min_dat = dat[21:29]
#    min_val = decode (min_dat, parity=True)
#    if min_val == None or min_val > 59:
#        continue
#    hr_dat = dat[30:36]
#    hr_val = decode (hr_dat, parity=True)
#    if hr_val == None or hr_val > 23:
#        continue

#    date_dat = dat[37:59]
#    date_val = decode (date_dat, parity=True)
#    if date_val == None:
#        continue

#    day_dat = dat[37:42]
#    day_val = decode (day_dat)
#    if day_val == None or day_val > 31:
#        continue
#    dow_dat = dat[43:45]
#    dow_val = decode (dow_dat)

    mon_dat = dat[46:50]
    mon_val = decode (mon_dat)
    if mon_val == None or mon_val > 12:
        continue

    year_dat = dat[51:58]
    year_val = decode (year_dat)
    if year_val == None:
        continue
    
    print "%02d:%02d %02d-%02d-%04d, dow = %s" % (hr_val, min_val, day_val, mon_val, year_val, dow_val)
