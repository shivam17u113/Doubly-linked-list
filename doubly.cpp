#include<iostream>
#include<string.h>
using namespace std;

typedef struct linklist
{
int sal;
char name[10];
int id;
char company[10];
struct linklist *next;
struct linklist *prev;
}node;

node*getdata()
{

node *record;

record=new node;

cout<<"enter the salary";
cin>>record->sal;
cout<<"enter the name";
cin>>record->name;
cout<<"enter the company name";
cin>>record->company;
cout<<"enter the id";
cin>>record->id;
record->next=NULL;
record->prev=NULL;
return record;

}
// INSERT AT END
node* insert_end(node *head)
{
node *move,*newnode;
newnode=getdata();

if(head==NULL)
{
head=newnode;
	newnode->prev=head;
cout<<"head is created!!!";
}

else
{
move=head;
while(move->next!=NULL)
     move=move->next;

move->next=newnode;
newnode->prev=move;
}
return head;

}


// INSETR AT POSITION
 node *insert_mid(node *head)
 { 
  int pos,count=1;
  node *move,*newnode;
  move=head;
  cout<<" enter the position at which you wnat to insert";
  cin>>pos;
  
  newnode=getdata();
  move=head;
  while(count!=pos-1)
   {
   move=move->next;
   count++;
   }
   
   newnode->next=move->next;
                                               newnode->prev=move;
                                               (move->next)->prev=newnode;
   move->next=newnode;
    
    return head;
   
 }  
 
 // INSERT AT BEGINING
   
  node *insert_beg(node *head)
  {
  
  node *move,*newnode;
  newnode=getdata();
  
  newnode->next=head;
head->prev=newnode;
  head=newnode;
newnode->prev=NULL;
  
  return head;
  
 } 
 
 

// DISPLAY LINKLIST
void display(node* head)
{
node *move;
move=head;
while(move!=NULL)
{
cout<<"\n\t"<<"id::      "<<move->id<<"\n\t"<<"name::    "<<move->name<<"\n\t"<<"salary::  "<<move->sal<<"\n\t";
   cout<<"company::  "<<move->company<<"\n\t";
cout<<"\n\t";
cout<<"**********";
cout<<"\n\t";
move=move->next;

}
}
// delete at given position
node * Delete_position(node *head)
{
int pos,count=1;
cout<<"enter the which you want to delete ";
cin>>pos;

node*move;

move=head;

while(count!=pos)
{

move=move->next;
count++;
}
(move->next)->prev=move->prev;
(move->prev)->next=move->next;


move->next=NULL;
move->prev=NULL;


cout<<"deleted record is";

cout<<"\n\t"<<"id::      "<<move->id<<"\n\t"<<"name::    "<<move->name<<"\n\t"<<"salary::  "<<move->sal<<"\n\t";
   cout<<"company::  "<<move->company<<"\n\t";
cout<<"\n\t";
cout<<"**********";
cout<<"\n\t";
delete move;
return head;
}
// delete at first
node *delete_first(node *head)
{
node *move;
move=head;
head=head->next;

 head->prev=NULL;
move->next=NULL;

cout<<"deleted record is";

cout<<"\n\t"<<"id::      "<<move->id<<"\n\t"<<"name::    "<<move->name<<"\n\t"<<"salary::  "<<move->sal<<"\n\t";
   cout<<"company::  "<<move->company<<"\n\t";
cout<<"\n\t";
cout<<"**********";
cout<<"\n\t";

delete move;

return head;

}

// DELETE AT END
node *delete_end(node *head)
{
 int count=0,num=0;
 node *move,*a;
  move=head;
if(head==NULL)
 {
cout<<"list is empty";
 }

 else
 {
  while(move->next!=NULL)
   {
    move=move->next;
    }
(move->prev)->next=NULL;
move->prev=NULL;
    
    cout<<"the deleted record is";
  cout<<"\n\t"<<"id::      "<<move->id<<"\n\t"<<"name::    "<<move->name<<"\n\t"<<"salary::  "<<move->sal<<"\n\t";
   cout<<"company::  "<<move->company<<"\n\t";
cout<<"\n\t";
cout<<"**********";
cout<<"\n\t";
   delete move;
  }
   
  return head;
}
// search
  void search(node *head)
  {
  node *move;
move=head;
  int empid;
  cout<<"enter the employee ID";
  cin>>empid;
  
  while(move!=NULL && move->id!=empid)
  move=move->next;
  
  if(move==NULL)
  cout<<" \n\n Record not found";
  
  else
   cout<<"\n\n\t the record belonging to that id is";
  cout<<"\n\t"<<"id::      "<<move->id<<"\n\t"<<"name::    "<<move->name<<"\n\t"<<"salary::  "<<move->sal<<"\n\t";
   cout<<"company::  "<<move->company<<"\n\t";
cout<<"\n\t";
cout<<"**********";
cout<<"\n\t";
  
  }
  // REVERSE THE LINKLIST
  void display_reverse(node *head)
 {
   node*move;
       move=head;
   while(move->next!=NULL)
  move=move->next;

  while(move!=head)
{
   cout<<"\n\t"<<"id::      "<<move->id<<"\n\t"<<"name::    "<<move->name<<"\n\t"<<"salary::  "<<move->sal<<"\n\t";
   cout<<"company::  "<<move->company<<"\n\t";
cout<<"\n\t";
cout<<"**********";
cout<<"\n\t";
   move=move->prev;
   }
   if(move=head)
{
cout<<"\n\t"<<"id::      "<<move->id<<"\n\t"<<"name::    "<<move->name<<"\n\t"<<"salary::  "<<move->sal<<"\n\t";
   cout<<"company::  "<<move->company<<"\n\t";
cout<<"\n\t";
cout<<"**********";
cout<<"\n\t";

}
 }
   //REVERSE
node* reverse(node*first)
{
node*a,*b,*c;

a=NULL;
b=first;
c=b->next;
while(b!=NULL)
{
b->next=a;
a=b;
b=c;
   if(c!=NULL)
    c=c->next;
}
return a;
   
   }
   
  int main()
{
node *head=NULL;
int no,ch,ele;


do
{
cout<<"\n\t 1.insert node at end  \n\t 2.insert node at position \n\t3. insert node at begining \n\t 4.Delete at given position\n\t5. delete  first node \n\t 6.delete at end \n\t7.display \n\t 8.display reverse\n\t 9.Search\n\t10.reverse ";
cout<<"\n\t enter your choise";
cin>>ch;
switch(ch)
{
case 1:
 head=insert_end(head);
break;
case 2:
 head=insert_mid(head);
 break;
case 3:
head=insert_beg(head);
break;

case 4:

head=Delete_position(head);
break;

case 5:
head=delete_first(head);
break;

case 6:
head=delete_end(head);
break;

case 7:
 display(head);
 break;
 
 case 9:
  search(head);
  break;
 
case 8:
display_reverse(head);
break;
case 10:
  head=reverse(head);
break;
}
}
while(ch!=0);
return 0;
} 
   
   
   



