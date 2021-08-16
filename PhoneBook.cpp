#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct node
{
   string name , number;
   node *next;
};
node *head = NULL , *newnode , *temp;
int len = 0 ;
void C_node ()
{
    int n;
    cout<<"how many contacts do you want to add today?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        newnode = new node;
        cout<<"Enter Name of contact"<<i+1<<endl;
        cin>>newnode->name;
        cout<<"Enter number of contact"<<i+1<<endl;
        cin>>newnode->number;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next= newnode;
            temp = newnode;
        }
    }
}
void display ()
{
    if(head == NULL)
    {
        cout<<"Contact list is Empty "<<endl;
    }
    else
    {
        node *p = head ;
        while (p != NULL)
        {
            cout<<"\nFull Name "<<p->name<<endl;
            cout<<"\nPhone Number "<<p->number<<endl;
            cout<<"-------------------------"<<endl;
            p= p->next;
            len++;
        }
        cout<<"Total contacts in the list = "<<len<<endl;
    }
}
void search_contact ()
{
    node *search_node = head;
    string s;
    int count = 0;
    cout<<"Enter your desired contact you want to search ";
    cin>>s;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nList is Empty "<<endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if(s == search_node->name || s == search_node->number)
            {
                cout<<"\n\t\tFull name: "<<search_node->name<<endl;
                cout<<"\t\tPhone number: "<<search_node->number<<endl;
                found =true;
                
            }
            search_node = search_node->next;
            count++;
            if(found == true)
            {
                cout<<"\t\tIndex of the Contact = "<<count<<endl;
                found=false;
            }
        }
    }
    
    if(found==false)
    {
        cout<<"Desired contact not fount "<<endl;
    }
}

void delete_contact()
{
    node *search_node = head->next;
    node *q;
    struct node *p = head;
    string s;
    bool d=false;
    int count = 1;
    cout<<"Enter your desired contact number you want to delete ";
    cin>>s;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nList is Empty "<<endl;
    }
    else
    {
        if( s == head->number)
        {
            q = head;
            head = head->next;
            delete q;
            cout<<"Contact has been deleted "<<endl;
        }
        else{
            while (search_node != NULL)
            {
                if( s == search_node->number)
                {
                    q=p;
                    p=p->next;
                    d=true;
                    break;
                }
                search_node = search_node->next;
            }        
            q->next = p->next;
            delete p;
            cout<<"Contact of has been deleted "<<endl;    
            if(d == true)
            {
    
            cout<<"\t\tIndex of the Contact = "<<count<<endl;
            }
            else
            {
            cout<<"Desired contact not fount "<<endl;
            }
        }
    }
    
}

void clear_all ()
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        temp = head ;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout<<"\n\t\tALL contact list has been deleted "<<endl;
    }
}


    

int main ()
{
    int op;
    cout<<"\t\t\t\t\tWELCOME TO ONLINE PHONE BOOK DIRECTORY\t\t\t\t\t"<<endl;
    cout<<"Enter 1 to add contact "<<endl;
    cout<<"Enter 2 to display all contact "<<endl;
    cout<<"Enter 3 to search contact "<<endl;
    cout<<"Enter 4 to delete contact from where you want "<<endl;
    cout<<"Enter 5 to clear All record "<<endl;
    cout<<"Enter 6 to exit"<<endl;
    while (true )
    {
        
        cin>>op;
        switch (op)
        {
        case 1:
            C_node();
            cout<<"enter next operation"<<endl;
            break;
        case 2:
            len = 0;
            display();
            cout<<"enter next operation"<<endl;
            break;
        case 3:
            search_contact();
            cout<<"enter next operation"<<endl;
            break;
        case 4:
            delete_contact();
            cout<<"enter next operation"<<endl;
            break;
        case 5:
            clear_all();
            cout<<"enter next operation"<<endl;
            break;
        case 6:
            exit(1);
        default:
            cout<<"Invalid Option "<<endl;
        }
    }
}


