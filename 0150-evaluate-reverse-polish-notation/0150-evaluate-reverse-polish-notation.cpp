class Solution {
public:
    int evalRPN(vector<string>& token) {
        int n=token.size();
        if(n<3){
            return stoi(token[0]);
        }
        int a;
        int b;
        int ans=0;
        stack <int> st;
        for(int i=0;i<n;i++){
            if(token[i]=="+"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                ans=a+b;
                st.push(ans);
            }
            else if(token[i]=="-"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                ans=a-b;
                st.push(ans);
            }
            else if(token[i]=="*"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                ans=a*b;
                st.push(ans);
            }
            else if(token[i]=="/"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                ans=a/b;
                st.push(ans);
            }
            else{
                st.push(stoi(token[i]));
            }
        }
        return ans;
    }
};