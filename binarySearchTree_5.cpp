#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
    int data;
    Node* lptr;
    Node* rptr;
    public:
    Node(){
        data=0;
        lptr = rptr = NULL;
    }
    Node(int data){
        this->data = data;
        lptr = rptr = NULL;
    }
    class BTree{
        Node* root;
        public:
        BTree(){
            root = NULL;
        }
        Node* create_tree(int k,Node* root){
            if(!root){
                return new Node(k);
            }
            if(k<root->data){
                root->lptr = create_tree(k,root->lptr);
                cout<<k<<" inserted to the left of "<<root->data<<endl;
            }
            else{
                root->rptr = create_tree(k,root->rptr);
                cout<<k<<" inserted to the right of "<<root->data<<endl;
            }
            return root;
        }
        void ascendingOrder(Node* root){
            stack<Node*> st;
            Node* curr = root;
            while(!st.empty()||root){
                while(root){
                    st.push(root);
                    root = root->lptr;
                }
                root = st.top();
                cout<<root->data<<" "; 
                st.pop();
                root = root->rptr;
            }
        }
        void decendingOrder(Node* root){
            stack<Node*> st;
            Node* curr = root;
            while(!st.empty()||root){
                while(root){
                    st.push(root);
                    root = root->rptr;
                }
                root = st.top();
                cout<<root->data<<" "; 
                st.pop();
                root = root->lptr;
            }
        }
        int search(Node* root,int key,int &cmp){
            if(!root){
                return -1;
            }
            if(key==root->data){
                cmp++;
                return 1;
            }
            else if(key<root->data){
                cmp++;
                int left = search(root->lptr,key,cmp);
            }
            else{
                cmp++;
                int right = search(root->rptr,key,cmp);
            }
            return -1;
        }
        void levelOrderTraversal(Node* root){
            queue<Node*> q;
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                Node* frontNode = q.front();
                q.pop();
                if(frontNode==NULL){
                    cout<<endl;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    cout<<frontNode->data<<" ";
                    if(frontNode->lptr){
                        q.push(frontNode->lptr);
                    }
                    if(frontNode->rptr){
                        q.push(frontNode->rptr);
                    }
                }
            }
        }
        Node* mirror(Node* root){
            if(!root){
                return NULL;
            }
            Node* newNode = new Node(root->data);
            newNode->lptr = mirror(root->rptr);
            newNode->rptr = mirror(root->lptr);
            return newNode;
        }
        int height(Node* root){
            if(!root){
                return 0;
            }
            return max(height(root->lptr),height(root->rptr))+1;
        }        
    };  
};


int main(){
    Node::BTree t;
    Node* root = NULL;
    int n;
    cout<<"Number of elements :- ";
    cin>>n;
    while(n--){
        int k;
        cout<<"Enter key :- ";
        cin>>k;
        root = t.create_tree(k,root);
    }
    t.ascendingOrder(root);
    cout<<endl;
    t.decendingOrder(root);
    cout<<endl;
    //---------------Mirror--------------------------//
    cout<<"Before taking mirror Image :- "<<endl;
    t.levelOrderTraversal(root);
    cout<<endl;
    Node* newNode = t.mirror(root);
    cout<<"After taking mirror Image :- "<<endl;
    t.levelOrderTraversal(newNode);
    cout<<endl;
    //-----------------------------------------------//
    int p;
    bool flag;
    cout<<"Element you wanna search :- ";
    cin>>p;
    int cmp=0;
    flag = t.search(root,p,cmp);
    if(flag==1){
        cout<<"Element found with number of comparisions :- "<<cmp<<endl;
    }
    else{
        cout<<"Element not found!!"<<endl;
    }
    cout<<"Number of nodes in the longest path are :- "<<t.height(root)<<endl;    
}