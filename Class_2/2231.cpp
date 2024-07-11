#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int result = 0;
    for (int i = 1; i < N; i++)
    {
        int sum = i;
        int temp = i;
        while (temp != 0)  // 분해합 계산
        {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N)  // i의 분해합이 N과 같다면
        {
            result = i;
            break;
        }
    }

    cout << result << '\n';

    return 0;
}

// endl -> '\n'