#include <iostream>
#include<fstream>
#include<cstring>
#include <time.h>
#include<stdlib.h>
#include <iosfwd>
#include <exception> 		// For ios_base::failure
#include <bits/char_traits.h> 	// For char_traits, streamoff, streamsize, fpos
#include <bits/localefwd.h>	// For class locale
#include <bits/ios_base.h>	// For ios_base declarations.
#include <streambuf> 
#include <bits/basic_ios.h>
#include<conio.h>
using namespace std;

//bool sell(string ,int , list );
struct medicine{
	string name;
	int price;
	int quantity;
	medicine();
};
struct Node{
	medicine data;
	Node *next;
	Node();

	
};

class list {
private:
	int size;
	Node *head;
public:
	list();
	void display();
	bool add(medicine);
	Node* Ghead();
	int getS();
	bool search(string );           
	int getN(int);
	bool swap(int , int );
};



class hash {
	private:
	//	max=27;
		list h[26];
	public:
	int function(int );
	bool insert(medicine );
	bool search(string );
	int sell(string ,int );
	bool modify(string ,int,int);
	bool check_availability(string ,int);
    void display();

};

int sell(string ,int , list );
bool check_availability(string ,int , list );
int Total_bill(list);
