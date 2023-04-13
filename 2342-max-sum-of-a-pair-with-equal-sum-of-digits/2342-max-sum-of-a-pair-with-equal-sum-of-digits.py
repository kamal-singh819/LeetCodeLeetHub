class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        mp = defaultdict(list)
        
        for n in nums:
            summ = 0
            num = n
            while num > 0:
                summ += num%10
                num //= 10
            mp[summ].append(n)
        ans = -1
        for v in mp.values():
            if len(v) > 1:
                v = sorted(v, reverse = True)
                ans = max(ans, v[0]+v[1])
        return ans