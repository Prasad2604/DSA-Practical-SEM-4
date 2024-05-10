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
    friend class Graph;

};

class Edge{
    private:
    string vertex1,vertex2;
    int wt;
    public:
    Edge(){
        vertex1=vertex2=" ";
        wt=0;
    }
    Edge(string vertex1,string vertex2,int wt){
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->wt = wt;
    }
    friend class Graph;
};

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
        Node* find(Node* root,string k){
            Node* nptr=root->down;
            while(nptr){
                if(nptr->data==k){
                    return nptr;
                }
            }
            return NULL;
        }

        void prims(Node *root,int n){
            vector<string> visited;
            int mincostspanningtree = 0;
            Node* nptr = root->down;
            visited.push_back(nptr->data);
            while(visited.size()<n){
                int mincost = 9999;
                Edge e;
                for(auto it:visited){
                    Node* ptr = find(root,it);
                    Node* child = ptr->next;
                    while(child){
                        if(!check(visited,child->data)){
                            if(child->wt<mincost){
                                e.vertex1 = ptr->data;
                                e.vertex2 = child->data;
                                e.wt = child->wt;
                                mincost = child->wt;
                            }
                        }
                        child = child->next;
                    }
                }
                cout<<"Edge added :- "<<e.vertex1<<"->"<<e.vertex2<<" "<<mincost<<endl;
                mincostspanningtree+=mincost;
                visited.push_back(e.vertex2);
            }
        }
    };

