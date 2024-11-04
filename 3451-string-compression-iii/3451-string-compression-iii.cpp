class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        string comp;
        int count=1;
        char ch=word[0];

        for(int i=1;i<n;i++){
            if(word[i]==word[i-1] && count<9){
                count++;
            }
            else{
                comp+=to_string(count);
                comp+=ch;
                ch=word[i];
                count=1;
            }
        }
        comp+=to_string(count);
        comp+=ch;
        return comp;
    }
};