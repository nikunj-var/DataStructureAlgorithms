#include <iostream>
using namespace std;

struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

struct bstnode *insert(struct bstnode *root, int item)
{
    struct bstnode *n1 = new struct bstnode;
    n1->data = item;
    n1->left = NULL;
    n1->right = NULL;
    if (root == NULL)
    {
        root = n1;
    }
    else if ((root->data) > item)
    {
        root->left = insert(root->left, item);
    }
    else
    {
        root->right = insert(root->right, item);
    }
    return (root);
}

void search(struct bstnode *root, int item)
{
    if (root == NULL)
    {
        cout << "UNSUCCESFULL SEARCH " << endl;
    }
    else if (root->data > item)
    {

        search(root->left, item);
    }

    else if (root->data < item)
    {
        search(root->right, item);
    }
    else
    {
        cout << " succesfull search " << endl;
    }
}
void preorder(struct bstnode *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        cout << root->data << ends;
        preorder(root->left);
        preorder(root->right);
    }
}
struct bstnode *findmax(struct bstnode *root)
{
    if (root == NULL)
    {
        cout << " tree is empty" << endl;
    }
    else
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
    }
    return root;
}

struct bstnode *del(struct bstnode *root, int item)
{

    struct bstnode *temp;
    if (root == NULL)
    {
        cout << "tree is empty " << endl;
    }
    else if (root->data > item)
    {
        cout << "Check 1\n";
        root->left = del(root->left, item);
    }
    else if (root->data < item)
    {
        cout << "Check 2\n";
        root->right = del(root->right, item);
    }
    else
    {

        if (root->left != NULL && root->right != NULL)
        {
            temp = findmax(root->left);
            root->data = temp->data;
            root->left = del(root->left, item);
        }
        else
        {
            // node has single child or no child--->
            cout << "Check3\n";
            temp = root;
            // if (!root->left && !root->right)
            //     root = NULL;
            if (root->left == NULL)
            {
                cout << "Check 4 \n";
                root = root->right;
            }
            if (root->right == NULL)
            {
                cout << "Check 5\n";
                root = root->left;
            }
            delete temp;
        }
    }
    return (root);
}

int main()
{
    struct bstnode *root = NULL;
    root = insert(root, 5);

    root = insert(root, 8);
    root = insert(root, 10);
    preorder(root);
    //	preorder(root);
    //	search(root,20);
    root = del(root, 10);
    cout << root->right->data;
    cout << root->data;
    preorder(root);
    // preorder(root);
}