def main():
    test_cases = int(input())
    for _ in range(test_cases):
        a = int(input())
        arr = list(map(int, input().split()))
        mp = {}
        for num in arr:
            mp[num] = mp.get(num, 0) + 1
        arr.sort()
        i = 0
        prev = 0
        for i in range(a):
            if arr[i] - prev > 1:
                break
            prev = arr[i]
            if i == a:
            if len(mp) % 2 == 0:
                print("Bob")
            else:     
                print("Alice")
        elif a == 1 or i % 2 == 0 or len(mp) == 1:            print("Alice")
        else:            print("Bob")
if name == "__main__":
    main()