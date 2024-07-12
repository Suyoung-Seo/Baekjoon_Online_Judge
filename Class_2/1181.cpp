#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int series = 666;
    while (N != 0)
    {
        while (true)
        {
            int temp = series;
            bool br = false;

            while (temp != 0)
            {
                if (temp % 1000 == 666)
                {
                    br = true;
                    break;
                }
                temp /= 10;
            }

            if (br)
            {
                break;
            }
            series++;
        }

        N--;
        series++;
    }

    cout << series - 1 << '\n';

    return 0;
}

// endl -> '\n'