class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;
        int m=matrix[0].size();
        int n=matrix.size();
        int i=0;
        int j=m-1;
        while(i<n){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                int left=0;
                int right=m-1;

                while(left<=right){
                    int mid=left+(right-left)/2;

                    if(matrix[i][mid]==target){
                        return true;
                    }
                    else if(matrix[i][mid]>target){
                        right=mid-1;
                    }
                    else{
                        left=mid+1;
                    }
                }
                break;
            }
            else{
                i++;
            }
        }
        return false;
    }
};