//David Gilmore CS202 Program #3 Winter 17
//This file holds the implementations for the bst_node and the bst_adt
//classes. The bst_node holds the last name of a contact and the list of
//all contacts with that same last name. The bst_adt call insert, display all, serach
//and remove all. If I had more time I would have properly implemented the remove function for
// a single node. Also If I had more time I would have implemented the inheritance that I had envisioned
//where the bst_node inherited from the list_adt, so that a node would have access to all of the list_adt
//class functions. I had a tough time getting it to work, so I simplified so that I could get the assignment done. 

#include "contact.h"

//bst node constructor
bst_node::bst_node()
{
   last_name = NULL;
   right = NULL;
   left = NULL;
}

//bst node destructor 
bst_node::~bst_node()
{
   if(!last_name)
      delete [] last_name;
   if(!right)
      delete right;
   if(!left)
      delete left;
}

//bst node argument constructor
bst_node::bst_node(char * l_name, bst_node * rght, bst_node * lft)
{
    last_name = new char[strlen(l_name) + 1];
    strcpy(last_name, l_name); 

    right = rght;
    left = lft;
}

//bst node copy consturctor
bst_node::bst_node(const bst_node &b_node)
{
   last_name = new char[strlen(b_node.get_last())];
   strcpy(last_name, b_node.get_last()); 
}

//bst node retursn last name char * for compares
char* bst_node::get_last() const
{
   return last_name;
}

//wrapper function returns the right node pointer
bst_node*& bst_node::go_right()
{
   return right;
}

//wrapper function returns the left node pointer
bst_node *& bst_node::go_left()
{
  return left;
}

//set the right node pointer to null
void bst_node::set_right_null()
{
   right = NULL;
   return;
}

//sets the left node pointer to null
void bst_node::set_left_null()
{
   left = NULL;
   return;
}

void bst_node::set_last(char * lst_nme)
{
   last_name = new char[strlen(lst_nme) + 1];
   strcpy(last_name, lst_nme);
   return;
} 

//wrapper function for the bst_node class to call the insert
//function for the LLL
int bst_node::my_insert(node to_add)
{
   return my_list.insert(to_add);
   
}

//list destroyer 
void bst_node::my_destroy()
{
   my_list.remove_all();
}

//wrapper function to call the LLL display once a match has
//been found or the whole list is displayed.
void bst_node::my_display() const
{
   my_list.display();
}

//wrapper function to call the search on a LLL
void bst_node::my_search(char * frst_name)
{
  my_list.search(frst_name);
}


//overloaded operator == both node ref
bool operator==(const bst_node &my_node, bst_node &b_node)
{
   if(strcmp(my_node.get_last(), b_node.get_last()) == 0)
     return true;
   else
     return false;
}

//overloaded op == for bst node ref and pointer
bool operator==(const bst_node &my_node, bst_node *b_node)
{
   if(strcmp(my_node.get_last(), b_node->get_last()) == 0)
      return true;
   else
      return false;
}

//overloaded op == for bst node ref and pointer
bool operator==(bst_node *b_node, const bst_node &my_node)
{
   if(strcmp(b_node->get_last(), my_node.get_last()) == 0)
     return true;
   else
     return false;
}

//overloaded != for two bst node ref
bool operator!=(const bst_node &my_node, const bst_node &b_node)
{
   if(strcmp(my_node.get_last(), b_node.get_last()) == 0)
      return false;
   else
      return true;
}

//overloaded != for ref and pointer
bool operator!=(const bst_node &my_node, bst_node *b_node)
{
   if(strcmp(my_node.get_last(), b_node->get_last()) == 0)
     return false;
   else
     return true;
}

//for ref and pointer
bool operator!=(const bst_node *b_node, bst_node &my_node)
{
  if(strcmp(b_node->get_last(), my_node.get_last()) == 0)
    return false;
  else 
    return true; 
}

//for two referecnes 
bool operator<(const bst_node &my_node, bst_node &b_node)
{
   if(strcmp(my_node.get_last(), b_node.get_last()) < 0 )
     return true;
   else
     return false;
}

