
vector<int> sieve(1001, 1);
vector<int>prime;
bool is_done = false;

void calc() {
    if (is_done)
        return;

    is_done = true;
    sieve[0] = 0, sieve[1] = 0;
    for (int i = 2; i < 1001; i++) {
        if (sieve[i]) {
            for (int j = i * 2; j < 1001; j += i) {
                sieve[j] = 0;
            }
        }
    }
    for(int i=0;i<1001;i++){
        if(sieve[i])prime.push_back(i);
    }
}
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        calc();
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] >= nums[i+1]){
                int rem = nums[i]-nums[i+1];

                auto it = upper_bound(prime.begin(),prime.end(),rem);
                if(it == prime.end()) return false;
                nums[i] -= *it;
                if(nums[i]<=0) return false;
            }
        }
        return true;
    }
};
