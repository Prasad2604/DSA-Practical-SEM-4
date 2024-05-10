// 0) Create an inordered threaded binary search tree for integer. Perform inorder traversal,
// and deletion of a node.
// Note: Display lbit, rbit for every node


#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
    int rbit;
    int lbit;

    Node(int d){
        this ->data = d;
        this->left = NULL;
        this->right = NULL;
        this->rbit = 0;
        this->lbit = 0;
    }

    friend class TBST;
};

class TBST{
    private:
    Node* root , *head;
   
   public:

   TBST(){
      root = NULL;
      head = NULL;
   }

   Node* get_root(){
    return root;
   }


   void insert(int x){
       if(root == NULL){
        head = new Node(999);
        head->right = head;
        root = new Node(x);
        head->left = root;
        head->lbit=1;
        root->left = head;
        root->right = head;
         return;
       }

       else{
          Node* p = root;
          Node* q = new Node(x);

          while(true){
            if(x == p->data){
                delete q;
                return;
            }
            else if(x < p->data){
                if(p->lbit==1){
                    p=p->left;
                }
                else{
                    q->left = p->left;
                    q->right=p;
                    p->left=q;
                    p->lbit=1;
                    return;
                }
            }
            else{
                if(p->rbit==1){
                    p=p->right;
                }
                else{
                    q->right = p->right;
                    q->left=p;
                    p->right=q;
                    p->rbit=1;
                    return;
                }
            }
          }
       }
   }


   void Inorder(){
      Node* p = root;

      while(p->lbit == 1){
         p = p->left;
      }
      while(p!=head){
        cout<<p->data<<" "<<endl;
        cout<<"The lbit of "<<p->data<<" is : "<<p->lbit<<endl;
        cout<<"The rbit of "<<p->data<<" is : "<<p->rbit<<endl;

        if(p->rbit == 1){
            p = p->right;
            while(p->lbit == 1){
                p = p->left;
            }
        }

        else{
            p = p->right;
        }
      }
      cout<<endl;
   }

   void preoOrder(){
      Node* p = root;
      int flag;

      while(p != head){
        if(flag == 0){
            cout<<p->data<<" ";
        }

        if(flag ==0 && p->lbit == 1){
            p = p->left;
        }
        else{
            if(p->rbit ==1){
                flag =0;
            }
            else{
                flag =1;
            }
            p = p->right;
        }
      }
   }


   void Search(int x, Node* node, int &flag){
    if (node == nullptr) {
        flag = 0;
        cout << "Element is not present (empty tree)" << endl;
        return;
    }

    while (node != nullptr) {
        if (x == node->data) {
            flag = 1;
            cout << "Element is present" << endl;
            return;
        } else if (x < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    flag = 0;
    cout << "Element is not present" << endl;
}

   

   void Deletion(int x, Node* node){
        int flag;
        Search(x, node, flag);

        Node* curr = node;
        Node* p = NULL;

        if(flag == 0){
            cout<<"Node not present"<<endl;
            return;
        }
        else{

            // CASE 1: if both right and left clid are there
            if(node->rbit ==1 &&  node->lbit==1){
                curr = node->right;
                 p = node;
                while(curr->lbit == 1){
                    p = curr;
                    curr = curr->left;
                }

                node->data = curr->data;
                p->lbit =0;
                p->left = curr->left;
                delete curr;
                cout<<"The node has been deleted"<<endl;
            }

            //CASE 2: Either left or right child

            else if(node->lbit == 1 && node->rbit == 0){
                   curr = node->left;
                     p = node;

                    while(curr->rbit == 1){
                        p = curr;
                        curr = curr->right;
                    }

                    node -> data = curr->data;
                    p->rbit = 0;
                    p->right = curr->right;
                    delete curr;
                    cout<<"The node has been deleted"<<endl;
            }
            else if(node->lbit == 0 && node->rbit == 1){
                     curr = node->right;
                     p = node;

                    while(curr->lbit == 1){
                        p = curr;
                        curr = curr->left;
                    }

                    node -> data = curr->data;
                    p->lbit =0;
                    p->left = curr->left;
                    delete curr;
                    cout<<"The node has been deleted"<<endl;
            }

            else{
                  
            }
        }
        
   }


    
};


int main(){

    TBST tree;

    tree.insert(7);
    tree.insert(8);
    tree.insert(3);
    tree.insert(6);
    tree.insert(10);

    tree.Inorder();


    int sm = tree.smallest();
    int lr = tree.largest();

    cout<<sm<<endl;
    cout<<lr<<endl;


return 0;
}