#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n1, n2, ascend;
    cin >> n1 >> n2;

    if (n1 < n2)
    {
        ascend = 1;
    }
    else
    {
        ascend = 0;
    }

    n1 = n2;
    
    for (int i = 0; i < 6; i++)
    {
        cin >> n2;

        if (ascend == 1 && n1 > n2)
        {
            ascend = -1;
            break;
        }
        else if (ascend == 0 && n1 < n2)
        {
            ascend = -1;
            break;
        }

        n1 = n2;
    }

    if (ascend == 1)
    {
        cout << "ascending" << '\n';
    }
    else if (ascend == 0)
    {
        cout << "descending" << '\n';
    }
    else
    {
        cout << "mixed" << '\n';
    }

    return 0;
}

// endl -> '\n'