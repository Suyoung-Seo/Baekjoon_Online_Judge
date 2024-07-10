#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;

    cin >> N >> X;

    int *A = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        cin >> *(A + i);
        if (*(A + i) < X)
        {
            cout << *(A + i) << ' ';
        }
    }

    cout << '\n';

    free(A);

    return 0;
}

// endl -> '\n'