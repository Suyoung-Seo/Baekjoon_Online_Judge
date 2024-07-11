#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    int x = A * B * C;
    int arr[10] = {0};

    while (x != 0)
    {
        arr[x % 10]++;
        x /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << '\n';
    }

    return 0;
}

// endl -> '\n'