#include <iostream>
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
        int H, W, N;
        cin >> H >> W >> N;

        // ((N - 1) / H) + 1 -> 호수, (N - 1) % H + 1 -> 층수
        cout << (N - 1) % H + 1;
        if (((N - 1) / H) + 1 < 10)
        {
            cout << 0 << ((N - 1) / H) + 1 << '\n';
        }
        else
        {
            cout << ((N - 1) / H) + 1 << '\n';
        }
    }

    return 0;
}

// endl -> '\n'