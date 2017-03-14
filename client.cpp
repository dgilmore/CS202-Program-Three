//David Gilmore CS202 Program #3 Winter 17
//This is the client driver file where I will declared my controller class and 
//run the program. This program stores and has various operations on a binary search tree 
//of emergency contracts. Each tree node has a LLL of all the contacts with the same last name, organized
//alphabetically by first name with a home phone, email and cell phone number. 
#include "contact.h" 

int main()
{

   controller my_controller;//creates instance of controller
   my_controller.create_bst();//creates our contact tree 
   my_controller.contact_menu();//logic for the user menu, lets user display, add, search  
  if(my_controller.destroy())//kicks off the destructors for our data structures 
    cout << "Program Ended Successfully: " << endl;
  else
    cout << "Error when closing program: " << endl;
   return 0; 
}

