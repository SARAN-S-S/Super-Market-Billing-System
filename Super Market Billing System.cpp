#include<bits/stdc++.h>
#include<fstream>

using namespace std;

class Shopping 
{
	private:
		int Pcode;
		float Price;
		float Discount;
		string Pname;
		
	public:
		void Menu();
		void Administrator();
		void Buyer();
		void Add();
		void Edit();
		void Remove();
		void List();
		void Receipt();
		
};

void Shopping :: Menu()
{
	m:
	int choice;
	
	string Email;
	string Password;
	
	cout<<"\t\t\t\t___________________________________\n";
	cout<<"\t\t\t\t                                   \n";
	cout<<"\t\t\t\t       SuperMarket Main Menu       \n";
	cout<<"\t\t\t\t                                   \n";
	cout<<"\t\t\t\t___________________________________\n";
	cout<<"\t\t\t\t                                   \n";
	
	cout<<"\t\t\t\t     |                     |\n";
	cout<<"\t\t\t\t     |  1) Administrator   |\n";
	cout<<"\t\t\t\t     |                     |\n";
	cout<<"\t\t\t\t     |  2) Buyer           |\n";
	cout<<"\t\t\t\t     |                     |\n";
	cout<<"\t\t\t\t     |  3) Exit            |\n";
	cout<<"\t\t\t\t     |                     |\n";
	cout<<"\n\t\t\t Please select : ";
	cin>>choice;
	
	switch(choice)  
	{
	    case 1:
	      cout<<"\n";
	      cout<<"\t\t\t  Please Login  \n";	
	      cout<<"\t\t\t  Enter Email   \n";	
	      cin>>Email;
	      cout<<"\t\t\t  Password      \n";
		  cin>>Password;	 
		  
		  if(Email == "saranriderz22@gmail.com" && Password == "Sarankalam")  {
		  	Administrator();
		  }
		  else  {
		  	cout<<"Invalid Email/Password";
		  }
		  break;
		  
		case 2:
			Buyer();
			
		case 3:
			exit(0);
			
		default :
			cout<<"Plaese select from the Given Options!";
			
	} 
	
	goto m;
}

void Shopping :: Administrator()  {
	m:
	int choice;
	cout<<"\n\n\n\t\t\t         Administrator Menu";
	cout<<"\n\t\t\t                                    ";
	cout<<"\n\t\t\t|_______ 1) Add the product _______|";
	cout<<"\n\t\t\t|                                  |";
	cout<<"\n\t\t\t|_______ 2) Modify the product ____|";
	cout<<"\n\t\t\t|                                  |";
	cout<<"\n\t\t\t|_______ 3) Delete the product ____|";
	cout<<"\n\t\t\t|                                  |";
	cout<<"\n\t\t\t|_______ 4) Back to main menu _____|";
	
	cout<<"\n\n\t Please Enter your choice : ";
	cin>>choice;
	
	switch(choice)  {
		case 1:
			Add();
			break;
			
		case 2:
			Edit();
			break;
			
		case 3:
			Remove();
			break;
			
		case 4:
			Menu();
			break;
			
		default :
			cout<<"Invalid choice!";
	}
	goto m;
	
}

void Shopping :: Buyer()  {
	m:
	int choice;
	
	cout<<"                     \n";
	cout<<"\t\t\t  Buyer \n";
	cout<<"\t\t\t__________________ \n";
	cout<<"                     \n";
	cout<<"\t\t\t1) Buy product \n";
	cout<<"                     \n";
	cout<<"\t\t\t2) Go Back     \n";
	cout<<"                     \n";
	cout<<"\t\t\t__________________ \n";
	cout<<"\n\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	switch(choice)  {
		case 1:
			Receipt();
			break;
			
		case 2:
			Menu();
			
		default:
			cout<<"Invalid choice!";
	}
	goto m;
}

