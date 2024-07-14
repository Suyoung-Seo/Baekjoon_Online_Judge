#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> V;
    stack<int> S;

    int cur = 0;

    string str;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        V.push_back(num);

        while (cur < num)
        {
            str.append("+");
            cur++;
        }

        str.append("-");
    }

    int num = 1;
    vector<int> comp;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+')
        {
            S.push(num++);
        }
        else if (str[i] == '-')
        {
            comp.push_back(S.top());
            S.pop();
        }
    }

    bool vaild = true;

    for (int i = 0; i < n; i++)
    {
        if (V[i] != comp[i])
        {
            vaild = false;
            break;
        }
    }

    if (vaild)
    {
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i] << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }

    return 0;
}

// endl -> '\n'