#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        vector<pair<int, int>> v;
        v.push_back(make_pair(1, 0));
        v.push_back(make_pair(0, 1));

        for (int j = 2; j <= N; j++)
        {
            v.push_back(make_pair(v[j - 1].first + v[j - 2].first, v[j - 1].second + v[j - 2].second));
        }

        cout << v[N].first << ' ' << v[N].second << '\n';
    }

    return 0;
}

// endl -> '\n'