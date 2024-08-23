#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int **arr = new int *[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];

        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    /*
    before
    a b
    c d

    after
    a b'
    c' d'

    b' = a + b
    c' = a + c
    d' = - a + b' + c' + d
    */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp = arr[i][j];

            if (i != 0 && j != 0)
            {
                temp -= arr[i - 1][j - 1];
            }

            if (i != 0)
            {
                temp += arr[i - 1][j];
            }

            if (j != 0)
            {
                temp += arr[i][j - 1];
            }

            arr[i][j] = temp;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == 1 && y1 == 1)
        {
            cout << arr[x2 - 1][y2 - 1] << '\n';
        }
        else if (x1 == 1)
        {
            cout << arr[x2 - 1][y2 - 1] - arr[x2 - 1][y1 - 2] << '\n';
        }
        else if (y1 == 1)
        {
            cout << arr[x2 - 1][y2 - 1] - arr[x1 - 2][y2 - 1] << '\n';
        }
        else
        {
            cout << arr[x1 - 2][y1 - 2] - arr[x1 - 2][y2 - 1] - arr[x2 - 1][y1 - 2] + arr[x2 - 1][y2 - 1] << '\n';
        }
    }

    return 0;
}