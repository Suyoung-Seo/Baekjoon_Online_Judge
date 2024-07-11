#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int result = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 1)
        {
            continue;
        }

        bool isPrime = true;

        for (int j = 2; j < num; j++)
        {
            if (num % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        result += (int)isPrime;
    }

    cout << result << '\n';

    return 0;
}

// endl -> '\n'