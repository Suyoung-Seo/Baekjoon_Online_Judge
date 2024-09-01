#include <iostream>
using namespace std;

void dfs(int N, int M, int depth, int *arr, int current)
{
    if (depth == M) // 수열의 크기가 M인 경우 수열 출력 후 위로 올라감
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int i = current; i <= N; i++)
        {
            arr[depth] = i;               // 숫자 수열에 넣고 방문 체크
            dfs(N, M, depth + 1, arr, i); // 다음 경우의 수 dfs 탐색
        }
    }
}

/*
알고리즘 ->
처음 생각한 거 (각 숫자마다 O, X로 나누어서 상태공간트리 그리기) ->
실제로 푼 방법 (1에서 시작하여 모든 숫자를 유망성 검증하여 백트래킹) ->
이게 더 쉬운 방법이라 그런듯?

1. 1부터 N까지 방문 여부 검사 후 방문하지 않은 숫자를 수열에 삽입
2. 삽입 이후 경우의 수를 dfs를 이용하여 확인
3. 수열의 크기가 M일 경우 수열 출력 후 하위 경우를 배제

필요한거 -> N, M, 방문여부 배열, 현재 수열 배열

15649에서 오름차순만 체크 -> 추가 매개변수 사용 -> 현재 dfs에서 넣은 숫자 체크
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int *arr = new int[M];

    for (int i = 0; i < M; i++)
    {
        arr[i] = 0;
    }

    dfs(N, M, 0, arr, 1);

    return 0;
}