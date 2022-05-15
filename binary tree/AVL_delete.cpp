Node *findNode_del(Node *root, int V);
Node *minVal(Node *root);
int height(Node *node);
int getBalance(Node *node);
Node *rotateLeft(Node *Z);
Node *rotateRight(Node *Z);

Node *deleteNode(Node *root, int data)
{
    Node *find = findNode_del(root, data);
    //  cout<<data<<" d "<<endl;
    return find;
    // add code here,
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
                free(root);
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
        }
        else
        {
            Node *min = minVal(root->right);
            root->data = min->data;

            root->right = deleteNode(root->right, min->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    //   cout<<check<<" ";
    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node *rotateLeft(Node *Z)
{

    Node *temp = Z->right;
    Z->right = temp->left;
    temp->left = Z;
    // update height order matters coz z is under temp now
    Z->height = max(height(Z->left),
                    height(Z->right)) +
                1;
    temp->height = max(height(temp->left),
                       height(temp->right)) +
                   1;

    return temp;
}
Node *rotateRight(Node *Z)
{
    Node *temp = Z->left;
    Z->left = temp->right;
    temp->right = Z;

    // update height order matters coz z is under temp now
    Z->height = max(height(Z->left),
                    height(Z->right)) +
                1;
    temp->height = max(height(temp->left),
                       height(temp->right)) +
                   1;

    return temp;
}

int height(Node *node)
{
    if (node == NULL)
        return 0;

    else
        return node->height;
}

int getBalance(Node *node)
{
    int left = height(node->left);
    int right = height(node->right);
    return left - right;
}

Node *minVal(Node *root)
{
    if (root->left == NULL)
        return root;

    minVal(root->left);
}