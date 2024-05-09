class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        int n=candy.size();
        int ans=1;
        sort(candy.begin(),candy.end());
        for(int i=0;i<n-1;i++){
            if(candy[i]!=candy[i+1]){
                ans++;
            }
            if(ans>n/2){
                return n/2;
                break;
            }
        }
        return ans;
    }
};