#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<int> Q;

    for (int i = 0; i < N; i++)
    {
        Q.push(i + 1);
    }

    cout << '<';

    for (int i = 0; i < K - 1; i++)
    {
        Q.push(Q.front());
        Q.pop();
    }

    cout << Q.front();
    Q.pop();

    while (!Q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }

        cout << ", " << Q.front();
        Q.pop();
    }
    
    cout << '>' << '\n';

    return 0;
}

// endl -> '\n'