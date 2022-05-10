#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

int n, m;

map<string, int> tenDiem;
map<string, int> tenThuTu;

bool cmp(std::pair<string,int>& a, std::pair<string,int>& b) {
    return a.second > b.second;
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        std::pair<string, int> e;
        e.first = s;
        e.second = i;
        std::pair<string, int> e1;
        e1.first = s;
        e1.second = 0;
        tenThuTu.insert(e);
        tenDiem.insert(e1);
    }
    cin >> m;
    for (int j = 0; j < m; ++j) {
        string ss;
        cin >> ss;
        int score;
        cin >> score;
        std::pair<string, int> e;
        e.first = ss;
        e.second = score;

        std::map<string,int>::iterator it = tenDiem.find(ss);
        if ( it != tenDiem.end()) {
            it->second+=score;
        }
    }
    std::vector<pair<string,int>> vec;
    std::copy(tenDiem.begin(),
              tenDiem.end(),
              std::back_inserter<std::vector<pair<string,int>>>(vec));
    std::sort(vec.begin(), vec.end(), cmp);
    vector<pair<string,int>> result;
    for (int i = 0; i < vec.size(); ++i) {
       if (result.empty())
       result.push_back(vec.at(i));
       else {
           for (int j = 0; j < result.size(); ++j) {
               if (vec.at(i).second == result.at(j).second) {
                   std::map<string,int>::iterator it1;
                   it1 = tenThuTu.find(vec.at(i).first);
                   std::map<string,int>::iterator it2;
                   it2 = tenThuTu.find(result.at(j).first);
                   if (it1 != tenThuTu.end() && it2 != tenThuTu.end()) {
                       if (it1->second < it2->second) {
                           result.insert(result.begin() + j, vec.at(i));
                           break;
                       } else {
                           if (it1->first != it2->first) {
                               result.push_back(vec.at(i));
                               break;
                           }
                       }
                   }
               } else {
                   if (result.size() < 3) {
                       result.push_back(vec.at(i));
                   } else {
                       break;
                   }
               }
           }
       }
    }
    for(int i = 0; i < 3; i++) {
        cout << result.at(i).first << " " << result.at(i).second << endl;
    }
}

int main() {
    solve();
    return 0;
}
