//========================================================
// Khoa Ho
// List.cpp
// December 2023
// This file contains the class methods for the
// Linked List class.
//========================================================

#include "List.h"
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

//------------------------------------
// define List class
//------------------------------------


//==================================================
// default constructor
// Creates a new empty List 
// Parameters: none
// Return Value: none
//==================================================
template <class T>
List<T>::List       ( void )
{
    head = NULL;
}
//==================================================
// copy constructor
// Creates a new List from an existing one
// Parameters: none
// Return Value: none
//==================================================
template <class T>
List<T>::List       ( const List<T> &mylist )
{
    head = NULL;
    Node *fromPtr = mylist.head;
    Node **toPtr = &head; 
    while (fromPtr != NULL) 
    {
        *toPtr = new Node;
        (*toPtr)->item = fromPtr->item; 
        (*toPtr)->next = NULL; 
        toPtr = &((*toPtr)->next); 
        fromPtr = fromPtr->next;
    }
}

//==================================================
// destructor
// Cleans up the memory of the list
// Parameters: none
// Return Value: none
//==================================================
template <class T>
List<T>::~List      ( void ) 
{
    Node *next_node;

    while ( head != NULL )
    {
        next_node = head->next;
        delete head;
        head = next_node;
    }

    head = NULL;
}
//==================================================
// operator=
// assignment operator
// destructor + copy constructor = assignment operator
// Parameters: Linked List reference to mylist
// Return value: the existing linked list with all 
// its value replaced by mylist's values
//==================================================
template <class T>
List<T> List<T>::operator= ( const List<T> &mylist )
{
    if ( this != &mylist )
    {
        clear(); 

        Node *fromPtr = mylist.head;
        Node **toPtr = &head; 

        while ( fromPtr != NULL ) 
        {
            *toPtr = new Node;
            (*toPtr)->item = fromPtr->item;
            (*toPtr)->next = NULL;
            toPtr = &((*toPtr)->next); 
            fromPtr = fromPtr->next;
        }
    }
    return *this;
}

//==================================================
// append
// Appends a new item onto the back of the list
// Parameters: T item (to be appended)
// Return Value: none
//==================================================
template <typename T>
void        List<T>::append     ( const T &item )
{
    Node *qtr = new Node;
    qtr->item = item;
    qtr->next = NULL;
    
    if ( head == NULL )
    {
        head = qtr;
    }
    else
    {
        Node *ptr = head;
        while ( ptr->next != NULL )
            ptr = ptr->next;
        ptr->next = qtr;
    }
}

//==================================================
// operator[]
// Access (by reference) the item at the specified index
// Parameters: int position (index of the accessed item)
// Return Value: T& (referenced to the item at the inspected position)
//==================================================
template <class T>
T &List<T>::operator[]  ( int index )
{
    Node *index_ptr;
    int index_counter = 0;
    index_ptr = head;

    if ( index < 0 || index > length() - 1 )
        throw invalid_argument("Invalid index");

    if ( index_ptr == NULL )
        throw out_of_range("List index out of range");

    while ( index_counter < index )
    {
        index_counter++;
        index_ptr = index_ptr->next;
    }
    return ( index_ptr->item );
}

//==================================================
// insert
// Inserts a new value at the specified position
// Parameters: T item (to be inserted)
//             int position (index to add new value)
// Return Value: none
//==================================================
template <typename T>
void		List<T>::insert		( const T &item, int index )
{
    if ( index < 0 || index > length() )
        throw invalid_argument("Invalid index");

    if ( index == 0 )
    {
        Node *qtr;
        qtr = new Node;
        qtr->item = item;
        qtr->next = head;
        head = qtr;
    }
    else if ( index == length() )
        append(item);
    else 
    {
        Node *prev = head;
        for ( int i = 0; i < index - 1; ++i ) 
        {
            prev = prev->next;
        }
        Node *qtr = new Node;
        qtr->item = item;
        qtr->next = prev->next;
        prev->next = qtr;
    }
}

//==================================================
// remove
// Removes an an item at the specified location
// Parameters: int position (index of the accessed item)
// Return Value: none
//==================================================
template <class T>
void    List<T>::remove      ( int index )
{
   
    if ( index >= 0 && index < length()  && head != NULL )
    {
        Node *ptr = head;
        if ( index == 0 ) 
        {
            Node *to_del = head;
            head = head->next;
            delete to_del;
            return;
        }
        Node *to_del = NULL;
        for (int i = 0; i < index; i++) 
        {
            to_del = ptr;
            ptr = ptr->next;
        }

        to_del->next = ptr->next;   
        delete ptr;
    }
    else
        throw std::out_of_range("Index out of range");

}

//==================================================
// operator+
// Concatenates two lists into a new list. Does not   
// change either existing list
// Parameters: none
// Return Value: bool (True if the list is empty, 
// false otherwise)
//==================================================
template <typename T>
List<T> List<T>::operator+ ( const List<T> &mylist ) const
{
    List<T> ret;

    if ( head == NULL && mylist.head == NULL )
        return ret;

    Node *fromPtr = head;
    while ( fromPtr != NULL )
    {
        ret.append(fromPtr->item);
        fromPtr = fromPtr->next;
    }

    Node *toPtr = mylist.head;
    while ( toPtr != NULL )
    {
        ret.append(toPtr->item);
        toPtr = toPtr->next;
    }

    return ret;
}

//==================================================
// length
// Returns the number of items in the list
// Parameters: none
// Return Value: none
//==================================================
template <class T>
int List<T>::length     ( void ) const
{
    int len = 0;
    Node *head_ptr;
    head_ptr = head;

    while ( head_ptr != NULL )
    {
        len++;
        head_ptr = head_ptr->next;
    }
    return len;
}

//==================================================
// isEmpty
// Returns true if the list is empty, false otherwise
// Parameters: none
// Return Value: bool (True if the list is empty, 
// false otherwise)
//==================================================
template <typename T>
bool		List<T>::isEmpty		( void ) const
{
    return ( head == NULL );
}

//==================================================
// clear
// Removes all items from the list
// Parameters: none
// Return Value: none
//==================================================
template <class T>
void    List<T>::clear     ( void )
{
    Node *next_node;

    while ( head != NULL )
    {
        next_node = head->next;
        delete head;
        head = next_node;
    }
    head = NULL;
}