
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <random>
#include <limits>
#include <fstream>
using namespace std; 

void dk(int& n) {
	while (!(cin >> n) || n < 0) {
		cout << " INVALID, try again: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
}
string Lowwer( string s ) {
	transform(s.begin(), s.end(), s.begin(), ::tolower); 
	s = Lowwer(s);
	return s; 

}
class book {
private : 
	int Code; 
	string name ;
	string author; 
	int isBorrow; 
public : 
	book (int c, string n, string a) { 
		Code = c ; 
		name = n ; 
		author = a ; 
		isBorrow = 0; 
		
	}
	int getCode() { return Code; }
	string getname() { return name; }
	string getauthor() { return author;  }
	int getisBorrow() { return isBorrow;  }
	void print() {
		cout << " Code of Book : " << Code << endl;
		cout << " Name : " << name << endl;
		cout << " Author : by " << author << endl;
		cout << " Available : ";
		if (isBorrow == 0) {
			cout << " Book On Desk    " << endl ; 
		}
		else cout << " Book Unavailable " << endl;
		cout << " ------------------------------------------------- " << endl; 
	}
	void borrow(int n) {
		isBorrow = n; 
	}

	void returned ( ) {
		isBorrow = 0; 
	}
	
} ;
class Customer {
private:
	int id;
	string namecustom;
	string sdt;

public:
	Customer(int i, string nc, string dt) {
		id = i;
		namecustom = nc;
		sdt = dt;
		
	}
	int getId() { return id; }
	string getnamec() { return namecustom; }
	string getsdt() { return sdt; }
	
	void printc() {
		cout << " Id of Customer : " << id << endl;
		cout << " Name : " << namecustom << endl;
		cout << " Phone number : " << sdt << endl;

		cout << " ------------------------------------------------- " << endl;
	}



};

class Libary {
private  : 
	vector < book > books; 
	vector < Customer > Customers;
public : 

// -----------------------------------------------------------------------------
	bool isNew(book b) {
		for (int i = 0; i < books.size(); i++) {
			if (b.getCode() == books[i].getCode())
				return false; 
		} 
		return true; 

	} 
	bool isNewc(Customer b) {
		for (int i = 0; i < Customers.size(); i++) {
			if (b.getId() == Customers[i].getId())
				return false;
		}
		return true;

	}
// ----------------------------------------------------------------------------------------------

	
	void addbook(book b) {
		if (isNew(b)) {
			books.push_back(b);
		}
		else cout << " Same Code of another Book, please check again ! " << endl;
		
	} 
	void showAll() {
		if (books.empty()) {
			cout << " No Books in Libary, please add more !  " << endl;
		}
		for (int i = 0; i < books.size(); i++) {
			books[i].print(); 

	    }
	} 


	void addcustom(Customer b) {
		if (isNewc(b)) {
			Customers.push_back(b);
		}
		else cout << " Same Code of another Customer, please check again ! " << endl;

	}
	void showAllcustom() {
		if (Customers.empty()) {
			cout << " No Customers in Data, please add more !  " << endl;
		}
		for (int i = 0; i < Customers.size(); i++) {
			Customers[i].printc();

		}
	}



// ---------------------------------------------------------------------------------------------




	int findbyCode( int n ) {
		 
		
		for (int i = 0; i < books.size(); i++) {
			if (n ==  books[i].getCode() )  {
				return i ; 
				
			} 
		} 
		return -1; 

	}
	void showbyCode( ) {
		int n; 
		
		cout << " Find Book by Code :"; dk(n); 
		int l = findbyCode(n); 
		if (l == -1) cout << " NOT FOUND " << endl;
		else { books[l].print(); cout << endl; } 
	}


	int findbyId(int n) {


		for (int i = 0; i < Customers.size(); i++) {
			if (n == Customers[i].getId()) {
				return i;

			}
		}
		return -1;

	}
	void showbyId() {
		int n;

		cout << " Find Customer by Id :"; dk(n);
		int l = findbyId(n);
		if (l == -1) cout << " NOT FOUND " << endl;
		else { Customers[l].printc(); cout << endl; };
	}


	// --------------------------------------------------------------------------------

	void findbyname() {
		string s; cout << " Find Book by Name : "; getline(cin, s);
		Lowwer(s);
		bool found = false; 
		for (int i = 0; i < books.size(); i++) {
			if (Lowwer(books[i].getname()).find(s)  != string::npos) {
				found = true;
				books[i].print();
			}
			
		}
		if (found == false) {
			cout << " NOT FOUND " << endl; 
		}


	}

	void findbynamec() {
		string s; cout << " Find Customer by Name : "; getline(cin, s);
		Lowwer(s); 
		bool found = false;
		for (int i = 0; i < Customers.size(); i++) {
			if (Lowwer(Customers[i].getnamec()) .find(s) != string::npos) {
				found = true;
				Customers[i].printc();
			}

		}
		if (found == false) {
			cout << " NOT FOUND " << endl;
		}


	}
	// ------------------------------------------------------------------------------------



	void findbyauthor() {
		string s; cout << " Find Book by Author : "; getline(cin, s);
		Lowwer(s); 
		bool found = false;
		for (int i = 0; i < books.size(); i++) {
			if (Lowwer ( books[i].getauthor()) .find(s) != string::npos) {
				found = true; 
				books[i].print();
			}
			
		}
		if (found == false) {
			cout << " NOT FOUND " << endl;
		}


	}

	void findbysdt ( ){ 
	
		string s; cout << " Find Customer by Phone Number : "; getline(cin, s); 
		bool found = false;
		for (int i = 0; i < Customers.size(); i++) {
			if (Customers[i].getsdt().find(s) != string::npos) {
				found = true;
				Customers[i].printc();

			}

		}
		if (found == false) {
			cout << " NOT FOUND " << endl;
		}
	
	}

	// -----------------------------------------------------------------------------------------
	void CustomBorrow() {
		int n; cout << " Enter Customer'Id : "; dk(n);
		int have = 0;
		int l = findbyId(n);
		if (l == -1) {
			cout << " NOT FOUND !" << endl;
			return; 
		}
		else { Customers[l].printc(); }
		for (int i = 0; i < books.size(); i++) {
			if (books[i].getisBorrow() == n) {
				books[i].print();
				have++;
			}

		}
		if (have == 0) {
			cout << " Customer not Borrowed any Books yet !  " << endl;
		}

	}
	int LimitBorrow(int n) {

		int have = 0;
		
		

		for (int i = 0; i < books.size(); i++) {
			if (books[i].getisBorrow() == n) {

				have++;
			}

		}
		return have;


	}
	// ------------------------------------------------------------------------------------------
	void borrowBook(  ) {
		int n;
		int y;
		
		cout << " Borrow Book (code):"; dk(n);
		int l = findbyCode(n);
		if (l == -1) cout << " NOT FOUND " << endl;
		else if (books[l].getisBorrow() != 0 ) {
			cout << " Books -" << books[l].getname() << "- had been borrowed, please try next time " << endl;
		} 
		else {
			
			cout << " Id of Customer : " << endl;
			dk(y); 
			int o = findbyId(y);
			 
			if ( o == -1 ) {
				cout << " Customer's Id not exist " << endl;
			}
			else if (LimitBorrow(y) >= 5 ) {
				cout << " Reach Limit of Books can be Borowed "<<endl;
			}
			else {

				books[l].borrow(y); cout << " Succesful Borrowed !  " << endl;
			} 
		} 
	}
	void returnBook() {
		int n;
		
		
		cout << " Return Book (code) :"; dk(n);
		int l = findbyCode(n);
		if (l == -1) cout << " NOT FOUND " << endl;
		else if (books[l].getisBorrow() == 0) {
			cout << " Books had been returned, pleasy try next time " << endl;
		}
		else {
			books[l].returned(); cout << " Succesful Returned !  " << endl;
		}
	}


	void deleteBook() {
		int n;
		cout << " Delete Book (code) :"; dk(n);
		int l = findbyCode(n);
		if (l == -1) cout << " NOT FOUND " << endl;
		else if (books[l].getisBorrow() != 0  ) {
			cout << " Can't delete Books that being borrow !  " << endl;
		}
		else { 

			books.erase(books.begin() + l )  ; cout << " Succesful Deleted !  " << endl;
		}

	}

	bool isBorrowing( int n) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].getisBorrow() == n)
				return true; 
		} 
		return false; 
	} 

	

	void deleteCustomer() {
		int n; 
		cout << " Delete Customer ( Id ) :  "; dk(n) ; 
		int l = findbyId(n);
		if (l == -1) cout << " NOT FOUND " << endl;
		else if ( isBorrowing(n) )  {
			cout << " Can't delete Customer that being borrow !  " << endl;
		}
		else {

			Customers.erase(Customers.begin() + l); cout << " Succesful Deleted !  " << endl;
		}
	
	
	
	} 

	

	void input() {
		ofstream in("Libary.txt"); 
		if (!in) {

			cout << " CAN'T OPEN FILE \n";
			return;
		}
		for (int i = 0; i < books.size(); i++) {
			in << books[i].getCode() << "|" << books[i].getname() << "|" << books[i].getauthor() << "|" << books[i].getisBorrow()<<endl; 
		}
	} 


	void output() {
		ifstream dow("Libary.txt");
		if (!dow) {

			
			return;
		}
		string s;
		while (getline(dow, s)) {
			int dem = 0;
			for (char x : s) {
				if (x == '|') {
					dem++;
				}
			}
			if (dem != 3) {
				continue;
			}
			int s1 = s.find('|', 0);
			int s2 = s.find('|', s1 + 1);
			int s3 = s.find('|', s2 + 1);

			string p1 = s.substr(0, s1);
			string p2 = s.substr(s1 + 1, s2 - s1 - 1);
			string p3 = s.substr(s2 + 1, s3 - s2 - 1);
			string p4 = s.substr(s3 + 1);

			book b(stoi(p1), p2, p3);
			int pp4 = stoi(p4); 
			if (pp4 != 0 ) {
				b.borrow(pp4 );
			}
			books.push_back(b);
		} 
		dow.close();
	}
	
	


