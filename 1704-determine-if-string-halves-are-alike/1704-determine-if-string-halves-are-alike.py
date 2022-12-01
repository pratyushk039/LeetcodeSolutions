class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)
        f,sc=0,0
        arr=['A','E','I','O','U','a','e','i','o','u']
        for i in range(n//2):
            if s[i] in arr:
                f+=1
        for i in range(n//2,n):
            if s[i] in arr:
                sc+=1
        return sc==f