#!/usr/bin/env python3


from collections import Counter

input()

prices = [int("".join(x.split("."))) for x in input().split()]

total = sum(prices)

last = Counter((x % 5 for x in prices))

total -= last[1] + 2 * last[2]

threefourpairs = min(last[3], last[4])

total -= threefourpairs * 2
last[3] -= threefourpairs
last[4] -= threefourpairs

total -= last[3] // 2 + last[4] // 3 * 2

print(f"{total/100:.2f}")
