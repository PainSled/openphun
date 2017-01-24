#! /usr/bin/env python

import math
import random

nWine = 1000 # Change to any number of wine. (Starts to get sluggish above a couple of million)
nMice = math.ceil(math.log(nWine, 2))

badWine = random.randrange(1, nWine, 1)

def testWineBottles(wineBottles):
    for n in wineBottles:
        if n == badWine:
            return True
    return False

def selectRange(mouseNumber):
    rng = []
    n = 0
    while n <= nWine:
        for r in range(0,2**mouseNumber):
            n += 1
        for r in range(0,2**mouseNumber):
            n += 1
            rng.append(n)
    return rng


def main():
    print("Number of wine bottles: " + str(nWine))
    print("Number of experimental mice: " + str(nMice) + "\n")
    
    estimate = 1 # We started at 1, not 0, when numbering the wine.
    tally = []
    for i in range(0, nMice):
        dead = testWineBottles(selectRange(i))
        tally.append([2**i, dead])
        if dead:
            estimate += 2**i 

    for number, status in tally:
        print(str(number) + "\t", end="")
    print("")
    for number, status in tally:
        print(("Dead" if status else "Alive") + "\t", end="")
    print("\n\nBinary: ", end="")
    for number, status in tally:
        print(("1" if status else "0"), end="")

    print("\n\nEstimated poisoned wine: " + str(estimate))
    print("Specific poisoned wine: " + str(badWine) + "\n")

main()
