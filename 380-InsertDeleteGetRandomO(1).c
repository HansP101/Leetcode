class RandomizedSet {
public:
    unordered_map<int, int> arrLocMap;// K: intval V: location in array
    vector<int> array;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(arrLocMap.find(val)==arrLocMap.end()){
            array.push_back(val);
            arrLocMap[val]=array.size()-1;
            return true;
        }else
            return false;
    }
    
    bool remove(int val) {
        auto it=arrLocMap.find(val);
        if(it!=arrLocMap.end()){
            swap(array[it->second], array[array.size()-1]);
            arrLocMap[array[it->second]]=it->second;
            arrLocMap.erase(val);
            array.pop_back();
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        return array[rand()%array.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
