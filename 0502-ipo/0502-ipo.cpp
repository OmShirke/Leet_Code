class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> maxcap;
        int i=0;
        while(k--){
            while(i<n && projects[i].first<=w){
                maxcap.push(projects[i].second);
                i++;
            }
            if(maxcap.empty()){
                break;
            }
            w+=maxcap.top();
            maxcap.pop();
        }
        return w;
    }
};