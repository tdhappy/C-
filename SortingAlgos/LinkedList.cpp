#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {};

LinkedList::LinkedList(Node *head, Node *tail, const int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;

    this->size = size;
}

LinkedList::~LinkedList() {}

Node *LinkedList::get_head() const { return head; }
Node *LinkedList::get_tail() const { return tail; }
int   LinkedList::get_size() const { return size; }

void LinkedList::set(Node *head, Node *tail, int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;
    this->size = size;
}

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

    // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::reset()
{
    head = tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

 * Referenced:
 * - GeeksforGeeks
 * - http://www.geeksforgeeks.org/merge-sort-for-linked-list/
 */
void LinkedList::split(LinkedList& list1, LinkedList& list2)
{
	Node* first;
	Node* second;
	if(head == nullptr || head->next == nullptr)  //checking head position and head->next position
	{
	    list1.head = head;
	    list2.head = nullptr;
	}
	else
	{
	    first = head;
	    list1.head = first;
	    second = head->next;
	    if(second != nullptr)
	    {
	        second = second->next;
	    }
	    while(second != nullptr)
	    {
	        first = first->next;
	        second = second->next;
	        if(second != nullptr)
	        {
	            second = second->next;
	        }
	    }
	    list2.head = first->next;
	    first->next = nullptr;
	}
}

/**
 * Add another list to the end of this list.
 * @param other_list the other list.
 */
void LinkedList::concatenate(LinkedList& other_list)
{



	Node *ptr1, *ptr2;	//two node pointers

	ptr1 = head;
	ptr2 = other_list.head;

	while (ptr1->next != nullptr)
	{
		ptr1 = ptr1->next;
	}

	ptr1->next = ptr2;

}