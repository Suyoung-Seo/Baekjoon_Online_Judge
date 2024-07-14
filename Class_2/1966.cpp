#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;  // 테스트 케이스 입력

    for (int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N >> M;  // 문서 개수, 인쇄 순서가 궁금한 작업

        queue<pair<int, int>> Q;

        for (int j = 0; j < N; j++)  // 우선 순위 입력
        {
            int priorty;
            cin >> priorty;
            Q.push(make_pair(priorty, j));
        }

        int print = 1;

        while (!Q.empty())
        {
            pair<int, int> p = Q.front();
            Q.pop();

            bool is_max = true;
            for (int k = 0; k < Q.size(); k++)
            {
                if (p.first < Q.front().first)
                {
                    is_max = false;
                }
                Q.push(Q.front());
                Q.pop();
            }

            if (!is_max)
            {
                Q.push(p);
            }
            else
            {
                if (p.second == M)
                {
                    break;
                }
                else
                {
                    print++;
                }
            }
        }

        cout << print << '\n';
    }

    return 0;
}

// endl -> '\n'