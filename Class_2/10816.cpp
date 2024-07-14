#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    map<int, int> num_list;
    
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num_list.find(num) != num_list.end())
        {
            num_list[num]++;
        }
        else
        {
            num_list.insert({num, 1});
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        if (num_list.find(num) != num_list.end())
        {
            cout << num_list[num] << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }
    cout << '\n';


    return 0;
}

// endl -> '\n'