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
        string S;
        cin >> S;

        int result = 0;

        for (int j = 0; j < S.size(); j++)
        {
            int score = 1;
            while (S[j] == 'O')
            {
                result += score;
                score++;
                j++;
            }
        }

        cout << result << '\n';
    }

    return 0;
}

// endl -> '\n'