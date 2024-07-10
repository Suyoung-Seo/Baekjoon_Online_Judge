#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    int *A = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        cin >> *(A + i);
    }

    int v, result = 0;
    
    cin >> v;

    for (int i = 0; i < N; i++)
    {
        if (*(A + i) == v)
        {
            result++;
        }
    }

    cout << result << '\n';

    free(A);

    return 0;
}

// endl -> '\n'