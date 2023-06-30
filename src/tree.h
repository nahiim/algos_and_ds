
//  Binary Tree in C++

struct Node
{
    int data;
    Node *left, *right;
    

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }



    // Preorder traversal
    void preorderTraversal()
    {
        if (this == NULL)
        {
            return;
        }
        std::cout << this->data << "->";
        this->left->preorderTraversal();
        this->right->preorderTraversal();
    }

    // Postorder traversal
    void postorderTraversal()
    {
        if (this == NULL)
        {
            return;
        }

        this->left->postorderTraversal();
        this->right->postorderTraversal();
        std::cout << this->data << "->";
    }

    // Inorder traversal
    void inorderTraversal()
    {
        if (this == NULL)
        {
            return;
        }

        this->left->inorderTraversal();
        std::cout << this->data << "->";
        this->right->inorderTraversal();
    }


    // Count the number of nodes
    int getCount()
    {
        if (this == NULL)
        {
            return (0);
        }

        return (1 + this->left->getCount() + this->right->getCount());
    }

    int maxDepth()
    {
        if(this == NULL)
        {
            return 0;
        }
        else
        {
            // compute the depth of each subtree
            int left_depth = this->left->maxDepth();
            int right_depth = this->left->maxDepth();

            // use the larger one
            return (left_depth > right_depth ? left_depth : right_depth);
        }
    }


    // A full/proper Binary tree is a special type of binary tree
    // in which every parent node/internal node has either two or no children.
    bool isFullBinaryTree()
    {
        // Checking for emptiness
        if (this == NULL)
        {
            return true;
        }

        // Checking for the presence of children
        if (this->left == NULL && this->right == NULL)
        {
            return true;
        }

        if ((this->left) && (this->right))
        {
            return (this->left->isFullBinaryTree() && this->right->isFullBinaryTree());
        }

        return false;
    }

    // A complete binary tree is a binary tree 
    // in which all the levels are completely filled 
    // except possibly the lowest one, which is filled from the left.
    bool isCompleteBinaryTree(int index = 0)
    {      
        // Check if the tree is empty
        if (this == NULL)
        {
            return true;
        }

        if (index >= getCount())
        {
            return false;
        }

        return (this->left->isCompleteBinaryTree(2 * index + 1) && this->right->isCompleteBinaryTree(2 * index + 2));
    }

    // Check height balance
    bool isHeightBalance(int *height)
    {
        // Check for emptiness
        int left_height = 0, right_height = 0;

        int l = 0, r = 0;

        if (this == NULL)
        {
            *height = 0;
            return 1;
        }

        l = this->left->isHeightBalance(&left_height);
        r = this->left->isHeightBalance(&right_height);

        *height = (left_height > right_height ? left_height : right_height) + 1;

        if (std::abs(left_height - right_height >= 2))
        {
            return 0;
        }
        else
        {
            return l && r;
        }
    }

    // A perfect binary tree is a type of binary tree
    // in which every internal node has exactly two
    // child nodes and all the leaf nodes are at the same level.
    bool isPerfect(int level = 0)
    {
        // An empty tree is perfect
        if(this == NULL)
        {
            return true;
        }

        int depth = maxDepth();

        // If leaf node, then current level must be equal to max depth
        if(this->left == NULL && this->right == NULL)
        {
            return (depth == level);
        }

        // If internal node and one child is empty
        if(this->left == NULL && this->right == NULL)
        {
            return this->left->isPerfect(level + 1) && this->right->isPerfect(level + 1);
        }
    }

};



// Driver code
// int main()
// {
//     std::cout << "\n\t\t:: ::\n\n";


//     Node* root = new Node(1);
//     root->left = new Node(12);
//     root->right = new Node(9);
//     root->left->left = new Node(5);
//     root->left->right = new Node(6);

//     std::cout << "Inorder traversal ";
//     root->inorderTraversal();

//     std::cout << "\nPreorder traversal ";
//     root->preorderTraversal();

//     std::cout << "\nPostorder traversal ";
//     root->postorderTraversal();


//     std::cout << "\n\n\n\n  PRESS ENTER TO EXIT(): ";
//     std::cin.get();
// }