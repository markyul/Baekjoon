#include <iostream>
#define MAX_SIZE 10000
using namespace std;

int N;
int front_idx = 0, rear_idx = 0;
int deque[MAX_SIZE];

bool empty() {
	if (front_idx == rear_idx)
		return true;
	else
		return false;
}

void push_front(int data) {
	if (front_idx == 0)
		front_idx = MAX_SIZE - 1;
	else
		front_idx--;

	deque[front_idx] = data;
}

void push_back(int data) {
	deque[rear_idx] = data;

	if (rear_idx == MAX_SIZE - 1)
		rear_idx = 0;
	else
		rear_idx++;

}

int pop_front() {
	if (empty())
		return -1;
	else {
		if (front_idx == MAX_SIZE - 1) {
			front_idx = 0;
			return deque[MAX_SIZE - 1];
		}
		else {
			front_idx++;
			return deque[front_idx - 1];
		}
	}
}

int pop_back() {
	if (empty())
		return -1;
	else {
		if (rear_idx == 0) {
			rear_idx = MAX_SIZE - 1;
			return deque[rear_idx];
		}
		else {
			rear_idx--;
			return deque[rear_idx];
		}
	}
}

int size() {
	if (rear_idx < front_idx)
		return rear_idx - front_idx + MAX_SIZE;
	else
		return rear_idx - front_idx;
}

int front() {
	if (empty())
		return -1;
	else {
		return deque[front_idx];
	}
}

int back() {
	if (empty())
		return -1;
	else {
		if (rear_idx == 0)
			return deque[MAX_SIZE - 1];
		else
			return deque[rear_idx - 1];
	}
}

void input() {
	int data;
	string command;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push_front") {
			cin >> data;
			push_front(data);
		}
		else if (command == "push_back") {
			cin >> data;
			push_back(data);
		}
		else if (command == "pop_front") {
			cout << pop_front() << "\n";
		}
		else if (command == "pop_back") {
			cout << pop_back() << "\n";
		}
		else if (command == "size") {
			cout << size() << "\n";
		}
		else if (command == "empty") {
			cout << empty() << "\n";
		}
		else if (command == "front") {
			cout << front() << "\n";
		}
		else if (command == "back") {
			cout << back() << "\n";
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	return 0;
}