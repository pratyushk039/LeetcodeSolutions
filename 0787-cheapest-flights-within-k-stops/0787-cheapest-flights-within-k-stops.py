class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        edgeDict = collections.defaultdict(list)
        for vertex, edge, weight in flights:
            edgeDict[vertex].append((edge, weight))

        costs = [float('inf') for _ in range(n)]
        costs[src] = 0
        
        for _ in range(k + 1):
            temp = costs.copy()
            for vertex in range(n):
                for edge, weight in edgeDict[vertex]:
                    temp[edge] = min(temp[edge], costs[vertex] + weight)
            costs = temp
        
        if temp[dst] != float('inf'):
            return temp[dst]
        else:
            return -1