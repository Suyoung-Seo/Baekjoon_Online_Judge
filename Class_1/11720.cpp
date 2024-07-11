#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string num;
    cin >> num;

    int result = 0;

    for (int i = 0; i < num.size(); i++)
    {
        result += ((int)num[i] - 48);
    }

    cout << result << '\n';

    return 0;
}

// endl -> '\n'