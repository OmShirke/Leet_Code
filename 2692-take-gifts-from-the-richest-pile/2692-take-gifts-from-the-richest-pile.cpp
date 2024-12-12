class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> heap(gifts.begin(),gifts.end());
        int temp=0;
        long long ans=0;
        for(int i=0;i<k;i++){
            temp=heap.top();
            temp=sqrt(temp);
            heap.pop();
            heap.push(temp);
        }

        while(!heap.empty()){
            ans+=heap.top();
            heap.pop();
        }

        return ans;
    }
};