//for a ref and pointer
bool operator<(const bst_node &my_node, bst_node *b_node)
{
  if(strcmp(my_node.get_last(), b_node->get_last()) < 0)
    return true;
  else
   return false;
}

//for a pointer and a ref
bool operator<(const bst_node *b_node, bst_node &my_node)
{
  if(strcmp(my_node.get_last(), b_node->get_last()) < 0)
    return true;
  else
   return false;
}

//for two node ref
bool operator>(const bst_node &my_node, bst_node &b_node)
{
  if(strcmp(my_node.get_last(), b_node.get_last()) > 0)
    return true;
  else
   return false;
}

//for a pointer and node ref
bool operator>(const bst_node &my_node, bst_node *b_node)
{
  if(strcmp(my_node.get_last(), b_node->get_last()) > 0)
    return true;
  else
   return false;
}

//for a pointer and node ref
bool operator>(const bst_node *b_node, bst_node &my_node)
{
  if(strcmp(my_node.get_last(), b_node->get_last()) > 0)
    return true;
  else
   return false;
}

//node class overloaded << operator 
ostream& operator<<(ostream &out, const bst_node &node2)
{
    out << "Last Name: " << node2.get_last() << endl;
    node2.my_display(); 
}

//node class overloaded << operator 
ostream& operator<<(ostream &out, bst_node * node2)
{
    out << "Last Name: " << node2->get_last() << endl;
   // node2->my_display();    
}

//bst_adt constructor
bst_adt::bst_adt()
{
   root = NULL; 
}

//bst_adt destructor
bst_adt::~bst_adt()
{
   if(!root)
      delete root;
}

//bst_adt wrapper insert function 
int bst_adt::insert(char * lst_nme, node &to_add)
{
   return insert_pr(lst_nme, to_add, root); 
}

//bst_adt recursive function to insert in a bst
int bst_adt::insert_pr(char * lst_nme, node &to_add, bst_node *& root)
{
   if(!root)
   {
      root = new bst_node; 
      root->set_last(lst_nme); 
      root->my_insert(to_add); 
      root->set_right_null();
      root->set_left_null();
      return 1;
   }

   if(strcmp(root->get_last(), lst_nme) == 0)
   {
      root->my_insert(to_add);
      return 1;
   }

   if(strcmp(lst_nme, root->get_last()) == 0 || strcmp(lst_nme, root->get_last()) > 0)
   {
       insert_pr(lst_nme, to_add, root->go_right());
   }
   else
       insert_pr(lst_nme, to_add, root->go_left());
}

//bst search wrapper function takes lst name to find right node and first
//name to search the LLL for the correct first name
void bst_adt::search(char * lst_name, char * frst_name)
{
   search_pr(root,frst_name, lst_name);
}

//recursive search function taking last name to find right tree node and first
//name to search the LLL for correct firs name
void bst_adt::search_pr(bst_node * root, char * frst_name, char * lst_name)
{
   if(!root)
     return;

   if(strcmp(root->get_last(), lst_name) == 0)
   {
      root->my_search(frst_name);
      return;
   }

   if(strcmp(root->get_last(), lst_name) > 0)
     search_pr(root->go_left(), frst_name, lst_name);
   else
     search_pr(root->go_right(), frst_name, lst_name);
}

//bst display wrapper function
void bst_adt::display()
{
  display_pr(root);
}

//bst tree recursive wrapper function
void bst_adt::display_pr(bst_node * root)
{
   if(!root)
     return;

   cout << root << endl; 
   root->my_display(); 
   display_pr(root->go_left());
   display_pr(root->go_right());
}

//wrapper function for remove_all for the bst
int bst_adt::remove_all()
{
   return remove_all_pr(root);
}

//revursive function to removall all trees 
int bst_adt::remove_all_pr(bst_node *& root)
{
   if(!root)
      return 1;
   root->my_destroy(); 
   delete root;
   remove_all_pr(root->go_left());
   remove_all_pr(root->go_right());
}

