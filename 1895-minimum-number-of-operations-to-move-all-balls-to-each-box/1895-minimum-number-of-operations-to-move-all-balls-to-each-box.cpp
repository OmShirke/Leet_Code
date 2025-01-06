class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> one;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                one.push_back(i);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<one.size();j++){
                ans[i]+=abs(one[j]-i);
            }    
        }
        return ans;
    }
};