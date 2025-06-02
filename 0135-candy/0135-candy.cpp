class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> count(n,1);
        for(int i=0;i<n-1;i++){
            if(ratings[i+1]>ratings[i]){
                count[i+1]=max(count[i+1],count[i]+1);
            }
        }
        int ans=count[n-1];
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                count[i-1]=max(count[i-1],count[i]+1);
            }
            ans+=count[i-1];
        }
        return ans;
    }
};