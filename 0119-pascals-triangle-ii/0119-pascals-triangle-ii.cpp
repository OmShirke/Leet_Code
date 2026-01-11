class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums(1,1);
        if(rowIndex==0){
            return nums;
        }
        nums.push_back(1);
        if(rowIndex==1){
            return nums;
        }
        nums[1]=2;
        nums.push_back(1);
        if(rowIndex==2){
            return nums;
        }
        int index=3;
        while(index<=rowIndex){
            int n=nums.size();
            nums.push_back(1);
            int a=1;
            for(int i=0;i<n;i++){
                int temp=nums[i]+nums[i+1];
                nums[i]=a;
                a=temp;
            }
            
            index++;
        }
        
        return nums;
    }
};