void inputc() {
	ofstream in("Customer.txt");
	if (!in) {

		cout << " CAN'T OPEN FILE \n";
		return;
	}
	for (int i = 0; i < Customers.size(); i++) {
		in << Customers[i].getId() << "|" << Customers[i].getnamec() << "|" << Customers[i].getsdt()<<endl;
	}
}


void outputc() {
	ifstream dow("Customer.txt");
	if (!dow) {


		return;
	}
	string s;
	while (getline(dow, s)) {
		int dem = 0;
		for (char x : s) {
			if (x == '|') {
				dem++;
			}
		}
		if (dem != 2) {
			continue;
		}
		int s1 = s.find('|', 0);
		int s2 = s.find('|', s1 + 1);
		

		string p1 = s.substr(0, s1);
		string p2 = s.substr(s1 + 1, s2 - s1 - 1);
		string p3 = s.substr(s2 + 1); 
	
		Customer b(stoi(p1), p2, p3);
		Customers.push_back(b);
	}
	dow.close();
}


};





book inBook( Libary &lib) {
	while (true) {
		
		cout << " Code of book : ";
		int c; dk(c);
		if (lib.findbyCode(c) == -1) {
			cout << endl;
			cout << " Name : ";
			string n; getline(cin, n);cout << endl;
			cout << " Author : ";
			string a; getline(cin, a);cout << endl;
			cout << " ------------------------------ " << endl;

			book b1(c, n, a);
			return b1;
		}
		else {
			
			cout << " Same Code of another Book, please check again ! " << endl;
		} 
	} 
} 

