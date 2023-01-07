class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        diff = 0
        current_sum, index = 0, 0
        for i in range(n):
            current_sum += gas[i] - cost[i]
            if current_sum < 0:
                diff+=current_sum
                current_sum = 0
                index = i+1
        if current_sum >= -diff:
            return index
        return -1