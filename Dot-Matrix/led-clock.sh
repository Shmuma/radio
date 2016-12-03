#!/bin/sh
set -x
export PATH=/home/pi/bin:$PATH

BLANK_HOUR=22
ON_HOUR=6

PREV='something'
while true; do
  t=`date +"%H:%M"`
  h=`date +"%H"`
  if test $h -ge $BLANK_HOUR -o $h -lt $ON_HOUR; then
    t=""
  fi
  if test a$PREV != a$t; then
    echo $t
    PREV=$t
  fi
  sleep 5
done | text-example -f ~/.led/fonts/6x13.bdf -r 16 -x 1 -y 1 -C 0,200,255
#(while :; do date +"%H:%M" ; sleep 10 ; done) | text-example -f ~/.led/fonts/6x13.bdf -r 16 -x 1 -y 1 -C 0,200,255

