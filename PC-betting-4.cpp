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
        
        // Compute frequency of each bet day
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
        }
        
        // Find maximum frequency
        int max_freq = 0;
        for (auto [day, f] : freq) {
            max_freq = max(max_freq, f);
        }
        
        // Vadim can guarantee a win only if he can cover all 4 scenarios for some pair
        if (max_freq >= 4) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}