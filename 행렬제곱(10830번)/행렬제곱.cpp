#include <iostream>
#include <vector>

#define MOD 1000
using namespace std;

int N;
vector<vector<int>> matrix;
vector<vector<int>> answer;
long long B;

void multiMatrix(vector<vector<int>> Amatrix, vector<vector<int>> Bmatrix) {
	vector<vector<int>> C;
	vector<int> nums;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;

			for (int k = 0; k < N; k++) {
				sum += Amatrix[i][k] * Bmatrix[k][j];
			}
			nums.push_back(sum);
		}
		C.push_back(nums);
		nums.clear();
	}

	for (int i = 0; i < N; i++) {
		answer.push_back(C[i]);
	}
}

void input() {
	int num;
	vector<int> nums;

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			nums.push_back(num);
		}
		matrix.push_back(nums);
		nums.clear();
	}
}

vector<vector<int>> recursion() {
	vector<vector<int>> test;
	
	return test;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	multiMatrix(matrix, matrix);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}