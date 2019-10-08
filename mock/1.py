class Solution:
    def findOcurrences(self, text, first, second):
        l = text.split(" ")
        rst = []
        if len(l) < 3:
            return rst
        for i in range(len(l)-2):
            if l[i] == first and l[i+1] == second:
                rst.append(l[i+2])
        return rst


text =  "alice is a good girl she is a good student"
first = "a"
second = "good"

s = Solution()
print(s.findOcurrences(text, first, second))
