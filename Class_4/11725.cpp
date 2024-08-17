#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 개수
    int N;
    cin >> N;

    // 인접 리스트
    vector<int> *adjust = new vector<int>[N + 1];
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        adjust[x].push_back(y);
        adjust[y].push_back(x);
    }

    // 방문 여부, dfs 스택
    stack<int> dfs;
    bool *visited = new bool[N + 1];
    for (int i = 1; i <= N; i++)
    {
        visited[i] = false;
    }

    // dfs
    int *parent = new int[N + 1];

    visited[1] = true; // 초기화 과정

    for (int i = 0; i < adjust[1].size(); i++) // 인접 노드 확인
    {
        if (visited[adjust[1][i]] == false) // 방문하지 않았다면
        {
            visited[adjust[1][i]] = true; // 인접 노드 방문 후 부모 노드 저장, 스택에 push
            parent[adjust[1][i]] = 1;
            dfs.push(adjust[1][i]);
        }
    }

    while (!dfs.empty())
    {
        int cur = dfs.top(); // 현재 노드
        dfs.pop();

        for (int i = 0; i < adjust[cur].size(); i++) // 인접 노드 확인
        {
            if (visited[adjust[cur][i]] == false) // 방문하지 않았다면
            {
                dfs.push(adjust[cur][i]);
                parent[adjust[cur][i]] = cur;
                visited[adjust[cur][i]] = true;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}