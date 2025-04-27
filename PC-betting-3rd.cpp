#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Check max frequency of any day
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
        }
        int max_freq = 0;
        for (auto [day, f] : freq) {
            max_freq = max(max_freq, f);
        }
        
        if (max_freq >= 4) {
            cout << "Yes\n";
            continue;
        }
        
        // Create pairs and build connectivity graph
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({a[i] + 1, a[i] + 2});
        }
        
        // Map days to pairs for connectivity
        map<int, vector<int>> day_to_pair;
        for (int i = 0; i < n; i++) {
            day_to_pair[pairs[i].first].push_back(i);
            day_to_pair[pairs[i].second].push_back(i);
        }
        
        // DFS to check if all pairs are connected
        vector<bool> visited(n, false);
        int component_size = 0;
        function<void(int)> dfs = [&](int p) {
            if (visited[p]) return;
            visited[p] = true;
            component_size++;
            int d1 = pairs[p].first, d2 = pairs[p].second;
            for (int next_p : day_to_pair[d1]) {
                if (!visited[next_p]) dfs(next_p);
            }
            for (int next_p : day_to_pair[d2]) {
                if (!visited[next_p]) dfs(next_p);
            }
        };
        
        if (n > 0) {
            dfs(0);
        }
        
        // Yes if fully connected and n >= 3, or max_freq >= 4
        if (component_size == n && n >= 3) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}