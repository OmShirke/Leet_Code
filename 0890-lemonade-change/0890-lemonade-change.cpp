class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10 && five!=0){
               five--;
               ten++;
            }
            else if(bills[i]==20 && five!=0 && ten!=0){
                ten--;
                five--;
            }
            else if(bills[i]==20 && five>2 && ten==0){
                five-=3;
            }
            else{
                return false;
            }
        }
        return true;
    }
};