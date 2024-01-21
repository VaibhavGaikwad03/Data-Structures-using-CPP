#include <iostream>
#include "Queue.hpp"
using std::cin;
using std::cout;
using std::endl;
 
struct node
{
    node *left;
    int data;
    node *right;
};
 
class BinaryTree
{
    node *root;

public:
    BinaryTree() : root(nullptr) {}
    void create();
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }

private:
    void preorder(node *p);
    void inorder(node *p);
    void postorder(node *p);
};

void BinaryTree::create()
{
    int x;
    node *p = nullptr, *new_node = nullptr;

    Queue<node *> q;

    root = new node;
    if (root == nullptr)
        return;

    cout << "\nEnter the data of root: ";
    cin >> x;

    root->data = x;
    root->left = root->right = nullptr;

    q.enqueue(root);

    while (!q.is_empty())
    {
        p = q.dequeu();

        cout << "\nEnter the left child of " << p->data << ": ";
        cin >> x;

        if (x != -1)
        {
            new_node = new node;
            if (new_node == nullptr)
                return;
            new_node->data = x;
            new_node->left = new_node->right = nullptr;
            q.enqueue(new_node);
            p->left = new_node;
        }

        cout << "\nEnter the right child of " << p->data << ": ";
        cin >> x;

        if (x != -1)
        {
            new_node = new node;
            if (new_node == nullptr)
                return;
            new_node->data = x;
            new_node->left = new_node->right = nullptr;
            q.enqueue(new_node);
            p->right = new_node;
        }
    }
}

void BinaryTree::preorder(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void BinaryTree::inorder(node *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void BinaryTree::postorder(node *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

int main(void)
{
    BinaryTree btree;
    btree.create();
    cout << "Pre: ";
    btree.preorder();
    cout << endl;
    cout << "In: ";
    btree.inorder();
    cout << endl;
    cout << "Post: ";
    btree.postorder();
    cout << endl;

    return 0;
}
