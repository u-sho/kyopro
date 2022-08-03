N, a = map(int, input().split())
k = int(input())
b = [-1] + list(map(int, input().split()))

bPassed = [0]*(N+1)

chain = [0]
chainLength = 1
idx = a
while True:
    if bPassed[b[idx]] > 0: break

    chainLength += 1
    bPassed[idx] = chainLength

    idx = b[idx]
    chain.append(idx)

if k < chainLength:
    print(chain[k])
else:
    k -= chainLength - 1
    k %= chainLength - idx
    print( chain[ idx + k ] )

# print(bPassed[idx]
print(chain)