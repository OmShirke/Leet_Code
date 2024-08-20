class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=0;
        vector<int> arr(n,1);
        for(int i=n-1;i>0;i--){
            if(ratings[i]<ratings[i-1]){
               arr[i-1]=max(arr[i-1],arr[i]+1);
            }
        }
        for(int i=0;i<n-1;i++){
            if(ratings[i]<ratings[i+1]){
                arr[i+1]=max(arr[i+1],arr[i]+1);
            }
        }
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum;
    }
};