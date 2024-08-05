#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first != 0)
        {
            if (arr[p.first - 1][p.second] == 1)
            {
                arr[p.first - 1][p.second] = arr[p.first][p.second] + 1;
                q.push(make_pair(p.first - 1, p.second));
            }
        }

        if (p.first != n - 1)
        {
            if (arr[p.first + 1][p.second] == 1)
            {
                arr[p.first + 1][p.second] = arr[p.first][p.second] + 1;
                q.push(make_pair(p.first + 1, p.second));
            }
        }

        if (p.second != 0)
        {
            if (arr[p.first][p.second - 1] == 1)
            {
                arr[p.first][p.second - 1] = arr[p.first][p.second] + 1;
                q.push(make_pair(p.first, p.second - 1));
            }
        }

        if (p.second != m - 1)
        {
            if (arr[p.first][p.second + 1] == 1)
            {
                arr[p.first][p.second + 1] = arr[p.first][p.second] + 1;
                q.push(make_pair(p.first, p.second + 1));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                cout << arr[i][j] - 2 << ' ';
            }
            else
            {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

// endl -> '\n'