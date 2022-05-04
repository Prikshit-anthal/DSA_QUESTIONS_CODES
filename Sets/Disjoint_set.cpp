#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> parent, rank;

public:
    void makeSet(int n)
    {
        for (int i = 0; i < n; i++)
            parent.push_back(i), rank.push_back(0);
    }

    int findParent(int v)
    {
        if (v == parent[v])
            return v;

        // compression done here
        return parent[v] = findParent(parent[v]);
    }

    void _union(int u, int v)
    {
        // imp parents find pehle then jodo
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (rank[uParent] > rank[vParent])
        {
            parent[vParent] = uParent;
        }
        else if (rank[vParent] > rank[uParent])
        {
            parent[uParent] = v;
        }
        else
        {
            parent[vParent] = uParent;
            rank[uParent]++; // rank increased here
        }
    }
};

int main()
{
    Solution obj;
    obj.makeSet(7);
    obj._union(0, 1);
    cout << obj.findParent(1);
    obj._union(1, 2);
    // obj._union(2,3);
    // cout << obj.findParent(3);

    obj._union(3, 4);
    obj._union(5, 6);
    cout << obj.findParent(6);

    obj._union(4, 5);
    cout << obj.findParent(5);
    cout << obj.findParent(3);

    obj._union(2, 6);
    return 0;
}