void Shopping :: Add()  {
	m:
	fstream data;
	int c;  //product code
	int token = 0;
	float p;  //price of the product
	float d;  //discount
	string n;  // name of the product
	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Enter the Product code of the product : ";
	cin>>Pcode;
	cout<<"\n\n\t Enter Name of the product : ";
	cin>>Pname;
	cout<<"\n\n\t Enter Price of the product : ";
	cin>>Price;
	cout<<"\n\n\t Enter Discount on the product : ";
	cin>>Discount;
	
	//ios::in - open the file in reading mode and ios::out - open the file in writing mode
	data.open("database.txt", ios::in);
	
	if(!data)  {
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<Pcode<<" "<<Pname<<" "<<Price<<" "<<Discount<<"\n";
		data.close();
	}
	
	else  {
		data>>c>>n>>p>>d;
		
		while(!data.eof())  {
			if(c == Pcode)  {
				token++;
			
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
		if(token == 1)  {
			cout<<"\n\n\t\t\t *** The product code is already exists. Please choose another product code... ***";
			goto m; 
		}
		   
		   
		else  {
			data.open("database.txt", ios::app|ios::out);
			data<<" "<<Pcode<<" "<<Pname<<" "<<Price<<" "<<Discount<<"\n";
			data.close();
		}
    }
	cout<<"\n\n\t\t Record insertes!";
}


void Shopping :: Edit()  {
	
	fstream data, data1;
	int pkey; //getting product code from the administrator
	int token = 0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record ";
	cout<<"\n\t\t\t Product code : ";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	if(!data)  {
		cout<<"\n\n File doesn't exists!";
	}
	else  {
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>Pcode>>Pname>>Price>>Discount; 
		while(!data.eof())  {
			if(pkey == Pcode)  {
				cout<<"\n\t\t Product new code : ";
				cin>>c;
				cout<<"\n\t\t Name of the product : ";
				cin>>n;
				cout<<"\n\t\t Price : ";
				cin>>p;
				cout<<"\n\t\t Discount : ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited!";
				token++;
			}
			
			else {
				data1<<" "<<Pcode<<" "<<Pname<<" "<<Price<<" "<<Discount<<"\n";
				
			}
			
			data>>Pcode>>Pname>>Price>>Discount;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)  {
			cout<<"\n\n Record not found!";
		}
	}
}


void Shopping :: Remove()  {
	fstream data, data1;
	int pkey;
	int token = 0;
	cout<<"\n\n\t Delete the product";
	cout<<"\n\n\t Product code : ";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	if(!data)  {
		cout<<"File doesn't exists!";
	}
	
	else  {
		data1.open("database1.txt",ios::app | ios::out);
		data>>Pcode>>Pname>>Price>>Discount;
		while(!data.eof())  {
			if(Pcode == pkey)  {
				cout<<"\n\n\t Product deleted successfully!";
				token++;
			}
			else  {
				data1<<" "<<Pcode<<" "<<Pname<<" "<<Price<<" "<<Discount<<"\n";
			}
			data>>Pcode>>Pname>>Price>>Discount;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");
			
		if(token == 0)  {
			cout<<"Record doesn't found!";
		}
	}
	
}


void Shopping :: List()  {
	fstream data;
	data.open("database.txt", ios::in);
	cout<<"\n\n___________________________________________________________________\n\n";
	cout<<"Prod_No\t\tName\t\tPrice\n";
	cout<<"\n___________________________________________________________________\n";
	data>>Pcode>>Pname>>Price>>Discount;
	while(!data.eof())  {
		
		cout<<Pcode<<"\t\t"<<Pname<<"\t\t"<<Price<<"\n";
		data>>Pcode>>Pname>>Price>>Discount;
		
	}
	data.close();
}

void Shopping :: Receipt()  {
	
	fstream data;
	
	int arr_code[100];
	int arr_quan[100];
	char choice;
	int count = 0;
	float amount = 0;
	float discountAmount;
	float total = 0;
	
	cout<<"\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt",ios::in);
	
	if(!data)  {
		cout<<"\n\n Empty database";
	}
	
	else  {
		data.close();
		List();  // Display the list of products
		
		cout<<"\n________________________________________________\n";
		cout<<"\n|                                              |\n";
		cout<<"\n|            Please place the order            |\n";
		cout<<"\n|                                              |\n";
		cout<<"\n|______________________________________________|\n";
		
		do  {
			m:
				
			cout<<"\n\n Enter Product code : ";
			cin>>arr_code[count];
			cout<<"\n\n Enter the product quantity : ";
			cin>>arr_quan[count];
			
			for(int i=0;i<count;i++)  {
				if(arr_code[count] == arr_code[i])  {
					cout<<"\n\n Duplicate product code. Please try again";
					goto m;
				}
			}
			count++;
			cout<<"\n\n Do you want to buy another product? If yes, then press Y or y else N or n : ";
			cin>>choice;
			
		}   while(choice == 'Y' || choice == 'y');
		
		cout<<"\n\n\t\t\t_______________________RECEIPT_______________________\n";
		cout<<"\n\nProduct No\tProduct Name\tProduct Quantity\tPrice\tTot_Amount\tDiscount%\tAmount with discount";
		cout<<"\n________________________________________________________________________________________________________________________";
		
		
		for(int i=0;i<count;i++)  {
			data.open("database.txt", ios::in);
			data>>Pcode>>Pname>>Price>>Discount;
			
			while(!data.eof())  {
				if(Pcode == arr_code[i])  {
					amount = Price * arr_quan[i];
					discountAmount = amount* (Discount/100);
					total += (amount - discountAmount);
					cout<<"\n    "<<Pcode<<"\t\t"<<Pname<<"\t\t"<<arr_quan[i]<<"\t\t\t"<<Price<<"\t"<<amount<<"\t\t"<<Discount<<"%\t\t"<<(amount - discountAmount);	
					
				}
				
				data>>Pcode>>Pname>>Price>>Discount;
			}
			data.close();
		}
		cout<<"\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
	    cout<<"\n\t\t\t\t\t\t\t\t\t\t Total Amount : "<<total<<endl;
	}
}

int main()  {
	Shopping s;
	s.Menu();
}








