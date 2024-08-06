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
        int temp;
        cin >> temp;

        v.push_back(make_pair(temp, i));
    }

    sort(v.begin(), v.end(), comp1);

    // 좌표 압축
    int cnt = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (v[i].first != v[i + 1].first)
        {
            v[i].first = cnt++;
        }
        else
        {
            v[i].first = cnt;
        }
    }
    v[N - 1].first = cnt;

    sort(v.begin(), v.end(), comp2);

    for (int i = 0; i < N; i++)
    {
        cout << v[i].first << ' ';
    }
    cout << '\n';

    return 0;
}

// endl -> '\n'