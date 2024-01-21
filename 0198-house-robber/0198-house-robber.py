class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return nums[0]
        max_i=[0 for i in range(n)]
        max_i[0],max_i[1]=nums[0],max(nums[0],nums[1])
        for i in range(2,n):
            max_i[i]=max(nums[i]+max_i[i-2],max_i[i-1])
        return max_i[n-1]