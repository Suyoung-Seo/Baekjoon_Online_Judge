#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T, P;
    int size[6];

    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> size[i];
    }
    cin >> T >> P;

    int result = 0;
    
    for (int i = 0; i < 6; i++)
    {
        if (size[i] % T == 0)
        {
            result += size[i] / T;
        }
        else
        {
            result += size[i] / T + 1;
        }
    }

    cout << result << '\n';
    cout << N / P << ' ' << N % P << '\n';

    return 0;
}

// endl -> '\n'