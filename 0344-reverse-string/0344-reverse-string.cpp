class Solution {
public:
    void recursion(vector<char>& s, int left, int right){
        if(left>=right){
            return;
        }
        swap(s[left],s[right]);
        left++;
        right--;
        recursion(s,left,right);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        int right=n-1;
        int left=0;
        recursion(s,left,right);
    }
};