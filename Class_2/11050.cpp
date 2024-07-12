#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 동적 프로그래밍
    int arr[11][11] = {0};

    for (int i = 0; i <= 10; i++)
    {
        arr[i][0] = 1;

        for (int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }

        arr[i][i] = 1;
    }

    int N, K;
    cin >> N >> K;

    // 동적 프로그래밍
    cout << arr[N][K] << '\n';

    /* 일반 구현
    int NF = 1;
    for (int i = 1; i <= N; i++)
    {
        NF *= i;
    }

    int KF = 1;
    for (int i = 1; i <= K; i++)
    {
        KF *= i;
    }

    int NKF = 1;
    for (int i = 1; i <= N - K; i++)
    {
        NKF *= i;
    }

    cout << NF / (KF * NKF) << '\n';
    */

    return 0;
}

// endl -> '\n'