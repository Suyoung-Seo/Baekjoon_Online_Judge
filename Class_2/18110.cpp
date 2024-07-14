#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int percent = (int)((double)n * 0.15 + 0.5);
    int average = 0;

    for (int i = percent; i < n - percent; i++)
    {
        average += arr[i];
    }

    average = (int)((double)average / (n - percent * 2) + 0.5);

    cout << average << '\n';

    return 0;
}

// endl -> '\n'