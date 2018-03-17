#include<iostream>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
using namespace std;
int index=0;
class employee
{
	private:
		char no[11];
	public:
	    char name[20];
		char address[20];
	    char designation[10];
		int id,bonus;
		float TA,DA,HRA,TS;
	static int count;
	float salary;
	employee()
	{
		strcpy(name,"null");
		strcpy(designation,"null");
		strcpy(address,"null");
		strcpy(no,"null");
		salary=0.0;
		bonus=0.0;
		DA=0.0;
		TA=0.0;
		HRA=0.0;
		TS=0.0;
	}
	void read()
	{
		id=count++;
		printf("\n Enter the name of employee");
		fflush(stdin);
		gets(name);
		printf("\n Enter the designation");
		gets(designation);
		printf("\n Enter the contactno.");
		gets(no);
		printf("\n Enter the salary");
		scanf("%d",&salary);
		
		printf("\n****Congrtualations Record has been added successfully****");
	}
	void show()
	{
		cout<<"\nID ="<<id;
		cout<<"\nName="<<name;
		cout<<"\nDesignation="<<designation;
		cout<<"\nAddress="<<address;
		cout<<"\nContactno="<<no;
		cout<<"\nSalary="<<salary;
		
	}
};
int employee::count=101;
employee e[10];

