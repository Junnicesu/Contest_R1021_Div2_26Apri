#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<pii> odd_cells(k + 1);
        for (int i = 0; i <= k; i++) {
            int x, y;
            cin >> x >> y;
            odd_cells[i] = {x - 1, y - 1}; // Convert to 0-based indexing
        }
        
        // Directions for adjacent cells
        vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Check if a cell is within bounds
        auto in_bounds = [&](int x, int y) {
            return 0 <= x && x < n && 0 <= y && y < m;
        };
        
        // Find candidate p_{2i} for each segment
        vector<vector<pii>> candidates(k);
        for (int i = 0; i < k; i++) {
            int x1 = odd_cells[i].first, y1 = odd_cells[i].second;
            int x2 = odd_cells[i + 1].first, y2 = odd_cells[i + 1].second;
            set<pii> possible;
            for (auto [dx, dy] : dirs) {
                int nx = x1 + dx, ny = y1 + dy;
                if (in_bounds(nx, ny)) {
                    // Check if (nx, ny) is adjacent to (x2, y2)
                    int dx2 = abs(nx - x2), dy2 = abs(ny - y2);
                    if ((dx2 == 1 && dy2 == 0) || (dx2 == 0 && dy2 == 1)) {
                        possible.insert({nx, ny});
                    }
                }
            }
            candidates[i].assign(possible.begin(), possible.end());
        }
        
        // Initialize used cells with odd-indexed cells
        set<pii> used(odd_cells.begin(), odd_cells.end());
        
        // Backtracking to count valid paths
        ll ans = 0;
        function<void(int, set<pii>&)> backtrack = [&](int idx, set<pii>& current_used) {
            if (idx == k) {
                ans = (ans + 1) % MOD;
                return;
            }
            for (auto cell : candidates[idx]) {
                if (current_used.count(cell) == 0) {
                    current_used.insert(cell);
                    backtrack(idx + 1, current_used);
                    current_used.erase(cell);
                }
            }
        };
        
        set<pii> current_used = used;
        backtrack(0, current_used);
        
        cout << ans << '\n';
    }
    
    return 0;
}