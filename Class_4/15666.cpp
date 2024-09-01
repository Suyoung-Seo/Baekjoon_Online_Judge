#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void dfs(int N, int M, int depth, int *arr, int *num, set<vector<int>> *st, int current)
{
    if (depth == M) // 수열의 크기가 M인 경우 수열 출력 후 위로 올라감
    {
        vector<int> v;
        for (int i = 0; i < M; i++)
        {
            v.push_back(arr[i]);
        }

        st->insert(v);
    }
    else
    {
        for (int i = current; i <= N; i++)
        {
            arr[depth] = num[i];                // 숫자 수열에 넣고 방문 체크
            dfs(N, M, depth + 1, arr, num, st, i); // 다음 경우의 수 dfs 탐색
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

15649에서 1~N이 아닌 N개의 자연수 -> 정렬 후 하면 가능
15654에서 중복 포함 수 입력 -> 세트 사용하기
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int *num = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
    }

    sort(num + 1, num + (N + 1));

    int *arr = new int[M];

    for (int i = 0; i < M; i++)
    {
        arr[i] = 0;
    }

    set<vector<int>> *st = new set<vector<int>>;

    dfs(N, M, 0, arr, num, st, 1);

    for (set<vector<int>>::iterator iter = st->begin(); iter != st->end(); iter++) // 세트 반복자로 세트 처음부터 끝까지 순회
    {
        for (int i = 0; i < iter->size(); i++)
        {
            cout << iter->at(i) << ' ';
        }
        cout << '\n';
    }

    return 0;
}