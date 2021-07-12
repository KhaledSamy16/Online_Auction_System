#include <iostream>
#include <string>

using namespace std;

//intiaize struct member
struct member
{
	string memberID;
	string email;
	string name;
	string passowrd;
	string deliveryaddress;
	string phonenumber;
	int points = 0;
	int listOfItems = 0;
};

//intiaize struct date
struct date
{
	int day;
	int month;
	int year;
};

//intiaize struct item
struct item
{
	string category;
	string status;
	date theStartDate;
	date theEndDate;
	int itemNumber;
	int startingbidprice;
	int counter = 0;
};

//intialize the constants
const int nmembers = 100;
const int nitems = 100;


//intialize array of struct
member members[nmembers];
item items[nitems];

//intialize the global variables
int m;
int z = 0;

//intialize the boolean for the loop
bool open = true;

//intialize the functions
void login();
void signup();
void buyer();
void seller();
void market();
void search();
void topcategory();
void feedback();

//the main function
int main()
{
	//values for member 1
	members[0].email = "member1@yahoo.com";
	members[0].passowrd = "12345678";
	members[0].memberID = "1";
	members[0].name = "member1";

	//values for member 2
	members[1].email = "member2@yahoo.com";
	members[1].passowrd = "12345678";
	members[1].memberID = "2";
	members[1].name = "member2";

	//values for member 3
	members[2].email = "member3@yahoo.com";
	members[2].passowrd = "12345678";
	members[2].memberID = "3";
	members[2].name = "member3";

	//intialize the local variables
	int a;

	cout << "--------------------------------------" << endl;
	cout << "welcome to Online Auction System " << endl;
	cout << "--------------------------------------" << endl;

	//the system loop
	while (open == true)
	{
		cout << "1-log in " << endl;
		cout << "2-sign up " << endl;
		cout << "3-top category " << endl;
		cout << "4-exit " << endl;
		cout << "please enter a number" << endl;
		cin >> a;
		cout << "--------------------------------------" << endl;
		//to choose 
		if (a == 1)
		{
			login();
		}
		else if (a == 2)
		{
			signup();
		}
		else if (a == 3)
		{
			topcategory();
		}
		else if (a == 4)
		{
			cout << "your welcome " << endl;
			cout << "--------------------------------------" << endl;
			open = false;
		}
	}
}

//this function used to login by the member
void login()
{
	//intialize the local variables
	int b;
	int f;
	string membersemail;
	string memberpassword;
	
	cout << "enter your email:";
	cin >> membersemail;
	cout << "enter your password:";
	cin >> memberpassword;
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < 100; i++)
	{

		if (membersemail == members[i].email && memberpassword == members[i].passowrd)
		{
			cout << "-----Hello-----" << endl;
			cout << "your points is:" << members[i].points << endl;
			cout << "1-buyer" << endl;
			cout << "2-seller" << endl;
			cout << "3-exit " << endl;
			cout << "please enter a number" << endl;
			cin >> b;
			cout << "--------------------------------------" << endl;
			if (b == 1)
			{
				cout << "1-Market place" << endl;
				cout << "2-search" << endl;
				cout << "3-exit" << endl;
				cout << "please enter a number" << endl;
				cin >> f;
				cout << "--------------------------------------" << endl;
				if (f == 1)
				{
					market();
				}
				else if (f == 2)
				{
					search();
				}
				else if (f == 3)
				{
					cout << "your welcome " << endl;
					cout << "--------------------------------------" << endl;
					open = false;
				}
			}
			else if (b == 2)
			{
				m = i;
				seller();
			}
			else if (b == 3)
			{
				cout << "your welcome " << endl;
				cout << "--------------------------------------" << endl;
				open = false;
			}
			break;

		}

		if (i == 99)
		{
			cout << "invalide" << endl;
			cout << "--------------------------------------" << endl;
		}
	}
}

//this function used to signup new members
void signup()
{
	//intialize the local variables
	int j = 3;
	
	while (j < 100)
	{
		cout << "enter your id:";
		cin >> members[j].memberID;
		cout << "enter your email:";
		cin >> members[j].email;
		cout << "enter your passowrd:";
		cin >> members[j].passowrd;
		cout << "enter your name:";
		cin.ignore();
		getline(cin, members[j].name);
		cout << "enter your deliveryaddress:";
		cin.ignore();
		getline(cin, members[j].deliveryaddress);
		cout << "enter your phonenumber:";
		cin >> members[j].phonenumber;
		j++;
		cout << "--------------------------------------" << endl;
		break;
	}
}

