#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

/*
1. 0 검사 -> 없으면 0 출력 후 end
2. 1 검사 -> 1의 위치들을 기억
3. 각 1에 대하여 BFS 실행 (0에 대한 BFS) -> 0 검사 -> 없으면 BFS 실행 횟수 출력 후 end
4. BFS 종료 후 0이 있으면 -1 출력 후 end
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;

    int ***tomato = new int **[H];
    for (int i = 0; i < H; i++)
    {
        tomato[i] = new int *[N];
        for (int j = 0; j < N; j++)
        {
            tomato[i][j] = new int[M];
            for (int k = 0; k < M; k++)
            {
                int temp;
                cin >> temp;

                tomato[i][j][k] = temp;
            }
        }
    }

    // 0 검사
    bool isZero = false;
    for (int i = 0; i < H && isZero == false; i++)
    {
        for (int j = 0; j < N && isZero == false; j++)
        {
            for (int k = 0; k < M && isZero == false; k++)
            {
                if (tomato[i][j][k] == 0)
                {
                    isZero = true;
                }
            }
        }
    }

    if (isZero == false)
    {
        cout << 0 << '\n';
        return 0;
    }

    // 1 검사
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomato[i][j][k] == 1)
                {
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    // BFS
    while (!q.empty())
    {
        // BFS 실행
        tuple<int, int, int> t = q.front();
        q.pop();

        if (get<0>(t) != 0)
        {
            if (tomato[get<0>(t) - 1][get<1>(t)][get<2>(t)] == 0)
            {
                tomato[get<0>(t) - 1][get<1>(t)][get<2>(t)] = tomato[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                q.push(make_tuple(get<0>(t) - 1, get<1>(t), get<2>(t)));
            }
        }

        if (get<0>(t) != H - 1)
        {
            if (tomato[get<0>(t) + 1][get<1>(t)][get<2>(t)] == 0)
            {
                tomato[get<0>(t) + 1][get<1>(t)][get<2>(t)] = tomato[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                q.push(make_tuple(get<0>(t) + 1, get<1>(t), get<2>(t)));
            }
        }

        if (get<1>(t) != 0)
        {
            if (tomato[get<0>(t)][get<1>(t) - 1][get<2>(t)] == 0)
            {
                tomato[get<0>(t)][get<1>(t) - 1][get<2>(t)] = tomato[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                q.push(make_tuple(get<0>(t), get<1>(t) - 1, get<2>(t)));
            }
        }

        if (get<1>(t) != N - 1)
        {
            if (tomato[get<0>(t)][get<1>(t) + 1][get<2>(t)] == 0)
            {
                tomato[get<0>(t)][get<1>(t) + 1][get<2>(t)] = tomato[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                q.push(make_tuple(get<0>(t), get<1>(t) + 1, get<2>(t)));
            }
        }

        if (get<2>(t) != 0)
        {
            if (tomato[get<0>(t)][get<1>(t)][get<2>(t) - 1] == 0)
            {
                tomato[get<0>(t)][get<1>(t)][get<2>(t) - 1] = tomato[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                q.push(make_tuple(get<0>(t), get<1>(t), get<2>(t) - 1));
            }
        }

        if (get<2>(t) != M - 1)
        {
            if (tomato[get<0>(t)][get<1>(t)][get<2>(t) + 1] == 0)
            {
                tomato[get<0>(t)][get<1>(t)][get<2>(t) + 1] = tomato[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                q.push(make_tuple(get<0>(t), get<1>(t), get<2>(t) + 1));
            }
        }
    }

    // 0, 최댓값 검사
    isZero = false;
    int max = 0;
    for (int i = 0; i < H && isZero == false; i++)
    {
        for (int j = 0; j < N && isZero == false; j++)
        {
            for (int k = 0; k < M && isZero == false; k++)
            {
                if (max < tomato[i][j][k])
                {
                    max = tomato[i][j][k];
                }

                if (tomato[i][j][k] == 0)
                {
                    isZero = true;
                }
            }
        }
    }

    if (isZero == true)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << max - 1 << '\n';
    }

    return 0;
}

// endl -> '\n'