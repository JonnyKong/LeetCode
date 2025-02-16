class TimeMap {
    /*
    For each key, create a vector<pair<int, str>>

    On set, push back to the vector (no need to re-sort, as timestamps guaranteed
    to increase)

    On get, do binary search, look for the largest timestamp_prev that is <= timestamp

    */
    unordered_map<string, vector<pair<int, string>>> store;

    static bool comparePair(const std::pair<int, string> &p1,
                    const std::pair<int, string> &p2) {
        return p1.first < p2.first;
    }

public:

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        if (store.count(key) == 0) {
            store[key] = vector<pair<int, string>>();
        }
        store[key].push_back(std::make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (store.count(key) == 0) {
            return "";
        }        
        auto &vec = store[key];

        // Points to the first element > timestamp
        auto it = std::upper_bound(vec.begin(), vec.end(),
                                   std::make_pair(timestamp, "foo"),
                                   comparePair);
        
        // Now move back by one, to find the last element <= timestamp
        if (it == vec.begin()) {
            // Can't move back, means there's no values
            return "";
        } else {
            return std::prev(it)->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
