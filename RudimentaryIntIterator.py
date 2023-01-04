#!/usr/bin/python

n = int(input())
c = 0

LOOP = True

while LOOP:

	it = int(input())

	c += it
	n -= 1

	if n == 0:

		LOOP = False

print(c)
