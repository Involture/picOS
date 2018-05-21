import numpy as np

scs = open("scs2.txt", "r")

blank = False

tree = {}

hexd = {
	'0': 0,
	'1': 1,
	'2': 2,
	'3': 3,
	'4': 4,
	'5': 5,
	'6': 6,
	'7': 7,
	'8': 8,
	'9': 9,
	'A': 10,
	'B': 11,
	'C': 12,
	'D': 13,
	'E': 14,
	'F': 15,
	'a': 10,
	'b': 11,
	'c': 12,
	'd': 13,
	'e': 14,
	'f': 15
}

def cv16to10(s, l):
	if len(s) != 2:
		raise ValueError(s)
	else:
		i = 0
		if hexd.has_key(s[0]):
			i += hexd[s[0]] * 16
			if hexd.has_key(s[1]):
				i += hexd[s[1]]
				return i
			else:
				raise ValueError(2+l)
		else:
			raise ValueError(3+l)

def cv10to16(s):
	s = int(s[1])
	s += 10 * int(s[0])
	return s

i = 0
while True:
	i += 1
	# if i > 9:
	# 	break
	line = scs.readline()

	if line == "\n":
		if blank == True:
			break
		else:
			blank = True
	elif line[0:2] == "##":
		pass
	else:
		blank = False

		part = -1

		p0_id = ""
		p1_caption = ""
		p2_content = ""
		p2_parsed_content = []
		p3_content = ""
		p3_parsed_content = []

		for c in line:
			print(line)
			if part == -1:
				if c != ",":
					p0_id += c
				else:
					part = 0

			elif part == 0:
				if c != ",":
					p1_caption += c
				else:
					part = 1
			elif part == 1:
				if c == "," or c == "\n":
					part = 2
					for k in p2_content.split(';'):
						p2_parsed_content.append(k)
				elif c == " ":
					pass
				else:
					p2_content += c
			elif part == 2:
				if c == "\n":
					if p3_content == "":
						pass
					else:
						if p3_content == " ":
							p3_parsed_content.append(" ")
							p3_parsed_content.append(" ")
							p3_parsed_content.append(" ")
						else:
							for k in p3_content.split(' '):
								p3_parsed_content.append(k)
					while len(p3_parsed_content) < 3:
						p3_parsed_content.append("\\0")
				else:
					p3_content += c

		print(p3_parsed_content)

		# to catch the case when a keyboard key is released
		r_p2_parsed_content = []
		if p2_parsed_content[0] == "E0":
			r_p2_parsed_content.append("E0")
		r_p2_parsed_content.append("F0")
		if p2_parsed_content[0] == "E0":
			r_p2_parsed_content.append(p2_parsed_content[1])
		else:
			r_p2_parsed_content.append(p2_parsed_content[0])


		r_p2_parsed_content.reverse()
		r_s = 0
		r_p = 1
		for v in r_p2_parsed_content:
			r_s += r_p * cv16to10(v, i)
			r_p *= 256
		r_p2_parsed_content.reverse()
		r_s2 = format(r_s, '06x').upper()


		tree[r_s2] = [p1_caption+" released", r_p2_parsed_content, 0, p0_id, "\\0", "\\0", "\\0"]
		# done

		p2_parsed_content.reverse()


		s = 0
		p = 1
		for v in p2_parsed_content:
			s += p * cv16to10(v, i)
			p *= 256

		p2_parsed_content.reverse()
		s2 = format(s, '06x').upper()

		tree[s2] = [p1_caption, p2_parsed_content, 1, p0_id, p3_parsed_content[0], p3_parsed_content[1], p3_parsed_content[2]]

scs.close()

# now
# the initial file has been read



# to add the last two exceptions of SCS2

# done


# to generate the corresponding C code


L1 = []
L2 = {}
L3 = {}
for key in sorted(tree.items()):
	print(key)

# _i_ = input()

for key in sorted(tree):
	a1 = cv16to10(key[0:2], 0)
	a2 = cv16to10(key[2:4], 0)
	a3 = cv16to10(key[4:6], 0)
	nk1 = format(int(a1), '02x').upper()
	if not nk1 in L1:
		L1.append(nk1)

for v1 in L1:
	L2[v1] = []

for key in sorted(tree):
	a1 = cv16to10(key[0:2], 0)
	a2 = cv16to10(key[2:4], 0)
	a3 = cv16to10(key[4:6], 0)
	nk1 = format(int(a1), '02x').upper()
	nk2 = format(int(a2), '02x').upper()
	if not nk2 in L2[nk1]:
		L2[nk1].append(nk2)

for v1 in L1:
	for v2 in L2[v1]:
		print(v1+v2)
		L3[v1+v2] = []

for key in sorted(tree):
	a1 = cv16to10(key[0:2], 0)
	a2 = cv16to10(key[2:4], 0)
	a3 = cv16to10(key[4:6], 0)
	nk1 = format(int(a1), '02x').upper()
	nk2 = format(int(a2), '02x').upper()
	nk3 = format(int(a3), '02x').upper()
	if not nk3 in L3[nk1+nk2]:
		L3[nk1+nk2].append(nk3)



	# if not nk2 in L2:
	# 	L2[nk1].append(nk2)

	# if not nk1 in L1:
	# 	L1.append(nk1)
	# L2[nk1] = []
	# L3[nk1+nk2] = []
	# if not nk2 in L2:
	# 	L2[nk1].append(nk2)

print(L1)
print(L2)
print(L3)

