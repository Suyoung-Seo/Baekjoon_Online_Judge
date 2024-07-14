#include <iostream>
#include <vector>
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
    int sum = 0;          // 산술평균
    int mode[8001] = {0}; // 최빈값

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        mode[arr[i] + 4000]++;
    }

    if (sum >= 0)
    {
        sum = (int)(((double)sum / (double)N) + 0.5); // 산술평균
    }
    else
    {
        sum = (int)(((double)sum / (double)N) - 0.5); // 산술평균
    }
    
    sort(arr, arr + N); // 중앙값, 범위

    cout << sum << '\n';
    cout << arr[N / 2] << '\n';

    int max = 0;
    vector<int> V;

    for (int i = 0; i < 8001; i++)
    {
        if (max < mode[i])
        {
            max = mode[i];
            V.clear();
            V.push_back(i - 4000);
        }
        else if (max == mode[i])
        {
            V.push_back(i - 4000);
        }
    }

    if (V.size() > 1)
    {
        cout << V[1] << '\n';
    }
    else
    {
        cout << V[0] << '\n';
    }

    cout << arr[N - 1] - arr[0] << '\n';

    return 0;
}

// endl -> '\n'