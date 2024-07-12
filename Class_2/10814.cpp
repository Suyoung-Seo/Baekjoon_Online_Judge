#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, string> p1, pair<int, string> p2)
{
    return p1.first < p2.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int, string>> V;

    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        V.push_back(make_pair(age, name));
    }

    stable_sort(V.begin(), V.end(), comp);

    for (int i = 0; i < N; i++)
    {
        cout << V[i].first << ' ' << V[i].second << '\n';
    }

    return 0;
}

// endl -> '\n'