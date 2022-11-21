#include"bstSpec.h"



void Bst_init(btreeNode_t * node)
{
    node->left = NULL;
    node->right = NULL;
}


btreeNode_t * findMinNode(btreeNode_t * root)
{
    if(root == NULL)
    {
        printf("no tree\n");
        return NULL;
    }

    if(root->left == NULL)
    {
        return root;
    }
    else
    {
        return findMinNode(root->left);
    }
}

btreeNode_t * findMaxNode(btreeNode_t * root)
{
    if(root == NULL)
    {
        printf("no tree\n");
        return NULL;
    }

    if(root->right == NULL)
    {
        return root;
    }
    else
    {
        return findMaxNode(root->right);
    }
}


void inOrder(btreeNode_t * root, void(*print)(btreeNode_t * root))
{
    if(root == NULL)
    {
        printf("no node\n");
    }
    else
    {
        if(root->left != NULL)
        {
            inOrder(root->left, print);
        }

        print(root);

        if(root->right != NULL)
        {
            inOrder(root->right, print);
        }
    }

}

btreeNode_t * treeCopy(btreeNode_t * root, btreeNode_t *(*copy)(btreeNode_t * root))
{
    if(root != NULL)
    {
        btreeNode_t * new_root = copy(root);

        if(root->left != NULL)
        {
            new_root->left = treeCopy(root->left, copy);
        }

        if(root->right != NULL)
        {
            new_root->right = treeCopy(root->right, copy);
        }

        return new_root;
    }
    else
    {
        return NULL;
    }
}

int treeEqual(btreeNode_t * root_A, btreeNode_t * root_B, int(*compare)(btreeNode_t * root_A, btreeNode_t * root_B))
{
    if(root_A == NULL && root_B == NULL)
    {
        return 1;
    }
    else if(root_A != NULL && root_B != NULL)
    {
        if(compare(root_A, root_B))
        {
            if(treeEqual(root_A->left, root_B->left, compare))
            {
                if(treeEqual(root_A->right, root_B->right, compare))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}