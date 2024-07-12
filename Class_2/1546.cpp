#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *arr = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        cin >> *(arr + i);
    }

    int max = *arr;

    for (int i = 1; i < N; i++)
    {
        if (max < *(arr + i))
        {
            max = *(arr + i);
        }
    }

    double average = 0;

    for (int i = 0; i < N; i++)
    {
        average += (double)*(arr + i) / (double)max * 100;
    }

    average /= (double)N;

    cout << average << '\n';

    free(arr);

    return 0;
}

// endl -> '\n'