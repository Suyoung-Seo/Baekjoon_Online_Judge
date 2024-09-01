#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    queue<pair<long long, long long>> q;

    q.push(make_pair(A, 1));

    while (!q.empty())
    {
        pair<long long, long long> p = q.front();
        q.pop();

        if (p.first * 2 == B || p.first * 10 + 1 == B)
        {
            cout << p.second + 1 << '\n';
            return 0;
        }

        if (p.first * 2 < B)
        {
            q.push(make_pair(p.first * 2, p.second + 1));
        }

        if (p.first * 10 + 1 < B)
        {
            q.push(make_pair(p.first * 10 + 1, p.second + 1));
        }
    }

    cout << -1 << '\n';

    return 0;
}