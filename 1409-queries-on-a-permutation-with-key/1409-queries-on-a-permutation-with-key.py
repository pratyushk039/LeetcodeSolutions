class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        arr = [i for i in range(1,m+1)]
        n = len(queries)
        ans=[0 for i in range(n)]
        for i in range(n):
            for j in range(m):
                if queries[i]==arr[j]:
                    ans[i]=j
                    arr.remove(arr[j])
                    arr = [queries[i]]+arr
        return ans
        