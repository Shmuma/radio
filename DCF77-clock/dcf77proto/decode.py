# read uart received data bits, guess minute start

import sys


class Event (object):
    def __init__ (self, sec, usec, bit):
        self.sec = sec
        self.usec = usec
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

for l in sys.stdin:
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


j_events = [e for e in join_events (450, events)]

print "%d events joined into %d" % (len (events), len (j_events))
