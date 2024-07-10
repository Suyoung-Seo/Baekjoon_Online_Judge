#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[30] = {0};
    int n;

    for (int i = 0; i < 28; i++)
    {
        cin >> n;
        A[n - 1]++;
    }

    for (int i = 0; i < 30; i++)
    {
        if (A[i] == 0)
        {
            cout << i + 1 << '\n';
        }
    }

    return 0;
}

// endl -> '\n'