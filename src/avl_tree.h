
//  Self-Balancing Binary Search Tree in C++

class AVLTree
{
    int m_data;
    AVLTree *m_left, *m_right;
    int m_height;
    
public:

    AVLTree(int data)
    {
        m_data = data;
        m_left = m_right = NULL;
    }

    AVLTree getLeft()
    {
        return m_left;
    }


    AVLTree getRight()
    {
        return m_right;
    }


    int getData()
    {
        return m_data;
    }

    // Calculate height
    int getHeight()
    {
        if (this == NULL)
        {
           return 0;
        }

        return m_height;
    }


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

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }


    // Rotate right
    AVLTree *rightRotate(AVLTree *y)
    {
        AVLTree *x = m_left;
        AVLTree *T2 = x->right;
        x->right = this;
        m_left = T2;
        m_height = max(m_left->getHeight(), m_right->getHeight()) + 1;
        x->height = max(x->left->getHeight(), x->right->getHeight()) + 1;
  
        return x;
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
    // is defined as a binary tree in which the height of the
    // left and right subtree of any node differ by not more than 1.
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
