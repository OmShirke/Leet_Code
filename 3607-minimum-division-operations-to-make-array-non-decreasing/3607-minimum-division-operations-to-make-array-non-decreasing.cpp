class Solution {
private:
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = n-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                
                for(int j = 2; j*j <= nums[i]; j++){
                    if(nums[i]%j == 0){
                        nums[i] = j;
                        ans++;
                        break;
                    }
                }

                if(nums[i]>nums[i+1]) return -1;
            }
        }

        return ans;
    }
};

