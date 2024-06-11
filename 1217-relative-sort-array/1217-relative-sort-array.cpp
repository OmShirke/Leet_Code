class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int n=arr1.size();
        int m=arr2.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr2[i]==arr1[j]){
                    ans.push_back(arr1[j]);
                    arr1[j]=INT_MAX;
                }  
            }
        }
        sort(arr1.begin(),arr1.end());
        for(int k=0;k<n;k++){
            if(arr1[k]!=INT_MAX){
                ans.push_back(arr1[k]);
            }
        }
        return ans;
    }
};