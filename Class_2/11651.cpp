#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp_x(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

bool comp_y(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int, int>> V;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        V.push_back(make_pair(x, y));
    }

    stable_sort(V.begin(), V.end(), comp_x);
    stable_sort(V.begin(), V.end(), comp_y);

    for (int i = 0; i < N; i++)
    {
        cout << V[i].first << ' ' << V[i].second << '\n';
    }

    return 0;
}

// endl -> '\n'