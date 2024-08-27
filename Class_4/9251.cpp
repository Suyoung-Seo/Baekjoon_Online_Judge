#include <iostream>
using namespace std;

/*
LCS 알고리즘으로 풀어야 함 -> DP

LCS 알고리즘 -> 2차원 배열 사용 -> 두 문자열의 부분 문자열을 모두 비교하여 최장 부분 문자열 찾기

두 문자열의 문자 비교 ->
같으면 각 이전 문자까지의 문자열 LCS의 값에서 +1 ->
다르면 첫 번째 문자열의 현재 문자를 제외한 문자열과 두 번째 문자열을 비교한 최장 부분 문자열, 두 번째도 동일 ->
둘 중 큰 값으로 설정

점화식 ->
1. 같은 경우 -> DP[i - 1][j - 1] + 1
2. 다른 경우 -> MAX(DP[i - 1][j], DP[i][j - 1])
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int max = 0;

    int **DP = new int *[str2.size() + 1];

    for (int i = 0; i <= str2.size(); i++)
    {
        DP[i] = new int[str1.size() + 1];

        for (int j = 0; j <= str1.size(); j++)
        {
            if (i == 0 || j == 0) // 초기화
            {
                DP[i][j] = 0;
            }
            else
            {
                if (str1[j - 1] == str2[i - 1]) // 같은 경우
                {
                    DP[i][j] = DP[i - 1][j - 1] + 1;

                    if (max < DP[i][j])
                    {
                        max = DP[i][j];
                    }
                }
                else // 다른 경우
                {
                    if (DP[i - 1][j] > DP[i][j - 1]) // MAX
                    {
                        DP[i][j] = DP[i - 1][j];

                        if (max < DP[i][j])
                        {
                            max = DP[i][j];
                        }
                    }
                    else
                    {
                        DP[i][j] = DP[i][j - 1];

                        if (max < DP[i][j])
                        {
                            max = DP[i][j];
                        }
                    }
                }
            }
        }
    }

    cout << max << '\n';

    return 0;
}