#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    int **A = (int **)malloc(sizeof(int *) * N);
    int **B = (int **)malloc(sizeof(int *) * N);

    for (int i = 0; i < N; i++)
    {
        *(A + i) = (int *)malloc(sizeof(int) * M);
        *(B + i) = (int *)malloc(sizeof(int) * M);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> *(*(A + i) + j);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> *(*(B + i) + j);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << *(*(A + i) + j) + *(*(B + i) + j) << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < N; i++)
    {
        free(*(A + i));
        free(*(B + i));
    }

    free(A);
    free(B);

    return 0;
}

// endl -> '\n'