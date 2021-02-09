#include <iostream>
#define endl "\n"
using namespace std;

int M;
bool set[21];

void add_set(int index) {
	set[index] = true;
}

void remove_set(int index) {
	set[index] = false;
}

void check_set(int index) {
	cout << set[index] << endl;
}

void toggle_set(int index) {
	if (set[index])
		set[index] = false;
	else
		set[index] = true;
}

void all_set() {
	for (int i = 1; i <= 20; i++) {
		set[i] = true;
	}
}

void empty_set() {
	for (int i = 1; i <= 20; i++) {
		set[i] = false;
	}
}

void solve() {
	string command;
	int index = 0;
	cin >> command; 
	if (command == "all" || command == "empty") {}
	else {
		cin >> index;
	}

	if (command == "add")
		add_set(index);
	else if (command == "remove")
		remove_set(index);
	else if (command == "check")
		check_set(index);
	else if (command == "toggle")
		toggle_set(index);
	else if (command == "all")
		all_set();
	else if (command == "empty")
		empty_set();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++) {
		solve();
	}

	return 0;
}