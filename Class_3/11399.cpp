#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int sum = arr[0];
    for (int i = 1; i < N; i++)
    {
        arr[i] += arr[i - 1];
        sum += arr[i];
    }

    cout << sum << '\n';

    return 0;
}

// endl -> '\n'