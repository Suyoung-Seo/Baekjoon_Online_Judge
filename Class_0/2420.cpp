#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;

    cin >> N >> M;

    if (N - M >= 0)
    {
        cout << N - M << '\n';
    }
    else
    {
        cout << M - N << '\n';
    }
    
    return 0;
}

// endl -> '\n'