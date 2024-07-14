#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        string str;
        getline(cin, str);
        if (str == ".")
        {
            break;
        }

        stack<char> S;
        bool bal = true;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' || str[i] == '[')
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
            else if (str[i] == ']')
            {
                if (S.empty())
                {
                    bal = false;
                    break;
                }

                if (S.top() == '[')
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
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }

    return 0;
}

// endl -> '\n'