#include<iostream> 
#include<vector>
#include<stack>
#include<queue>
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
                    cout<<curr->next->data<<" Added adjacent to "<<nptr->down->data<<endl;
                }
                nptr = nptr->down;
            }
            if(flag==0){
                nptr->down = new Node(c1);
                Node* curr = nptr->down;
                // nptr->next = new Node(c2);
                while(curr->next){
                    curr = curr->next;
                }
                curr->next = new Node(c2);
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
        Node* find(Node* root,string start){
            Node* nptr = root;
            while(nptr){
                if(nptr->data==start){
                    return nptr;
                }
                nptr = nptr->down;
            }
            return NULL;
        }
        bool present(vector<string> arr,string s){
            for(auto i:arr){
                if(i==s){
                    return 1;
                }
            }
            return 0;
        }
        
        void bfs(Node* root,string start){
            vector<string> visited;
            queue<Node*> q; 
            Node* ptr = find(root,start);
            q.push(ptr);
            visited.push_back(ptr->data);
            while(!q.empty()){
                Node* frontNode = q.front();
                q.pop();
                cout<<frontNode->data<<" ";
                Node* curr = find(root,frontNode->data);
                while(curr){
                    if(!present(visited,curr->data)){
                        q.push(curr);
                        visited.push_back(curr->data);
                    }
                    curr = curr->next;
                }
            }
        }
        void dfs(Node* root,string start){
            vector<string> v;
            stack<Node*> s;
            Node* ptr = find(root,start);
            s.push(ptr);
            v.push_back(ptr->data);
            while(!s.empty()){
                Node* top = s.top();
                s.pop();
                cout<<top->data<<" ";
                Node* curr = find(root,top->data);
                while(curr){
                    if(!present(v,curr->data)){
                        s.push(curr);
                        v.push_back(curr->data);
                    }
                    curr = curr->next;
                }
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
    cout<<"BFS :- "<<endl;
    string start;
    cout<<"Enter start for BFS :- "<<endl;
    cin>>start;
    g.bfs(root,start);
    cout<<endl;
    cout<<"DFS :- "<<endl;
    // string start;
    cout<<"Enter start for DFS :- "<<endl;
    cin>>start;
    g.dfs(root,start);
}