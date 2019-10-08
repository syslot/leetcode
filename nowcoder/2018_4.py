T = int(input())


def check(arr, n, m):
    for i in range(1, n):
        if a[i] - a[i - 1] > 1:
            a[i] -= 1
        m += 1
    elif a[i] == a[i - 1] + 1:
        continue
    elif 0 <= a[i - 1] - a[i] < m:
        res = a[i - 1] - a[i]
        a[i] += (res + 1)
        m -= (res + 1)
    else:
        return 0


    return 1

def check(arr, n, m):
    for i in range(1,n):
        if arr[i] - arr[i-1] > 1:
            arr[i] -=1
            m+=1
        elif arr[i] == arr[i-1]+1:
            continue
        elif 0 <= arr[i-1] - arr[i] < m:
            res = arr[i-1] - arr[i]
            arr[i] += (res +1)
            m -= (res +1)
        else:
            return 0


for _ in range(T):
    tmp = input().split()
    n, m = int(tmp[0]), int(tmp[1])
    tmp = input.split()
    arr = [int(x) for x in tmp]

    arr[0] -= 1
    m += 1
    if check(arr, n, m) == 0:
        print('NO')
    else:
        print('YES')

