#!/usr/bin/python

import sys
for arg in sys.argv[1:]:
  try:
    f = open(arg, 'r')
  except IOError:
    print('cannot open', arg)
  else:
    print(arg, 'lines:', len(f.readlines()))
    f.close
