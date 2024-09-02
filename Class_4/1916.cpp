#include <iostream>
using namespace std;

#define INF 1000000000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 인접 행렬 초기화
    int **adjust = new int *[N + 1];
    for (int i = 1; i <= N; i++)
    {
        adjust[i] = new int[N + 1];
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                adjust[i][j] = 0;
            }
            else
            {
                adjust[i][j] = INF;
            }
        }
    }

    // 인접 행렬 입력
    for (int i = 0; i < M; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;

        if (adjust[start][end] > cost)
        {
            adjust[start][end] = cost;
        }
    }

    // 다이크스트라
    int start, end; // 출발 노드, 도착 노드
    cin >> start >> end;

    int *distance = new int[N + 1]; // 최단 거리 테이블, 방문 여부
    bool *visited = new bool[N + 1];

    for (int i = 1; i <= N; i++) // 방문 처리 -> 테이블 갱신 -> 최솟값 찾기 (start)
    {
        distance[i] = adjust[start][i];
        visited[i] = false;
    }
    visited[start] = true;


    for (int a = 0; a < N - 1; a++)
    {
        int idx, min = INF; // 최솟값 찾기
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == false)
            {
                if (distance[i] < min)
                {
                    min = distance[i];
                    idx = i;
                }
            }
        }

        visited[idx] = true; // 방문 처리

        for (int i = 1; i <= N; i++) // 테이블 갱신
        {
            if (visited[i] == false)
            {
                if (distance[i] > distance[idx] + adjust[idx][i])
                {
                    distance[i] = distance[idx] + adjust[idx][i];
                }
            }
        }
    }

    cout << distance[end] << '\n';

    return 0;
}