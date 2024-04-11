class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
       for (const auto& ex:s){
        if(ex=='{' || ex=='[' || ex=='('){
            st.push(ex);
        }
        else if(st.empty()){
            return false;
        }
        else
        {
            const auto& last= st.top();
            if(ex=='}' && last!='{'){
                return false;
            }if(ex==']' && last!='['){
                return false;
            }if(ex==')' && last!='('){
                return false;
            }
            st.pop();
        }
       }
       return st.empty();
    };
        
};