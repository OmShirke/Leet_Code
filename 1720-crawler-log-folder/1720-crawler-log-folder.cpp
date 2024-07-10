class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        int num=0;
        for(int i=0;i<n;i++){
            if(logs[i]!="../" && logs[i]!="./"){
               num++;
            }
            if(logs[i]=="../" && num>0){
                num--;
            }
        }
        return num;
    }
};