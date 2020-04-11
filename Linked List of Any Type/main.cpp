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

void instructions( void );

int main( void )
{
    listNode<char> *startPtr = NULL; // initially there are no nodes
    char choice; // user's choice
    char item, first; // char entered by user

    instructions(); // display the menu
    printf( "? " );
    scanf( "\n%c", &choice);

   // loop while user does not choose 3
    while ( choice != '4' ) {

        switch ( choice ) {
            case '1':
                printf( "Enter a character: " );
                scanf( "\n%c", &item );
                insert( &startPtr, item ); // insert item in list
                printList( startPtr );
                break;
            case '2': // delete an element
            // if list is not empty
                if ( !isEmpty( startPtr ) ) {
                    printf( "Enter character to be deleted: " );
                    scanf( "\n%c", &item );

                    // if character is found, remove it
                    if ( Delete( &startPtr, item ) ) {
                        printf( "%c deleted.\n", item );
                        printList( startPtr );
                    }
                    else {
                        printf( "%c not found.\n\n", item );
                    }
                }
                else {
                    puts( "List is empty.\n" );
                }

            break;
            case '3':
                if ( !isEmpty( startPtr ) ){
                    printf( "Find a character: " );
                    scanf( "\n%c", &item );
                    auto pr = find(node_wrap<char>(startPtr), node_wrap<char>(), item);
                    if(pr != NULL)
                        printf( "Find %c\n", item);
                    else
                        printf( "Not Found.\n");
                    printList( startPtr );
                }
                else{
                    printf( "List is empty\n" );
                }
                break;
            default:
                puts( "Invalid choice.\n" );
                instructions();
                break;
        } // end switch

        printf( "? " );
        scanf( "\n%c", &choice);
    } // end while

    puts( "End of run." );
} // end main

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
