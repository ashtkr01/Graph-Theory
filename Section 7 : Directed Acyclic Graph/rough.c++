class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    //Inorderd Successor"
    Node* inorderPredecessor(Node *root)
    {
        Node* temp = root->left;
        if(temp == NULL)
        {
            return NULL;
        }
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }
        //Inorderd Successor"
    Node* inorderSuccessor(Node *root)
    {
        Node* temp = root->right;
        if(temp == NULL)
        {
            return NULL;
        }
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    //Check for Bst:
    bool isBst(Node *root)
    {
        bool res = true;
        if(root == NULL)
        {
            return True;
        }
        Node *inorderPred = inorderPredecessor(root);
        Node *Inordersucc = inorderSuccessor(root);
        
        if(root->left != NULL)
        {
            if(root->left->data < root->data)
            {
                res = res | true;
            }
            else
            {
                res = res | false;
            }
        }
        if(root->right != NULL)
        {
            if(root->left->data >= root->data)
            {
                res = res | true;
            }
            else
            {
                res = res | false;
            }
        }
        if(inorderPred != NULL)
        {
            if(inorderPred->data < root)
            {
                return res | true;
            }
            else
            {
                return res | false;
            }
        }
         if(inorderSucc != NULL)
        {
            if(inorderSucc->data >= root)
            {
                return res | true;
            }
            else
            {
                return res | false;
            }
        }
        return res;
        
    }
    pair<int , int > largestBstHelper(Node *root)
    {
        if(root == NULL)
        {
            return { 0 , 0 };
        }
        
        pair<int , int> a = largestBstHelper(root->left);
        pair<int , int> b = largestBstHelper(root->right);
        
        if(a.first == a.second and b.first = b.second)
        {
            if(isCheck(root))
            {
                pair<int , int > res = {1+ max(a.first , b.first) , 1+max(a.second , b.second)};
                return res;
            }
            else
            {
                pair<int , int > res = {max(a.first , b.first) , 1 + max(a.second , b.second)};
                return res;
            }
        }
        else
        {
             pair<int , int > res = {max(a.first , b.first) , 1 + max(a.second , b.second)};
                return res;
        }
    }
    int largestBst(Node *root)
    {
    
    }
};