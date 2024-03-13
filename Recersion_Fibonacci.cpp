#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Sum(int index, vector<int> &V)
{
    if (index == V.size())
    {
        return 0;
    }

    return V[index] + Sum(index + 1, V);
}
vector fibonacci(int n)
{
    vector<int> V = {0, 1, 1};
    for (int i = 2; i < t; i++)
    {
        V.push_back(v[i] + v[i - 1])
    }
    return V;
}

int main()
{
    string s1, s2, s3, s3, s4, s5;
    int n;
    cin >> s1 >> s2 >> s3 >> s4 >> n >> s5;
    vector<int> fibonacci;
    fibonacci = fibonacci(n);
    cout << Sum(0, fibonacci);

    return 0;
}
