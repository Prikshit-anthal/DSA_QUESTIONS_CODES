class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int lh = 0, rh = 0;
        int x = findHeight(root);
        if (x == -1)
            return false;
        else
            return true;
    }

    int findHeight(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = findHeight(root->left);

        int rh = findHeight(root->right);

        if (lh == -1 || rh == -1)
            return -1;

        if (lh - rh > 1 || lh - rh < -1)
            return -1;

        if (lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }
};