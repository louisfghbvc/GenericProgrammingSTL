// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <bits/stdc++.h>
using namespace std;

// self-referential structure
template <typename T>
struct listNode {
    T data;
    listNode *nextPtr;
    bool operator==(const T& i) const {return data == i;}
    bool operator!=(const T& i) const {return !data == i;}
}; // end structure listNode

template <typename T>
using ListNode = listNode<T>; // synonym for struct listNode

//陳泓睿
template <typename T>
struct node_wrap: public iterator<input_iterator_tag, T>{
    listNode<T>* ptr;
    node_wrap(listNode<T>* p = nullptr) : ptr(p) { }
    listNode<T>& operator*() const{return *ptr;}
    listNode<T>* operator->() const{return ptr;}
    node_wrap& operator++(){ptr= ptr->nextPtr; return *this;}
    node_wrap operator++(int){node_wrap tmp= *this; ptr= ptr->nextPtr; return tmp;}
    bool operator==(const node_wrap& i) const{ return ptr== i.ptr; }
    bool operator!=(const node_wrap& i) const{ return ptr!= i.ptr; }
};
//陳泓睿

// prototypes
template<class ListNode, typename T>
void insert( ListNode **sPtr, T value );

template<class ListNode, typename T>
T Delete( ListNode **sPtr, T value );

template<class ListNode>
int isEmpty( ListNode* sPtr );

template<class ListNode>
void printList( ListNode *currentPtr );

string init(); // choose type
void instructions( void ); // choose action
template<typename T>
bool input(string type, T &val, char choice);

int main( void )
{
    listNode<char> *char_startPtr = NULL; // initially there are no nodes
    listNode<int> *int_startPtr = NULL; // initially there are no nodes

    char choice; // user's choice
    int int_item;
    char char_item;

    string type = init();
    while(type != "bye"){

        instructions(); // display the menu
        printf( "? " );
        cin >> choice;

        // loop while user does not choose 3
        while ( choice != '4' ) {
            switch ( choice ) {
                case '1':
                    printf( "Enter a item: " );
                    if(type == "int"){
                        while(!input(type, int_item, choice));
                        insert( &int_startPtr, int_item); // insert item in list
                        printList( int_startPtr );
                    }
                    else {
                        while(!input(type, char_item, choice));
                        insert( &char_startPtr, char_item); // insert item in list
                        printList( char_startPtr );
                    }
                    break;
                case '2': // delete an element
                    printf( "Enter item to be deleted: " );
                    if(type == "int"){
                        // if list is not empty
                        if ( !isEmpty( int_startPtr ) ) {
                            while(!input(type, int_item, choice));
                            // if character is found, remove it
                            if ( Delete( &int_startPtr, int_item ) ) {
                                printf( "%d deleted.\n", int_item );
                                printList( int_startPtr );
                            }
                            else {
                                printf( "%d not found.\n\n", int_item );
                            }
                        }
                        else {
                            puts( "List is empty.\n" );
                        }
                    }
                    else{
                        // if list is not empty
                        if ( !isEmpty( char_startPtr ) ) {
                            while(!input(type, char_item, choice));
                            // if character is found, remove it
                            if ( Delete( &char_startPtr, char_item ) ) {
                                printf( "%c deleted.\n", char_item );
                                printList( char_startPtr );
                            }
                            else {
                                printf( "%c not found.\n\n", char_item );
                            }
                        }
                        else {
                            puts( "List is empty.\n" );
                        }
                    }
                break;
                case '3':
                    printf( "Find a item: " );
                    if(type == "int"){
                        if ( !isEmpty( int_startPtr ) ){
                            while(!input(type, int_item, choice));
                            auto pr = find(node_wrap<int>(int_startPtr), node_wrap<int>(), int_item);
                            if(pr != NULL)
                                printf( "Find %d\n", int_item);
                            else
                                printf( "Not Found.\n");
                            printList( int_startPtr );
                        }
                        else{
                            printf( "List is empty\n" );
                        }
                    }
                    else{
                        if ( !isEmpty( char_startPtr ) ){
                            while(!input(type, char_item, choice));
                            auto pr = find(node_wrap<char>(char_startPtr), node_wrap<char>(), char_item);
                            if(pr != NULL)
                                printf( "Find %c\n", char_item);
                            else
                                printf( "Not Found.\n");
                            printList( char_startPtr );
                        }
                        else{
                            printf( "List is empty\n" );
                        }
                    }
                    break;
                default:
                    puts( "Invalid choice.\n" );
                    instructions();
                    break;
            } // end switch

            printf( "? " );
            cin >> choice;
        } // end while
        puts( "End of run." );
        type = init();
    }
    puts( "End of run." );

} // end main

//check if is type
template<typename T>
bool input(string type, T &val, char choice){
    int i; char c;
    cin.ignore();
    if(isdigit(cin.peek())){
        cin >> i;
        if(type == "int"){
            val = i;
            return 1;
        }
        printf("Hey guys. Don't trick me. Please put Character!\n");
    }
    else{
        cin >> c;
        if(type == "char"){
            val = c;
            return 1;
        }
        printf("Hey guys. Don't trick me. Please put Integer!\n");
    }

    if(choice == '1')
        printf( "Enter a item: " );
    else if(choice == '2')
        printf( "Enter item to be deleted: " );
    else
        printf( "Find a item: " );
    return 0;
}

// choose type int or char
string init(){
    printf("Choose type : int or char.\n \"bye\" is End of process\n");
    string s;
    cin >> s;
    while(s != "int" && s != "char" && s != "bye") {
        printf("hey! I want you type correct type.\n");
        cin >> s;
    }
    return s;
}

// display program instructions to user
void instructions( void )
{
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to find an element from the list.\n"
      "   4 to end." );
} // end function instructions

// insert a new value into the list in sorted order
template<class ListNode, typename T>
void insert( ListNode **sPtr, T value )
{
   ListNode *newPtr; // pointer to new node
   ListNode *previousPtr; // pointer to previous node in list
   ListNode *currentPtr; // pointer to current node in list

   newPtr = (ListNode *)malloc( sizeof( ListNode ) ); // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->data = value; // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node

      previousPtr = NULL;
      currentPtr = *sPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && value > currentPtr->data ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // insert new node at beginning of list
      if ( previousPtr == NULL ) {
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } // end if
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } // end else
   } // end if
   else {
      printf( "%c not inserted. No memory available.\n", value );
   } // end else
} // end function insert

// delete a list element
template<class ListNode, typename T>
T Delete( ListNode **sPtr, T value )
{
   ListNode *previousPtr; // pointer to previous node in list
   ListNode *currentPtr; // pointer to current node in list
   ListNode *tempPtr; // temporary node pointer

   // delete first node
   if ( value == ( *sPtr )->data ) {
      tempPtr = *sPtr; // hold onto node being removed
      *sPtr = ( *sPtr )->nextPtr; // de-thread the node
      free( tempPtr ); // free the de-threaded node
      return value;
   } // end if
   else {
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->data != value ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // delete node at currentPtr
      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return value;
      } // end if
   } // end else

   return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
template<class ListNode>
int isEmpty( ListNode *sPtr )
{
   return sPtr == NULL;
} // end function isEmpty

// print the list
template<class ListNode>
void printList( ListNode *currentPtr )
{
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else {
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr != NULL ) {
         cout << currentPtr->data << " --> ";
         currentPtr = currentPtr->nextPtr;
      } // end while

      puts( "NULL\n" );
   } // end else
} // end function printList




/**************************************************************************
 * (C) Copyright 1992-2013 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
