class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int num:nums){
            int temp=num;
            int count=0;
            int div=1;
            while(div<=num/2 && count<4){
                if(num%div==0){
                    temp+=div;
                    count++;
                }
                div++;
            }
            if(count==3){
                ans+=temp;
            }
        }
        return ans;
    }
};