class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        int ind=s.find(part);
        while(ind!=string::npos){
            s.erase(ind,n);
            ind=s.find(part);
        }
        return s;
    }
};