#include<iostream>
#include<fstream>

using namespace std;

class Student{
    int roll_no;
    string name;
    string div;
    public:
    Student(){
        roll_no=0;
        name="";
        div ='A';
    }
    Student(int roll_no,string name,string div){
        this->roll_no = roll_no;
        this->name = name;
        this->div = div;
    }
    friend fstream &operator<<(fstream& out,Student &s);
    friend fstream &operator>>(fstream& in,Student &s);
    friend ostream &operator<<(ostream& out,Student &s);
    void display(fstream &in,Student &s){
        in.open("file1.txt",ios::in);
        while(1){
            in>>s;
            if(in.eof()){
                break;
            }
            cout<<s<<endl;;
        }
        in.close();
    }
    void search(fstream &in,int x,Student &s){
        in.open("file1.txt",ios::in);
        while(1){
            in>>s;
            if(s.roll_no==x){
                cout<<s<<endl;
                break;
            }
            if(in.eof()){
                cout<<"Record not found !!"<<endl;
                break;
            }
        }
        in.close();
    }
    void delete1(fstream &in,int x,Student &s,int n){
        in.open("file1.txt",ios::in);
        Student arr[n];
        for(int i=0;i<n;i++){
            in>>s;
            arr[i] = s;
        }
        in.close();
        in.open("file1.txt",ios::out|ios::trunc);
        for(int i=0;i<n;i++){
            // in>>s;
            if(arr[i].roll_no==x){
                continue;
            }
            else{
                in<<arr[i];
                cout<<arr[i];
            }
        }
        in.close();
    }
};

fstream &operator<<(fstream& out1,Student& s){
    out1 << s.roll_no<<" ";
    out1 <<s.name<<" ";
    out1<<s.div<<" ";
    out1<<endl;
    return out1;
}
fstream &operator>>(fstream& in1,Student& s){
    in1>>s.roll_no;
    in1>>s.name;
    in1>>s.div;
    return in1;
}
ostream &operator<<(ostream& out1,Student& s){
    out1 <<s.roll_no<<" ";
    out1<<s.name<<" ";
    out1<<s.div<<" ";
    out1<<endl;
    return out1;
}
int main(){
    fstream myfile;
    Student s;
    int n;
    cout<<"Number of students :- ";
    cin>>n;
    myfile.open("file1.txt",ios::out);
    for(int i=0;i<n;i++){
        int roll_no;
        cout<<"Enter roll no :- ";
        cin>>roll_no;
        string name;
        cout<<"Enter name :- ";
        cin>>name;
        string div;
        cout<<"Enter your division :- ";
        cin>>div;
        Student s1(roll_no,name,div);
        myfile<<s1;
    }
    myfile.close();
    s.display(myfile,s);
    s.delete1(myfile,1,s,n);
}
