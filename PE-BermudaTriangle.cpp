#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const double EPS = 1e-9;
const int MAX_REFLECTIONS = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, x, y, vx, vy;
        cin >> n >> x >> y >> vx >> vy;
        
        double px = x, py = y;
        double dvx = vx, dvy = vy;
        int reflections = 0;
        bool escaped = false;
        int ans = -1;
        
        while (reflections < MAX_REFLECTIONS) {
            double t_x = dvx < -EPS ? -px / dvx : 1e18;
            double t_y = dvy < -EPS ? -py / dvy : 1e18;
            double t_h = (dvx + dvy > EPS) ? (n - px - py) / (dvx + dvy) : 1e18;
            
            double t = 1e18;
            if (t_x > EPS) t = min(t, t_x);
            if (t_y > EPS) t = min(t, t_y);
            if (t_h > EPS) t = min(t, t_h);
            
            if (t >= 1e17) break; // No boundary hit
            double next_px = px + t * dvx;
            double next_py = py + t * dvy;
            
            // Check vertices
            if ((abs(next_px) < EPS && abs(next_py) < EPS) ||
                (abs(next_px) < EPS && abs(next_py - n) < EPS) ||
                (abs(next_px - n) < EPS && abs(next_py) < EPS)) {
                ans = reflections;
                escaped = true;
                break;
            }
            
            // Reflect based on boundary
            if (abs(t - t_x) < EPS) {
                dvx = -dvx;
            } else if (abs(t - t_y) < EPS) {
                dvy = -dvy;
            } else if (abs(t - t_h) < EPS) {
                double temp = dvx;
                dvx = -dvy;
                dvy = -temp;
            }
            
            px = next_px;
            py = next_py;
            reflections++;
        }
        
        cout << (escaped ? ans : -1) << '\n';
    }
    
    return 0;
}