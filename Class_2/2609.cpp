#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    if (A < B)
    {
        int temp = A;
        A = B;
        B = temp;
    }

    // 유클리드 호제법
    int AB = A * B;
    while (A % B != 0)
    {
        int temp = A % B;
        A = B;
        B = temp;
    }

    cout << B << '\n';
    cout << AB / B << '\n';

/* brute force
    int div;

    for (int i = 1; i <= B; i++)
    {
        if (A % i == 0 && B % i == 0)
        {
            div = i;
        }
    }

    cout << div << '\n';
    cout << (A / div) * (B / div) * div << '\n';
*/

    return 0;
}

// endl -> '\n'