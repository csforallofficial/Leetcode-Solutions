#include <set>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    
    int query(const set<int>& available, int i) {
        if(available.empty()) {return -1;}
        
        auto later = available.lower_bound(i);
        if(later != available.end()) {return *later;}
        return *available.begin();
    }
    
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        int num_processed[k];
        for(int i = 0; i < k; i++) {available.insert(i); num_processed[i] = 0;}
        
        for(int i = 0; i < arrival.size(); i++) {
            int curr_arrival = arrival[i];
            int curr_load = load[i];
            while(!pq.empty() && pq.top().first <= curr_arrival) {
                available.insert(pq.top().second);
                pq.pop();
            }
            int server_to_use = query(available, i%k); 
            if(server_to_use != -1) {
                available.erase(server_to_use);
                num_processed[server_to_use] += 1;
                pq.push(make_pair(curr_arrival + curr_load, server_to_use));
            }
        }
        int max_val = num_processed[0];
        for(int i = 1; i < k; i++) {
            if(num_processed[i] > max_val) {
                max_val = num_processed[i];
            }
        }
        vector<int> biggest_servers;
        for(int i = 0; i < k; i++) {
            if(num_processed[i] == max_val) {
                biggest_servers.push_back(i);
            }
        }
        return biggest_servers;
        
    }
};