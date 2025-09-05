#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int val;
    node *left;
    node *right;

    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node *tree()
{

    int val;
    cin >> val;

    if (val == -1)
        return NULL;

    node *root = new node(val);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        node *leftN, *rightN;

        if (l == -1)
            leftN = NULL;
        else
            leftN = new node(l);

        if (r == -1)
            rightN = NULL;
        else
            rightN = new node(r);

        f->left = leftN;
        f->right = rightN;

        if (f->left)
        {
            q.push(leftN);
        }
        if (f->right)
        {
            q.push(rightN);
        }
    }
    return root;
}

void counter(node *root, map<int, int> &m)
{

    if (!root)
        return;
    if (!root->left && !root->right)
    {
        m[root->val]++;
        return;
    }
    counter(root->left, m);
    counter(root->right, m);
}

int main()
{

    node *root = tree();

    map<int, int> m;
    counter(root, m);

    int t = 0;
    int max = INT_MAX;

    for (auto x : m)
    {
        if (x.second > t || (x.second == max || x.first < max))
        {
            t = x.second;
            max = x.first;
        }
    }

    cout << max;

    return 0;
}
