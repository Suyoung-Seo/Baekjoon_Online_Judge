#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    N--;
    
    int result = 1;

    while (N > 0)
    {
        N -= result * 6;
        result++;
    }

    cout << result << '\n';

    return 0;
}

// endl -> '\n'