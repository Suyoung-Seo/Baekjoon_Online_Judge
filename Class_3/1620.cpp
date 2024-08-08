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

    map<string, int> name_num;
    map<int, string> num_name;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        name_num.insert(make_pair(s, i + 1));
        num_name.insert(make_pair(i + 1, s));
    }

    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))
        {
            cout << name_num[s] << '\n';
        }
        else if (s[0] >= '0' && s[0] <= '9')
        {
            cout << num_name[stoi(s)] << '\n';
        }
    }

    return 0;
}

// endl -> '\n'