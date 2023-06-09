class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        j = 0 #for popped array
        for i in pushed:
            stack.append(i)
            while len(stack) > 0 and stack[-1] == popped[j]:
                stack.pop()
                j += 1
        return len(stack) == 0