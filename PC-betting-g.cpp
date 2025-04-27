#include <iostream>
#include <vector>
#include <algorithm>
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

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        bool found = false;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] == a[i + 1]) {
                found = true;
                break;
            }
        }

        if (n >= 4 || found) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
