#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int arr[n][n];
    //convert the string to array to array
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            int temp = s[j] - 48;
            arr[i][j] = temp;
        }
    }
    //dijikstra
    int dis[n*n + 1];
    for (int i=0; i<=n*n; ++i) {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, std::greater<pair<int, pair<int, int>>>> pq;
    // import vertex 0of
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    pq.push({0, {0, 0}}); // trong so, toa do canh
    while (!pq.empty()) {
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();
        int w = top.first;
        pair<int, int> v = top.second;
        int pos = (v.first * n) + v.second + 1;
        if (w > dis[pos]) continue;
        for (int i = 0; i < 4; ++i) {
            int tmpX = v.first + dx[i];
            int tmpY = v.second + dy[i];
            if (tmpX >= 0 && tmpX < n && tmpY >= 0 && tmpY < n) {
                int posU = tmpX * n + tmpY + 1;
                if (w + arr[tmpX][tmpY] < dis[posU]) {
                    dis[posU] = w + arr[tmpX][tmpY];
                    pq.push({dis[posU], {tmpX, tmpY}});
                }
            }
        }
    }
    int posD = n * n;
    cout << dis[posD] << endl;
}

int main() {
    solve();
    return 0;
}
