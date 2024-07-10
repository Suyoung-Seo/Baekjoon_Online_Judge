#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, D, E;

    cin >> A >> B >> C >> D >> E;

    cout << (A * A + B * B + C * C + D * D + E * E) % 10 << '\n';

    return 0;
}

// endl -> '\n'