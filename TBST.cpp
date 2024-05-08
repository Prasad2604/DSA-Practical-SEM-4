#include<iostream>
using namespace std;



class Node{
    int data;
    Node* lptr;
    Node* rptr;
    bool lThread;
    bool rThread;
    public:
    Node(){
        data = 0;
        lptr = rptr = NULL;
        lThread = rThread = true;
    }
    Node(int x){
        this->data = x;
        lptr = rptr = NULL;
        lThread = rThread = true;
    }
    class TBST{
        Node* root;
        public:
        TBST(){
            root = NULL;
        }
        Node* create_tree(Node* root,int k){
            Node* ptr = root; //for iteration
            Node* par = NULL; //for parent node
            while(ptr!=NULL){
                if(ptr->data==k){
                    cout<<"Key already present!!"<<endl;
                    return root;
                }
                par = ptr;
                if(k<ptr->data){
                    if(ptr->lThread==false){
                        ptr = ptr->lptr;
                    }
                    else{
                        break;
                    }
                }
                else {
                    if(ptr->rThread==false){
                        ptr = ptr->rptr;
                    }
                    else{
                        break;
                    }
                }
            }
            Node* newNode = new Node(k);
            if(par==NULL){
                root = new Node(k);
            }
            else if(par->lThread==true){
                newNode->lptr = par->lptr;
                newNode->rptr = par;
                par->lptr = newNode;
                par->lThread = false;

            }
            else {
                newNode->rptr = par->rptr;
                newNode->lptr = par;
                par->rptr = newNode;
                par->rThread = false;
            }
            return root;
        }
        Node* getSuccessor(Node* ptr){
            if(ptr->rThread==true){
                return ptr->rptr;
            }
            ptr = ptr->rptr;
            while(ptr->lThread==false){
                ptr = ptr->lptr;
            }
            return ptr;
        }
        Node* get_predecessor(Node* ptr){
            if(ptr->lThread==true){
                return ptr->lptr;
            }
            ptr = ptr->lptr;
            while(ptr->rThread==false){
                ptr = ptr->rptr;
            }
            return ptr;
        }
        void inorder(Node* root){
            Node* ptr = root;
            if(ptr==NULL){
                cout<<"Tree is empty!!"<<endl;
                return;
            }
            while(ptr->lThread==false){
                ptr = ptr->lptr;
            }
            while(ptr){
                cout<<ptr->data<< " (lbit: " << ptr->lThread << ", rbit: " << ptr->rThread << ") -> ";
                ptr = this->getSuccessor(ptr);
            }
        }
        void perorder(Node* root){
            if(root==NULL){
                cout<<"Tree is empty!!"<<endl;
                return;
            }
            Node* ptr = root;
            while(ptr){
                cout<<ptr->data<< " (lbit: " << ptr->lThread << ", rbit: " << ptr->rThread << ") -> ";
                if(ptr->lThread==false){
                    ptr = ptr->lptr;
                }
                else if(ptr->rThread==false){
                    ptr = ptr->rptr;
                }
                else{
                    while(ptr!=NULL && ptr->rThread==true){
                        ptr = this->getSuccessor(ptr);
                    }
                    if(ptr!=NULL){
                        ptr = ptr->rptr;
                    }
                }
            }
        }
        Node* NoChild(Node* root,Node* par,Node* ptr){
            if(par==NULL){
                root = NULL;
                return root;
            }
            if(par->lptr==ptr){
                par->lptr = ptr->lptr;
                par->lThread = true;
            }
            else{
                par->rptr = ptr->rptr;
                par->rThread = true;
            }
            delete ptr;
            return root;
        }
        Node* OneChild(Node* root,Node* par,Node* ptr){
            Node* child = NULL;
            if(ptr->lThread==false){
                child = ptr->lptr;
            }
            else{
                child = ptr->rptr;
            }
            if(par==NULL){
                root = child;
            }
            else if(par->lptr==ptr){
                par->lptr = child;
            }
            else{
                par->rptr = child;
            }
            Node* s = this->getSuccessor(ptr);
            Node* p = this->get_predecessor(ptr);
            if(ptr->lThread==false){
                p->rptr = s;
            }
            else if(ptr->rThread==false){
                s->lptr = p;
            }
            delete ptr;
            return root;
        }
        Node* TwoChild(Node* root,Node* par,Node* ptr){
            Node* parsucc = ptr;
            Node* succ = ptr->rptr;
            while(succ->lptr!=NULL){
                parsucc = succ;
                succ = succ->lptr;
            }
            int temp = succ->data;
            succ->data = ptr->data;
            ptr->data = temp;
            if(succ->lThread==true || succ->rThread==true){
                root = NoChild(root,parsucc,succ);
            }
            else{
                root = OneChild(root,parsucc,succ);
            }
            return root;
        }
        void del(Node* root,int key){
            Node* ptr = root;
            Node* par = NULL;
            bool found = 0;
            while(ptr!=NULL){
                if(ptr->data==key){
                    found=1;
                    break;
                }
                par = ptr;
                if(key<ptr->data){
                    if(ptr->lThread==false){
                        ptr = ptr->lptr;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(ptr->rThread==false){
                        ptr = ptr->rptr;  
                    }
                    else{
                        break;
                    }
                }
            }
            if(found==0){
                cout<<"key not present "<<endl;
                return;
            }
            else if(ptr->lThread==false && ptr->rThread==false){
                root = TwoChild(root,par,ptr); 
            }
            else if(ptr->lThread==false){
                root = OneChild(root,par,ptr);
            }
            else if(ptr->rThread==false){
                root = OneChild(root,par,ptr);
            }
            else{
                root = NoChild(root,par,ptr);
            }
        }

    };
};


int main(){
    Node::TBST t;
    Node* root = NULL;
    int n;
    cout<<"Enter number of nodes :- ";
    cin>>n;
    while(n--){
        int k;
        cout<<"Enter key :- ";
        cin>>k;
        root = t.create_tree(root,k);
    }
    t.inorder(root);
    cout<<endl;
    t.perorder(root);
    cout<<endl;
    cout<<"Which key you wanna delete?? :- ";
    int p;
    cin>>p;
    t.del(root,p);
    cout<<"After deletion :- "<<endl;
    t.inorder(root);
    cout<<endl;
}