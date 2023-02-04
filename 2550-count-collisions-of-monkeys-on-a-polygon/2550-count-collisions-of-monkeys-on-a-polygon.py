class Solution:
    def monkeyMove(self, n: int) -> int:
        return (pow(2,n,10**9+7)-2)%(10**9+7) 
        