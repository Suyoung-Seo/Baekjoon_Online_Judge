#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string com;
    int data;
    stack<int> st;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> com;
        if (com == "push")
        {
            cin >> data;
            st.push(data);
        }
        else if (com == "pop")
        {
            if (st.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (com == "size")
        {
            cout << st.size() << '\n';
        }
        else if (com == "empty")
        {
            cout << st.empty() << '\n';
        }
        else if (com == "top")
        {
            if (st.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << st.top() << '\n';
            }
        }
    }

    return 0;
}

// endl -> '\n'