#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10]; // Virus data
int C[3 + 1];
int sol; // Correct answer

void InputData(void)
{
	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (i = 0; i < M; i++) {
		cin >> B[i];
	}
}

void OutputData(void)
{
	cout << sol;
}



void Solve(void)
{
	std::sort(B, B + M);
	sol = 0;
	for (int i = 0; i < N; ++i) {
		int C[10001];
		int d = 0;
		for (int j = i; j < i+ M; ++j) {
			C[d] = A[j];
			d++;
		}
		std::sort(C, C + M);
		if (std::equal(C, C + M, B)) {
			sol++;
		}
		else {
			int subtract = C[0] - B[0];
			bool isVirus = true;
			for (int k = 1; k < M; k++) {
				int sub = C[k] - B[k];
				if (sub != subtract) isVirus = false;
			}
			if (isVirus) {
				sol++;
			}
		}
	}
}

int main(void)
{
	InputData(); // Input

	Solve(); // Problem solving

	OutputData(); // Output

	return 0;
}
