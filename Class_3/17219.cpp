#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, string> site;

    for (int i = 0; i < N; i++)
    {
        string addr, pass;
        cin >> addr >> pass;

        site.insert(make_pair(addr, pass));
    }

    for (int i = 0; i < M; i++)
    {
        string addr;
        cin >> addr;

        cout << site[addr] << '\n';
    }

    return 0;
}

// endl -> '\n'