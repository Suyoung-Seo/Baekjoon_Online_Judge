#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    cin >> K >> N;

    vector<unsigned int> V;

    for (int i = 0; i < K; i++)
    {
        unsigned int lan;
        cin >> lan;

        V.push_back(lan);
    }

    unsigned int start = 1, end = *max_element(V.begin(), V.end());

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int num = 0;
        
        for (int i = 0; i < K; i++)
        {
            num += V[i] / mid;
        }

        if (num >= N)
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