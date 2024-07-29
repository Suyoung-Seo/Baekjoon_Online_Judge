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

    int node, edge;
    cin >> node >> edge;

    vector<int> *E = new vector<int>[node + 1];

    for (int i = 0; i < edge; i++)
    {
        int first, second;
        cin >> first >> second;

        E[first].push_back(second);
        E[second].push_back(first);
    }

    vector<int> visited;
    stack<int> s;

    for (int i = 0; i < E[1].size(); i++)
    {
        s.push(E[1][i]);
    }
    visited.push_back(1);

    while (!s.empty())
    {
        int search = s.top();
        s.pop();

        if (find(visited.begin(), visited.end(), search) == visited.end())
        {
            for (int i = 0; i < E[search].size(); i++)
            {
                s.push(E[search][i]);
            }
            visited.push_back(search);
        }
    }

    cout << visited.size() - 1 << '\n';

    return 0;
}

// endl -> '\n'