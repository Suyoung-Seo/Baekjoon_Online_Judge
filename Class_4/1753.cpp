#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 개수, 에지 개수, 시작 노드 설정
    int V, E, K;
    cin >> V >> E >> K;

    // 인접 리스트 초기화
    vector<pair<int, int>> *adjust = new vector<pair<int, int>>[V + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adjust[u].push_back(make_pair(v, w));
    }

    // 최단 거리 테이블
    int *distance = new int[V + 1];

    for (int i = 1; i <= V; i++)
    {
        distance[i] = INF;
    }
    distance[K] = 0;

    // 우선순위 큐로 다익스트라 알고리즘 구현
    priority_queue<pair<int, int>> pq; // pair의 first 기준 내림차순 정렬

    pq.push(make_pair(0, K)); // K에 대해서 방문 처리 -> 테이블 갱신

    while (!pq.empty())
    {
        // 우선순위 큐에서 가장 
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        // 현재 코스트보다 최단 경로의 코스트가 더 낮을 때 넘기기
        if (distance[cur] < cost)
        {
            continue;
        }

        // 현재 노드의 인접 노드 모두 확인
        for (int i = 0; i < adjust[cur].size(); i++)
        {
            int adCost = cost + adjust[cur][i].second; // 인접 노드의 코스트 = 코스트 + 현재 노드의 코스트

            if (adCost < distance[adjust[cur][i].first]) // 인접 노드의 코스트가 기존 최단 경로 테이블의 코스트보다 낮으면 업데이트 후 우선순위 큐에 음수로 push
            {
                distance[adjust[cur][i].first] = adCost;
                pq.push(make_pair(-adCost, adjust[cur][i].first));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (distance[i] == INF)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << distance[i] << '\n';
        }
    }

    return 0;
}