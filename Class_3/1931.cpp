#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp1(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

bool comp2(pair<int, int> p1, pair<int, int> p2)
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

    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        v.push_back(make_pair(a, b));
    }

    stable_sort(v.begin(), v.end(), comp1);
    stable_sort(v.begin(), v.end(), comp2);

    int cnt = 1, cur = v[0].second;
    for (int i = 1; i < N; i++)
    {
        if (cur <= v[i].first)
        {
            cnt++;
            cur = v[i].second;
        }
    }

    cout << cnt << '\n';

    return 0;
}

// endl -> '\n'