#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
    string data;
    Node* next;
    Node* down;
    int wt;
    public:
    Node(){
        data = "";
        next=NULL;
        down=NULL;
        wt = 0;
    }
    Node(string data,int wt){
        this->data = data;
        this->wt = wt;
        next = down = NULL;
    }
    class Graph{
        Node* root = new Node("999",INT_MAX);
        public:
        void add(Node* root,string c1,string c2,int wt){
            bool flag=0;
            Node* nptr = root;
            while(nptr->down){
                if(nptr->down->data==c1){
                    flag=1;
                    Node* curr = nptr->down;
                    while(curr->next){
                        curr = curr->next;
                    }
                    curr->next = new Node(c2,wt);
                    cout<<c1<<" inserted next to "<<c2<<" with weight "<<wt<<endl;
                    flag=1;
                    break;
                }
                nptr = nptr->down;
            }
            if(flag==0){
                nptr->down = new Node(c1,wt);
                Node* curr = nptr->down;
                while(curr->next){
                    curr = curr->next;
                }
                curr->next = new Node(c2,wt);
                cout<<c1<<" inserted next to "<<c2<<" with weight "<<wt<<endl;
            }
        }
        void add_edge(Node* root,string c1,string c2,int wt){
            add(root,c1,c2,wt);
            add(root,c2,c1,wt);
        }
        bool check(vector<string> arr,string s){
            for(auto i:arr){
                if(i==s){
                    return 1;
                }
            }
            return 0;
        }
        
    };
};