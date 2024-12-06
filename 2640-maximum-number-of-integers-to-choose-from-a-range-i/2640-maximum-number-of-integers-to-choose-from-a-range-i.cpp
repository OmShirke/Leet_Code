class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mp;
        for(int a:banned){
            mp[a]++;
        }
        int sum=0;
        int i=1;
        int count=0;
        while(i<=n && sum<=maxSum){
            if(mp.find(i)==mp.end()){
                sum+=i;
                count++;
            }
            if(sum>maxSum){
                sum-=i;

                count--;
                break;
            }
            i++;
        }
        return count;
    }
};