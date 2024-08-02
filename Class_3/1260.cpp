#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    int **arr = new int *[N + 1];

    for (int i = 1; i <= N; i++)
    {
        arr[i] = new int[N + 1];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            arr[i][j] = 0;
        }
    }

    // 그래프 인접 행렬 표현
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    // DFS (stack)
    stack<int> s;

    int *visited = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        visited[i] = 0;
    }

    if (visited[V] == 0)
    {
        cout << V << ' '; // 방문
        visited[V] = 1;
    }

    for (int i = N; i >= 1; i--) // 방문X, 연결 노드 찾기
    {
        if (arr[V][i] == 1 && visited[i] == 0)
        {
            s.push(i);
        }
    }

    while (!s.empty())
    {
        int search = s.top();
        s.pop();

        if (visited[search] == 0)
        {
            cout << search << ' '; // 방문
            visited[search] = 1;
        }

        for (int i = N; i >= 1; i--)
        {
            if (arr[search][i] == 1 && visited[i] == 0)
            {
                s.push(i);
            }
        }
    }

    cout << '\n';

    // BFS (queue)
    queue<int> q;

    int *visited2 = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        visited2[i] = 0;
    }

    if (visited2[V] == 0)
    {
        cout << V << ' '; // 방문
        visited2[V] = 1;
    }

    for (int i = 1; i <= N; i++) // 방문X, 연결 노드 찾기
    {
        if (arr[V][i] == 1 && visited2[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int search = q.front();
        q.pop();

        if (visited2[search] == 0)
        {
            cout << search << ' '; // 방문
            visited2[search] = 1;
        }

        for (int i = 1; i <= N; i++)
        {
            if (arr[search][i] == 1 && visited2[i] == 0)
            {
                q.push(i);
            }
        }
    }

    cout << '\n';

    return 0;
}

// endl -> '\n'