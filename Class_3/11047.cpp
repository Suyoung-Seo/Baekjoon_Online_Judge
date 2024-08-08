#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int *arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int idx = N - 1;
    int coin = 0;

    while (K != 0)
    {
        int num = K / arr[idx];  // 동전 개수

        K -= num * arr[idx];
        idx--;
        coin += num;
    }

    cout << coin << '\n';

    return 0;
}

// endl -> '\n'