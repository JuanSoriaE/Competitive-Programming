import math
import sys
input = sys.stdin.readline

PI2 = 2 * math.pi

def get_angle(x, y):
    angle = math.atan2(y, x)
    return angle if angle >= 0 else angle + PI2

def solve():
    n, k = map(int, input().split())
    
    angles = []
    for _ in range(n):
        x, y = map(int, input().split())
        angles.append(get_angle(x, y))
    
    angles.sort()
    
    # Duplicate with 2*PI offset for circular wraparound
    extended = angles + [a + PI2 for a in angles]
    
    ans = 0
    for i in range(n):
        ans = max(ans, extended[i + k] - extended[i])
    
    print(f"{ans:.8f}")

t = int(input())
for _ in range(t):
    solve()