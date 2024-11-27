#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1); 
        }

        vector<int> answer;
        auto dijkstra = [&](int src, int target) -> int {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;

                for (int v : graph[u]) {
                    if (dist[u] + 1 < dist[v]) {
                        dist[v] = dist[u] + 1;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist[target];
        };

        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].push_back(v); 
            answer.push_back(dijkstra(0, n - 1)); 
        }

        return answer;
    }
};

