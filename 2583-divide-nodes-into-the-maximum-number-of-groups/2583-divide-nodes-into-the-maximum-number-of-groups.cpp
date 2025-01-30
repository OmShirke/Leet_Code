class Solution 
{
public:
    bool bipartite(int src, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it] = 1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;  
    }
    
    bool checkBipartite(int &n, vector<int> adj[])
    {
        int color[n+1];
        memset(color, -1, sizeof color);
        for(int i=1; i<=n; i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite(i, adj, color)) return false;
            }
        }
        return true;
    }
    
    int findFarthestDistBFS(int src, int n, vector<int> adj[])
    {
        vector<int> vis(n+1, 0);
        int cnt=0;
        queue<int> q;
        q.push(src);
        vis[src]=1;
                    
        while(!q.empty())
        {
            int sz=q.size();
            cnt++;
            
            for(int i=0; i<sz; i++)
            {
                int node = q.front();
                q.pop();

                for(auto it:adj[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
           
        }
        return cnt;
    }
    
    int dfsForComponents(int node, vector<int> adj[], vector<int> &vist, vector<int> &dist)
    {
        vist[node]=1;
        int maxi=dist[node];
        for(auto it:adj[node])
        {
            if(!vist[it])
            {
                maxi = max(maxi, dfsForComponents(it, adj, vist, dist));
            }
        }
        return maxi;
    }
    
    int magnificentSets(int n, vector<vector<int>>& edges) 
    {
        vector<int> adj[n+1];
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        if(!checkBipartite(n, adj)) return -1;
        
        vector<int> dist(n+1, 0);
        for(int i=1; i<=n; i++)
        {
            dist[i] = findFarthestDistBFS(i, n, adj);
        }
        
        vector<int> vist(n+1, 0);
        int maxi=0;
        for(int i=1; i<=n; i++)
        {
            if(vist[i]==0)
            {
                maxi += dfsForComponents(i, adj, vist, dist);
            }
        }
        return maxi;
        
    }
};