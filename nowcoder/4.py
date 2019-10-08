# import sys
#
# d = {}
# for i in range(10):
#     d[i] = chr(ord('0') + i)
# for i in range(26):
#     d[i+10] = chr(ord('A') + i)
#
# def KtoTen(s, k):
#     if k == 10:
#         return int(s)
#
#     sum = 0
#     for i in s:
#         if '0' <= i <= '9':
#             sum = sum *k + ord(i) - ord('0')
#         else:
#             sum = sum*k + ord(i) - ord('A')
#     return sum
#
# def TentoK(i, k):
#     if(k == 10):
#         return str(i)
#     s = ""
#     while i!=0:
#         s += d[i%k]
#         i = i // k
#     return s[::-1]
#
# s = input()
#
# while s!= "":
#     num = int(s)
#     for i in range(num):
#         k = int(input())
#         ns = input().split()
#         n1 = ns[0]
#         n2 = ns[1]
#         ch = ns[2]
#         n_k1 = KtoTen(n1, k)
#         n_k2 = KtoTen(n2, k)
#         rst = 0
#         if ch == '+':
#            rst = n_k1 + n_k2
#         elif ch == '-':
#             rst = n_k1 - n_k2
#         elif ch == '*':
#             rst = n_k1 * n_k2
#
#         print(TentoK(rst, k))

## Q1

# import sys
#
# tmp = input().split()
# n,m = int(tmp[0]), int(tmp[1])
#
# tmp = input().split()
# p = [int(x) for x in  tmp if int(x) > 0]
# n = [int(x) for x in tmp if  int(x) < 0]
# pos = len(p)
# neg = len(n)
# zero = len(tmp) - pos - neg
# sorted(p)
# sorted(n, reverse=True)
#
# sum = 0
#
# for i in range(m,0,-1):
#     if neg != 0 and pos != 0:
#         sum += n[neg-1] * p[pos-1]
#         neg -= 1
#         pos -= 1
#     elif neg != 0 and pos == 0:
#         if zero != 0:
#             # sum += 0;
#             neg -= 1;
#             zero -= 1;
#         else:
#             sum += n[0] * n[2*i-1]
#             neg -=2
#             n = n[1:-1]
#     elif pos != 0 and neg == 0:
#         if zero != 0:
#             pos -= 1;
#             zero -=1;
#         else:
#             sum += p[0] * p[2*i-1]
#             pos -=2
#             p = p[1:-1]
#     else:
#         break
#
# print(sum)


## Q2
tmp = input().split()
n,m = int(tmp[0]), int(tmp[1])

sum = 0
line = set({})
for i in range(m):
    tmp = input().split()
    now = (int(tmp[0]), int(tmp[1]))
    l_in = r_in = None
    cov = []
    for s in line:
        if s[0] == now[0] and s[1] == now[1]:
            continue
        if s[0]<=now[0] <= s[1]:
            l_in = s
        if s[0] <= now[1] <= s[1]:
            r_in = s
        if now[0] <=s[0] and s[1] <= now[1]:
            cov.append(s)
    cov_sum = 0
    for c in cov:
        cov_sum += c[1] - c[0] + 1
        line.remove(c)


    if l_in is None and r_in is None:
        sum += (now[1] - now[0] + 1)
        line.add(now)

    # if l_in  == r_in:
    #     pass

    if l_in is not None and r_in is None:
        sum += now[1] - l_in[1]
        line.remove(l_in)
        line.add((l_in[0], now[1]))

    if l_in is None and r_in is not None:
        sum += r_in[0] - now[0]
        line.remove(r_in)
        line.add((now[0], r_in[1]))

    sum -= cov_sum
    print(sum)