//this function used to buy the items
void buyer()
{
	//intialize the local variables
	string catname;
	int itemnumber;
	int suggestprice;
	int lowerprice;
	int f;
	int h;

	cout << "Do you want to buy?\n";
	cout << "1-yes\n";
	cout << "2-no\n";
	cout << "please enter a number" << endl;
	cin >> f;
	cout << "--------------------------------------" << endl;
	//to choose
	if (f == 1)
	{
		cout << "please enter categoury name:";
		cin >> catname;
		cout << "--------------------------------------" << endl;
		for (int e = 0; e < z; e++)
		{
			if (items[e].category == catname)
			{
				cout << "please enter item number:";
				cin >> itemnumber;
				cout << "--------------------------------------" << endl;
				if (itemnumber <= items[e].itemNumber)
				{
					cout << "1-buy by this price\n";
					cout << "2-suggest the price\n";
					cout << "3-exit\n";
					cout << "please enter a number" << endl;
					cin >> h;
					cout << "--------------------------------------" << endl;
					//to choose
					if (h == 1)
					{
						if (items[e].status == "available")
						{
							items[e].itemNumber = items[e].itemNumber - itemnumber;
							if (items[e].itemNumber == 0)
							{
								items[e].status = "sold";
							}
							items[e].counter = items[e].counter + itemnumber;
							cout << "you buy this item\n";
							cout << "--------------------------------------" << endl;
							feedback();
							break;
						}
					}
					else if (h == 2)
					{
						cout << "please enter the suggest price:";
						cin >> suggestprice;
						cout << "--------------------------------------" << endl;
						lowerprice = items[e].startingbidprice * 0.1;
						if (suggestprice >= lowerprice)
						{
							if (items[e].status == "available")
							{
								items[e].itemNumber = items[e].itemNumber - itemnumber;
								if (items[e].itemNumber == 0)
								{
									items[e].status = "sold";
								}
								items[e].counter = items[e].counter + itemnumber;
								cout << "you buy this item\n";
								cout << "--------------------------------------" << endl;
								feedback();
								break;
							}
						}
						else
						{
							cout << "you can't buy this item" << endl;
							cout << "--------------------------------------" << endl;
						}
					}
					else if (h == 3)
					{
						cout << "your welcome " << endl;
						cout << "--------------------------------------" << endl;
						open = false;
					}
				}
				else
				{
					cout << "you can't buy this item" << endl;
					cout << "--------------------------------------" << endl;
				}
			}
			else if (e == 99)
			{
				cout << "this category isn't available" << endl;
				cout << "--------------------------------------" << endl;
			}
		}
	}
	else if (f == 2)
	{
		cout << "your welcome " << endl;
		cout << "--------------------------------------" << endl;
	}
}

//this function is used to add items by seller
void seller()
{
	//intialize the local variables
	bool added = true;
	int e;
	int d;

	cout << "1-add new items\n";
	cout << "2-exit\n";
	cout << "please enter a number" << endl;
	cin >> d;
	cout << "--------------------------------------" << endl;
	//to choose
	if (d == 1)
	{
		while (added == true)
		{
			cout << "seller ID:" << members[m].memberID << endl;
			cout << "enter itemNumber:";
			cin >> items[z].itemNumber;
			cout << "enter item category:";
			cin >> items[z].category;
			cout << "enter item startingbidprice:";
			cin >> items[z].startingbidprice;
			cout << "enter item theStartDate(DD MM YYYY):";
			cin >> items[z].theStartDate.day;
			cin >> items[z].theStartDate.month;
			cin >> items[z].theStartDate.year;
			cout << "enter item theEndDate(DD MM YYYY):";
			cin >> items[z].theEndDate.day;
			cin >> items[z].theEndDate.month;
			cin >> items[z].theEndDate.year;
			if (items[z].theStartDate.day<=items[z].theEndDate.day&&items[z].theStartDate.month<=items[z].theEndDate.month)
			{
				cout << "the item is added\n";
				cout << "--------------------------------------" << endl;
				items[z].status = "available";
				z++;
				cout << "Do you want to add another item?" << endl;
				cout << "1-yes" << endl;
				cout << "2-no" << endl;
				cout << "please enter a number" << endl;
				cin >> e;
				cout << "--------------------------------------" << endl;
				if (e == 1)
				{
					continue;
				}
				else
				{
					break;
				}
			}
			else
			{
				cout << "please re sign again\n";
				cout << "--------------------------------------" << endl;
				continue;
			}
		}
	}
	if (d == 2)
	{
		cout << "your welcome " << endl;
		cout << "--------------------------------------" << endl;
		open = false;
	}
}

