#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    int **tomato = new int *[N];
    for (int i = 0; i < N; i++)
    {
        tomato[i] = new int[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;

            tomato[i][j] = temp;
        }
    }

    // 0 검사
    bool isZero = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tomato[i][j] == 0)
            {
                isZero = true;
                break;
            }
        }
        if (isZero)
        {
            break;
        }
    }

    if (!isZero)
    {
        cout << 0 << '\n';
        return 0;
    }

    // 1 검사
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tomato[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    // BFS
    while (!q.empty())
    {
        // BFS 실행
        pair<int, int> p = q.front();
        q.pop();

        if (p.first != 0)
        {
            if (tomato[p.first - 1][p.second] == 0)
            {
                tomato[p.first - 1][p.second] = tomato[p.first][p.second] + 1;
                q.push(make_pair(p.first - 1, p.second));
            }
        }

        if (p.second != 0)
        {
            if (tomato[p.first][p.second - 1] == 0)
            {
                tomato[p.first][p.second - 1] = tomato[p.first][p.second] + 1;
                q.push(make_pair(p.first, p.second - 1));
            }
        }

        if (p.first != N - 1)
        {
            if (tomato[p.first + 1][p.second] == 0)
            {
                tomato[p.first + 1][p.second] = tomato[p.first][p.second] + 1;
                q.push(make_pair(p.first + 1, p.second));
            }
        }

        if (p.second != M - 1)
        {
            if (tomato[p.first][p.second + 1] == 0)
            {
                tomato[p.first][p.second + 1] = tomato[p.first][p.second] + 1;
                q.push(make_pair(p.first, p.second + 1));
            }
        }
    }

    // 0, 최댓값 검사
    isZero = false;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (max < tomato[i][j])
            {
                max = tomato[i][j];
            }

            if (tomato[i][j] == 0)
            {
                isZero = true;
                break;
            }
        }

        if (isZero)
        {
            break;
        }
    }

    if (isZero)
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