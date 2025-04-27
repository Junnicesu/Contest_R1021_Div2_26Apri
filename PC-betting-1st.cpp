#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        map<ll, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        bool can_win = false;
        int max_freq = 0;
        for (auto [day, f] : freq) {
            max_freq = max(max_freq, f);
        }
        
        int distinct = freq.size();
        
        if (max_freq >= 4) {
            can_win = true;
        } else if (distinct >= 3) {
            can_win = true;
        } else if (distinct == 2) {
            if (n >= 3) {
                can_win = true;
            }
        } else { // distinct == 1
            if (n >= 4) {
                can_win = true;
            }
        }
        
        cout << (can_win ? "Yes" : "No") << '\n';
    }
    
    return 0;
}