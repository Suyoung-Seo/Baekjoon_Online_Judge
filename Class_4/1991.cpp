#include <iostream>
using namespace std;

void preorder(pair<int, int> *adjust, int cur)
{
    cout << (char)((char)cur + 'A');

    if (adjust[cur].first != -1)
    {
        preorder(adjust, adjust[cur].first);
    }

    if (adjust[cur].second != -1)
    {
        preorder(adjust, adjust[cur].second);
    }
}

void inorder(pair<int, int> *adjust, int cur)
{
    if (adjust[cur].first != -1)
    {
        inorder(adjust, adjust[cur].first);
    }

    cout << (char)((char)cur + 'A');

    if (adjust[cur].second != -1)
    {
        inorder(adjust, adjust[cur].second);
    }
}

void postorder(pair<int, int> *adjust, int cur)
{
    if (adjust[cur].first != -1)
    {
        postorder(adjust, adjust[cur].first);
    }

    if (adjust[cur].second != -1)
    {
        postorder(adjust, adjust[cur].second);
    }

    cout << (char)((char)cur + 'A');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 개수
    int N;
    cin >> N;

    pair<int, int> *adjust = new pair<int, int>[N];

    for (int i = 0; i < N; i++)
    {
        char p, l, r;
        cin >> p >> l >> r;

        if (l != '.')
        {
            adjust[(int)p - (int)('A')].first = (int)l - (int)('A');
        }
        else
        {
            adjust[(int)p - (int)('A')].first = -1;
        }

        if (r != '.')
        {
            adjust[(int)p - (int)('A')].second = (int)r - (int)('A');
        }
        else
        {
            adjust[(int)p - (int)('A')].second = -1;
        }
    }

    preorder(adjust, 0);
    cout << '\n';

    inorder(adjust, 0);
    cout << '\n';

    postorder(adjust, 0);
    cout << '\n';

    return 0;
}