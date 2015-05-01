#!/usr/bin/env python2

import sys

def get_paging(c, l, x):
	if c < 1 or c > l:
		return "ERR"

	if l == 1: 
		return c 

	lower_lim = c-x
	upper_lim = c+x

	output = ["1"]

	if lower_lim > 2:
		output.append("...")

	for i in range( max(lower_lim, 1), min(upper_lim, l)+1) :
		output.append("%d" % (i, ))

	if upper_lim < l:
		output.append("... %d" % (l, ))

	return " ".join(output)

for line in sys.stdin:
	c, l, x = line.split(',')
	c = int(c) # pagina central
	l = int(l) # ultima pagina
	x = int(x) # show range [c-x, c, c+x]
	
	print get_paging(c,l,x)