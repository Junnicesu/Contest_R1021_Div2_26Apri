#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        // Count frequency of each digit
        vector<int> freq(10, 0);
        for (char c : s) {
            freq[c - '0']++;
        }
        
        // Construct the smallest beautiful number
        string result = "";
        for (int i = 1; i <= 10; i++) {
            // Minimum digit required for position i is max(0, 10-i)
            int min_digit = max(0, 10 - i);
            // Find the smallest available digit >= min_digit
            for (int d = min_digit; d <= 9; d++) {
                if (freq[d] > 0) {
                    result += char('0' + d);
                    freq[d]--;
                    break;
                }
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}