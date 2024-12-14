class Solution {
public:
    int ans = 0;
    vector<vector<pair<int, int>>> graph;
    int maxTime;
    vector<int> values;

    void dfs(int curr, int time, int currentValue, vector<int>& visited) {
        if (time > maxTime) return;
        if (curr == 0) {ans = max(ans, currentValue);}
        for (auto& neighbor : graph[curr]) {
            int nextNode = neighbor.first;
            int travelTime = neighbor.second;

            bool isFirstVisit = (visited[nextNode] == 0);
            if (isFirstVisit) {
                currentValue += values[nextNode];
            }

            visited[nextNode]++;
            dfs(nextNode, time + travelTime, currentValue, visited);
            visited[nextNode]--;

            if (isFirstVisit) {
                currentValue -= values[nextNode];
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        this->maxTime = maxTime;
        this->values = values;

        int n = values.size();
        graph.resize(n);

        for (auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> visited(n, 0);
        visited[0] = 1;
        dfs(0, 0, values[0], visited);

        return ans;
    }
};
