//============================================================================
// Name        : 5.cpp
// Author      : Prasad Gujar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;

const int MAX_SIZE = 10;

class HashNode{
public:
string key;
string value;
HashNode* next;
HashNode(){
key="";
value="";
next=NULL;
}
HashNode(string key,string value){
this->key=key;
this->value=value;
this->next=NULL;
}

class HashTable{
public:
// vector<HashNode*> HashArray(10, nullptr);
HashNode* HashArray[10] = {nullptr};
int HashFunc(int p){
return p%10;
}
int getSum(string key){
int s=0;
for(int i=0;i<key.length();i++){
s+=key[i];
}
return s;
}
void insert(){
string k,v;
cout<<"Enter key :- ";
cin>>k;
cout<<"Enter value :- ";
cin>>v;
HashNode* temp = new HashNode(k,v);
int index = HashFunc(getSum(k));

if(HashArray[index]==NULL){
HashArray[index]=new HashNode(k,v);
cout<<HashArray[index]->key<<" inserted at "<<index<<endl;
}
else{
HashNode* nptr = HashArray[index];
while(nptr->next!=NULL){
if(nptr->key==k){
cout<<"key already exist!!"<<endl;
return;
}
nptr=nptr->next;
}
nptr->next = temp;
cout<<HashArray[index]->key<<" inserted at "<<index<<endl;
return;
}
}
void search(string key){
int index = HashFunc(getSum(key));
HashNode* nptr = HashArray[index];
while(nptr!=NULL){
if(nptr->key==key){
cout<<"Key Found at index :- "<<index<<endl;
cout<<key<<" : "<<nptr->value<<endl;
return;
}
nptr=nptr->next;
}
cout<<key<<" is not present in HashTable!!"<<endl;
return;
}

void del(string key){
int index = HashFunc(getSum(key));
bool flag=0;
if(HashArray[index]!=NULL){
if(HashArray[index]->key==key){
if(HashArray[index]->next!=NULL){
HashArray[index] = HashArray[index]->next;
cout<<key<<" deleted successfully!!"<<endl;
return;
}
else{
HashArray[index] = NULL;
cout<<key<<" deleted successfully!!"<<endl;
return;
}
}
else{
HashNode* nptr = HashArray[index];
while(nptr->next!=NULL){
if(nptr->next->key==key){
nptr->next=nptr->next->next;
cout<<key<<" deleted successfully!!"<<endl;
return;
}
}
cout<<"Key does not exist!!"<<endl;
}
}
else{
cout<<"Key does not exist!!"<<endl;
}
}
void display(){
for(int i=0;i<10;i++){
HashNode* nptr = HashArray[i];
cout<<i<<" ";
while(nptr!=NULL){
cout<<nptr->key<<" : "<<nptr->value<<" ";
nptr=nptr->next;
}
cout<<endl;
// cout<<i<<endl;
// if(HashArray[i]!=NULL){
// cout<<HashArray[i]->key<<" "<<HashArray[i]->value<<endl;
// }


}
}

};
};

int main() {
cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
HashNode::HashTable t;
t.display();
t.insert();
t.display();
t.insert();
t.display();
t.insert();
t.display();
cout<<"Enter key you wanna search :- "<<endl;
string k;cin>>k;
t.search(k);
cout<<"Enter key you wanna delete ;- "<<endl;
cin>>k;
t.del(k);
t.display();
// t.display();
return 0;
}