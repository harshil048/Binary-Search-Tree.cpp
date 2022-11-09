#include<bits/stdc++.h>
//#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBst(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBst(root->right, data);
    }
    else
    {
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}

void levelOrderTraversal(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void takeInput(Node *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

Node* minVal(Node *root)
{

    Node *temp = root;
    while(temp->left != NULL)
    {
        temp = temp ->left;
    }
    return temp;
}

Node *deleteInBst(Node *root, int val)
{
    if(root == NULL) return root;

    if(root->data == val)
    {
        //0 child
        if(root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //1 child
        if(root->left != NULL and root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL and root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left != NULL and root->right != NULL)
        {
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteInBst(root->right, mini);
            return root;
        }
    }
    else if(root->data > val)
    {
        root->left = deleteInBst(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteInBst(root->right, val);
        return root;
    }
}

int main()
{


#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.txt", "r", stdin);
    // for writing output to output.txt
    freopen("outputf.txt", "w", stdout);
#endif
    //fio;

    srand(time(NULL));

    Node *root = NULL;

    takeInput(root);
    levelOrderTraversal(root);
    int mini = minVal(root) -> data;
    cout<<mini<<endl;
    root = deleteInBst(root, 50);
    cout << endl;
    levelOrderTraversal(root);

}
