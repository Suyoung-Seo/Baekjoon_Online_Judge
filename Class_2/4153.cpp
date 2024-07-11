#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int arr[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
        {
            break;
        }

        if (arr[0] * arr[0] == arr[1] * arr[1] + arr[2] * arr[2])
        {
            cout << "right" << '\n';
            continue;
        }
        else if (arr[1] * arr[1] == arr[0] * arr[0] + arr[2] * arr[2])
        {
            cout << "right" << '\n';
            continue;
        }
        else if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1])
        {
            cout << "right" << '\n';
            continue;
        }

        cout << "wrong" << '\n';
    }

    return 0;
}

// endl -> '\n'