//this function is used to show the market
void market()
{
	for (int i = 0; i < z; i++)
	{
		if (items[i].status == "available")
		{
			cout << "seller ID:" << members[m].memberID << endl;
			cout << "item number:" << items[i].itemNumber << endl;
			cout << "item category:" << items[i].category << endl;
			cout << "starting bid price:" << items[i].startingbidprice << endl;
			cout << "item status:" << items[i].status << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	buyer();
}

//this function used to search through categories
void search()
{
	//intialize the local variables
	bool searchCategory = false;
	bool searchCategoryPrice = false;
	string categoryname;
	int pricevalue;
	int c;

	cout << "1-search via category " << endl;
	cout << "2-search via category and price " << endl;
	cout << "3-exit" << endl;
	cout << "please enter a number" << endl;
	cin >> c;
	cout << "--------------------------------------" << endl;
	//to choose
	if (c == 1)
	{
		cout << "category:";
		cin >> categoryname;
		cout << "--------------------------------------" << endl;
		for (int i = 0; i < 100; i++)
		{
			if (items[i].category == categoryname)
			{
				cout << "seller ID:" << members[m].memberID << endl;
				cout << "item number:" << items[i].itemNumber << endl;
				cout << "item category:" << items[i].category << endl;
				cout << "starting bid price:" << items[i].startingbidprice << endl;
				cout << "item status:" << items[i].status << endl;
				cout << "--------------------------------------" << endl;
				searchCategory = true;
			}
		}
		if (searchCategory == true)
		{
			buyer();
		}
		if (searchCategory == false)
		{
			cout << "not found " << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	if (c == 2)
	{
		cout << "category:";
		cin >> categoryname;
		cout << "--------------------------------------" << endl;
		cout << "buy now price:";
		cin >> pricevalue;
		cout << "--------------------------------------" << endl;
		for (int i = 0; i < 100; i++)
		{
			if (items[i].category == categoryname && items[i].startingbidprice == pricevalue)
			{
				cout << "seller ID:" << members[m].memberID << endl;
				cout << "item number:" << items[i].itemNumber << endl;
				cout << "item category:" << items[i].category << endl;
				cout << "starting bid price:" << items[i].startingbidprice << endl;
				cout << "item status:" << items[i].status << endl;
				cout << "--------------------------------------" << endl;
				searchCategoryPrice = true;
			}
		}
		if (searchCategoryPrice == true)
		{
			buyer();
		}
		if (searchCategoryPrice == false)
		{
			cout << "not found " << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	if (c == 3)
	{
		cout << "your welcome " << endl;
		cout << "--------------------------------------" << endl;
		open = false;
	}
}

//this function used to out the top category
void topcategory()
{
	//intialize the local variables
	int max = 0;
	int k = 0;
	
	if (z == 0)
	{
		cout << "there is no category" << endl;
		cout << "--------------------------------------" << endl;
	}
	else
	{
		for (int i = 0; i < z; i++)
		{
			if (items[i].counter >= max)
			{
				max = items[i].counter;
				k = i;
			}
		}
		cout << "top category is " << items[k].category << endl;
		cout << "--------------------------------------" << endl;
		cout << "items selled " << max << endl;
		cout << "--------------------------------------" << endl;
	}
}

//this function used to take feedback 
void feedback()
{
	//intialize the local variables
	string sellid;
	int n = 0;
	int feed = 0;
	
	cout << "please enter seller ID:";
	cin >> sellid;
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < 100; i++)
	{
		if (sellid == members[i].memberID)
		{
			n = i;
			cout << "enter your feedback (from 1 to 5):";
			cin >> feed;
			cout << "--------------------------------------" << endl;
		}
	}
	if (feed >= 3)
	{
		members[n].points++;
	}
}