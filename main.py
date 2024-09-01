from collections import Counter
 
n_tests = int(input())
for _ in range(n_tests):
    n = int(input())
    s = input()
 
    if n % 2 == 0:
        even_counter = Counter()
        odd_counter = Counter()
 
        for i in range(len(s)):
            if i % 2 == 0:
                even_counter[s[i]] += 1
            else:
                odd_counter[s[i]] += 1
 
        even_counter_max = even_counter.most_common(1)[0]
        odd_counter_max = odd_counter.most_common(1)[0]
 
        result = n // 2 - even_counter_max[1] + n // 2 - odd_counter_max[1]
        print(result)
    else:
        if n == 1:
            print(1)
            continue
        best = 10**9
        even_counter = Counter()
        odd_counter = Counter()
        for i in range(len(s) - 1):
            if i % 2 == 0:
                even_counter[s[i]] += 1
            else:
                odd_counter[s[i]] += 1
        even_counter_after = Counter()
        odd_counter_after = Counter()
        best = min(best, n // 2 - even_counter.most_common(1)[0][1] + n // 2 - odd_counter.most_common(1)[0][1])
        for i in range(len(s)-2, -1, -1):
            if i % 2 == 0:
                even_counter[s[i]] -= 1
                even_counter_after[s[i+1]] += 1
            else:
                odd_counter[s[i]] -= 1
                odd_counter_after[s[i+1]] += 1
            even_counter_merged = even_counter + even_counter_after
            odd_counter_merged = odd_counter + odd_counter_after
            best = min(best, n // 2 - even_counter_merged.most_common(1)[0][1] + n // 2 - odd_counter_merged.most_common(1)[0][1])
        if n < 2:
            print(best + 2)
        else:
            print(best + 1)