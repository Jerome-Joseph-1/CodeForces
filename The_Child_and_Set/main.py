from collections import defaultdict

def solve():

    d = defaultdict(lambda : [0])

    SUM, limit = map(int, input().split())

    def lowest_bit(number):
        i = 1
        while number & i == 0:
            i <<= 1
        return i

    for i in range(1, limit + 1):
        index = lowest_bit(i)
        d[index].append(i)
        d[index][0] += 1

    i = 1
    ans = []
    while i < 2**32:
        if SUM & i:
            if d[i][0] > 0:
                ans.append(d[i][d[i][0]])
                d[i][0] -= 1
            else:
                need = 2
                power = i // 2
                while need > 0 and power > 0:
                    pop_these = min(need, d[power][0])
                    need -= pop_these
                    if need > 0: 
                        need *= 2
                    for _ in range(pop_these):
                        ans.append(d[power][d[power][0]])
                        d[power][0] -= 1
                    power >>= 1
                if need > 0:
                    return -1
        i <<= 1

    return ans

ret = solve()
if ret == -1:
    print(-1)
else:
    print(len(ret))
    for i in ret:
        print(i, end=' ')
    print()