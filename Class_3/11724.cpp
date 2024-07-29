#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> *E = new vector<int>[N + 1];

    for (int i = 0; i < M; i++)
    {
        int first, second;
        cin >> first >> second;

        E[first].push_back(second);
        E[second].push_back(first);
    }

    int *visited = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        visited[i] = 0;
    }

    int graph = 1;

    stack<int> s;
    for (int i = 0; i < E[1].size(); i++)
    {
        s.push(E[1][i]);
    }
    visited[1] = 1;

    while (true)
    {
        while (!s.empty())
        {
            int search = s.top();
            s.pop();

            if (visited[search] == 0)
            {
                for (int i = 0; i < E[search].size(); i++)
                {
                    s.push(E[search][i]);
                }
                visited[search] = 1;
            }
        }

        bool full = true;
        int idx;

        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0)
            {
                full = false;
                idx = i;
                break;
            }
        }

        if (full)
        {
            break;
        }

        graph++;

        for (int i = 0; i < E[idx].size(); i++)
        {
            s.push(E[idx][i]);
        }
        visited[idx] = 1;
    }

    cout << graph << '\n';

    return 0;
}

// endl -> '\n'