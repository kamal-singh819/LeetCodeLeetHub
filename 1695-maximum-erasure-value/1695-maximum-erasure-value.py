class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        st = set()
        ans = -1
        sm = 0 # holds sum of unique numberes subarray
        i = 0
        j = 0
        while j < n:
            if nums[j] not in st:
                sm += nums[j]
                st.add(nums[j])
            else:
                ans = max(ans, sm)
                while nums[j] in st:
                    sm -= nums[i]
                    st.discard(nums[i])
                    i += 1
                sm += nums[j]
                st.add(nums[j])
            j += 1
        return max(ans, sm)