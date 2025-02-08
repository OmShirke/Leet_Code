class NumberContainers {
    unordered_map<int, int> indexToNumber;
    unordered_map<int, map<int, int>> numberToIndices;
public:
    NumberContainers() {}

    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        indexToNumber[index] = number;
        numberToIndices[number][index] = 1;
    }

    int find(int number) {
        if (numberToIndices.count(number)) {
            return numberToIndices[number].begin()->first;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */