#include <iostream>
#include <algorithm>
using namespace std;
 
string A, B;

void input() {
    cin >> A >> B;
}

void solve() {
    string result;
    int sum = 0, carry = 0;
    int A_size = A.size() - 1;
    int B_size = B.size() - 1;
    int end;

    A_size > B_size ? end = B_size : end = A_size;

    while (A_size >= 0 && B_size >= 0) {
        sum = (A[A_size] - '0') + (B[B_size] - '0') + carry;
        carry = sum / 10;

        result.push_back((sum % 10) + '0');

        A_size--;
        B_size--;
    }

    while (A_size >= 0) {
        sum = (A[A_size] - '0') + carry;
        carry = sum / 10;

        result.push_back((sum % 10) + '0');

        A_size--;
    }

    while (B_size >= 0) {
        sum = (B[B_size] - '0') + carry;
        carry = sum / 10;

        result.push_back((sum % 10) + '0');

        B_size--;
    }

    if (carry != 0) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());

    cout << result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}