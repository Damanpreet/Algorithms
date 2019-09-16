#include<iostream>
#include<cstring>
using namespace std;

struct Node{
    int key_val;
    Node *left;
    Node *right;
};

class binaryTree{
    public:
        btree();
        ~btree();

        void insert_tree(int key);
        void destroy_tree();
        void preorder_traversal(int key);
    
    private:
        void insert_tree(int key, Node *tree_node);
        void destroy_tree(Node *tree_node);

        Node *root;
};

binaryTree::btree()
{
    root = NULL;
}

binaryTree::~btree()
{
    destroy_tree();
}

/* Recursively destroy every node of the tree. */
void binaryTree::destroy_tree(Node* tree_node)
{
    destroy_tree(tree_node->left);
    destroy_tree(tree_node->right);
    delete tree_node;
}

/* Recursively insert node into the tree based on rules. */
void binaryTree::insert_tree(int key, Node* tree_node){
    if(key > tree_node->key_val){
        // go to right subtree.
        if(tree_node->right!=NULL){
            tree_node->right = new Node;
            tree_node->right->key_val = key;
            tree_node->right->left = tree_node->right->right = NULL;
        }
    }
    else{
        // go to left subtree.
        if(tree_node->left!=NULL){
            tree_node->left = new Node;
            tree_node->left->key_val = key;
            tree_node->left->left = tree_node->left->right = NULL;
        }
    }
}

/* Insert into tree. Public function. */
void binaryTree::insert_tree(int key){
    if(binaryTree::root != NULL){
        insert_tree(key, root);
    }
    else{
        root = new Node;
        root->key_val = key;
        root->right = root->left = NULL;
    }
}
