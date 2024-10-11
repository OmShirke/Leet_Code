class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tar) {
        vector<int> target = times[tar];
        
        sort(times.begin(), times.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        set<pair<int, int>> leavingTimes;

        for (int i = 0; i < times.size(); ++i) {
            availableChairs.push(i);
        }

        for (int i = 0; i < times.size(); ++i) {
            int arrive = times[i][0];
            int leave = times[i][1];
            
            while (!leavingTimes.empty() && leavingTimes.begin()->first <= arrive) {
                availableChairs.push(leavingTimes.begin()->second);
                leavingTimes.erase(leavingTimes.begin());
            }

            int chair = availableChairs.top();
            availableChairs.pop();
            
            if (times[i] == target) {
                return chair;
            }

            leavingTimes.insert({leave, chair});
        }
        
        return -1;
    }
};
