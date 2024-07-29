class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int count =0;
        if(n<3){
            return count;
        }
        for(int i=0;i<n;i++){
            int a=rating[i];
            for(int j=i;j<n;j++){
                if(a>rating[j]){
                    for(int k=j;k<n;k++){
                        if(rating[j]>rating[k]){
                            count++;
                        }
                    }
                }
                else if(a<rating[j]){
                    for(int k=j;k<n;k++){
                        if(rating[j]<rating[k]){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};