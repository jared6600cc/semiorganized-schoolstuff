#!/usr/bin/python

import sys

tokens = []
fsaname = ''

def read():
    with open(fsaname) as f:
        content = f.readline()
    print('the FSA: ' + content)
    global tokens
    tokens = content.split(';')


def showTokens():
    for i in range(0,len(tokens)-1):
        print('token - ' + tokens[i])

fsaname = sys.argv[1]
read()
showTokens()
