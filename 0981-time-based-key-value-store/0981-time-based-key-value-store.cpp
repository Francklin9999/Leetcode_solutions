class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto it = map.find(key);
        if(it != map.end()) {
            it->second.emplace_back(timestamp, value);
        } else {
            map[key] = {pair(timestamp, value)};
        }
    }
    
    string get(string key, int timestamp) {
        auto it = map.find(key);
        if(it == map.end()) return "";
    
        auto value = std::upper_bound(it->second.begin(), it->second.end(), timestamp, [](int timestamp, const pair<int, string>& value) {
            return timestamp < value.first;
        });

        if (value == it->second.begin()) return "";

        --value;
        return value->second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */