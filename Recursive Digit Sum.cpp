#include <iostream>
#include <string>

using namespace std;

long long super_digit_sum(string num) {
    if (num.size() == 1) {
        return num[0] - '0';
    }

    long long digit_sum = 0;
    for (long long i = 0; i < num.size(); i++) {
        digit_sum += num[i] - '0';
    }

    return super_digit_sum(to_string(digit_sum));
}

int main() {
    string n;
    long long k;
    cin >> n >> k;

    string appended_n;
    for (long long i = 0; i < k; i++) {
        appended_n += n;
    }

    cout << super_digit_sum(appended_n);

    return 0;
}