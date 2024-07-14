#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    int *arr = new int[N + 1];

    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        arr[i] = 0;
    }

    for (int i = 2; i <= sqrt(N); i++)  // N의 제곱근까지의 소수의 배수만 지우면 됨
    {
        if (arr[i] == 0)  // 소수(0)라면
        {
            for (int j = i + 1; j <= N; j++)  // 끝까지 확인
            {
                if (j % i == 0)  // 확인하여 배수(1)으로
                {
                    arr[j] = 1;
                }
            }
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (arr[i] == 0)
        {
            cout << i << '\n';
        }
    }

    return 0;
}

// endl -> '\n'