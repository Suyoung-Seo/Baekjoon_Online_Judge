#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        stack<char> S;
        bool bal = true;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                S.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (S.empty())
                {
                    bal = false;
                    break;
                }

                if (S.top() == '(')
                {
                    S.pop();
                }
                else
                {
                    bal = false;
                    break;
                }
            }
        }

        if (bal && S.empty())
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}

// endl -> '\n'