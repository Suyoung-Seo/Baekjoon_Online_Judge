#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int M, N, K;
        cin >> M >> N >> K;

        int **ground = new int *[N];
        for (int j = 0; j < N; j++)
        {
            ground[j] = new int[M];
        }

        for (int j = 0; j < N; j++)
        {
            for (int l = 0; l < M; l++)
            {
                ground[j][l] = 0;
            }
        }

        for (int j = 0; j < K; j++)
        {
            int X, Y;
            cin >> X >> Y;

            ground[Y][X] = 1;
        }

        stack<pair<int, int>> s;
        int worm = 0;

        for (int j = 0; j < N; j++)
        {
            for (int l = 0; l < M; l++)
            {
                if (ground[j][l] == 1)
                {
                    if (j != 0)
                    {
                        if (ground[j - 1][l] == 1)
                        {
                            s.push(make_pair(j - 1, l));
                        }
                    }

                    if (l != 0)
                    {
                        if (ground[j][l - 1] == 1)
                        {
                            s.push(make_pair(j, l - 1));
                        }
                    }

                    if (j != N - 1)
                    {
                        if (ground[j + 1][l] == 1)
                        {
                            s.push(make_pair(j + 1, l));
                        }
                    }

                    if (l != M - 1)
                    {
                        if (ground[j][l + 1] == 1)
                        {
                            s.push(make_pair(j, l + 1));
                        }
                    }

                    ground[j][l] = 2;
                    worm++;
                }

                while (!s.empty())
                {
                    int X, Y;
                    Y = s.top().first;
                    X = s.top().second;
                    s.pop();

                    if (ground[Y][X] == 1)
                    {
                        if (Y != 0)
                        {
                            if (ground[Y - 1][X] == 1)
                            {
                                s.push(make_pair(Y - 1, X));
                            }
                        }

                        if (X != 0)
                        {
                            if (ground[Y][X - 1] == 1)
                            {
                                s.push(make_pair(Y, X - 1));
                            }
                        }

                        if (Y != N - 1)
                        {
                            if (ground[Y + 1][X] == 1)
                            {
                                s.push(make_pair(Y + 1, X));
                            }
                        }

                        if (X != M - 1)
                        {
                            if (ground[Y][X + 1] == 1)
                            {
                                s.push(make_pair(Y, X + 1));
                            }
                        }

                        ground[Y][X] = 2;
                    }
                }
            }
        }

        cout << worm << '\n';
    }

    return 0;
}

// endl -> '\n'