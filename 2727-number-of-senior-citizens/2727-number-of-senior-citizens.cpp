class Solution {
public:
    int countSeniors(vector<string>& det) {
        int ans=0;
        for(const auto& str:det){
            string part=str.substr(11,2);
            int num=stoi(part);
            if(num>60){
                ans++;
            }
        }
        return ans;
    }
};