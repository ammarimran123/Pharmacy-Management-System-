#include<iostream>
#include"header.h"
using namespace std;
int main(){
  system("color 1f");
	char p;
	char st[4];  //
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	for(int j=0;j<4;j++){
	
	
	cout<<"\t\t\tEnter the password : ";
/*	for(int i=0;i<4;i++){
		cin>>st[i];
	}*/
	
    
    int i=0;
    while((st[i]=getch())!='\r')
    {
    cout<<"*";
    i++;
    }
	cout<<endl;
	if(st[0]=='i'&& st[1]=='r'&& st[2]=='h'&& st[3]=='a'){
	
	
	
	do{
		system("CLS");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\tMain Menu\n";
	cout << "\t\t\t1. want to sell medicine\n";
	cout << "\t\t\t2. want to show the record\n";
	cout << "\t\t\t3. want to show the medicine details\n";
    cout << "\t\t\t4. want to modify the medicine details\n";
	cout << "\t\t\t5. exit\n";
	int i;
	cin >>i;
	system("CLS");
	fstream file;
	switch (i){
	case 1:
		
		file.open("medicines.txt",ios::in | ios::out);
		if (!file){
			cout << "file does not exist" << endl;
		}
		else{
			string n;
			int p, q;
			list l;
			hash hh;
			medicine c;
			while (file >> n >> p >> q){
			//	cout<<n<<p<<q<<endl;
				c.name=n;
				c.price=p;
				c.quantity=q;
			//	l.add(c);
				hh.insert(c);
			}
			file.close();
			string a;
			char h;
			list k;
			do{
			
		cout<<"Enter the name of the medicine: ";
	cin>>a;
	//Node *m;
	
	    if(hh.search(a)==false){
	    	cout<<"Medicine is not available in the store\n";
		}
		else if (hh.search(a)==true){
			int b;
			cout<<"Enter the quantity you want: ";
			cin>>b;
			if(hh.check_availability(a,b)==true){
				//	sell(a,b,l);
			c.price=hh.sell(a,b); //  In this function, we also save the record in record.txt
			c.name=a;
			c.quantity=b;
		   k.add(c);
			}
			else{
		
		   cout<<"we dont have such Quantity\n";
	}
		}
	cout<<"Want to purchase more?\n";
	cout<<"Press 0 to finalize the bill or press any key to continue: ";
	cin>>h;	
	}while(h!='0');
	cout<<"\n\n";
	cout<<"\t Chatta Medical Store\n \t Fee Invoice Slip\n";
	// showing the time and date 
	 // declaring argument of time() 
    time_t my_time = time(NULL);   
    // ctime() used to give the present time 
    printf("%s", ctime(&my_time));
//	cout<<"   Name    Quantity\tTotal price\n";

    k.display();
    cout<<endl;
    
    cout<<"Your total bill is : ";
    cout<<Total_bill(k);
    cout<<"Rs\n";
  //  remove("medicine.txt");
  
  
  cout<<endl<<endl;
  
  
 /* file.open("medicines.txt",ios::in | ios::out);
		if (!file){
			cout << "file does not exist!!" << endl;
		}
		else{
    Node *t=l.Ghead();
    
  while(t!=NULL){
   	file<<t->data.name<<" "<<t->data.price<<" "<<t->data.quantity<<endl;
   	t=t->next;
   }
   file.close();
}
*/
hh.display(); //updatation of file occur in that function
		}
		break;
	case 2:
//	ifstream Record;
		file.open("record.txt");
	if (!file){
			cout << "file does not exist" << endl;
		}
		else{
		string name; 
		int price,quan;	
		cout<<"Name\tprice\tquantity"<<endl;
			while(file>>name>>price>>quan){
				
		cout <<name <<"\t"<<price <<"\t"<<quan<<endl;

			}
		    }
			file.close();
	break;   
	case 3:
			file.open("medicines.txt");
	if (!file){
			cout << "file does not exist" << endl;
		}
		else{
		string name; 
		int price,quan;	
		cout<<"Name\tprice\tquantity"<<endl;
			while(file>>name>>price>>quan){
				
		cout <<name <<"\t"<<price <<"\t"<<quan<<endl;

			}
		    }
			file.close();
		break;
	case 4:
		system("CLS");
		int i;
		cout<<"1. Modify the details of existing product\n";
		cout<<"2.Enter the details of new Product\n";
		cin>>i;
		   switch(i){
		   	  case 1:
		   	  	file.open("medicines.txt",ios::in | ios::out);
		if (!file){
			cout << "file does not exist" << endl;
		}
		else{
			string n;
			int p, q;
			list l;
			hash hh;
			medicine c;
			while (file >> n >> p >> q){
			//	cout<<n<<p<<q<<endl;
				c.name=n;
				c.price=p;
				c.quantity=q;
			//	l.add(c);
				hh.insert(c);
			}
			file.close();
		   	  	string st;
		cout<<"Enter the name of medicine: ";
		cin>>st;
		 if(hh.search(st)==false){
	    	cout<<"Medicine is not available in the store\n";
		}
		else if (hh.search(st)==true){
			int b,r;
			cout<<"Enter the quantity you want to add: ";
			cin>>b;
			cout<<"Enter the new price you want to set to that medicine: ";
			cin>>r;
			if(hh.modify(st,b,r)==true)	{
				cout<<"Added sucessfully\n";
			}
			else{
					cout<<"Not Added\n";
			}	
		       
		   }
		
	}
	              break;  //break for 1st nested case
	    case 2:
	    file.open("medicines.txt",ios::in | ios::out);
		if (!file){
			cout << "file does not exist" << endl;
		}
		else{
			string n;
			int p, q;
			list l;
			hash hh;
			medicine c;
			while (file >> n >> p >> q){
			//	cout<<n<<p<<q<<endl;
				c.name=n;
				c.price=p;
				c.quantity=q;
			//	l.add(c);
				hh.insert(c);
			}
			file.close();
	    	string str;
	    	medicine m;
	    	int t,y;
	    	cout<<"Enter the name of new medicine: ";
	    	cin>>str;
	    	cout<<"Enter the price of that medicine:";
	    	cin>>t;
	    	cout<<"Enter the quantity of that medicine: ";
	    	cin>>y;
	    	m.name=str;
	    	m.price=t;
	    	m.quantity=y;
	    if(hh.insert(m)){
	    	hh.display();
	    	cout<<"\nNew medicine added sucessfully\n";
		}
		else {
			cout<<"\nOperation unsucessfull\n";
		}
	    	
	    }
	    	
	    	break;
}
	    break;	
	case 5:
		break;
	default:
		cout << "Ziada pange lene ke zarorat nahi hai.\nJo likha hua hai us me se select karna tha!!";
	}
//	int h;
	cout<<"do you want to show the menue again??\nEnter 0 to end and any key to continue!!\n ";
	cin>>p;
}while(p!='0');
break;

}   //end if condition within the loop
cout<<"Invalid Password\n\n";
cout<<"\t\t\tYour tries left are : ";
cout<<4-(j+1)<<endl;
}  //end for loop for password
}