final_str = ""
def add(k, s):
	global final_str
	for i in range(k):
		final_str += "    "
	final_str += s+"\n"
n = 1


add(n, "switch(a) {")
add(n+1, "case 0x00:")
add(n+2, "switch(b) {")
add(n+3, "case 0x00:")
add(n+4, "switch(c) {")
for i in L3['0000']:
	add(n+5, "case 0x"+i+":")
	# add(n+6, "last_cmd_name = \""+str(tree["0000"+i][0])+"\";")
	add(n+6, "last_cmd_is_pressed = "+str(tree["0000"+i][2])+";")
	add(n+6, "kc = "+tree["0000"+i][3]+";")
	add(n+6, "last_cmd_chr1 = \'"+str(tree["0000"+i][4])+"\';")
	add(n+6, "last_cmd_chr2 = \'"+str(tree["0000"+i][5])+"\';")
	add(n+6, "last_cmd_chr3 = \'"+str(tree["0000"+i][6])+"\';")
	add(n+6, "break;")
add(n+5, "default:")
add(n+6, "is_cmd = 2;")
add(n+4, "}")
add(n+4, "break;")
add(n+3, "case 0xE0:")
add(n+4, "switch(c) {")
for i in L3['00E0']:
	add(n+5, "case 0x"+i+":")
	# add(n+6, "last_cmd_name = \""+str(tree["00E0"+i][0])+"\";")
	add(n+6, "last_cmd_is_pressed = "+str(tree["00E0"+i][2])+";")
	add(n+6, "kc = "+tree["00E0"+i][3]+";")
	add(n+6, "last_cmd_chr1 = \'"+str(tree["00E0"+i][4])+"\';")
	add(n+6, "last_cmd_chr2 = \'"+str(tree["00E0"+i][5])+"\';")
	add(n+6, "last_cmd_chr3 = \'"+str(tree["00E0"+i][6])+"\';")
	add(n+6, "break;")
add(n+5, "default:")
add(n+6, "is_cmd = 3;")
add(n+4, "}")
add(n+4, "break;")
add(n+3, "case 0xF0:")
add(n+4, "switch(c) {")
for i in L3['00F0']:
	add(n+5, "case 0x"+i+":")
	# add(n+6, "last_cmd_name = \""+str(tree["00F0"+i][0])+"\";")
	add(n+6, "last_cmd_is_pressed = "+str(tree["00F0"+i][2])+";")
	add(n+6, "kc = "+tree["00F0"+i][3]+";")
	add(n+6, "last_cmd_chr1 = \'"+str(tree["00F0"+i][4])+"\';")
	add(n+6, "last_cmd_chr2 = \'"+str(tree["00F0"+i][5])+"\';")
	add(n+6, "last_cmd_chr3 = \'"+str(tree["00F0"+i][6])+"\';")
	add(n+6, "break;")
add(n+5, "default:")
add(n+6, "is_cmd = 4;")
add(n+4, "}")
add(n+4, "break;")
add(n+3, "default:")
add(n+4, "is_cmd = 5;")
add(n+2, "}")
add(n+2, "break;")
add(n+1, "case 0xE0:")
add(n+2, "switch(b) {")
add(n+3, "case 0x00:")
add(n+4, "switch(c) {")
# for i in L3['e000']:
# 	add(n+5, "case 0x"+i+":")
# 	add(n+6, "last_cmd_name = \""+str(tree["e000"+i][0])+"\";")
# 	add(n+6, "last_cmd_is_pressed = \""+str(tree["e000"+i][1])+"\";")
# 	# add(n+6, "last_cmd_name = \""+str(tree[i][0])+"\";")
# 	add(n+6, "break;")
add(n+5, "default:")
add(n+6, "is_cmd = 6;")
add(n+4, "}")
add(n+4, "break;")
add(n+3, "case 0xE0:")
add(n+4, "switch(c) {")
# for i in L3['e0e0']:
# 	add(n+5, "case 0x"+i+":")
# 	add(n+6, "last_cmd_name = \""+str(tree["e0e0"+i][0])+"\";")
# 	add(n+6, "last_cmd_is_pressed = \""+str(tree["e0e0"+i][1])+"\";")
# 	# add(n+6, "last_cmd_name = \""+str(tree[i][0])+"\";")
# 	add(n+6, "break;")
add(n+5, "default:")
add(n+6, "is_cmd = 7;")
add(n+4, "}")
add(n+4, "break;")
add(n+3, "case 0xF0:")
add(n+4, "switch(c) {")
for i in L3['E0F0']:
	add(n+5, "case 0x"+i+":")
	# add(n+6, "last_cmd_name = \""+str(tree["E0F0"+i][0])+"\";")
	add(n+6, "last_cmd_is_pressed = "+str(tree["E0F0"+i][2])+";")
	add(n+6, "kc = "+tree["E0F0"+i][3]+";")
	add(n+6, "last_cmd_chr1 = \'"+str(tree["E0F0"+i][4])+"\';")
	add(n+6, "last_cmd_chr2 = \'"+str(tree["E0F0"+i][5])+"\';")
	add(n+6, "last_cmd_chr3 = \'"+str(tree["E0F0"+i][6])+"\';")
	add(n+6, "break;")
add(n+4, "}")
add(n+4, "break;")
add(n+3, "default:")
add(n+4, "is_cmd = 8;")
add(n+2, "}")
add(n+2, "break;")
add(n+1, "default:")
add(n+2, "is_cmd = 9;")
add(n, "}")

c_file = open("gc.c", "w")
c_file.write(final_str)
c_file.close()
