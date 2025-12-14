# Problem Name: Sale
# Difficulty  : 900
# Link        : https://codeforces.com/problemset/problem/34/B

# Inputs
amountTVs, maxCarry = map(int, input().split())
buyableTVs = list(map(int, input().split()))

#print(buyableTVs)

# Logic
buyableTVs.sort()
#print(buyableTVs)

moneyEarned = 0
for i in range(maxCarry):
    if buyableTVs[i] < 0:
        moneyEarned = moneyEarned-buyableTVs[i]
    else:
        break

# Outputs
print(moneyEarned)