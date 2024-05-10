#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node
{
private:
    char name;
    int val;
    node *next;
    node *down;

public:
    node()
    {
        name = '\n';
        val = 0;
        next = down = nullptr;
    }
    node(char n, int v)
    {
        name = n;
        val = v;
        next = down = nullptr;
    }
    friend class graph;
};

class edge
{
private:
    char vertex1, vertex2;
    int weight;

public:
    edge()
    {
        vertex1 = '\n';
        vertex2 = '\n';
        weight = 0;
    }
    edge(char v1, char v2, int w)
    {
        vertex1 = v1;
        vertex2 = v2;
        weight = w;
    }
    friend class graph;
};

class graph
{
private:
    node *head = nullptr;

    void addedge(char parent, char child, int wt)
    {
        // cout<<2<<endl;
        if (head == nullptr)
        {
            // cout<<3<<endl;
            head = new node(parent, 0);
            node *newnode = new node(child, wt);
            head->next = newnode;
        }
        else
        {
            node *current = head;
            node *previous = nullptr;
            bool found = false;
            while (current)
            {
                if (current->name == parent)
                {
                    found = true;
                    node *horizontal = current;
                    while (horizontal->next != nullptr)
                    {
                        horizontal = horizontal->next;
                    }
                    node *newnode = new node(child, wt);
                    horizontal->next = newnode;
                    break;
                }
                previous = current;
                current = current->down;
            }
            if (!found)
            {
                node *newparent = new node(parent, 0);
                node *newchild = new node(child, wt);
                previous->down = newparent;
                newparent->next = newchild;
            }
        }
    }

public:
    // graph()
    // {
    //     head = nullptr;
    // }
    void addingedge(char p, char c, int w)
    {
        // cout<<1<<endl;
        addedge(p, c, w);
        // cout<<2<<endl;
        addedge(c, p, w);
    }

    void display()
    {
        node *vertical = head;
        while (vertical)
        {
            node *horizontal = vertical->next;
            cout << vertical->name << "----> ";
            while (horizontal)
            {
                cout << horizontal->name << "(" << horizontal->val << ") ";
                horizontal = horizontal->next;
            }
            cout << endl;
            vertical = vertical->down;
        }
    }

    void prims()
    {
        vector<char> visited;
        int mincostspantree = 0;
        visited.push_back(head->name);
        while (visited.size() < 4)
        {
            int mincost = 9999;
            edge mincostedge;
            for (auto it : visited)
            {
                node *parent = head;
                while (parent)
                {
                    /* code */ if (parent->name == it)
                    {
                        node *child = parent->next;
                        while (child)
                        {
                            if (find(visited.begin(), visited.end(), child->name) == visited.end())
                            {
                                if (child->val < mincost)
                                {
                                    mincostedge.vertex1 = parent->name;
                                    mincostedge.vertex2 = child->name;
                                    mincostedge.weight = child->val;
                                    mincost = child->val;
                                }
                            }
                            child = child->next;
                        }
                        break;
                    }
                    parent = parent->down;
                }
            }
            cout << "PATH ADDED : " << mincostedge.vertex1 << "--->" << mincostedge.vertex2 << " " << mincost;
            cout << endl;
            mincostspantree = mincostspantree + mincost;
            visited.push_back(mincostedge.vertex2);
        }
    }

};

//     void prims()
//     {
//         // cout<<1<<endl;
//         vector<char> visited;
//         int mcst = 0;
//         visited.push_back(head->name);
//         while (visited.size() < 4)
//         {
//             // cout<<2<<endl;
//             int mc = 9999;
//             edge mce;
//             for (auto it : visited)
//             {
//                 // cout<<3<<endl;
//                 node *parent = head;
//                 while (parent)
//                 {
//                     // cout<<4<<endl;
//                     if (parent->name == it)
//                     {
//                         // cout<<5<<endl;
//                         node* child = parent->next;
//                         while(child){
//                             if(find(visited.begin(),visited.end(),child->val)==visited.end()){
//                                 if(child->val<mc){
//                                     mce.vertex1=parent->val;
//                                     mce.vertex2=child->val;
//                                     mce.weight=child->val;
//                                     mc = child->val;
//                                 }
//                             }
//                             child=child->next;
//                         }
//                         break;
//                     }
//                     parent = parent->down;
//                 }
//             }
//             cout<<"path added : "<<mce.vertex1<<" ---> "<<mce.vertex2<<" cost: "<<mce.weight<<endl;
//             mcst=mcst+mc;
//             visited.push_back(mce.vertex2);
//         }
//     }
// };

int main()
{
    graph g;
    // cout<<"HI"<<endl;
    g.addingedge('A', 'B', 10);
    // cout << "HI!" << endl;
    g.addingedge('B', 'C', 20);
    g.addingedge('C', 'D', 30);
    g.addingedge('D', 'A', 40);
    g.display();
    cout << endl;
    g.prims();
}