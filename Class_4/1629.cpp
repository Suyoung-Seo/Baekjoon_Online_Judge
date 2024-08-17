#include <iostream>
using namespace std;

long long mul(long long A, long long B, long long C)
{
    if (B == 1)
    {
        return A % C;
    }
    else
    {
        if (B % 2 == 0)
        {
            long long D = mul(A, B / 2, C);
            return (D * D) % C;
        }
        else
        {
            long long D = mul(A, (B - 1) / 2, C);
            return (((D * D) % C) * A) % C;
        }
    }
}

/*
분할 정복 -> 
A^N = A^(N/2) * A^(N/2) (N이 짝수)
A^N = A^(N/2) * A^(N/2) * A (N이 홀수)
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;

    /*
    분할 정복 없이 풀기 ->
    시간 초과 뜰듯.. ->
    계산해보면 약 20억 회 연산 ->
    2B ns -> 2M us -> 2K ms -> 2s -> 시간 초과!

        long long res = 1;

        for (int i = 0; i < B; i++)
        {
            res = (res * A) % C;
        }

        cout << res << '\n';
    */

    cout << mul(A, B, C) << '\n';

    return 0;
}