#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 초기화 (0번째)
    int max[3], min[3];
    cin >> max[0] >> max[1] >> max[2];
    min[0] = max[0];
    min[1] = max[1];
    min[2] = max[2];

    // DP
    for (int i = 1; i < N; i++)
    {
        int val0, val1, val2, res0, res1, res2;
        cin >> val0 >> val1 >> val2;

        if (max[0] >= max[1])
        {
            res0 = val0 + max[0];
        }
        else
        {
            res0 = val0 + max[1];
        }

        if (max[0] >= max[1] && max[0] >= max[2])
        {
            res1 = val1 + max[0];
        }
        else if (max[1] >= max[0] && max[1] >= max[2])
        {
            res1 = val1 + max[1];
        }
        else if (max[2] >= max[0] && max[2] >= max[1])
        {
            res1 = val1 + max[2];
        }

        if (max[1] >= max[2])
        {
            res2 = val2 + max[1];
        }
        else
        {
            res2 = val2 + max[2];
        }

        max[0] = res0;
        max[1] = res1;
        max[2] = res2;

        if (min[0] <= min[1])
        {
            res0 = val0 + min[0];
        }
        else
        {
            res0 = val0 + min[1];
        }

        if (min[0] <= min[1] && min[0] <= min[2])
        {
            res1 = val1 + min[0];
        }
        else if (min[1] <= min[0] && min[1] <= min[2])
        {
            res1 = val1 + min[1];
        }
        else if (min[2] <= min[0] && min[2] <= min[1])
        {
            res1 = val1 + min[2];
        }

        if (min[1] <= min[2])
        {
            res2 = val2 + min[1];
        }
        else
        {
            res2 = val2 + min[2];
        }

        min[0] = res0;
        min[1] = res1;
        min[2] = res2;
    }

    int maxval = max[0], minval = min[0];

    for (int i = 1; i < 3; i++)
    {
        if (maxval <= max[i])
        {
            maxval = max[i];
        }

        if (minval >= min[i])
        {
            minval = min[i];
        }
    }

    cout << maxval << ' ' << minval << '\n';

    return 0;
}