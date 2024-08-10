#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, B;
    cin >> N >> M >> B;

    int min = 256, max = 0;
    int **arr = new int *[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];

            if (min > arr[i][j])
            {
                min = arr[i][j];
            }

            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
        }
    }

    int mintime = 2147483647;
    int height;

    for (int i = min; i <= max; i++)
    {
        int time = 0, block = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (i - arr[j][k] > 0) // 블록 설치, 1초 소요, 블록 1개 소모
                {
                    time += i - arr[j][k];
                    block -= i - arr[j][k];
                }
                else if (i - arr[j][k] < 0) // 블록 제거, 2초 소요, 블록 1개 획득
                {
                    time += (arr[j][k] - i) * 2;
                    block += arr[j][k] - i;
                }
            }
        }

        if (B + block >= 0 && mintime >= time)
        {
            mintime = time;
            height = i;
        }
    }

    cout << mintime << ' ' << height << '\n';

    return 0;
}

// endl -> '\n'