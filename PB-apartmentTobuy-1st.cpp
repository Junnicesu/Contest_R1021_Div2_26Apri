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
        
        // l is the index (1-based) of the median in the remaining n - k bars
        int l = (n - k + 1) / 2; // ceil((n - k) / 2)
        
        // Smallest median: l-th element of first n - k elements (a[0] to a[n - k - 1])
        ll min_median = a[l - 1];
        
        // Largest median: l-th element of last n - k elements (a[k] to a[n - 1])
        ll max_median;
        if ((n - k) % 2 == 0) {
            // If n - k is even, median is between l-th and (l+1)-th elements
            // Use l-th element of the largest n - k elements
            max_median = a[k + l - 1];
        } else {
            // If n - k is odd, median is the l-th element
            max_median = a[k + l - 1];
        }
        
        // Number of possible x is the range from min_median to max_median, inclusive
        ll ans = max_median - min_median + 1;
        cout << ans << '\n';
    }
    
    return 0;
}
