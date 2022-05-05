#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m;
vector<string> candidates;
vector<std::pair<string, int>> votedPoll;
int scoreN[10000];

void inputData() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		candidates.push_back(s);
	}
	cin >> m;
	for (int j = 0; j < m; ++j) {
		string ss;
		cin >> ss;
		int score;
		cin >> score;
		vector<string>::iterator it = std::find(candidates.begin(), candidates.end(), ss);
		if (it != candidates.end()) {
			int pos = it - candidates.begin();
			cout << ss << " " << score << endl;
			scoreN[pos] = score;
		}
	}
}

int findMax(int s[], int score, int pos) {
	for (int i = n - 1; i >= 0; --i) {
		if (score < scoreN[i]) {
			score = scoreN[i];
			pos = i;
		}
	}
	cout << candidates.at(pos) << score << endl;
	return pos;
}

void solve() {
	int pos = 0;
	int count = 0;
	for (int i = n-1; i >= 0; --i) {
		if (i != pos) {
			int score = scoreN[i];
			pos = findMax(scoreN, score, i);
			count++;
		}	
		if (count == 2) break;
	}
	cout << endl;
}
int main() {
	inputData();
	solve();
	return 0;
}