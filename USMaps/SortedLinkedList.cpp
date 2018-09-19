#include "SortedLinkedList.h"

#include<iomanip>

/***** Complete this class. *****/

SortedLinkedList::SortedLinkedList(): head(nullptr)
{

}

SortedLinkedList::~SortedLinkedList()
{
 
}

void SortedLinkedList::insert(Node *node){

	Node *p=head;


	if(head==nullptr || *head>*node)
	{
		node->next = head;
		head = node;
	}
	else
	{

		while((p->next!= nullptr) && (*node>*(p->next)))
		{
			p = p->next;
		}

		node->next=p->next;
		p->next=node;

	}

//	while(prev->next!=node){
//		prev=prev->next;
//	}
//
//	if((prev->get_col()==node->get_col())&&(prev->get_row()==node->get_row()))
//	{
//			node->next=nullptr;
//	}


}


ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{



	char a[49][117];

		//int space;


		for(int i=0;i<49;i++)
		{
			for(int j=0;j<117;j++){

				a[i][j]=' ';

			}
		}
		Node *p=list.head;
		//Node *count=list.head;

		Node *q=list.head;
		do
		{
			if(p->get_row()==p->next->get_row() && p->get_col()==p->next->get_col())
			{
//				cout<<p->get_row()<<" "<<p->get_col()<<" "<<p->get_name()<<endl;
//				cout<<p->next->get_row()<<" "<<p->next->get_col()<<" "<<p->next->get_name()<<endl;
				p->next=p->next->next;
//				cout<<p->next->get_name()<<endl;
//
//
			}

			a[p->get_row()][p->get_col()]='#';

//			cout<<p->get_row()<<" ";
//			cout<<p->get_col()<<endl;
			//cout<<*p;
			p=p->next;

		}while (p->next!= nullptr);

			for(int i=0;i<49;i++)
				{
					for(int j=0;j<117;j++)
					{
					   

						//cout<<a[i][j];
						if(a[i][j]=='#')
						{
						   if((q->get_row()==43)&&(q->get_col()==84)){

							q=q->next;

							}
							outs<<*q;

							if(q->get_name()!="")
							{
								j=j+(q->get_name().length())+3;
								while((q->next->get_col()<=j)&&(q->get_row()==q->next->get_row()))
								{
									q=q->next;
								}

							}

							q=q->next;
						}
						else
						{
							outs<<' ';
						}
						a[48][89]='#';
					}
					if(i<48){
					cout<<endl;
					}
				}
//		SortedLinkedList::max_row=count->get_row();
//		outs<<SortedLinkedList::max_row;

	return outs;
}