int main()
{
	int ch,i,flag=1,pos,ID,b1;
	char choice;
	char ch1;
	int choice1;
	char NAME[20];
	do
	{
		
		cout<<"\n **MENU**";
		cout<<"\n 1.Enroll a Employee";
		cout<<"\n 2.Pyroll";
		cout<<"\n 3.Display a record";
		cout<<"\n 4.Deleting a record";
		cout<<"\n 5.Editing a record";
		cout<<"\n 6.Exit";
		cout<<"\n **Please enter your choice**";
		cin>>ch;
		switch(ch)
		{
			case 1:
			 e[index].read();
			 index++;
			 break;
			case 2:
			
			 cout<<"\n Pyroll Management";
			 cout<<"\n Enter your ID";
			 cin>>ID;
			 
			 for(i=0;i<index;i++)
			  {
			  	if(e[i].id == ID)
			  	{
			  		cout<<"\n Enter the percentage of bonus";
			  		cin>>b1;
			  		cout<<"\n **Salary slip** of MR."<<e[i].name;
			  		cout<<"\n Designation :"<<e[i].designation;
			  		cout<<"\n Basic Salary :"<<e[i].salary;
			  		e[i].bonus=(e[i].salary*b1)/100.0;
			  		cout<<"\n Bonus is ="<<e[i].bonus;
			  		e[i].DA=(e[i].bonus*50)/100.0;
			  		e[i].TA=(e[i].bonus*5)/100.0;
			  		e[i].HRA=((e[i].DA+e[i].TA)*50)/100.0;
			  		cout<<"\n DA:"<<e[i].DA;
			  		cout<<"\n TA:"<<e[i].TA;
			  		cout<<"\n HRA:"<<e[i].HRA;
			  		e[i].TS= (e[i].DA+e[i].HRA+e[i].TA);
			  		cout<<"\n Total Salary:"<<e[i].TS;
			  		flag=0;
				}
			  } 	
			  if(flag)
			     cout<<"**INVALID ID**";
			 break;
			case 3:
			 
			 
			 do
			 {
				cout<<"\n **The following record can be search by:**";
				cout<<"\n 1. Enter your ID";
				cout<<"\n 2. Enter your Name";
				cout<<"\n 3. Enter your Designation";
				cout<<"\n 4. Enter your Display all Records";
				cout<<"\n 5. exit";
				cout<<"\n Enter your choice";
				cin>>choice1;
				switch(choice1)
				{
					case 1:
						
						cout<<"\n Enter your ID";
						cin>>ID;
						for(i=0;i<index;i++)
						{
							if(e[i].id == ID)
							{
								e[i].show();
								flag=0;
								break;
							}
						}
						if(flag)
						  cout<<"**INVALID ID**";
					  break;
					case 2:
					 cout<<"\n Enter your Name";
					 fflush(stdin);
					 gets(NAME);
					 
					 for(i=0;i<index;i++)
					 {
					 	if(strcmp(e[i].name,NAME)==0)
					 	{
					 		e[i].show();
					 		flag=0;
						 }
					 }
					 if(flag)
					 cout<<"** INVALID NAME **";
					 break;
					case 3:
					 char DESIGNATION[20];
					 cout<<"\n Enter your Designation";
					 fflush(stdin);
					 gets(DESIGNATION);
					 
					  for(i=0;i<index;i++)
					  {
					  	 if(strcmp(e[i].designation, DESIGNATION)==0)
					  	 {
					  	 	e[i].show();
					  	 	flag=0;
						   }
					   }
					  if(flag) 
					  cout<<"\n ** INVALID DESIGNATION**";
					 break;
					case 4:
						char x;
						for(i=0;i<index;i++){
							e[i].show();
							cout<<"\n Press any key to continue";
							cin>>x;
							
							break;
						}
						break;
					case 5:
					   exit(0);
					   default:cout<<"\n Wrong Choice";	
					  
				}
				cout<<"\n Do you want to continue";
				cin>>ch1;
				 }while(ch1=='Y' ||ch1=='y');
				 break;
			case 4:
				int Id;
				cout<<"\n Enter the id u Want to Delete";
				cin>>Id;
				for(i=0;i<=index;i++)
				{
					if(e[i].id==Id)
					{
						pos=i;
						break;
					}
				}
				if(i>index)
				cout<<"**INVALID ID**";
				for(i=pos;i<index;i++)
				{
					e[i]=e[i+1];
				}     
					 index--;
					 cout<<"\n **ID is Deleted**";
			 break;
			case 5:
			    
				char ch2;
				int choice2;
				do{
					cout<<"\n **The following record can be edit by:**";
					cout<<"\n 1.Name";
					cout<<"\n 2.Address";
					cout<<"\n 3.Salary";
					cout<<"\n Exit";
					cout<<"\n Enter your choice";
					cin>>choice2;
					switch(choice2)
					{
						case 1:
							   cout<<"\n Enter employee ID";
							   cin>>ID;
							   for(i=0;i<index;i++)
							   {
							   	if(e[i].id==ID)
							   	{
							   		cout<<"\n Enter the name you want to replace it";
							   		cin>>NAME;
							   		strcpy(e[i].name,NAME);
							   		cout<<"\n Name has been changed";
							   		flag = 0;
							   		
								   }
								   }
							 if(flag)
							 cout<<"\n **INVALID ID**";
							 break;
						case 2:
						  char ADDRESS[20];
						  cout<<"\n Enter Employee ID:";
						  cin>>ID;
						  for(i=0;i<=index;i++)
						  {
						  	if(e[i].id == ID)
						  	{
						      cout<<"\nEnter the Address";
						      cin>>ADDRESS;
						      strcpy(e[i].address,ADDRESS);
						      cout<<"\n Address has been changed";
						      flag=0;
						    }
					      }
					      if(flag)
						  cout<<"\n** INVALID ID";
						  break;
						case 3:
							int SALARY;
						    cout<<"\n Enter Employee id";
						    cin>>ID;
						    for(i=0;i<index;i++)
						    {
						    	if(e[i].id==ID)
                                {
                                cout<<"\n Enter the Salary";
						  	 	cin>>SALARY;
						  	 	e[i].salary=SALARY;
						  	 	cout<<"\n Salary has been changed";
								flag=0;
								}
							}
						  if(flag)
						   cout<<"\n ** INVALID DESIGNATION**";
						   break;
						case 4:
						 exit(0);
						 default:cout<<"\n **WRONG CHOICE**";
						    
					}
					cout<<"\n Do  u want to continue";
					cin>>ch2;
					
				} while(ch1=='Y' ||ch1=='y');
				  break;
			case 6: exit(0);
			default: cout<<"\n**WRONG CHOICE";	   		 
		}
		cout<<"\n Do you want to Continue";
		cin>>choice;
	} while(choice=='y');
	getch();
}

