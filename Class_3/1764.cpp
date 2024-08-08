#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> m;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        m.insert(make_pair(s, 1));
    }

    vector<string> v;

    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        if (m.find(s) != m.end())
        {
            v.push_back(s);
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }

    return 0;
}

// endl -> '\n'