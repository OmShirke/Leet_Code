class Solution {
public:
    int findComplement(int num) {
        vector<int> arr;
        while (num > 0) {
            arr.push_back(num % 2);
            num /= 2;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = arr[i] == 0 ? 1 : 0;
        }
        long long sum = 0;
        long long unit = 1;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i] * unit;
            unit *= 2;
        }

        return sum;
    }
};