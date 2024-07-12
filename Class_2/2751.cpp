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

    vector<int> A;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        A.push_back(num);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << '\n';
    }

    return 0;
}

// endl -> '\n'