#include<iostream>
#include<conio.h>
using namespace std;
class Book
{
private:
	struct node {
		int id;
		string name, author, publisher;
		node* next;

	};
public:
	node* head = NULL;
	void menu();
	void insert();
	void search();
	void uptade();
	void del();
	void sort();
	void show();


};
void Book::menu()
{
p:

	int choice;
	cout << "\n\n\n                ----------------------ahsan and ibtasim------------------------";
	cout << "\n\n\n\n \t\t\t\t   -----------BOOK SHOP MANAGEMENT SYSTEM-----------";
	cout << "\n\n\n  		-----------------------------------------------------------------------";
	cout << "\n\n\t\t \ePress 1 For Insert Record ";
	cout << "\n\n\t\t \ePress 2 For Search Record ";
	cout << "\n\n\t\t \ePress 3 For Uptade Record ";
	cout << "\n\n\t\t \ePress 4 For Delete Record";
	cout << "\n\n\t\t \ePress 5 For Show All Record";
	cout << "\n\n\t\t \ePress 6 For Exit";
	cout << "\n\n Enter Your Choice ::";

	cin >> choice;

	switch (choice)
	{
	case 1:
		insert();

		break;
	case 2:
		search();
		break;
	case 3:
		uptade();
		break;
	case 4:
		del();
		break;
	case 5:
		sort();
		show();
		break;
	case 6:
		exit(0);
	default:
		cout << "\n\n Invalid Choice ....Pease Try Again....";

	}

	goto p;
}

void Book::insert() {

	cout << "\n\n\n			---------------------------------------------------------------------";
	cout << "\n\n\n\n		 \t\t\t**BOOK SHOP MANAGEMENT SYSTEM**";
	cout << "\n\n\n  		    -----------------------------------------------------------------------";
	node* new_node = new node;
	cout << "\n\n Book ID :";
	while (!(cin >> new_node->id)) {
		cout << "\n\t Please Enter the valid Input : ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
}
	cout << "\n\n Name :";
	cin >> new_node->name;
	cout << "\n\n Author :";
	cin >> new_node->author;
	cout << "\n\n Publisher Name :";
	cin >> new_node->publisher;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
	}
	else 
	{
		node* ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
	cout << "\n\n    New Book Inserted Succefully.........";
}
void Book::search() {

	int t_id, found = 0;

	if (head == NULL)
	 {
		
		cout << "\n\n Link list is Empty.......";
	}
	else 
	{
		cout << "\n\n Book ID: ";
		cin >> t_id;
		node* ptr = head;
		while (ptr != NULL)
		{
			if (t_id == ptr->id)
			{

				cout << "\n\n  Book ID: " << ptr->id;
				cout << "\n\n  Book Name : " << ptr->name;
				cout << "\n\n  Author Name : " << ptr->author;
				cout << "\n\n  Publisher Name : " << ptr->publisher;
				found++;
			}
			ptr = ptr->next;
		}
		if (found == 0)

		{
			cout << "\n\n   Book ID is Invalid......";
		}
	}
}

void Book::uptade() 
{

	int t_id, found = 0;
	
	if (head == NULL)
	 {
		cout << "/n/n Link list is Empty.......";
	}
	else {
		cout << "\n\n Book ID: ";
		cin >> t_id;
		node* ptr = head;
		while (ptr != NULL)
		{
			if (t_id == ptr->id)
			{

				cout << "\n\n  Book ID: ";
				cin >> ptr->id;
				cout << "\n\n  Book Name : ";
				cin >> ptr->name;
				cout << "\n\n  Author Name : ";
				cin >> ptr->author;
				cout << "\n\n  Publisher Name : ";
				cin >> ptr->publisher;
				found++;
				cout << "\n\n Uptade Record Successfully.......";
			}
			ptr = ptr->next;
		}
		if (found == 0)

		{
			cout << "\n\n   Book ID is Invalid......";
		}
	}
}
void Book::del() {

	int t_id, found = 0;

	if (head == NULL)
	 {
		cout << "/n/n Link list is Empty.......";
	}
	else {
		cout << "\n\n Book ID: ";
		cin >> t_id;
		if (t_id == head->id) {
			node* ptr = head;
			head = head->next;
			delete ptr;
			cout << "\n\n Delete Book succefully.........";
			found++;
		}
		else
		{
			node* pre = head;
			node* ptr = head;
			while (ptr != NULL) {
				if (t_id == ptr->id) {
					pre->next = ptr->next;
					delete ptr;
					cout << "\n\n Delete Book Succesfully........";
					found++;
					break;

				}
				pre = ptr;
				ptr = ptr->next;

			}
		}
		if (found == 0)
		{
			cout << "\n\n Book ID is invalid";
		}
	}
}
void Book::sort() {

	if (head == NULL)
	{

		cout << "\n\n Link list is Empty";
		getch();
		menu();
	}
	int count = 0, t_id;
	string t_name, t_author, t_publisher;
	node* ptr = head;
	while (ptr != NULL) {
		count++;
		ptr = ptr->next;
	}
	for (int i = 1;i <= count;i++) {
		node* ptr = head;
		for (int j = 1;j < count;j++)
		{
			if (ptr->id > ptr->next->id)
			{
				t_id = ptr->id;
				t_name = ptr->name;
				t_author = ptr->author;
				t_publisher = ptr->publisher;
				ptr->id = ptr->next->id;
				ptr->name = ptr->next->name;
				ptr->author = ptr->next->author;
				ptr->publisher = ptr->next->publisher;
				ptr->next->id = t_id;
				ptr->next->name = t_name;
				ptr->next->author = t_author;
				ptr->next->publisher = t_publisher;
			}
			ptr = ptr->next;
		}

	}
}
void Book::show() {
	
	node* ptr = head;
	while (ptr != NULL)
	{

		cout << "\n\n Book ID: " << ptr->id;
		cout << "\n\n Book Name : " << ptr->name;
		cout << "\n\n Author Name : " << ptr->author;
		cout << "\n\n Publisher Name : " << ptr->publisher;
		cout << "\n\n  \t\t--------------------------------------------------------" << endl;
		ptr = ptr->next;
	}


}
int main() {
	Book obj;
	obj.menu();
}
