class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        def fact(k):
            arr=[1 for i in range(k+1)]
            for i in range(1,k+1):
                arr[i]=arr[i-1]*i
            return arr
        li=fact(m+n-2)
        return (li[m+n-2])//(li[m-1]*li[n-1])
        