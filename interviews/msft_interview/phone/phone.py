#!/usr/bin 

import re 
import sys 

ERR_MSG = "Fleshling follow-up needed"

def is_valid(phone):
	valid_formats = [
		# Area code in parenthesis	
		"^(\+1 \(\d{3}\) \d{3}\-\d{4})$",
		"^(1 \(\d{3}\) \d{3}\-\d{4})$", 
		"^(\(\d{3}\) \d{3}\-\d{4})$", 
		# Period separation	
		"^(\+1\.\d{3}\.\d{3}\.\d{4})$",
		"^(1\.\d{3}\.\d{3}\.\d{4})$",
		"^(\d{3}\.\d{3}\.\d{4})$",
		# Dash separation	
		"^(\+1\-\d{3}\-\d{3}\-\d{4})$",
		"^(1\-\d{3}\-\d{3}\-\d{4})$",
		"^(\d{3}\-\d{3}\-\d{4})$",
		# Space separation	
		"^(\+1 \d{3} \d{3} \d{4})$",
		"^(1 \d{3} \d{3} \d{4})$",
		"^(\d{3} \d{3} \d{4})$",
		# Vanitiy format 
		"^(1-\d{3}-[a-zA-Z0-9]{7})$"
	]

	for format in valid_formats:
		if re.match(format, phone): 
			return True

	return False

def clean_number(phone):
	new_phone = phone
	to_delete = [" ", ".", "-", "(", ")"]
	to_change = [
		("A", "2"),
		("B", "2"),
		("C", "2"),
		("D", "3"),
		("E", "3"),
		("F", "3"),
		("G", "4"),
		("H", "4"),
		("I", "4"),
		("J", "5"),
		("K", "5"),
		("L", "5"),
		("M", "6"),
		("N", "6"),
		("O", "6"),
		("P", "7"),
		("Q", "7"),
		("R", "7"),
		("S", "7"),
		("T", "8"),
		("U", "8"),
		("V", "8"),
		("W", "9"),
		("X", "9"),
		("Y", "9"),
		("Z", "9")]

	for c in to_delete: 
		new_phone = new_phone.replace(c, "")
	for c in to_change:
		new_phone = new_phone.replace(c[0], c[1])
	return new_phone

def formated_number(phone):
	if not is_valid(phone):
		return ERR_MSG

	phone = clean_number(phone)

	if len(phone) == 10: 
		return "+1%s" % (phone, ) 

	elif len(phone) == 11:
		return "+%s" % (phone, )

	else: 
		return phone

for phone in sys.stdin:
	print formated_number(phone)
