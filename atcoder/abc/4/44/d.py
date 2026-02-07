N = int(input())
A = [int(Ai) for Ai in input().split()]
A.sort()

ans = [0]
for i in range(A[0]):
    ans[0] = ans[0] + 10**i
(x, y) = divmod(ans[0] * N, 10**A[0])
ans[0] = y
ans.append(x)

for i in range(1, N):
    if A[i] == A[i-1]:
        continue

    bi = 0
    for j in range(A[i]-A[i-1]):
        bi = bi + 10**j

    (x, y) = divmod(bi * (N-i) + ans[-1], 10**(A[i]-A[i-1]))
    ans[-1] = y
    ans.append(x)

if ans[-1] == 0 and len(ans) > 1:
    ans.pop()
for i in range(0, len(ans)):
    print(ans[len(ans)-1-i], end='')
