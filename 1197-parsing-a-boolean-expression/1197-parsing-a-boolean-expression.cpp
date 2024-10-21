class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;

        for(char curr:exp){

            if(curr==',' || curr=='('){
                continue;
            }
            else if(curr=='!' || curr=='&' || curr=='t' || curr=='f' || curr=='|'){
                st.push(curr);
            }
            else if(curr==')'){
                bool tst=false;
                bool fst=false;
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char value = st.top();
                    st.pop();
                    if (value == 't') tst = true;
                    if (value == 'f') fst = true;
                }
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(tst ? 'f' : 't');
                } else if (op == '&') {
                    st.push(fst ? 'f' : 't');
                } else {
                    st.push(tst ? 't' : 'f');
                }    
            }
        }
        return st.top()=='t';
    }
};