class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0;
        long long ans=0;
        int smallest=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0){
                    neg++;
                }
                smallest=min(smallest,abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
            }
        }
        if(neg%2!=0){
            ans-=(smallest*2);
        }
        return ans;
    }
};