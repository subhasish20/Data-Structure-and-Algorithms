#include<iostream>
using namespace std;

class BinarySearchTree
{
    public:
    typedef struct BSTNode
    {
        struct BSTNode* lchild;
        int data;
        struct BSTNode* rchild;
    }Node;


    Node* CreateNode(int key)
    {
        Node* newNode = new Node();

        newNode->lchild = NULL;
        newNode->data = key;
        newNode->rchild = NULL;

        return newNode;
    }

    Node* InsertANewNode(Node* root, int key)
    {
        if(root == NULL)
        {
        return CreateNode(key);
        }
        if(key < root->data)
        {
            root->lchild = InsertANewNode(root->lchild, key);
        }
        else if(key > root->data)
        {
            root->rchild = InsertANewNode(root->rchild, key);
        }

        return root;
    }

    Node* FreeAllNode(Node* root)
    {
        if(root == NULL)
        return NULL;

        FreeAllNode(root->lchild);
        FreeAllNode(root->rchild);
        delete root;

        return NULL;
    }

    Node* FindInorderPredecessor(Node* root)
    {
        if (root == NULL) return NULL;

        Node* temp = root;
        while (temp->rchild != NULL) {
            temp = temp->rchild;
        }
        return temp;
    }

    Node* DeleteANode(Node* root, int key)
    {
        if(root == NULL)
        {   
            return NULL;
        }
        else if (key < root->data) // if the given key is less than current node 
        {
            root->lchild = DeleteANode(root->lchild, key); // recursive call for reaching the key
        }
        else if ( key > root->data) // if the given key is greater than the current node
        {
            root->rchild = DeleteANode(root->rchild, key);
        }
        else if (key == root->data)
        {
            // if the given key is the leaf node ( there is no child node of the given key to delete)
            if(root->lchild == NULL && root->rchild == NULL)
            {
            delete root;
            return NULL; 
            }
            // if the given key has a righ child
            else if (root->lchild == NULL)
            {
                Node* temp = root;
                root = root->rchild;
                delete temp;
            } 
            // if the given key has a left child
            else if (root->rchild == NULL)
            {
                Node* temp = root;
                root = root->lchild;
                delete temp;
            }
            /* if there is left and right subtree of the given key.
            it will fill by inorder predecessor or in order sucessor*/
            else
            {
                Node* temp = FindInorderPredecessor(root->lchild); // geting the inorder predeccor

                // copy the inorder predecessor
                root->data = temp->data;

                // Delete the inorder predecessor
                root->lchild = DeleteANode(root->lchild, temp->data);

            }
        }
        else
        {
            cout << "Key not found in the tree" << endl;
        }

        return root;
    }

        /* Preorder Traversal: Root -> Left -> Right */
    void PreorderTraversal(Node* root)
    {
    if (root == NULL) {
        cout << "The tree is empty!" << endl;
        return;
    }
        cout << root->data << " "; // for all traversal functions
        PreorderTraversal(root->lchild);
        PreorderTraversal(root->rchild);
    }

    /* Inorder Traversal: Left -> Root -> Right */
    void InOrderTraversal(Node* root)
    {
    if (root == NULL) {
        cout << "The tree is empty!" << endl;
        return;
    }
        InOrderTraversal(root->lchild);
        cout << root->data << " "; // for all traversal functions
        InOrderTraversal(root->rchild);
    }

    /* Postorder Traversal: Left -> Right -> Root */
    void PostOrderTraversal(Node* root)
    {
    if (root == NULL) {
        cout << "The tree is empty!" << endl;
        return;
    }
        PostOrderTraversal(root->lchild);
        PostOrderTraversal(root->rchild);
        cout << root->data << " "; // for all traversal functions
    }
  
};


int main()
{
    int choice, key;
    BinarySearchTree bst;
    BinarySearchTree::Node* root = NULL; // Declare root node

    cout << "\n\n-------------Welcome to Binary Search Tree Menu--------------" << endl;
    cout << "Enter the value of root node: ";
    cin >> key;
    root = bst.CreateNode(key); // Store the created node as root

    do
    {
        cout << "---------------BST Menu---------------" << endl;
        cout << "\n Press 1 : Insert a key";
        cout << "\n Press 2 : Delete a key";
        cout << "\n Press 3 : Preorder traversal on the BST";
        cout << "\n Press 4 : Inorder traversal on the BST ";
        cout << "\n Press 5 : Postorder traversal on the BST";
        cout << "\n Press 6 : Free all nodes (Delete the tree)";
        cout << "\n Press 0 : Exit";
        cout << "\n Enter your choice: ";
        cin >> choice;

        if(choice == 0)
        {
            cout<<"Thank you visit again !!";
            bst.FreeAllNode(root);
            root = NULL;
            exit(0);
        }

        switch (choice)
        {
        case 1:
            cout << "Enter the key to insert: ";
            cin >> key;
            root = bst.InsertANewNode(root, key); // Insert new node
            break;
        
        case 2:
            cout << "Enter the key to delete: ";
            cin >> key;
            root = bst.DeleteANode(root, key); // Call delete functionality
            break;

        case 3:
            cout << "Preorder Traversal: ";
            bst.PreorderTraversal(root);
            cout << endl;
            break;

        case 4:
            cout << "Inorder Traversal: ";
            bst.InOrderTraversal(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder Traversal: ";
            bst.PostOrderTraversal(root);
            cout << endl;
            break;

        case 6:
            bst.FreeAllNode(root); // Free all nodes and delete the tree
            root = NULL; // Set root to NULL after freeing
            cout << "Tree deleted successfully!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0); 

    return 0;
}
