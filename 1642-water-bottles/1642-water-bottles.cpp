class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int emptyBottles = numBottles;
        while (emptyBottles >= numExchange) {
            int newb = emptyBottles / numExchange;
            total += newb;
            emptyBottles = emptyBottles % numExchange + newb;
        }
        return total;
    }
};
