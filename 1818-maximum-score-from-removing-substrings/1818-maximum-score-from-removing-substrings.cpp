class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        string fp="ab";
        string sp="ba";
        int fv=x; 
        int sv=y;
        
        if(y>x){
            swap(fv,sv);
            swap(fp,sp);
        }
         
        for(char c:s){
            if(!st.empty() && st.top()==fp[0] && c==fp[1]){
                st.pop();
                ans+=fv;
            }
            else{
                st.push(c);
            }
        } 
        
        string rem;
        while(!st.empty()){
            rem+=st.top();
            st.pop();
        }
        reverse(rem.begin(),rem.end());
        for(char c:rem){
            if(!st.empty() && st.top()==sp[0] && c==sp[1]){
                st.pop();
                ans+=sv;
            }
            else{
                st.push(c);
            }
        }
        return ans;
    }
};