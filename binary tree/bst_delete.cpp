Node *findNode_del(Node *root, int V);
Node *minVal(Node *root);

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X)
{
    // your code goes here
    Node *find = findNode_del(root, X);
    return find;
}

Node *findNode_del(Node *root, int V)
{
    if (root == NULL)
        return root;

    else if (root->data < V)
        root->right = findNode_del(root->right, V);

    else if (root->data > V)
        root->left = findNode_del(root->left, V);

    else
    {

        if (root->left == NULL || root->right == NULL)
        {
            Node *temp;
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if (root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }

            *root = *temp;
            free(temp);
            return root;
        }
        else
        {
            Node *min = minVal(root->right);
            root->data = min->data;

            root->right = deleteNode(root->right, min->data);
        }
    }

    return root;
}
Node *minVal(Node *root)
{
    if (root->left == NULL)
        return root;

    minVal(root->left);
}