//David Gimore CS202 Program #3 Winter 17 
//This is my header file for all of my classes
//There are two nodes classes, one of which is for a LLL of contact info
//and the other is for the bst tree which holds the LLL for contacts with the same
//last name. There are two classes that manage the tree and list which can each display
//insert, search and remove and remove all. Finally there is a controller class that adds another level
//of abstraction to the user/client. 


#include <iostream>
#include <cctype>
#include <cstring>
using namespace std; 

//forward class declarations
class bst_adt;
class list_adt;
class bst_node;
class node;

//the bst adt class declaration
//this class controlls the bst 
class bst_adt
{
   public:
      bst_adt();
      ~bst_adt();
      int insert(char * lst_name, node &to_add);
      int remove();
      void search(char * lst_name, char * frst_name);
      void display();
      int remove_all();
      
   private:
      int insert_pr(char * lst_nme, node &to_add, bst_node *& root); 
      void search_pr(bst_node * root, char * frst_nme, char * lst_name); 
      void display_pr(bst_node * root);
      int remove_all_pr(bst_node *& root);
      bst_node * root;
};


class controller
{
   public: 
      int create_bst();
      void contact_menu(); 
      int destroy(); 
   private:
       bst_adt my_bst;
};


//the list adt controls all the functionality
//for the list that is in each bst node
class list_adt
{
   public:
     list_adt();
     ~list_adt();
     int insert(node &to_copy);
     int remove(char * to_remove);
     void search(char * to_find);
     int remove_all();
     void display() const; 
   protected:
       void display_pr(node * head) const; 
       int insert_pr(node *&head, node*&prev, node &to_copy); 
       void search_pr(node * head, char * name2); 
       int remove_pr(node *& head, node *& prev, char * to_remove);
       int remove_all_pr(node *& head); 
       node * head;
};

//bst node class holds the last name for a contact and 
//the list of contact info for everyone with that last name
class bst_node
{

   public:
      bst_node();
      ~bst_node();
      bst_node(char * name, bst_node * rght, bst_node * lft);
      bst_node(const bst_node &b_node); 
      void set_right(bst_node * rght);
      void set_left(bst_node * lft);
      bst_node *& go_right();
      bst_node *& go_left();
      void set_right_null();
      void set_left_null();
      char* get_last() const; 
      friend bool operator==(const bst_node&, bst_node&);
      friend bool operator==(const bst_node&, bst_node*);
      friend bool operator==(bst_node*, const bst_node&);
      friend bool operator!=(const bst_node&, const bst_node&);
      friend bool operator!=(const bst_node&, bst_node*);
      friend bool operator!=(const bst_node*, bst_node&);
      friend bool operator<(const bst_node&, bst_node&);
      friend bool operator<(const bst_node&, bst_node*);
      friend bool operator<(bst_node*, const bst_node&);
      friend bool operator>(const bst_node&, bst_node&);
      friend bool operator>(const bst_node&, bst_node*);
      friend bool operator>(bst_node*, const bst_node&);   
      friend ostream& operator<<(ostream &out, const bst_node &node2);
      friend ostream& operator<<(ostream &out, bst_node * b_node); 
      int my_insert(node to_add);
      void my_display() const;
      void my_search(char * frst_name); 
      void set_last(char * lst_nme); 
      void my_destroy(); 
   private:
      char * last_name;
      list_adt my_list; 
      bst_node * right;
      bst_node * left;
};


//node class holds the contact data
//for a contact in a list takes care of the data
class node
{
    public:
       node();
       ~node();
       node(const node&); 
       node(char * name, char * hp, char * cll, char * em, node * nt);       
       //node& operator=(const node&); 
       friend bool operator==(const node&, node&);
       friend bool operator==(const node&, node*);
       friend bool operator==(node*, const node&);
       friend bool operator!=(const node&, const node&);
       friend bool operator!=(const node&, node*);
       friend bool operator!=(const node*, node&);
       friend bool operator<(const node&, node&);
       friend bool operator<(const node&, node*);
       friend bool operator<(node*, const node&);
       friend bool operator>(const node&, node&);
       friend bool operator>(const node&, node*);
       friend bool operator>(node*, const node&); 

       friend ostream& operator<<(ostream&, const node&);
       friend ostream& operator<<(ostream&, node * print); 
       void set_null();
       void set_next(node * nxt);
       node*& get_next(); 
       char* get_first() const; 
       void set(node*);
   private:
      char * first_name;
      char * home_num;
      char * cell;
      char * email;
      node * next;
};
