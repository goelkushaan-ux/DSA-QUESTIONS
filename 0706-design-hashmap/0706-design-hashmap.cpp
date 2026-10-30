class MyHashMap {
    vector<int> temp;
    vector<bool> present;

public:
    MyHashMap() {
        temp.resize(1000001, -1);
        present.resize(1000001, false);
    }

    void put(int key, int value) {
        temp[key] = value;
        present[key] = true;
    }

    int get(int key) {
        if (present[key])
            return temp[key];
        return -1;
    }

    void remove(int key) {
        present[key]=false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */