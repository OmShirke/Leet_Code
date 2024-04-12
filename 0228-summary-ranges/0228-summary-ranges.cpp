class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> rang;
        int n=nums.size();       
        if(n==0)
           return rang;
        int start=nums[0];
        for(int i=0;i<n;i++){
            if(i==n-1 || nums[i]+1 != nums[i+1]){
                if(nums[i]!=start){
                   rang.push_back(to_string(start)+"->"+ to_string(nums[i]));
                }
                else
                   rang.push_back(to_string(start));
                
                if(i != n-1)
                   start=nums[i+1];
                   
            }
        }
        return rang;
    }
};