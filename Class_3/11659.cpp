#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int *arr = new int[N];

    cin >> arr[0];
    for (int i = 1; i < N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int a = 0; a < M; a++)
    {
        int i, j;
        cin >> i >> j;

        if (i != 1)
        {
            cout << arr[j - 1] - arr[i - 2] << '\n';
        }
        else
        {
            cout << arr[j - 1] << '\n';
        }
    }

    return 0;
}

// endl -> '\n'