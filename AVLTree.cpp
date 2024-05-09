#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

class Node{
    string key;
    string value;
    Node* left;
    Node* right;
    int height;
    public:
    Node(){
        key = value = "";
        left = right = NULL;
        height = 1;
    }
    Node(string key,string value){
        this->key = key;
        this->value = value;
        left = right = NULL;
        height = 1;
    }
    class AVL{
        Node* root;
        public:
        AVL(){
            root = NULL;
        }
        int get_height(Node* c){
            if(c==NULL){
                return 0;
            }
            c->height = max(get_height(c->left),get_height(c->right))+1;
            return c->height;
        }
        int balance_factor(Node* root){
            if(root==NULL){
                return 0;
            }
            return (get_height(root->left)) - (get_height(root->right));
        }
        Node* balance(Node* c){
            if(balance_factor(c)==2){
                if(balance_factor(c->left)<0){
                    c = LRrotation(c);
                }
                else{
                    c = LLrotation(c);
                }
            }
            else if(balance_factor(c)==-2){
                if(balance_factor(c->right)>0){
                    c = RLrotation(c);
                }
                else{
                    c = RRrotation(c);
                }
            }
            get_height(c);
            return c;
        }
        Node* LLrotation(Node* root){
            Node* temp = root->left;
            root->left = temp->right;
            temp->right = root;
            get_height(root);
            get_height(temp);
            return temp;
        }
        Node* RRrotation(Node* root){
            Node* temp = root->right;
            root->right = temp->left;
            temp->left = root;
            get_height(root);
            get_height(temp);
            return temp;
        }
        Node* LRrotation(Node* root){
            root->left = RRrotation(root->left);
            return LLrotation(root);
        }
        Node* RLrotation(Node* root){
            root->right = LLrotation(root->right);
            return LLrotation(root);
        }
        Node* insert(Node* root,string key,string value){
            if(root==NULL){
                return new Node(key,value);
            }
            if(key<root->key){
                root->left = insert(root->left,key,value);
            }
            else if(key>root->key){
                root->right = insert(root->right,key,value);
            }
            return balance(root);
        
        }
        void search(Node* root,string key,int &cmp){
            if(root){
                if(root->key==key){
                    cmp++;
                    cout<<"Key found with "<<cmp<<" comparisions!!"<<endl;
                    return;
                }
                if(key<root->key){
                    cmp++;
                    search(root,key,cmp);
                }
                else{
                    cmp++;
                    search(root,key,cmp);
                }
            }
        }
        void levelOrderTraversal(Node* root){
            queue<Node*> q;
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                Node* frontNode = q.front();
                q.pop();
                if(frontNode==NULL){
                    cout<<"--------------------------"<<endl;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    cout<<frontNode->key<<":"<<frontNode->value<<" BalanceFactor : "<<balance_factor(frontNode)<<endl;
                    if(frontNode->left){
                        q.push(frontNode->left);
                    }
                    if(frontNode->right){
                        q.push(frontNode->right);
                    }
                }
            }
        }
        void inorder1(Node* root){
            if(root==NULL){
                return;
            }
            inorder1(root->left);
            cout<<root->key<<":"<<root->value<<" ";
            inorder1(root->right);
        }
        void inorder(Node* root){
            stack<Node*> st;
            Node* curr = root;
            while(curr || !st.empty()){
                while(curr){
                    st.push(curr);
                    curr = curr->left;
                }
                curr = st.top();
                st.pop();
                cout<<curr->key<<" : "<<curr->value<<" BalanceFactor : "<<balance_factor(curr)<<endl;
                curr = curr->right;
            }
        }
    };
};

int main(){
    Node::AVL a;
    Node* root = NULL;
    int n;
    cout<<"Enter Number of key and value pairs you wanna insert :- ";
    cin>>n;
    while(n--){
        string k;
        string v;
        cout<<"Enter key :- ";
        cin>>k;
        cout<<"Enter value :- ";
        cin>>v;
        root = a.insert(root,k,v);
    }
    a.inorder1(root);
    // cout<<endl;
    // cout<<"LevelOrderTraversal :- "<<endl;
    // a.levelOrderTraversal(root);
    // cout<<endl;
    // cout<<"Inorder Traversal :- "<<endl;
    // a.inorder(root);
    // cout<<endl;
    // cout<<"Search :- "<<endl;
    // int cmp = 0;
    // string k;
    // cout<<"Enter key you wanna search :- ";
    // cin>>k;
    // a.search(root,k,cmp);
}