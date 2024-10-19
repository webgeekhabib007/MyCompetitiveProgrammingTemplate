def solve(n):
    result = []
    for i in range(n):
        result.append('0' if i % 2 == 0 else '1')
    print(''.join(result))

if __name__ == "__main__":
    
    for _ in range(int(input())):
        n = int(input())
        solve(n)