Customer inCustom(Libary& lib) {
	while (true) {

		cout << " Id of Customer : ";
		int i; dk(i) ;
		if (i > 0) {
			if (lib.findbyId(i) == -1) {
				cout << endl;
				cout << " Name : ";
				string nc; getline(cin, nc);cout << endl;
				cout << " Phone number : ";
				string dt;
				while (true) {
					getline(cin, dt);cout << endl;
					bool ok = true;
					for (int i = 0; i < dt.size(); i++) {
						if (!isdigit(dt[i])) {
							ok = false;
						}
					}
					if (dt.size() == 10 && dt[0] == '0'  && ok == true )
					  {
						break;
					}
					else cout << " Your Phone Number Invalid ! " << endl;
				}
				cout << " ------------------------------ " << endl;

				Customer b1(i, nc, dt);
				return b1;
			}
			else {

				cout << " Same Code of another Customers, please check again ! " << endl;
			}
		}
		else  cout << " This ID Is Not Allow ! " << endl;
	}
}





int main() {
	int i;
	int first;
	Libary s;
	s.output();
	s.outputc();
	while (true) {

		cout << " ========================= W  E  L  C  O  M  E ========================= " << endl;
		cout << "                          What You Want Manage ?                         " << endl;
		cout << "                               1 . Libary                                " << endl;
		cout << "                               2 . Customer                              " << endl;
		cout << "                               3 . Exit                                  " << endl;
		dk(first);
		if (first > 3) {
			cout << "INVALID, TRY AGAIN !" << endl;
			dk(first); 
		}
		switch (first) {




		case 1: {
			bool quit = false;
			while (true) {
				cout << " ================== Libary ===============" << endl;
				cout << " I   . Add Books " << endl;
				cout << " II  . Show All Books  " << endl;
				cout << " III . Find Books " << endl;
				cout << " IV  . Borrow Books " << endl;
				cout << " V   . Return Books " << endl;
				cout << " VI  . Delete Books " << endl;
				cout << " VII . Return " << endl;
				cout << endl;
				dk(i);
				while (i < 1 || i > 7) {
					cout << " INVALID, TRY AGAIN ! " << endl;
					dk(i);
				}


				switch (i) {
				case 1: {

					int n; cout << " How many book ? : "; dk(n);
					for (int i = 0; i < n; i++) {

						s.addbook(inBook(s));

					}
					s.input();
					break;

				}

				case 2: {
					s.showAll();
					break;
				}
				case 3: {
					int u;
					cout << " I  . Find By Code :  " << endl;
					cout << " II . Find By Name :  " << endl;
					cout << " III. Find By Author : " << endl;

					dk(u);
					while (u < 1 || u > 3) {
						cout << " INVALID TRY AGAIN " << endl;
						dk(u);
					}

					switch (u) {
					case 1: {
						s.showbyCode();
						break;
					}
					case 2: {
						s.findbyname();
						break;
					}
					case 3: {
						s.findbyauthor();
						break;
					}
					default: { break; }

					}
					break;

				}
				case 4: {
					s.borrowBook();
					s.input();
					break;
				}
				case 5: {
					s.returnBook();
					s.input();
					break;

				}
				case 6: {
					s.deleteBook();
					s.input();
					break;
				}
				case 7:
				{
					quit = true;
					break;
				}
				default: {
					break;
				}

				}
				if (quit == true) {
					break;
				}
			}
			break; 
		}
		case 2: {
			int l;
			while (true) {
				bool quit = false;
				cout << " ================== Customer ===============" << endl;
				cout << " I   . Add Customers " << endl;
				cout << " II  . Show All Customers  " << endl;
				cout << " III . Find Customers " << endl;
				cout << " IV  . Delete Customers " << endl;
				cout << " V   . Borrow List by Customer " << endl;
				cout << " VI  . Return " << endl;
				cout << endl;
				dk(l);
				
				while (l < 1 || l > 6) {
					cout << " INVALID, TRY AGAIN ! " << endl;
					dk(l);
				}
				switch (l) {
				case 1: {
					int n; cout << " How many customer ? : "; dk(n);
					for (int i = 0; i < n; i++) {

						s.addcustom(inCustom(s));

					}
					s.inputc();
					break;

				}
				case 2: {

					s.showAllcustom();
					break;
				}
				case 3: {


					int t;
					cout << " I  . Find By Id :  " << endl;
					cout << " II . Find By Name :  " << endl;
					cout << " III. Find By Phone Number : " << endl;

					dk(t);
					while (t < 1 || t > 3) {
						cout << " INVALID TRY AGAIN " << endl;
						dk(t);
					}

					switch (t) {
					case 1: {
						s.showbyId();
						break;
					}
					case 2: {
						s.findbynamec();
						break;
					}
					case 3: {
						s.findbysdt();
						break;
					}
					default: { break; }

					}
					break;
				}
				case 4: {
					s.deleteCustomer();
					s.inputc();
					break;

				}
				case 5: {
					s.CustomBorrow(); 
					break; 
				}
				case 6: { quit = true; break; }
				default: { break; }

				}
				if (quit == true) {
					break;
				}


			}
			break; 
		}
		case 3: {
			return 0;
		}
		default: { break; }
		}
	 

	 






	}







	
}
