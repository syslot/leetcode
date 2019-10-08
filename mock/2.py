class Solution:
    def combinationSum3(self, k, n):
        if n < 1:
            return None
        if k==1:
            return [[n]];

        s = set()
        for i in range(1,10):
            rst = self.combinationSum3(k-1, n-i)
            if rst is not None:
                for r in rst:
                    r.append(i)
                    r.sort()
                    s.add(tuple(r))
        return [list(x) for x in s]




s = Solution();
print(s.combinationSum3(3,7))
        
