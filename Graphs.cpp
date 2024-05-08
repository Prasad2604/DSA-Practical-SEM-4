#include<iostream> 
#include<vector>
using namespace std;

class Node{
    string data;
    Node* next;
    Node* down;
    public:
    Node(){
        data=" ";
        next = NULL;
        down = NULL;
    }
    Node(string data){
        this->data = data;
        next = NULL;
        down = NULL;
    }
    class Graph{
        // vector<Node*> clgMap; 
        Node* root;
        public:
        Graph(){
            root = new Node("ABCD");
        }

        void add_edge(Node* root,string c1,string c2){
            bool flag=0;
            Node* nptr = root;
            while(nptr->down){
                if(nptr->down->data==c1){
                    Node* curr = nptr->down;
                    flag=1;
                    while(curr->next){
                        curr = curr->next;
                    }
                    curr->next = new Node(c2);
                    cout<<"HEhehe"<<endl;
                    cout<<curr->next->data<<" Added adjacent to "<<nptr->down->data<<endl;
                }
                nptr = nptr->down;
            }
            // if(flag==0 && nptr->data==c1){
            //     Node* curr = nptr;
            //     while(curr->next){
            //         curr = curr->next;
            //     }
            //     curr->next = new Node(c2);
            //     flag=1;
            //     cout<<"Hiiii"<<endl;
            //     cout<<c2<<" Added adjacent to "<<c1<<endl;
            // }
            if(flag==0){
                nptr->down = new Node(c1);
                Node* curr = nptr->down;
                // nptr->next = new Node(c2);
                while(curr->next){
                    curr = curr->next;
                }
                curr->next = new Node(c2);
                cout<<"Helloooo"<<endl;
                cout<<c2<<" Added adjacent to "<<c1<<endl;
            }
        }
        void add(Node* root,string c1,string c2){
            add_edge(root,c1,c2);
            add_edge(root,c2,c1);
        }

        void disp(Node* root){
            Node* nptr = root;
            // cout<<root->down->data<<endl;
            while(nptr->down){
                cout<<nptr->down->data<<"->";
                Node* curr = nptr->down;
                while(curr->next){
                    cout<<curr->next->data<<"->";
                    curr = curr->next;
                }
                cout<<endl;
                nptr = nptr->down;
            }

        }
        
    };
};

int main(){
    int n;
    Node::Graph g;
    cout<<"Enter number of edges you wanna add :- ";
    cin>>n;
    Node* root = new Node("ABCD");
    while(n--){
        string c1;
        string c2;
        cout<<"Enter city1 :- ";
        cin>>c1;
        cout<<"Enter city2 :-  ";
        cin>>c2;
        g.add(root,c1,c2);
    }
    g.disp(root);
}