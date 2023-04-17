class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        start = min(a,b,c)
        end = max(a,b,c)
        mid = (a+b+c) - (start + end)
        
        ans = 0
        while mid > 0 and end > 0:
            end -= 1
            mid -= 1
            total = start+mid+end
            start = min(start, mid, end)
            end = max(start, mid, end)
            mid = total - (start + end)
            ans += 1
        return ans