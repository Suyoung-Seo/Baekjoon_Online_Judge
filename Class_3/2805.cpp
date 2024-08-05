#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;

    vector<long long> V;

    for (long long i = 0; i < N; i++)
    {
        long long tree;
        cin >> tree;

        V.push_back(tree);
    }

    long long start = 0, end = *max_element(V.begin(), V.end());

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long num = 0;
        
        for (long long i = 0; i < N; i++)
        {
            if (V[i] - mid > 0)
            {
                num += V[i] - mid;
            }
        }

        if (num >= M)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

    }

    cout << end << '\n';

    return 0;
}

// endl -> '\n'