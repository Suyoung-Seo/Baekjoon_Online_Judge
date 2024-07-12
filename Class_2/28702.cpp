#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    int i;

    if (a[0] >= 48 && a[0] <= 57)
    {
        i = stoi(a) + 3;
    }
    else if (b[0] >= 48 && b[0] <= 57)
    {
        i = stoi(b) + 2;
    }
    else if (c[0] >= 48 && c[0] <= 57)
    {
        i = stoi(c) + 1;
    }

    if (i % 3 == 0 && i % 5 == 0)
    {
        cout << "FizzBuzz" << '\n';
    }
    else if (i % 3 == 0)
    {
        cout << "Fizz" << '\n';
    }
    else if (i % 5 == 0)
    {
        cout << "Buzz" << '\n';
    }
    else
    {
        cout << i << '\n';
    }

    return 0;
}

// endl -> '\n'