class UnionFind:
    def __init__(self,n):
        self.rank=[1 for i in range(n)]
        self.parent=[i for i in range(n)]
    def find(self,x):
        if self.parent[x]==x:
            return x
        self.parent[x]=self.find(self.parent[x])#path compression
        return self.parent[x]
    def union(self,x,y):
        px,py=self.find(x),self.find(y)
        if px==py:
            return
        if self.rank[px]>self.rank[py]:    #union by rank
            self.parent[py]=px
        if self.rank[py]>self.rank[px]:
            self.parent[px]=py
        else:
            self.parent[py]=px
            self.rank[px]+=1
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections)<n-1:
            return -1
        d_set=UnionFind(n)
        parent=[i for i in range(n)]
        for j in connections:
            d_set.union(j[0],j[1])
        for k in range(n):
            parent[k]=d_set.find(k)
        comps=set(parent)
        return len(comps)-1
            