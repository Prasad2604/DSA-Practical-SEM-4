#include<iostream> 
#include<stack>
#include<vector>
using namespace std;

class Node{
    public:
    char data;
    Node* lptr;
    Node* rptr;
    
    Node(){
        data='0';
        lptr =rptr=NULL;
    }
    Node(char val){
        this->data = val;
        lptr = rptr = NULL;
    }
    class Tree{
        Node* root;
        public:
        Tree(){
            root = NULL;
        }
        Node* getRoot(){
            return this->root;
        }
        
        void inorder_rec(Node* root){
            if(root==NULL){
                return;
            }
            inorder_rec(root->lptr);
            cout<<root->data;
            inorder_rec(root->rptr);
        }   
    };
};

Node* create_expression_tree(string exp){
    stack<Node*> s;
    for(int i=exp.length()-1;i>=0;i--){
        if(isalpha(exp[i])){
            s.push(new Node(exp[i]));
        }
        else{
            Node* root = new Node(exp[i]);
            if(!s.empty()){
                root->lptr = s.top();
                s.pop();
            }
            if(!s.empty()){
                root->rptr = s.top();
                s.pop();
            }
            s.push(root);
        }
    }
    return s.top();
}


int main(){
    Node::Tree t;
    Node* root = NULL;
    string expression = "+--a*bc/def";
    root = create_expression_tree(expression);
    t.inorder_rec(root);
}


Node* create(string s){
    stack<Node*> st;
    for(int i=s.length()-1;i>=0;i--){
        if(isalpha(s[i])){
            st.push(new Node(s[i]));
        }
        else{
            Node* node = new Node(s[i]);
            if(!st.empty()){
                node->lptr = st.top();
                st.pop();            
            }
            if(!st.empty()){
                node->rptr = st.top();
                st.pop();
            }
            st.push(node);
        }
    }
    return st.top();
}

void countAndDisplay(Node* root,vector<char> &operators, vector<char> &operands){
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        if(isalpha(node->data)){
            operands.push_back(node->data);
        }
        else{
            operators.push_back(node->data);
        }
        if(node->lptr){
            s.push(node->lptr);
        }
        if(node->rptr){
            s.push(node->rptr);
        }
    }
}

