#include <iostream>
using namespace std;

/*
0-1 배낭 채우기 문제 -> DP

n개의 물건
n번 물건을 포함하지 않는 경우 -> n-1개 물건의 최적해와 같음
n번 물건을 포함하는 경우 -> 새로운 무게 한도 (W-Wn) 내에서 n-1개 물건의 최적해 + Pn
포함하는 경우와 포함하지 않는 경우 중 최댓값을 저장

점화식
1. Wn > W인 경우 2번 경우가 성립하지 않기 때문에 위의 1번 경우와 같음 -> DP[n-1][W]
2. Wn <= W인 경우 MAX(DP[n-1][W], DP[n-1][W-Wn] + Pn)
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int *W = new int[N];
    int *V = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> W[i] >> V[i];
    }

    int max = 0;

    int **DP = new int *[N + 1];

    for (int i = 0; i <= N; i++)
    {
        DP[i] = new int[K + 1];

        for (int j = 0; j <= K; j++)
        {
            if (i == 0 || j == 0) // 초기화
            {
                DP[i][j] = 0;
            }
            else // 점화식
            {
                if (W[i - 1] > j) // 1번 경우
                {
                    DP[i][j] = DP[i - 1][j];

                    if (max < DP[i][j])
                    {
                        max = DP[i][j];
                    }
                }
                else // 2번 경우
                {
                    if (DP[i - 1][j] > DP[i - 1][j - W[i - 1]] + V[i - 1])
                    {
                        DP[i][j] = DP[i - 1][j];

                        if (max < DP[i][j])
                        {
                            max = DP[i][j];
                        }
                    }
                    else
                    {
                        DP[i][j] = DP[i - 1][j - W[i - 1]] + V[i - 1];

                        if (max < DP[i][j])
                        {
                            max = DP[i][j];
                        }
                    }
                }
            }
        }
    }

    cout << max << '\n';

    return 0;
}