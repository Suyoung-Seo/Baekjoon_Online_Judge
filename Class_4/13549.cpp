#include <iostream>
#include <deque>
using namespace std;

/*
1697과 달리 주의할 점
가중치가 다른 BFS이기 때문에 다이크스트라 알고리즘 또는 0-1 BFS를 사용해야 함.
가중치 그래프 최단 경로 = 다이크스트라 알고리즘 (일반적인 풀이법)

0-1 BFS (최적화된 풀이법) -> 가중치가 두 가지인 그래프에서 사용 가능 ->
하나의 가중치를 동일 레벨, 하나의 가중치를 하위 레벨로 둠 ->
Deque를 이용하여 동일 레벨을 front에 push 하도록, 하위 레벨을 back에 push하도록 하면 됨
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int arr[100001] = {0};
    arr[N] = 1;

    deque<int> dq;
    dq.push_back(N);

    while (!dq.empty())
    {
        int num = dq.front();
        dq.pop_front();

        if (num - 1 >= 0)
        {
            if (arr[num - 1] == 0 || arr[num - 1] > arr[num] + 1)
            {
                arr[num - 1] = arr[num] + 1;
                dq.push_back(num - 1);
            }
        }

        if (num + 1 <= 100000)
        {
            if (arr[num + 1] == 0 || arr[num + 1] > arr[num] + 1)
            {
                arr[num + 1] = arr[num] + 1;
                dq.push_back(num + 1);
            }
        }

        if (num * 2 <= 100000)
        {
            if (arr[num * 2] == 0 || arr[num * 2] > arr[num])
            {
                arr[num * 2] = arr[num];
                dq.push_front(num * 2);
            }
        }
    }

    cout << arr[K] - 1 << '\n';

    return 0;
}

// endl -> '\n'