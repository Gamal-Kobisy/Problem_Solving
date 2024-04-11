#include <iostream>
#include <string>

using namespace std;

long long super_digit_sum(string num, int k, int i)
{
    long long sum = 0;
    for (char c : num)
    {
        sum += c - '0';
    }
    sum *= (i == 0) ? k : 1;
    return ((sum > 9) ? super_digit_sum(to_string(sum), k, ++i) : sum);
}

int main()
{
    string num;
    cin >> num;
    int k;
    cin >> k;
    cout << super_digit_sum(num, k, 0) << endl;

    return 0;
}