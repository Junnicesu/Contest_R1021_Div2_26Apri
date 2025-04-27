#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        // Number of bars to keep after closing up to k bars
        int m = n - k;
        
        // Index for the smallest median (0-based)
        int l = (m + 1) / 2 - 1;
        
        // Index for the largest median (0-based)
        int r = n - (m + 1) / 2;
        
        // Smallest possible median value
        ll left = a[l];
        
        // Largest possible median value
        ll right = a[r];
        
        // Number of possible x values (inclusive range)
        ll ans = right - left + 1;
        
        cout << ans << '\n';
    }
    
    return 0;
}