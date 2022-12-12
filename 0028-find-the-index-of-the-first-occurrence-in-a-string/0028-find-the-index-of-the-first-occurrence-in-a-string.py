class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        big=len(haystack)
        small=len(needle)
        if small>big:
            return -1
        for i in range(0,big+1-small):
            if needle[0]==haystack[i]:
                if needle==haystack[i:i+small]:
                    return i
        return -1