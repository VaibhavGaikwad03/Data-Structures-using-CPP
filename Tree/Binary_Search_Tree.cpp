#include <iostream>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
};

class BST
{
    node *root;
    void inorder(node *root);
    node *r_insert(node *root, int key);
    node *r_search(node *root, int key);
    node *r_delete(node *root, int key);
    int height(node *root);

public:
    BST() : root(NULL) {}
    void insert(int key);
    node *search(int key);
    void inorder() { inorder(root); }
    node *r_search(int key) { return r_search(root, key); }
    void r_insert(int key) { root = r_insert(root, key); };
    node *r_delete(int key) { r_delete(root, key); };
    int height() { return height(root); };
};

void BST::inorder(node *r)
{
    if (r == NULL)
        return;

    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

int BST::height()
{
    int x, y;

    if (root == NULL)
        return 0;

    x = height(root->left);
    y = height(root->right);

    return x > y ? x + 1 : y + 1;
}

node *BST::search(int key)
{
    node *tmp = root;

    while (tmp != NULL)
    {
        if (key < tmp->data)
            tmp = tmp->left;
        else if (key > tmp->data)
            tmp = tmp->right;
        else
            return tmp;
    }
    return NULL;
}

node *BST::r_search(node *r, int key)
{
    if (r == NULL)
        return NULL;

    if (key < r->data)
        return r_search(r->left, key);
    else if (key > r->data)
        return r_search(r->right, key);
    else
        return r;
}

void BST::insert(int key)
{

    node *new_node = NULL;
    node *tmp1 = root, *tmp2 = NULL;

    new_node = new node;
    new_node->data = key;
    new_node->left = new_node->right = NULL;

    if (root == NULL)
    {
        root = new_node;
        return;
    }

    while (tmp1 != NULL)
    {
        tmp2 = tmp1;

        if (key < tmp1->data)
            tmp1 = tmp1->left;
        else if (key > tmp1->data)
            tmp1 = tmp1->right;
        else
        {
            delete new_node;
            return;
        }
    }

    new_node->data = key;

    if (key < tmp2->data)
        tmp2->left = new_node;
    else
        tmp2->right = new_node;
}

node *BST::r_insert(node *r, int key)
{
    if (r == NULL)
    {
        node *new_node = new node;
        if (new_node == NULL)
            return NULL;
        new_node->data = key;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    if (key < r->data)
        r->left = r_insert(r->left, key);
    else if (key > r->data)
        r->right = r_insert(r->right, key);

    return r;
}

node *BST::r_delete(node *r, int key)
{
    node *q = NULL;

    if (r == NULL)
        return NULL;

    if (r->left == NULL && r->right == NULL)
    {
        if (r == root)
            root = NULL;
        delete r;
        return NULL;
    }

    if (key < r->data)
        r->left = r_delete(r->left, key);
    else if (key > r->data)
        r->right = r_delete(r->right, key);
    else
    {
        if ()
    }
}

int main(void)
{
    BST bst;

    bst.r_insert(30);
    bst.r_insert(20);
    bst.r_insert(40);
    bst.r_insert(10);
    bst.r_insert(25);
    bst.r_insert(35);
    bst.r_insert(50);
    bst.inorder();
    cout << endl
         << bst.r_search(25)->data << endl;

    return 0;
}