//controller create bst function, simply creates a bunch of contacts and inserts
//into the tree so we can test our structures
int controller::create_bst()
{
   char name1 [] = "Dj";
   char name2 [] = "Billy";
   char name3 [] = "Rachel";
   char name4 [] = "Kelsey";
   char name5 [] = "Douglas";
   char name6 [] = "Kim";

   char l_name1[] = "Jones";
   char l_name2[] = "Meyers";
   char l_name3[] = "Reynolds"; 

   char number1 [] = "503-223-3456";
   char number2 [] = "415-543-6577";
   char number3 [] = "545-342-2221";

   char cell1[] = "444-444-4444";
   char cell2[] = "222-222-2222";
   char cell3[] = "555-555-5555";

   char email1[] = "Dj@pdx.edu";
   char email2[] = "Billy@pdx.edu";
   char email3[] = "Rachel@pdx.edu";
   char email4[] = "Kelsey@pdx.edu";
   char email5[] = "Douglas@pdx.edu";
   char email6[] = "kim@pdx.edu"; 

  node node1(name1, number1, cell1, email1, NULL);
  node node2(name2, number2, cell2, email2, NULL);
  node node3(name3, number3, cell3, email3, NULL);
  node node4(name4, number1, cell1, email4, NULL);
  node node5(name5, number2, cell2, email5, NULL);
  node node6(name6, number3, cell3, email6, NULL); 

  my_bst.insert(l_name1, node1);
  my_bst.insert(l_name1, node2);
  my_bst.insert(l_name2, node3);
  my_bst.insert(l_name2, node4);
  my_bst.insert(l_name3, node5);
  my_bst.insert(l_name3, node6); 
  return 1;
} 

//controller class contact menu
//holds the logic for the user to decide what they want to do with the list
//of contacts, they can search, insert, display all or remove
void controller::contact_menu()
{
  char name[200]; 
  char l_name[200];
  char phone[200];
  char cell[200];
  char email[200]; 
  char response = 'Y';
  char answer;
  
  cout << "*******************WELCOME THE YOUR EMERGENCY CONTACT LIST*************************" << endl;

  while(response == 'Y' || response == 'y')
  {
     cout << "Please choose one of the following options:    " << endl;
     cout << "Press 'D' to display the contact list:         " << endl;
     cout << "Press 'A' to add a contact:                    " << endl; 
     cout << "Press 'R' to remove a contact:                 " << endl;
     cout << "Press 'S' to search for a contact:             " << endl;

     cin >> answer;
     cin.ignore(100, '\n'); 
     answer = toupper(answer); 
     
     if(answer == 'D')
         my_bst.display();
    
     if(answer == 'A')
     {
       
       cout << "Please Enter the first name of your contact: " << endl;
       cin >> name;
       cin.ignore(100, '\n');

      cout << "Please Enter the last Name:  " << endl;
      cin >> l_name;
      cin.ignore(100, '\n');

      cout << "Please Enter the contact home phone number: " << endl;
      cin >> phone;
      cin.ignore(100, '\n');

      cout << "Please Enter the contacts cell phone number: " << endl;
      cin >> cell;
      cin.ignore(100, '\n');

      cout << "Please Enter the contacts email: " << endl;
      cin >> email;
      cin.ignore(100, '\n');

      node b_node(name, phone, cell, email, NULL);
      my_bst.insert(l_name, b_node);
    }


     if(answer == 'S')
     {
        cout << "Please Enter the First Name of the contact you'd like to search for: " << endl;
	cin >> name;
	cin.ignore(100, '\n'); 

	cout << "Now please enter the Last Name of the contact you'd like to search for: " << endl;
	cin >> l_name;
	cin.ignore(100, '\n');

	my_bst.search(l_name, name); 
     }

     cout << "Would you like to see the menu again? " << endl;
     cin >> response;
     cin.ignore(100, '\n'); 

  }
}

//destroys the bst and kicks off the list destroy function. 
int controller::destroy()
{
   return my_bst.remove_all();
}


