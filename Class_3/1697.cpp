#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int arr[100001] = {0};
    arr[N] = 1;

    queue<int> q;
    q.push(N);

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        if (num - 1 >= 0)
        {
            if (arr[num - 1] == 0 || arr[num - 1] > arr[num] + 1)
            {
                arr[num - 1] = arr[num] + 1;
                q.push(num - 1);
            }
        }

        if (num + 1 <= 100000)
        {
            if (arr[num + 1] == 0 || arr[num + 1] > arr[num] + 1)
            {
                arr[num + 1] = arr[num] + 1;
                q.push(num + 1);
            }
        }

        if (num * 2 <= 100000)
        {
            if (arr[num * 2] == 0 || arr[num * 2] > arr[num] + 1)
            {
                arr[num * 2] = arr[num] + 1;
                q.push(num * 2);
            }
        }
    }

    cout << arr[K] - 1 << '\n';

    return 0;
}

// endl -> '\n'