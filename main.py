def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def solve(n, a):
    b = []
    for i in range(n - 1):
        b.append(gcd(a[i], a[i + 1]))

    idx = -1
    for i in range(n - 2):
        if b[i] > b[i + 1]:
            idx = i
            break

    if idx == -1:
        return "YES"

    a1 = []
    for i in range(n):
        if i != idx + 1:
            a1.append(a[i])

    a2 = []
    for i in range(n):
        if i != idx + 2:
            a2.append(a[i])

    a3 = []
    for i in range(n):
        if i != idx:
            a3.append(a[i])

    b1 = []
    for i in range(n - 2):
        b1.append(gcd(a1[i], a1[i + 1]))

    b2 = []
    for i in range(n - 2):
        b2.append(gcd(a2[i], a2[i + 1]))

    b3 = []
    for i in range(n - 2):
        b3.append(gcd(a3[i], a3[i + 1]))

    flag1 = True
    for i in range(n - 3):
        if b1[i] > b1[i + 1]:
            flag1 = False
            break

    flag2 = True
    for i in range(n - 3):
        if b2[i] > b2[i + 1]:
            flag2 = False
            break

    flag3 = True
    for i in range(n - 3):
        if b3[i] > b3[i + 1]:
            flag3 = False
            break

    if not (flag1 or flag2 or flag3):
        return "NO"
    else:
        return "YES"

def main():
    tes = int(input())
    for _ in range(tes):
        n = int(input())
        a = list(map(int, input().split()))
        result = solve(n, a)
        print(result)

if __name__ == "__main__":
    main()
