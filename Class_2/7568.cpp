#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> W, H;

    for (int i = 0; i < N; i++)
    {
        int w, h;
        cin >> w >> h;

        W.push_back(w);
        H.push_back(h);
    }

    for (int i = 0; i < N; i++)
    {
        int lv = 1;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (W[i] < W[j] && H[i] < H[j])
            {
                lv++;
            }
        }
        cout << lv << '\n';
    }

    return 0;
}

// endl -> '\n'