class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int lt=i+1;
            int rt=n-1;

            while(lt<rt){
                int currsum=nums[i]+nums[lt]+nums[rt];
                if(abs(target-currsum) < abs(target-sum)){
                    sum=currsum;
                }
                if (currsum<target){
                    lt++;
                }
                else if(currsum>target){
                    rt--;
                }
                else{
                    return currsum;
                }
            }
        }
        return sum;
    }
};