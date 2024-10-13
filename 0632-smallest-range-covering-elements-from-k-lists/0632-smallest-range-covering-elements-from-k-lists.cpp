class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        bool indicator=true;
        int n=nums.size();

        int mini=INT_MAX;
        int mintemp=INT_MAX;
        int index=0;

        int maxi=INT_MIN;

        int start=0;
        int end=INT_MAX;

        while(indicator){

            mini=INT_MAX;
            maxi=INT_MIN;
        
            for(int i=0;i<n;i++){
                mini=min(mini,nums[i][0]);
                if(mintemp!=mini){
                    index=i;
                    mintemp=mini;
                }

                maxi=max(maxi,nums[i][0]);
            }

            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            nums[index].erase(nums[index].begin()+0);
            if(nums[index].size()==0){
                indicator=false;
            }
        }
        return {start,end};
    }
};