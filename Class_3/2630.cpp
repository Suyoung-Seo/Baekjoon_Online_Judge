#include <iostream>
using namespace std;

int white = 0, blue = 0;

void divide(int **arr, int N, int x, int y)
{
    // 영역의 수가 모두 동일한 지 확인
    bool isSame = true;
    for (int i = x; i < N + x; i++)
    {
        for (int j = y; j < N + y; j++)
        {
            if (arr[x][y] != arr[i][j])
            {
                isSame = false;
                break;
            }
        }

        if (isSame == false)
        {
            break;
        }
    }

    // 동일하면 수에 따라 white, blue 증가, 동일하지 않으면 분할
    if (isSame == true)
    {
        if (arr[x][y] == 0)
        {
            white++;
        }
        else
        {
            blue++;
        }
    }
    else
    {
        divide(arr, N / 2, x, y);
        divide(arr, N / 2, x, y + N / 2);
        divide(arr, N / 2, x + N / 2, y);
        divide(arr, N / 2, x + N / 2, y + N / 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int **arr = new int *[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    divide(arr, N, 0, 0);

    cout << white << '\n' << blue << '\n';

    return 0;
}

// endl -> '\n'