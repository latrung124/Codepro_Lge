//#include <bits/stdc++.h>

//using namespace std;

////5
////messi ronaldo messy suarez ronaldu
////6
////messy 3
////suarez 3
////ronaldo 1
////messi 1
////ronaldoo 10
////messi 1

//struct candidate {
//    string name;
//    int score;
//    int number;
//    candidate() {

//    }
//    candidate(string _name, int _score, int _number) {
//        name = _name;
//        score = _score;
//        number = _number;
//    }
//};
//int n;
//map<string, pair<int, int>> candidateMap; // name, first: number, second = score
//int m;
//vector<candidate> candidateList;

//bool cmp(candidate _a, candidate _b) {
//    if (_a.score == _b.score) return _a.number < _b.number;
//    return _a.score > _b.score;
//}

//void solve() {
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        string s; // name
//        cin >> s;
//        candidateMap[s] = {i, 0}; // map to save pos of candidate
//    }
//    cin >> m;
//    for (int i = 0; i < m; ++i) {
//        string name;
//        int score;
//        cin >> name >> score;
//        if (candidateMap.count(name)) {
//            candidateMap[name].second += score;
//        }
//    }
//    for (auto& it : candidateMap) {
//        candidate can(it.first, it.second.second, it.second.first);
//        candidateList.push_back(can);
//    }
//    sort(candidateList.begin(), candidateList.end(), cmp);
//    for (int i = 0; i < 3; ++i) {
//        cout << candidateList[i].name << " " << candidateList[i].score << endl;
//    }
//}

//int main() {
//    solve();
//    return 0;
//}
