#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person {
	int age;
	string name;
};

int N;
person people[100000];

bool compare(person a, person b) {
	return a.age < b.age;
}

void input() {
	person test;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> people[i].age >> people[i].name;
	}
}

void solve() {
	stable_sort(people, people + N, compare);

	for (int i = 0; i < N; i++) {
		cout << people[i].age << " " << people[i].name << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}