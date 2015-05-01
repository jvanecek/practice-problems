#!/usr/bin/
import sys

def compress(s):
	if s == "": return ""

	actual_c = None
	last_c = s[0]
	count = 0
	compressed = ""

	for i in range(0,len(s)):
		actual_c = s[i]
		
		if last_c == actual_c:
			count = count + 1
		else: 
			compressed = "%s%s%s" % (compressed, count if count > 1 else "", last_c)
			last_c = actual_c
			count = 1
	
	compressed = "%s%s%s" % (compressed, count if count > 1 else "", last_c)
	return compressed

N = sys.stdin.readline()
output = N

for i in range(0, int(N)):
	line = sys.stdin.readline()
	output = output + compress(line)

print output