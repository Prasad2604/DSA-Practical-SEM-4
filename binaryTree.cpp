#include <iostream>
#include <stack>
#include<queue>

using namespace std;

class Node
{
public:
    int data;
    Node *lptr;
    Node *rptr;
    Node()
    {
        data = 0;
        lptr = rptr = NULL;
    }
    Node(int data)
    {
        this->data = data;
        lptr = rptr = NULL;
    }
    class Tree
    {
        Node *root;

    public:
        Tree()
        {
            root = NULL;
        }
        Node *getRoot() { return this->root; }
    };
};

Node *create_tree(Node *&root)
{
    int data;
    cout << "Enter data :- ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter data for the left of " << data << endl;
    root->lptr = create_tree(root->lptr);
    cout << "Enter data for the right of " << data << endl;
    root->rptr = create_tree(root->rptr);
    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->lptr);
    preorder(root->rptr);
}

// void inorder(Node* root){
//     stack<Node*> s;
//     // s.push(root);
//     while(root){
//         // cout<<root->data<<endl;
//         while(root!=NULL){
//             s.push(root);
//             root = root->lptr;
//         }
//         // cout<<s.top()->data<<endl;
//         root = s.top();
//         while(!root->rptr){
//             // cout<<"HI"<<endl;
//             cout<<root->data<<" ";
//             root = s.top();
//             s.pop();
//         }
//         root = root->rptr;
//     }
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }

// }

void inorder(Node *root)
{
    stack<Node *> st;
    // cout<<st.top()->data<<endl;
    while (!st.empty() || root != nullptr)
    {
    // st.push(root);

        while (root)
        {
            st.push(root);

            root = root->lptr;

        }

        root = st.top();
        st.pop();
        cout << root->data << " ";
        root = root->rptr;
    }
    while(!st.empty()){
        cout<<st.top()->data<<" ";
        st.pop();
    }
}

void inorder1(Node* root){
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty() || curr!=NULL){
        while(curr){
            s.push(curr);
            curr = curr->lptr;
        }
        curr = s.top();
        cout<<curr->data<<" ";
        curr = curr->rptr;
        s.pop();
    }
}

void Postorder(Node* root){
    stack<Node*> s1;
    stack<Node*> s2;
    // Node* curr = root;
    s1.push(root);
    while(!s1.empty()){
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        // if(curr->lptr && curr->rptr){
        //     s1.push(curr->lptr);
        //     s1.push(curr->rptr);
        // }
        if(curr->lptr){
            s1.push(curr->lptr);
        }
        if(curr->rptr){
            s1.push(curr->rptr);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

void count(Node* root){
    int cnt = 0;
    int inte = 0;
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty()|| curr){
        while(curr){
            s.push(curr);
            curr = curr->lptr;
        }
        curr = s.top();
        if(!curr->lptr && !curr->rptr){
            cnt++;
        }
        else{
            inte++;
        }
        s.pop();
        curr = curr->rptr;
    }
    cout<<"Leaf :- "<<cnt<<" Internal :- "<<inte<<endl;

}

Node* mirrorTree(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node* newRoot = new Node(root->data);
    newRoot->lptr = mirrorTree(root->rptr);
    newRoot->rptr = mirrorTree(root->lptr);
    return newRoot;
}

void printTree(Node* root, int space = 0, int height = 10) {
    if (root == nullptr) return;
    space += height;
    printTree(root->rptr, space);
    std::cout << std::endl;
    for (int i = height; i < space; i++) std::cout << ' ';
    std::cout << root->data << "\n";
    printTree(root->lptr, space);
}


void Preorder(Node* root){
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty() || curr){
        while(curr){
            cout<<curr->data<<" ";
            s.push(curr);
            curr = curr->lptr;
        }
        curr = s.top();
        s.pop();
        curr = curr->rptr;
    }
}

void height_tree(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int ans = 0;
    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        if(frontNode==NULL){
            // q.pop();
            ans++;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(frontNode->lptr){
                q.push(frontNode->lptr);
            }
            if(frontNode->rptr){
                q.push(frontNode->rptr);
            }
        }
    }
    cout<<ans<<endl;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->lptr),height(root->rptr))+1;
}

Node* mirror(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* newNode = new Node(root->data);
    newNode->lptr = mirror(root->rptr);
    newNode->rptr = mirror(root->lptr);
    return newNode;
}

int main()
{
    // Node::Tree t;
    Node *root = NULL;
    root = create_tree(root);
    // preorder(root);
    // inorder1(root);
    Postorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    count(root);
    cout<<endl;
    cout<<height(root)<<endl;
    Node* mirroredRoot = mirror(root);
    cout << "Original Tree:\n";
    printTree(root);
    cout << "Mirrored Tree:\n";
    printTree(mirroredRoot);
}




// 5 10 -1 -1 12 -1 -1
