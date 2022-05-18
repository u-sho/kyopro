import numpy

N = int(input())
T = [int(input()) for i in range(N)]

ans = 1
for ti in T:
    ans = numpy.lcm(ans, ti)

print(ans)