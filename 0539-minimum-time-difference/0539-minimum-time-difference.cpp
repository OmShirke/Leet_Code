class Solution {
public:
    int findMinDifference(vector<string>& time) {
        int n = time.size();
        vector<int> arr;
        int ans = INT_MAX;

        for (const string& times : time) {
            istringstream ss(times);
            string hours, minutes;

            getline(ss, hours, ':');
            getline(ss, minutes);

            int h = stoi(hours);
            int m = stoi(minutes);
            int total = (h * 60) + m;
            arr.push_back(total);
        }

        sort(arr.begin(), arr.end());

        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                return 0;
            }
            ans=min(ans,arr[i]-arr[i-1]);
        }
        ans=min(ans,1440-(arr.back()-arr.front()));
        return ans;
    }
};