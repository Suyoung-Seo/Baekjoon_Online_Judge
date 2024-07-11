#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int *card = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        cin >> *(card + i);
    }

    int result = 0;

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (result < (*(card + i) + *(card + j) + *(card + k)) && (*(card + i) + *(card + j) + *(card + k)) <= M)
                {
                    result = *(card + i) + *(card + j) + *(card + k);
                }
            }
        }
    }

    cout << result << '\n';

    free(card);

    return 0;
}

// endl -> '\n'