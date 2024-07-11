#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B, C;
    cin >> A >> B >> C;

    cout << stoi(A) + stoi(B) - stoi(C) << '\n';
    cout << stoi(A.append(B)) - stoi(C) << '\n';

    return 0;
}

// endl -> '\n'