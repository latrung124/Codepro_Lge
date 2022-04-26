#include <stdio.h>
#include <iostream>
using namespace std;

int N;//Number of sponsored goods
int D[100000 + 10];//Preference
int sol = -30001;//Maximum preference of the first method
void InputData(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}
}

void Solve(void)
{
	int sum = D[0];
	int max = D[0];
	cout << N << endl;
	for (int i = 1; i < N; i++) {
		sum += D[i];
		if (sum < 0) {
			sum = 0;
		}
		else {
			if (sum > max) {
				max = sum;
			}
		}
	}
	cout << max << endl;
}

int main(void) {
	InputData();//Input function
	Solve();
	printf("%d\n", sol);//Output
	return 0;
}