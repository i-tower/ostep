#! /usr/bin/env python3

import re
#import optparse as OptionParser

#options = OptionParser()



regx = re.compile(r'[0-9a-f]{8,10}')

with open("trace.txt", "r", encoding="utf-8") as infile:
    read_data = infile.read()




parsed = regx.findall(read_data)

shifted = []
for address in parsed:
    tmp = int(address, base=16)
    tmp &= 0xfffffffffffff000
    tmp >>= 12
    shifted.append(str(tmp))

collection = []
count = 0
for page in shifted:
    if collection.count(page) == 0:
        collection.append(page)
        count += 1

print("Parsed file contains " + str(count) + " unique pages\n")

with open("addresses.txt", "w", encoding="utf-8") as outfile:
    for address in shifted:
        outfile.write(address + "\n")
    


