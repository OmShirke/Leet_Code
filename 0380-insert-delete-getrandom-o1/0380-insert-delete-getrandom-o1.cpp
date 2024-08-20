class RandomizedSet {
    vector<int> arr;
    unordered_map<int,int> mp;
public:
    RandomizedSet() {
        
    }
    bool search(int val){
        if(mp.find(val)!=mp.end())
           return true;
        return false;
    }
    bool insert(int val) {
        if(search(val)){
           return false;
        }
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val)){
           return false;
        }
        auto it = mp.find(val);
        arr[it->second] = arr.back();
        arr.pop_back();
        mp[arr[it->second]] = it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */