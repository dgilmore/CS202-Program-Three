//David Gilmore CS202 PROGRAM #3 WINTER 17
//This file holds the implementations for the bst_node and the bst_adt
//classes. The bst_node holds the last name of a contact and the list of
//all contacts with that same last name. The bst_adt call insert, display all, serach
//and remove all. If I had more time I would have properly implemented the remove function for
// a single node. Also If I had more time I would have implemented the inheritance that I had envisioned
//where the bst_node inherited from the list_adt, so that a node would have access to all of the list_adt
//class functions. I had a tough time getting it to work, so I simplified so that I could get the assignment done. 

#include "contact.h"

//node class default  constructor 
node::node()
{
   first_name = NULL;
   home_num = NULL;
   cell = NULL;
   email = NULL;
   next = NULL;
}

//node class argument constructor 
node::node(char * name, char * hp, char * cll, char * em, node * nt)
{
   first_name = new char[strlen(name) + 1];
   strcpy(first_name, name);
   home_num = new char[strlen(hp) + 1];
   strcpy(home_num, hp);
   cell = new char[strlen(cll) + 1];
   strcpy(cell, cll);
   email = new char[strlen(em) + 1];
   strcpy(email, em); 
   next = nt;   
}

//node class destructor
node::~node() 
{
   if(!first_name)
      delete [] first_name;
   if(!home_num)
      delete [] home_num;
   if(!cell)
      delete [] cell;
   if(!email)
      delete [] email;
   if(!next)
      delete next;
}

//node class copy constructor 
node::node(const node &node2)
{
   first_name = new char[strlen(node2.first_name) + 1];
   strcpy(first_name, node2.first_name);
   home_num = new char[strlen(node2.home_num) + 1];
   strcpy(home_num, node2.home_num);
   cell = new char[strlen(node2.cell) + 1];
   strcpy(cell, node2.cell);
   email = new char[strlen(node2.email) + 1];
   strcpy(email, node2.email); 
   next = node2.next; 
}

//wrapper function to set the current node next
//pointer to null
void node::set_null()
{
   next = NULL;
}

//wrapper function to set next pointer of current node
void node::set_next(node * nxt)
{
    next = nxt; 
}

//returns the node pointer for the current node
node*& node::get_next()
{
   return next;
}

//returns a char pointer from current node
char* node::get_first() const
{
   return first_name;
}

/*
//node class overloaded = operator 
node& node::operator=(const node &node2)
{
   if(this == &node2)
      return *this;
  
   if(first_name)
      delete [] first_name;
   if(home_num)
      delete [] home_num;
   if(cell)
      delete [] cell;
   if(email)
      delete [] email;
   if(next)
      delete next;

   first_name = new char[strlen(node2.first_name) + 1];
   strcpy(first_name, node2.first_name);
   home_num = new char[strlen(node2.home_num) + 1];
   strcpy(home_num, node2.home_num);
   cell = new char[strlen(node2.cell) + 1];
   strcpy(cell, node2.cell);
   email = new char[strlen(node2.email) + 1];
   strcpy(email, node2.email); 
   next = node2.next; 
   return *this;
}
*/

//node class overloaded == operator
//when bother arg's are node reference
bool operator==(const node &node2, node &an_node)
{
   if(strcmp(node2.get_first(), an_node.get_first()) == 0)
         return true;
   else
         return false; 
}

//node class overloaded == operator
//for node ref and node pointer
bool operator==(const node &node2, node * comp)
{
   if(strcmp(node2.get_first(), comp->get_first()) == 0)
           return true;
   else
           return false;
}

//overloaded == operator, pointer arg and node ref
bool operator==(node *comp, const node &node2)
{
    if(strcmp(node2.get_first(), comp->get_first()) == 0)
       return true;
    else
       return false;
}

//node class overloaded != operator
bool operator!=(const node &node2, node &an_node)
{
   if(strcmp(node2.get_first(), an_node.get_first()) != 0)
        return true;
   else
        return false;
}

//node class != overloaded operator, node ref and node pointer
bool operator!=(const node &node2, node * comp)
{
   if(strcmp(node2.get_first(), comp->get_first()) != 0)
        return true;
   else
        return false;
}

//overloaded with a pointer and ref to node as arguments
bool operator!=(node * comp, const node &node2)
{
   
   if(strcmp(node2.get_first(), comp->get_first()) != 0)
        return true;
   else
        return false;
}

//node class overloaded < operator
bool operator<(const node &node2, node &an_node)
{
    if(strcmp(node2.get_first(), an_node.get_first()) < 0)
         return true; 
    else
         return false;
}

