#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
void print_node(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " (l-> ";
    print_node(node->left);
    cout << ") (r-> ";
    print_node(node->right);
    cout << ") ";
}

//NO NEED FOR NODES LIKE I USED HERE
//BETTER APPROACH IN second file
class Solution
{
    Node *unbal_occur_z_p = NULL;
    Node *unbal_occur_z = NULL;
    Node *unbal_occur_y = NULL;
    Node *unbal_occur_x = NULL;
    bool unbal_found = false;
    bool can_add_z_p = false;

public:
    /*You are required to complete this method */
    Node *
    insertToAVL(Node *node, int data)
    {
        // Your code here
        //  if(node==NULL)cout<<"NULL";
        // isert in bst and find z,y,x
        node = insertBST(node, data);

        // if (unbal_occur_x != NULL)
        //     cout << unbal_occur_x->data << " x ";
        // if (unbal_occur_y != NULL)
        //     cout << unbal_occur_y->data << " y ";
        // if (unbal_occur_z_p != NULL)
        //     cout << unbal_occur_z_p->data << endl;
        // cout << "unbal found " << unbal_found << endl;

        if (unbal_occur_x != NULL && unbal_occur_y != NULL && unbal_occur_z != NULL && unbal_found)
        {
            // cout << "doing rotation ";
            // now re-balance using rotations
            node = rotate(node);

            // check if balanced now
            //  if(findBalanced(node)==-1)
            //  cout<<" unbalanced ";
            //  else cout<<" Balanced ";
        }

        unbal_occur_z_p = NULL;
        unbal_occur_z = NULL;
        unbal_occur_y = NULL;
        unbal_occur_x = NULL;
        unbal_found = false;
        can_add_z_p = false;

        return node;
    }

    Node *rotate(Node *node)
    {
        char p;
        if (unbal_occur_z_p == NULL)
            p = 'n';
        else if (unbal_occur_z_p->left == unbal_occur_z)
            p = 'l';
        else
            p = 'r';

        if (unbal_occur_z->left == unbal_occur_y)
        {
            // left left
            if (unbal_occur_y->left == unbal_occur_x)
            {
                unbal_occur_z = rotateHelper(unbal_occur_z, unbal_occur_y, true);
            }
            // left right
            else if (unbal_occur_y->right == unbal_occur_x)
            {
                // left rotate y
                unbal_occur_z->left = rotateHelper(unbal_occur_y, unbal_occur_x, false);

                // right rotate x
                unbal_occur_z = rotateHelper(unbal_occur_z, unbal_occur_x, true);
            }
        }
        else if (unbal_occur_z->right == unbal_occur_y)
        {
            // right right
            if (unbal_occur_y->right == unbal_occur_x)
            {
                unbal_occur_z = rotateHelper(unbal_occur_z, unbal_occur_y, false);
            }
            // right left
            else if (unbal_occur_y->left == unbal_occur_x)
            {
                // right rotate y
                unbal_occur_z->right = rotateHelper(unbal_occur_y, unbal_occur_x, true);
                // left rotate x
                unbal_occur_z = rotateHelper(unbal_occur_z, unbal_occur_x, false);
            }
        }

        if (p == 'l')
            unbal_occur_z_p->left = unbal_occur_z;
        else if (p == 'r')
            unbal_occur_z_p->right = unbal_occur_z;
        else
            node = unbal_occur_z;

        // print_node(node);
        // cout << endl;
        return node;
    }

    Node *rotateHelper(Node *a, Node *b, bool r_l)
    {
        if (r_l) // right rotate
        {
            a->left = b->right;
            b->right = a;
            return b;
        }
        else
        { // left rotate
            a->right = b->left;
            b->left = a;
            return b;
        }
    }

    Node *insertBST(Node *node, int data)
    {
        if (node == NULL)
        {
            node = (struct Node *)malloc(sizeof(struct Node));
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            node->height = 1;
            // cout << endl
            //      << " add " << data << endl;
            unbal_occur_x = node;

            return node;
        }
        else if (data < node->data)
        {
            node->left = insertBST(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insertBST(node->right, data);
        }

        // just added data to child
        if (unbal_occur_y == NULL)
        {
            unbal_occur_y = node;
        }

        // y hai z nai hai
        else if (unbal_occur_z == NULL)
        {
            unbal_occur_z = node;
            if (findBalanced(node) == -1)
            {
                unbal_found = true;
                can_add_z_p = true;
                return node;
            }
        }

        // sb hai now sliding up the tree
        else if (!unbal_found)
        {
            unbal_occur_x = unbal_occur_y;
            unbal_occur_y = unbal_occur_z;
            unbal_occur_z = node;
            if (findBalanced(node) == -1)
            {
                unbal_found = true;
                can_add_z_p = true;
                return node;
            }
        }

        if (can_add_z_p)
        {
            unbal_occur_z_p = node;
            can_add_z_p = false;
        }

        return node;
    }

    int findBalanced(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = findBalanced(root->left);

        int rh = findBalanced(root->right);

        if (lh == -1 || rh == -1)
            return -1;

        if (lh - rh > 1 || lh - rh < -1)
        {
            return -1;
        }

        if (lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }
};

int main()
{
    int arr[] = {984 ,286 ,587 ,377, 286};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    Node *node = NULL;
    for (int i = 0; i < n; i++)
    {
        node = obj.insertToAVL(node, arr[i]);
        cout << "itr  :  " << i << endl;
        print_node(node);
    }
    cout << obj.findBalanced(node);
}