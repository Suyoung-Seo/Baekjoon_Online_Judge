#include <iostream>
using namespace std;

/*
LIS 알고리즘으로 풀어야 함 -> DP

LIS 알고리즘 ->
현재 원소의 값보다 작은 이전 원소들의 LIS의 최댓값 + 1이 LIS의 길이 ->
현재 원소에서 끝나는 최장 수열은 현재 원소가 최댓값이기 때문 ->
따라서 최장 수열을 구하기 위해 이전 최장 수열의 길이를 사용
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *A = new int[N];
    int *DP = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    DP[0] = 1;

    for (int i = 1; i < N; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                if (max < DP[j])
                {
                    max = DP[j]; // 현재 원소(i)의 값보다 작은 이전 원소(j)의 최장 수열 길이(DP)의 최댓값 구하기
                }
            }
        }
        DP[i] = max + 1;  // 최댓값+1이 현재 원소의 최장 수열의 길이
    }

    int max = 0;  // 전체 최장 수열의 최댓값 찾기
    for (int i = 0; i < N; i++)
    {
        if (max < DP[i])
        {
            max = DP[i];
        }
    }

    cout << max << '\n';

    return 0;
}