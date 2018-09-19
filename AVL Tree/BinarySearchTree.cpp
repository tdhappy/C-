#include "BinarySearchTree.h"

#include <string>
#include "BinarySearchTree.h"

/*used some of the class sides as refernce*/

using namespace std;

// Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {

}
// Destructor
BinarySearchTree::~BinarySearchTree() {
	clear();
}

BinaryNode *BinarySearchTree::get_root() const {
	return root;
}

int BinarySearchTree::height() const {
	return height(root);
}

int BinarySearchTree::height(const BinaryNode *ptr) const
{

    if(ptr == nullptr){
    	return -1;
    }


    int htOfLeftSubTree = height(ptr->left);
 
    int htOfRightSubTree = height(ptr->right);

  
    if(htOfLeftSubTree > htOfRightSubTree)
    {
    	return htOfLeftSubTree + 1;
    }
    else
    {
    	 return htOfRightSubTree + 1;
    }

}

int BinarySearchTree::find_min() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_min(root)->data;
}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
	BinaryNode* root = ptr;

	 while(root->left != nullptr){
		 root = root->left;
	 }

    return root;
}

int BinarySearchTree::find_max() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_max(root)->data;
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
	BinaryNode* root = ptr;

	 while(root->right != nullptr){
		 root = root->right;
	 }

    return root;
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{

    if(ptr == nullptr){
    		return;
    }

    clear(ptr->left);

    clear(ptr->right);


    ptr = nullptr;
}

bool BinarySearchTree::is_empty() const
{
    return root == nullptr;
}

bool BinarySearchTree::contains(const int data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{

	if(ptr == nullptr){
		return false;
	}
	else{

		if(ptr->data == data){
			return true;
		}
		else if (data < ptr->data ){
			return contains(data,ptr->left);
		}
		else{
			return contains(data,ptr->right);
		}
	}


}

void BinarySearchTree::insert(const int data)
{
    insert(data, root);
}

void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    if(ptr == nullptr){
    	ptr  =	new BinaryNode(data);
    }

    if( data < ptr->data){
    	 insert( data, ptr->left);
    }
    else if (data >ptr->data ){
    insert( data, ptr->right);
    }
}

void BinarySearchTree::remove(const int data)
{
    remove(data, root);
}
/**
 * Citation : From class slides
 */
void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
   if(ptr == nullptr){
	   return;
   }
   if(data < ptr->data){
	   remove(data,ptr->left);
   }else if(data > ptr->data){
	   remove(data,ptr->right);
   }else if(	(ptr->left != nullptr) && (ptr->right != nullptr)	){
	   ptr->data = find_min(ptr->right)->data;
	   remove(ptr->data, ptr->right);
   }
   else{

	   BinaryNode *oldNode = ptr;
	   ptr = (ptr->left != nullptr) ? ptr->left:ptr->right;
	   delete oldNode;


   }

}