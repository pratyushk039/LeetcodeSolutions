class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        n=len(nums)
        arr=[]
        for i in range(n):
            if i<n-1:
                arr.append(nums[i+1]-nums[i])
        for i in arr:
            if i!=0:
                sign=i//abs(i)
                break
        else:
            return True
        print(arr)
        for k in arr:
            if k!=0:
                if k//abs(k)!=sign:
                    return False
        else:
            return True