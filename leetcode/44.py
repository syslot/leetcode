import re
class Solution:
    def isMatch(self, s, p):
        patt = re.compile(p)
        if patt.match(s) is not None:
            return True
        else:
            return False

if __name__ == '__main__':
    s = Solution()
    str = "aa"
    p = r"*"
    print(s.isMatch(str, p));
