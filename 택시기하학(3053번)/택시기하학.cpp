#include <iostream>
#define PI 3.14159265358979
#define TAXI_PI 2.0
using namespace std;

void solve() {
	double R;
	double area, area_taxi;

	cin >> R;

	area = R * R * PI;
	area_taxi = R * R * TAXI_PI;

	cout << fixed;
	cout.precision(6);
	cout << area << "\n" << area_taxi;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}