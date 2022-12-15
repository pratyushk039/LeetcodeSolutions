class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        li = [i for i in sentence.strip().split()]
        n=len(li)
        d = 1-discount/100
        def isp():
            arr = [str(x) for x in range(0,10)]
            for i in range(n):
                word = li[i]
                if(word[0]=="$" and len(word)>1):
                    for ch in word[1:]:
                        if ch not in arr:
                            break
                    else:
                        x = float(word[1:])
                        x = d*x
                        li[i] = "$"+format(x, '.2f')
            return
        isp()
        s=""
        for k in li:
            s+=k+" "
        return s.strip()
                        
        
        