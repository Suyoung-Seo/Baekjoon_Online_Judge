#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int **RGB = new int *[N];

    for (int i = 0; i < N; i++)
    {
        RGB[i] = new int[3];
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }

    // 같은 색을 제외한 모든 색에 비용을 더한 값의 최솟값을 구하면 N-1의 비용 중 최솟값이 정답
    for (int i = 1; i < N; i++)
    {
        int r = RGB[i][0], g = RGB[i][1], b = RGB[i][2];

        RGB[i][1] = RGB[i - 1][0] + g;
        RGB[i][2] = RGB[i - 1][0] + b;
        RGB[i][0] = RGB[i - 1][1] + r;

        if (RGB[i][2] > RGB[i - 1][1] + b)
        {
            RGB[i][2] = RGB[i - 1][1] + b;
        }

        if (RGB[i][0] > RGB[i - 1][2] + r)
        {
            RGB[i][0] = RGB[i - 1][2] + r;
        }

        if (RGB[i][1] > RGB[i - 1][2] + g)
        {
            RGB[i][1] = RGB[i - 1][2] + g;
        }
    }

    int min = RGB[N - 1][0];

    for (int i = 1; i < 3; i++)
    {
        if (min > RGB[N - 1][i])
        {
            min = RGB[N - 1][i];
        }
    }

    cout << min << '\n';

    return 0;
}