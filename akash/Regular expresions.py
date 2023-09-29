import re

text = "Do you know how to be a script kiddie. how ? It's simple, just copy me"
hack = "To hack the hacker, you need to hack the hacker's hacking system."
match = re.search('script', text)
print(match.start())
print(match.end())

print(re.split('a', text))

out = re.findall("hack", hack)
print(out)




