#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string *C = new string[N];

    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    int min = N * M;

    for (int a = 0; a <= N - 8; a++)
    {
        for (int b = 0; b <= M - 8; b++)
        {
            int start_W = 0, start_B = 0;
            for (int i = 0; i < 8; i++)
            {
                // 칸 검사
                for (int j = 0; j < 8; j++)
                {
                    // 0, 0 칸과 같은 색상
                    if ((a + i + b + j) % 2 == 0)
                    {
                        if (C[a + i][b + j] == 'W')
                        {
                            start_B++;
                        }
                        else
                        {
                            start_W++;
                        }
                    }
                    // 0, 0 칸과 다른 색상
                    else
                    {
                        if (C[a + i][b + j] == 'W')
                        {
                            start_W++;
                        }
                        else
                        {
                            start_B++;
                        }
                    }
                }
            }

            if (min > start_W)
            {
                min = start_W;
            }

            if (min > start_B)
            {
                min = start_B;
            }
        }
    }

    cout << min << '\n';

    return 0;
}

// endl -> '\n'