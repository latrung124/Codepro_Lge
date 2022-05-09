#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n; //vertical size of map : row
int m; // horizontal size of map : column
int mark = 1;
int graph[50 + 5][50 + 5];
int result = 0;

int connectedG[50 + 5][50 + 5]; // connected graph mark number
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

void inputData() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> graph[i][j];
		}
	}
}

void dfs(int i, int j) {
	connectedG[i][j] = mark;
	//cout << mark << endl;
	for (int k = 0; k < 4; ++k) {
		int x = dx[k] + i;
		int y = dy[k] + j;
		if (x > 0 && x <= n && y > 0 && y <= m && graph[x][y] == 1 && connectedG[x][y] == 0) {
			//cout << x << " " << y << " " << mark << endl;
			dfs(x, y);
		}
	}
}

void bfs(int i, int j, int connected) {
	bool isVisited[50 + 5][50 + 5];
	memset(isVisited, false, sizeof(isVisited));
	queue<pair<int, int>> q;
	q.push({ i,j });
	int distanceG[50 + 5][50 + 5]; //dis > 0
	memset(distanceG, 0, sizeof(distanceG));
	while (!q.empty()) {
		pair<int, int> top = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int x = dx[k] + top.first;
			int y = dy[k] + top.second;
			if (x > 0 && x <= n && y > 0 && y <= m && connectedG[x][y] == 0 && isVisited[x][y] == false) {
				//cout << "plus distance: " << distanceG[x][y] << endl;
				distanceG[x][y] = distanceG[top.first][top.second] + 1;
				//cout << "after plus distance: " << distanceG[x][y] << endl;
				q.push({ x,y });
				isVisited[x][y] = true;
			}
			else if (connectedG[x][y] != connected && connectedG[x][y] != 0) {
				//cout << "distance: " << distanceG[x][y] << endl;
				if (result == 0) result = distanceG[top.first][top.second];
				else 
				result = min(result, distanceG[top.first][top.second]);
			}
		}
	}
}

void solve() {
	//cout << __func__ << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (graph[i][j] == 1 && connectedG[i][j] == 0) {
				//cout << "thanh phan lien thong thu " << mark << " : " << endl;
				dfs(i, j);
				++mark;
			}
		}
	}

	for (int g = 1; g < mark; ++g) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (connectedG[i][j] == g) {
					bfs(i, j, g);
				}
			}
		}
	}
	cout <<  result << endl;
}


int main() {
	inputData();
	solve();
	return 0;
}