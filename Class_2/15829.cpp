#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L;
    string S;

    cin >> L >> S;

    long long result = 0;

    // mod 분배 법칙
    for (int i = 0; i < L; i++)
    {
        long long temp = 1;
        for (int j = 1; j <= i; j++)
        {
            temp *= 31;
            temp %= 1234567891;
        }

        result += (((long long)(S[i] - 96)) * temp) % 1234567891;
        result %= 1234567891;
    }
    
    cout << result << '\n';

    return 0;
}

// endl -> '\n'