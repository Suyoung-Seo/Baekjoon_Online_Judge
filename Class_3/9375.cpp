#include <iostream>
#include <map>
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
        int n;
        cin >> n;

        vector<string> v;
        map<string, int> m;
        for (int j = 0; j < n; j++)
        {
            string a, b;
            cin >> a >> b;

            if (m.find(b) != m.end())
            {
                m[b]++;
            }
            else
            {
                v.push_back(b);
                m.insert(make_pair(b, 1));
            }
        }

        int ans = 1;

        for (int j = 0; j < v.size(); j++)
        {
            ans *= m[v[j]] + 1;
        }

        cout << ans - 1 << '\n';
    }

    return 0;
}

// endl -> '\n'