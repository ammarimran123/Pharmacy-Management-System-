#include"header.h"
using namespace std;

Node::Node(){
		next = NULL;
	}
	
medicine::medicine(){
		 name="";
		 price=0;
		 quantity = 0;
	}
	
bool list::search(string a){
		Node *t = head;
		//int x = 0;
		while (t != NULL){
			if (t->data.name == a){
			//	if(t->data.quantity<0)
				cout<<"Name\tprice\tquantity"<<endl;
				cout << t->data.name <<"\t"<<t->data.price <<"\t"<<t->data.quantity<<endl;
				return true;

			}
			t = t->next;
		//	x++;
		}
		return false;
	} 
/*
bool list::swap(int a, int b){
		Node *first = head;

		for (int i = 0; i < a - 1; i++){
			first = first->next;
		}
		Node *second = head;
		for (int i = 0; i < b - 1; i++){
			second = second->next;
		}
		//	Node *t=new Node();

		int t = first->data;
		first->data = second->data;
		second->data = t;
		return true;

	}*/
	
list::list(){
	size = 0;
	head = NULL;
}

void list::display(){
	Node *t;
	t = head;
	        cout<<"  Name        Quantity\tPrice"<<endl;
int j=1;
	for (int i = 0; i<size; i++){
		cout <<j<<"  "<< t->data.name <<"\t"<<t->data.quantity <<"\t"<<t->data.price<<endl;
		t = t->next;
		j++;
	}
}

Node* list::Ghead(){
	return head;
}
int list::getS(){
	return size;
}
bool list::add(medicine a){
	Node *t = new Node();
	t->data.name = a.name;
	t->data.price = a.price;
	t->data.quantity = a.quantity;
	t->next = head;
	head = t;
	size++;
	return true;
}

/*
int listTotal_bill(list k){
	int i=0;
	Node *t=head;
	while(t!=NULL){
		i+=t->data.price;
		t=t->next;
	}
	return i;
}*/
 
 /*int list::getN(int a){
	int i = 0;
	Node *t = head;
	while (t != NULL){
		if (i == a){
			return t->data;
		}
		t = t->next;
		i++;
	}


}


*/


	int hash::function(int k){
		
		return k%26;
	}
	
	bool hash::insert(medicine a){       //thid
if(a.name[0]>=65&&a.name[0]<=90){

		char mm=a.name[0];
		int ascii=int(mm);
		ascii=ascii-65;
		int index=function(26+ascii);
		h[index].add(a);
		return true;
	}
	else{
		cout<<"\n\tMedicine name should begin with the Capital letter!!\n\n";
		return false;
	}
	/*	switch(a.name[0]){
			case 'A':
				int index=function(max);
				return true;
				break;
			case 'B':
				int index=function(max+1);
				return true;
				break;
			case 'C':
				int index=function(max+2);
				return true;
				break;
			case 'D':
				int index=function(max+3);
				return true;
				break;
			case 'E':
				int index=function(max+4);
				return true;
				break;
			case 'F':
				int index=function(max+5);
				return true;
				break;
			case 'G':
				int index=function(max+6);
				return true;
				break;
			case 'H':
				int index=function(max+7);
				return true;
				break;
			case 'I':
				int index=function(max+8);
				return true;
				break;
			case 'J':
				int index=function(max+9);
				return true;
				break;
			case 'K':
				int index=function(max+10);
				return true;
				break;
			case 'L':
				int index=function(max+11);
				return true;
				break;
			case 'M':
				int index=function(max+12);
				return true;
				break;
			case 'N':
				int index=function(max+13);
				return true;
				break;
			case 'O':
				int index=function(max+14);
				return true;
				break;
			case 'P':
				int index=function(max+15);
				return true;
				break;
			case 'Q':
				int index=function(max+16);
				return true;
				break;
			case 'R':
				int index=function(max+17);
				return true;
				break;
			case 'S':
				int index=function(max+18);
				return true;
				break;
			case 'T':
				int index=function(max+19);
				return true;
				break;
			case 'U':
				int index=function(max+20);
				return true;
				break;
			case 'V':
				int index=function(max+21);
				return true;
				break;
			case 'W':
				int index=function(max+22);
				return true;
				break;
			case 'X':
				int index=function(max+23);
				return true;
				break;
			case 'Y':
				int index=function(max+24);
				return true;
				break;
			case 'Z':
				int index=function(max+25);
				return true;
				break;
		default:
			return false;
			
		}
		*/
			
	}
	
	bool hash::search(string a){
		char mm=a[0];
		int ascii=int(mm);
		ascii=ascii-65;
		int index=function(26+ascii);
		bool b=h[index].search(a);
		return b;
	}
	
	int hash::sell(string a,int b){
		char mm=a[0];
		int ascii=int(mm);
		ascii=ascii-65;
		int index=function(26+ascii);
	Node *temp=h[index].Ghead();
	fstream record;
	int amount;
while (temp!= NULL){
			if (temp->data.name == a){
			temp->data.quantity=temp->data.quantity-b;
			amount=b*temp->data.price;
				record.open("record.txt",ios::app);
	if (!record){
			cout << "file does not exist" << endl;
		}
		else{
			record<<a<<"\t"<<b<<"\t"<<amount<<endl;
		    }
			record.close();
            return amount;
			}
			temp = temp->next;
		//	x++;
		}
	
}



    void hash::display(){
	fstream file;
	file.open("medicines.txt",ios::in | ios::out);
		if (!file){
			cout << "file does not exist!!" << endl;
		}
		else{

	for(int i=0;i<26;i++){
		Node *t=h[i].Ghead();
		while(t!=NULL){
			file<<t->data.name<<" "<<t->data.price<<" "<<t->data.quantity<<endl;
   	t=t->next;
		}
	}
	file.close();
}
	
}


    bool hash::check_availability(string a,int b){
    		char mm=a[0];
		int ascii=int(mm);
		ascii=ascii-65;
		int index=function(26+ascii);
	Node *temp=h[index].Ghead();
	
//	fstream record;
	//int amount;
while (temp!= NULL){
			if (temp->data.name == a){
		if(b>temp->data.quantity){
			return false;
		}
		else{
			return true;
		}
			
		}
	
}

}


bool hash::modify(string a ,int b,int r){
		char mm=a[0];
		int ascii=int(mm);
		ascii=ascii-65;
		int index=function(26+ascii);
	Node *temp=h[index].Ghead();
	
//	int amount;
while (temp!= NULL){
			if (temp->data.name == a){
			temp->data.quantity=temp->data.quantity+b;
			temp->data.price=r;
			display();
			return true;
		}
	}
	
}



int sell(string a,int b, list l){
	Node *temp=l.Ghead();
	fstream record;
	int amount;
while (temp!= NULL){
			if (temp->data.name == a){
			temp->data.quantity=temp->data.quantity-b;
			amount=b*temp->data.price;
				record.open("record.txt",ios::app);
	if (!record){
			cout << "file does not exist" << endl;
		}
		else{
			record<<a<<"\t"<<b<<"\t"<<amount<<endl;
		    }
			record.close();
            return amount;
			}
			temp = temp->next;
		//	x++;
		}
	
}


bool check_availability(string a,int b, list l){
	Node *temp=l.Ghead();
//	fstream record;
	int amount;
while (temp!= NULL){
			if (temp->data.name == a){
		if(b>temp->data.quantity){
			return false;
		}
			
		}
	
}
return true;
}


int Total_bill(list k){
	int i=0;
	Node *t=k.Ghead();
	while(t!=NULL){
		i+=t->data.price;
		t=t->next;
	}
	return i;
}
