class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        dp=[-1 for i in range(n)]
        dp[n-1]=True
        for i in range(n-2,-1,-1):
            if any(dp[i+1:i+nums[i]+1]):
                dp[i]=True
            else:
                dp[i]=False
        return dp[0]
            
        