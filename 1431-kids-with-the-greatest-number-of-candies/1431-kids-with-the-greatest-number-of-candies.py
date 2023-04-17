class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        mx = max(candies) #max value in the list
        ans = list(range(len(candies)))
        for i, n in enumerate(candies):
            if mx <= (candies[i]+extraCandies):
                ans[i] = True
            else:
                ans[i] = False
        return ans