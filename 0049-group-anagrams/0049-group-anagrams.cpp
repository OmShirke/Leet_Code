class Solution {
public:
    string sortString(const string& str) {
    string sorted_str = str;
    sort(sorted_str.begin(), sorted_str.end());
    return sorted_str;
}
vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    
    for (const auto& str : strs) {
        string sorted_str = sortString(str);
        anagramGroups[sorted_str].push_back(str);
    }
    
    vector<vector<string>> result;
    for (const auto& group : anagramGroups) {
        result.push_back(group.second);
    }
    
    return result;
}
};