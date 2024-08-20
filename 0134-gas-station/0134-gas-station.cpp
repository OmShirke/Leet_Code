class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int current = 0;
        int total=0;
        int start=0;
        for (int i = 0; i < n; i++) {
            int calc=gas[i]-cost[i];
            total+=calc;
            current+=calc;
            if(current<0){
                start=i+1;
                current=0;
            }
        }
        return total>=0 ? start: -1;
    }
};