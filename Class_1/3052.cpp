#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[42] = {0};

    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;
        arr[num % 42]++;
    }

    int result = 0;

    for (int i = 0; i < 42; i++)
    {
        if (arr[i] > 0)
        {
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}

// endl -> '\n'