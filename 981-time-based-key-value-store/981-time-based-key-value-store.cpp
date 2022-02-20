class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,map<int,string>> track;
    void set(string key, string value, int timestamp) {
        track[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it = track[key].upper_bound(timestamp);
        return it==track[key].begin()?"":prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */