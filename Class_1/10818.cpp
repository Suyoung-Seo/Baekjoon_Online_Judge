#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    int min, max;
    cin >> min;
    max = min;

    for (int i = 1; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (min > temp)
        {
            min = temp;
        }
        if (max < temp)
        {
            max = temp;
        }
    }

    cout << min << ' ' << max << '\n';

    return 0;
}

// endl -> '\n'