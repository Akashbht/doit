import re

text = "Do you know how to be a script kiddie. how ? It's simple, just copy me"
hack = " The quick brown fox jumps over the lazy dog"
out = re.findall('ow', text)
print(out)

out = re.findall('ow*', hack)
print(out)

ok = "a......ab.....abb.......abbb.....abbbb"

lol = re.findall('ab*', ok)
lol = re.findall('ab?', ok)
lol = re.findall('ab+', ok)
print(lol)

text = "This is a sample paragraph. do you like paragliding? no, i like parasailing "
out = re.findall('para[aga]+', text)
print(out)

text = "This is a sample exclamation! Don't overreact mate? "
out = re.findall('[^!?.]+', text)
print(out)

text = "Do you know how 2 be a script kiddie. how ? It's simple, just copy me"
out = re.findall('[a-z]+', text)
print(out)
out2 = re.findall('[A-Z][a-z]+', text)
print(out2)



