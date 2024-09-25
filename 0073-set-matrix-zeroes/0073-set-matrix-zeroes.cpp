class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m=matrix[0].size();
        stack<int> sti;
        stack<int> stj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<m;k++){
                        stj.push(k);
                        sti.push(i);
                    }
                    for(int k=0;k<n;k++){
                        sti.push(k);
                        stj.push(j);
                    }    
                }
            }
        }
        while(!sti.empty()){
            matrix[sti.top()][stj.top()]=0;
            sti.pop();
            stj.pop();
        }
    }
};