class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        double ans=0;
        double calc=0;
        int n=cus.size();
        double total=0;
        for(int i=0;i<n;i++){
            if(total<cus[i][0]){
                total=cus[i][0];
            }
            total+=cus[i][1];
            calc=total-cus[i][0];
            ans+=calc;
        }
        return ans/n;
    }
};