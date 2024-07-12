#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 동적 프로그래밍
    int DP[5001] = {0};
    DP[3] = DP[5] = 1;

    for (int i = 6; i <= N; i++)
    {
        if (DP[i - 3] != 0)
        {
            DP[i] = DP[i - 3] + 1;
        }

        if (DP[i - 5] != 0)
        {
            DP[i] = DP[i - 5] + 1;
        }
    }

    if (DP[N] == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << DP[N] << '\n';
    }

/*    // 그리디 알고리즘
    int result = 0;

    while (N >= 0)
    {
        // 5로 나누어 떨어지면 봉지 개수 출력
        if (N % 5 == 0)
        {
            cout << result + N / 5 << '\n';
            return 0;
        }

        // 5로 나누어 떨어지지 않으면 봉지 3 추가
        N -= 3;
        result++;
    }

    // 5로 나누어 떨어지지 않고 3을 뺄 수도 없음
    cout << -1 << '\n';
*/

    return 0;
}

// endl -> '\n'