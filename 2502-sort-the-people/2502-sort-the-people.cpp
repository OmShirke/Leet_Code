class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> idk;
        vector<string> ans;
        for(int i=0;i<names.size();i++){
            idk.push_back({heights[i],names[i]});
        }
        sort(idk.begin(),idk.end(),[](auto &left, auto &right) {
        return left.first > right.first;
        });
        for(auto& person:idk){
            ans.push_back(person.second);
        }
        return ans;
    }    
};