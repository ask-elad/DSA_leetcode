class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<vector<pair<int, int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        table.resize(SIZE);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;  // update existing key
                return;
            }
        }
        table[idx].push_back({key, value});  // insert new key
    }
    
    int get(int key) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto &bucket = table[idx];
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i].first == key) {
                bucket.erase(bucket.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */