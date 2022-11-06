


class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mp = dict.fromkeys(nums,0)
        pref = [nums[0] for i in range(n)]
        for i in range(1,n):
            pref[i]=pref[i-1]+nums[i]
        
        ans=0
        kfreq=1
        for i in range(k):
            mp[nums[i]]+=1

        for key in mp:
            if(mp[key]==0):
                continue
            kfreq*=mp[key]
            #print(mp[key])
        if(kfreq==1):
            ans = pref[k-1]-pref[0]+nums[0]
        for i in range(1,n+1-k):
            if(mp[nums[i-1]]==1 or mp[nums[i-1]]==2):
                kfreq=kfreq//mp[nums[i-1]]
                mp[nums[i-1]]-=1
                mp[nums[i+k-1]]+=1
                kfreq=kfreq*mp[nums[i+k-1]]
                if(kfreq==1):
                    ans=max(ans,pref[i+k-1]-pref[i]+nums[i])
            else:
                kfreq = kfreq//mp[nums[i-1]]
                mp[nums[i-1]]-=1
                mp[nums[i+k-1]]+=1
                kfreq=kfreq*mp[nums[i-1]]*mp[nums[i+k-1]]
                #print(kfreq)
        return ans
        