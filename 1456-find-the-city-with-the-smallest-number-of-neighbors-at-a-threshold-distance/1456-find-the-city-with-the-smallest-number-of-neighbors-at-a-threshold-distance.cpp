class Solution {
public:
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // Step 1: Initialize the distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    // Step 2: Populate the distance matrix with the given edges
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }
    
    // Step 3: Apply the Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Step 4: Count the number of reachable cities within the distance threshold
    int min_reachable = INT_MAX;
    int result_city = -1;
    
    for (int i = 0; i < n; ++i) {
        int reachable_count = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= distanceThreshold) {
                ++reachable_count;
            }
        }
        
        // Step 5: Determine the city with the smallest number of reachable cities
        if (reachable_count < min_reachable || (reachable_count == min_reachable && i > result_city)) {
            min_reachable = reachable_count;
            result_city = i;
        }
    }
    
    return result_city;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;
    cout << findTheCity(n, edges, distanceThreshold) << endl;  // Output: 3
    return 0;
}
};