//node class overloaded < node ref and node pointer
bool operator<(const node &node2, node * comp)
{
 
    if(strcmp(node2.get_first(), comp->get_first()) < 0)
         return true; 
    else
         return false;
}

//node class overloaded < node ref and node pointer
bool operator<(node * comp, const node &node2)
{
    if(strcmp(node2.get_first(), comp->get_first()) < 0)
         return true; 
    else
         return false;
}

//node class overloaded > operator
bool operator>(const node &node2, node &an_node)
{
    if(strcmp(node2.get_first(), an_node.get_first()) > 0)
         return true;
    else
         return false; 
}

//node class overloaded > operator
bool operator>(const node &node2, node * comp)
{
    if(strcmp(node2.get_first(), comp->get_first()) > 0)
         return true;
    else
         return false; 
}

//node class overloaded > operator, pointer and node ref as arg
bool operator>(node * comp, const node &node2)
{
    if(strcmp(node2.first_name, comp->get_first()) > 0)
         return true;
    else
         return false; 
}

//node class overloaded << operator 
ostream& operator<<(ostream &out, const node &node2)
{
    out << "First Name: " << node2.first_name << endl;
    out << "Home Phone: " << node2.home_num << endl;
    out << "Cell Phone: " << node2.cell << endl;
    out << "Email:      " << node2.email << endl;
}

//node class overloaded for a node pointer output
ostream& operator<<(ostream &out, node * node2)
{
    out << "First Name: " << node2->first_name << endl;
    out << "Home Phone: " << node2->home_num << endl;
    out << "Cell Phone: " << node2->cell << endl;
    out << "Email:      " << node2->email << endl;
}

//List class default constructor
list_adt::list_adt()
{
   head = NULL;
}

//list class default destructor
list_adt::~list_adt()
{
  if(!head)
     delete head;
}

//insert wrapper function to add a new node to the proper place in list 
int list_adt::insert(node &to_copy)
{   
    node * prev = NULL; 
    //prev->set(head); 
    return insert_pr(head, prev, to_copy);
}

//recursive insert function for LLL, private. 
int list_adt::insert_pr(node *& head, node *& prev, node &to_copy)
{
   if(!head)//empty list
   {
      head = new node(to_copy);
      head->set_null(); 
      return 1; 
   }

   if(head == to_copy || head < to_copy) //add a node in middle of list in order
   {
      node * temp = new node(to_copy);
      temp->set_next(head);
      if(prev)
      { 
        prev->set_next(temp);
      }
      head = temp; 
      return 1;
   }


   insert_pr(head->get_next(), head, to_copy); 
    //recursive call
}

//display wrapper function for LLL
void list_adt::display() const
{
   display_pr(head);
}

//recursive display function for LLL
void list_adt::display_pr(node * head) const 
{
   if(!head)
       return;

    cout << head << endl;    
    display_pr(head->get_next());
}

//seearch wrapper function for LLL 
void list_adt::search(char * to_find)
{
   search_pr(head, to_find);
}
  
//recursive search function for LLL
void list_adt::search_pr(node * head, char * to_find)
{
   if(!head)
      return;

   if(strcmp(head->get_first(), to_find) == 0)
   {
      cout << head << endl;
   }

   search_pr(head->get_next(), to_find); 
}

//remove wrapper function for LLL
int list_adt::remove(char * to_remove)
{
   node * prev = NULL;
   return remove_pr(head, prev, to_remove);
}

//recursive remove function for LLL
int list_adt::remove_pr(node *& head, node *& prev, char * to_remove)
{
   if(!head)//if list is emtpy
      return 0;

   if(strcmp(head->get_first(), to_remove) == 0)//compare 
   {
      if(!prev)//if first in the list
      {
         node * temp = head->get_next();
	 delete head;
	 head = temp;
	 return 1;
      }

      if(!head->get_next())//if last in the list
      {
         prev->set_null(); 
	 delete head;
	 head = NULL;
	 return 1;
      }
      //in the middle of the list
      node * temp = head->get_next();
      delete head;
      prev->set_next(temp);
      head = temp;
      return 1;
   }
   //recursive call
   remove_pr(head->get_next(), head, to_remove);
}

//remove_all wrapper function
int list_adt::remove_all()
{
   return remove_all_pr(head);
}

//remove_all recursive function 
int list_adt::remove_all_pr(node *& head)
{
   
   if(!head)
      return 1;

   node * temp = head->get_next();
   delete head;
   head = temp;

   remove_all_pr(head); 
}
