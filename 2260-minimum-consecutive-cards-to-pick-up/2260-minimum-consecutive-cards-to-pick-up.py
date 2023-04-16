class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        ans = 1e5 + 1
        hashmap = {};
        for i, element in enumerate(cards):
            if element in hashmap:
                ans = min(ans, i-hashmap[element]+1);
            hashmap[element] = i;
        
        if ans == 1e5+1:
            return -1
        return ans