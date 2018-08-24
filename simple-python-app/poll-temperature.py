#!/usr/bin/python
import time
import os
 
os.makedirs("/var/volatile/log")
f = open('/var/log/poll-temp.log', 'w')
while (1):
    s = "%s %s polling temperature ...\n" % (time.strftime("%d/%m/%Y"), time.strftime("%I:%M:%S"))
    f.write(s)
    f.flush()
    time.sleep(5)
