#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string com;
    int data;
    queue<int> q;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> com;
        if (com == "push")
        {
            cin >> data;
            q.push(data);
        }
        else if (com == "pop")
        {
            if (q.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (com == "size")
        {
            cout << q.size() << '\n';
        }
        else if (com == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (com == "front")
        {
            if (q.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << q.front() << '\n';
            }
        }
        else if (com == "back")
        {
            if (q.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}

// endl -> '\n'