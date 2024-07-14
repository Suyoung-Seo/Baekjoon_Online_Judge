#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    stack<int> S;

    for (int i = 0; i < K; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            S.pop();
        }
        else
        {
            S.push(num);
        }
    }

    int result = 0;
    while (!S.empty())
    {
        result += S.top();
        S.pop();
    }

    cout << result << '\n';

    return 0;
}

// endl -> '\n'