# Tests for dht
from main import *
from random import randint

d = DHT(10)

# Add nodes
for i in range(15):
    r = randint(0, 10240)
    d.join(Node(r))

d.updateAllFingerTables()

for i in range(5, 20, 10):
    d.store(d._startNode, i, "hello" + str(i))

for i in range(5, 20, 2):
    print(d.lookup(d._startNode, i))
