# Problem Name: Multiply by 2, divide by 6
# Difficulty  : 900
# Link        : https://codeforces.com/problemset/problem/1374/B

# Inputs
amountTests = int(input())
listOfNumbers = []
resList = []

for _ in range(amountTests):
    listOfNumbers.append(int(input()))

# print(listOfNumbers)

# Logic
for number in listOfNumbers:
    counterDiv2 = 0
    counterDiv3 = 0
    while number % 2 == 0:
        number = number / 2
        counterDiv2 = counterDiv2 + 1
    
    while number % 3 == 0:
        number = number / 3
        counterDiv3 = counterDiv3 + 1

    # print("2^",counterDiv2, "3^", counterDiv3)
    if number > 1 or counterDiv3 < counterDiv2:
        resList.append(-1)
        continue
        
    res = counterDiv3 + (counterDiv3-counterDiv2)
    resList.append(res)

# Outputs
for value in resList:
    print(value)