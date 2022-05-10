#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
int a[100000+1];

typedef struct Product{
    int type;
    int loopNumber;
    Product(int _type, int _loop) {
        type = _type;
        loopNumber = _loop;
    }
}pd;
int result = 0;

vector<pd> v;

void calculateNumber(int tmp) {
    bool isIncluded = false;
    for (int j = 0; j < v.size(); ++j) {
        if (v.at(j).type == tmp) {
            v.at(j).loopNumber++;
            isIncluded = true;
        }
    }
    if (!isIncluded) {
        pd p(tmp, 1);
        v.push_back(p);
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
        if (v.empty()) {
            pd p(tmp, 1);
            v.push_back(p);
        } else {
            calculateNumber(tmp);
        }
    }
}

void printPermutations( int cid) {
    if (cid == v.size() - 1) {
        int arr[100000+1];
        memcpy(arr,a, sizeof(a));
        int count = 0;
        int k = 0;
        for (int j = 0; j < v.size()-1; ++j) {
            k = j == 0 ? 0 : k+=v.at(j).loopNumber;
            for (int s = k; s < v.at(j).loopNumber; ++s) {
                if (arr[s] != v.at(j).type) {
                    for (int p = k + v.at(j).loopNumber; p < n; ++p) {
                        if (arr[p] == v.at(j).type) {
                            swap(arr[s], arr[p]);
                            count += 2;
                            break;
                        }
                    }
                }
            }
        }
        if (result == 0) {
            result = count;
        } else {
            result = min(result, count);
        }
//        cout <<"count : "<< count << endl;
        return;
    }
    for (int i = cid; i < v.size(); ++i) {
        swap(v.at(i), v.at(cid));
//        for (auto& j : v) {
//            cout << j.type << " " << j.loopNumber << endl;
//        }
        printPermutations( cid + 1);
        swap(v.at(i), v.at(cid));
    }
}

void solve(){
    printPermutations( 0);
}

void output() {
//    for (int i = 0; i < n; ++i) {
//        cout << a[i];
//    }
//    cout << endl;
//    int k = 0;
//    for (int j = 0; j < v.size()-1; ++j) {
//        k = j == 0 ? 0 : k+=v.at(j).loopNumber;
//        for (int s = k; s < v.at(j).loopNumber; ++s) {
//            if (a[s] != v.at(j).type) {
//                for (int p = k + v.at(j).loopNumber; p < n; ++p) {
//                    if (a[p] == v.at(j).type) {
//                        swap(a[s], a[p]);
//                        break;
//                    }
//                }
//            }
//        }
//    }

//    cout << endl;

//    for (auto& j : v) {
//        cout << j.type << " " << j.loopNumber << endl;
//    }
    cout << result << endl;
}

int main() {
    input();
    solve();
    output();
    return 0 ;
}
