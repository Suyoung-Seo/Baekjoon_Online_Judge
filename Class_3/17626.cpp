#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int *DP = new int[n + 1];
    DP[0] = 0;

    // i보다 작은 제곱수 모두 뺀 DP 값 중 가장 작은 값 + 1을 DP에 저장
    for (int i = 1; i <= n; i++)
    {
        int min = DP[i - 1];
        for (int j = 2; j * j <= i; j++)
        {
            if (min > DP[i - j * j])
            {
                min = DP[i - j * j];
            }
        }
        DP[i] = min + 1;
    }

    cout << DP[n] << '\n';

    return 0;
}

// endl -> '\n'