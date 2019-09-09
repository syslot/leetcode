class Solution:
    def firstMissingPositive(self, nums):
        pos = {}
        rev = {}
        for n in set(nums):
            f1 = n + 1 in pos
            f2 = n - 1 in rev
            if f1 and not f2:
                v = pos[n + 1]
                pos[n] = v
                del pos[n + 1]
                rev[v] = n
            if not f1 and f2:
                v = rev[n - 1]
                rev[n] = v
                del rev[n - 1]
                pos[v] = n
            if not f1 and not f2:
                pos[n] = n
                rev[n] = n
            if f1 and f2:
                begin = rev[n-1]
                end = pos[n+1]
                del pos[n+1]
                del rev[n-1]
                pos[begin] = end
                rev[end] = begin
        min = 1
        for k in pos.keys():
            if pos[k] <= 0:
                continue
            if k <= min <= pos[k]:
                min = pos[k] + 1
        return min


if __name__ == '__main__':
    s = Solution()

    # nums = [1,2,0]
    # print(s.firstMissingPositive(nums))
    # nums = [3,4,-1,1]
    # print(s.firstMissingPositive(nums))
    # nums = [7,8,9,11,12]
    # print(s.firstMissingPositive(nums))
    # nums = [0,2,2,1,1]
    # print(s.firstMissingPositive(nums))
    nums = [98, 93, 95, 10, 91, 4, 90, 88, 56, 84, 65, 62, 83, 80, 78, 60, 73, 77, 76, 29, 63, 12, 57, 17, 69, 68, 50, 11, 31, 33, 8, 42, 38, 7, 0, 37, 48, 26, 20, 44, 46, 43, 52, 51, 47, 18, 49, 58, 2, 39, 30, 81, 22, 55, 36, 40, 15, 27, 21, 32, 64, 41, 53, 19, 28, 24, 9, 25, 3, 59, 66, 82, 61, 70, 23, 34, 71, 54, 74, -1, 1, 45, 14, 79, 5, 35, 13, 72, 75, 85, 87, 6, 16, 86, 67, 89, 94, 92, 96, 97]
    # nums = [2,11,2,0,3,22,-5,3,2,-6,1,4,-4,-1,0,3,-1,5,-7,2,-8,1,1,22,5,-8,1]
    print(sorted(set(nums)))
    print(s.firstMissingPositive(nums))

