//#include <iostream>
//#include <string>
//using namespace std;
//
//typedef long long ll;
//string s, c;
//
//void inputData() {
//	cin >> s >> c;
//}
//
//void solve() {
//
//	ll p = s.size();
//	for (auto& i : c) {
//		if (i == 'R') {
//			if (p < s.size()) {
//				p++;
//			}
//		}
//		else if (i == 'L') {
//			if (p > 0) {
//				p--;
//			}
//		}
//		else if (i == 'B') {
//			if (p != 0) {
//				s.erase(s.begin() + p - 1);
//				p--;
//			}
//		}
//		else {			
//			s.insert(s.begin() + p, i);
//			if (p < s.size()) {				
//				p++;
//			}
//		}
//		//cout <<"s: " <<  s << " i: "<< i << " p: " << p << endl;
//	}
//	cout << s << endl;
//}
//
//int main() {
//	inputData();
//	solve();
//	return 0;
//}