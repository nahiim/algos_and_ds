
//  Binary Search Tree in C++

class BST
{
    int m_data;
    BST *m_left, *m_right;
    
public:

    BST(int data)
    {
        m_data = data;
        m_left = m_right = NULL;
    }


    int getData()
    {
        return m_data;
    }


    // (inorder traversal allows us to traverse BST in ascending order)
    void inorder()
    {
        if (this == NULL)
        {
            return;
        }

        m_left->inorder();
        std::cout << m_data << "->";
        m_right->inorder();
    }


    // Insert a node
    BST *insert(int data)
    {
        // Return a new node if the tree is empty
        if (this == NULL)
        {
            return new BST(data);
        }

        // Traverse to the right place and insert the node
        if (data < m_data)
        {
            m_left = m_left->insert(data);
        }
        else
        {
            m_right = m_right->insert(data);
        }

        return this;
    }

    // Find the inorder successor
    BST *minValueNode()
    {
        BST *current = this;

        // Find the leftmost leaf
        while (current && current->m_left != NULL)
        {
            current = current->m_left;
        }

        return current;
    }



    // Deleting a node
    BST *deleteNode(int data)
    {
        // Return if the tree is empty
        if (this == NULL)
        {
            return this;
        }

        // Find the node to be deleted
        if (data < m_data)
        {
            m_left = m_left->deleteNode(data);
        }
        else if (data > m_data)
        {
            m_right = m_right->deleteNode(data);
        }
        else
        {
            // If the node is with only one child or no child
            if (m_left == NULL)
            {
                BST *temp = m_right;
                free(this);
                return temp;
            }
            else if (m_right == NULL)
            {
                BST *temp = m_left;
                free(this);
                return temp;
            }

            // If the node has two children
            BST *temp = m_right->minValueNode();

            // Place the inorder successor in position of the node to be deleted
            m_data = temp->getData();

            // Delete the inorder successor
            m_right = m_right->deleteNode(temp->getData());
        }


        return this;
    }


    // Count the number of nodes
    int getCount()
    {
        if (this == NULL)
        {
            return (0);
        }

        return (1 + m_left->getCount() + m_right->getCount());
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
            int left_depth = m_left->maxDepth();
            int right_depth = m_left->maxDepth();

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
        if (m_left == NULL && m_right == NULL)
        {
            return true;
        }

        if ((m_left) && (m_right))
        {
            return (m_left->isFullBinaryTree() && m_right->isFullBinaryTree());
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

        return (m_left->isCompleteBinaryTree(2 * index + 1) && m_right->isCompleteBinaryTree(2 * index + 2));
    }

    // A balanced binary tree, also referred to as a height-balanced binary tree, 
    // is defined as a binary tree in which the height of the left and right subtree of any node differ by not more than 1.
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

        l = m_left->isHeightBalance(&left_height);
        r = m_left->isHeightBalance(&right_height);

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
        if(m_left == NULL && m_right == NULL)
        {
            return (depth == level);
        }

        // If internal node and one child is empty
        if(m_left == NULL && m_right == NULL)
        {
            return m_left->isPerfect(level + 1) && m_right->isPerfect(level + 1);
        }
    }

};



// Driver code
// int main()
// {
//     std::cout << "\n\t\t:: ::\n\n";


//     BST *tree = NULL;
//     for(int i=19; i>5; i--)
//     {
//         tree = tree->insert(i);
//     }

//     std::cout << "Inorder traversal: ";
//     tree->inorder();
//     std::cout << std::endl;

//     std::cout << "\nAfter deleting 10\n";
//     tree = tree->deleteNode(10);
//     std::cout << "Inorder traversal: ";
//     tree->inorder();


//     std::cout << "\n\n\n\n  PRESS ENTER TO EXIT(): ";
//     std::cin.get();
// }
