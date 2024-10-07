class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            char ch=s[i];

            if(st.empty()){
                st.push(ch);
                continue;
            }

            if(ch=='B' && st.top()=='A'){
                st.pop();
            }
            else if(ch=='D' && st.top()=='C'){
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        return st.size();
    }
};