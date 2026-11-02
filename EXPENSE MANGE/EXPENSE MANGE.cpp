
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
using ll = long long ; 
// =========================== CHUYEN =============================  
string nghin( ll n) {
	int dem = 0;
	int res = 0; 
	char x;string tong;
	if (n == 0) {
		return "0";
	}
	while (n > 0) {
		x = ( n % 10) + '0';
		tong.insert(0,1, x ) ;
		n /= 10; 
		dem++; 
		if (dem == 3 * (res + 1) && n > 0 ) {
			tong.insert(0 , 1, '.');
			res++; 
		}
		
	}
	return tong; 
	
}
string thuong(string s) {
	for (char& c : s) {
		c = tolower(c);
	}
	return s;
}

//============================ YEAR ====================================

bool leapyear(ll year) {
	return (year % 4 == 0 && year % 100 != 0) ||
		year % 400 == 0;
}

int daysInMonth(ll month, ll year) {
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;

	case 2:
		if (leapyear(year))
			return 29;
		return 28;

	default:
		return 31;
	}
}

bool isValidDate(const string& s) {

	if (s.length() != 10)
		return false;

	if (s[2] != '/' || s[5] != '/')
		return false;

	for (int i = 0; i < 10; i++) {

		if (i == 2 || i == 5)
			continue;

		if (!isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}

	int day = stoi(s.substr(0, 2));
	int month = stoi(s.substr(3, 2));
	int year = stoi(s.substr(6, 4));

	if (year < 1900)
		return false;

	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > daysInMonth(month, year))
		return false;

	return true;
}

// =============================== DK =======================================================


void dk(ll& n) {
	while (!(cin >> n) || n < 0) {
		cout << " INVALID, try again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
}
bool space(const string& s) {
	for (char x : s) {
		if (x == ' ' || x == '\t') return true;
	}
	return false;
}
void di(string& s, bool choPhepSo) {
	while (true) {
		getline(cin, s);

		if (s.empty()) {
			cout << "INVALID, try again: ";
			continue;
		}

		if (!choPhepSo) {
			bool coSo = false;

			for (char x : s) {
				if (isdigit(x)) {
					coSo = true;
					break;
				}
			}

			if (coSo) {
				cout << "INVALID, try again: ";
				continue;
			}
		}

		return;
	}
}

void mon(ll& n) {
	while (!(cin >> n) || n < 0) {
		cout << " INVALID, try again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	if (n == 0) {
		cout << " FREE! \n";
	}
}


// ================================= STRUCT =========================== ; 

struct Expense
{
	string name;
	ll money;
	string categ;
	string date;
	

	void in() {
		cout << " NAME OF EXPENSE : ";di(name,true);cout << endl; 

		cout << " COST OF PRODUCT (VND) : ";
		mon(money); 


		cout << " KIND OF CATEGORY : ";
		while (true) {
			di(categ, false);
			if (!space(categ)) break;
			cout << " INVALID , try again: ";
		}
		cout << endl;
		cout << " DATE OF TRANSACTION : ";
		while (true) {
			getline(cin, date);if (isValidDate(date)) return;
			else
				cout << " INVALID DATE,TRY AGAIN \n"; 
		}
	}
	
	void out() {
		cout << " NAME    : " << name<<endl ; 
		cout << " COST     : " << nghin(money) << "VND"<<endl;
		cout << " CATEGORY : " << categ  << endl; 
		cout << " DATE     : " << date << endl; 
	}
}; 

//==================   Functionality   =======================  

void Sum(vector<Expense> &save) {
	if (save.empty()) {
		cout << " NO EXPENSE " << endl;
		return;

	}
	ll sum = 0; 
	for (int i = 0; i < save.size(); i++) {
		sum += save[i].money; 

	}
	cout << " -------------------------- " << endl; 
	cout << " TOTAL : " << nghin(sum)<< " VND" << endl;
	cout << " -------------------------- " << endl;
}
void biggest(vector <Expense >& save) {
	if (save.empty()) {
		cout << " NO EXPENSE " << endl;
		return;

	}
	ll lon = 0; 
	for (int i = 0; i < save.size(); i++) {
		if (save[i].money > save[lon].money) {
			lon = i;
		}
	}
		cout << "  THE MAX EXPENSE " << endl;
		save[lon].out(); cout << endl; 	
}


void search(vector< Expense>& save) {
	if (save.empty()) {
		cout << " NO EXPENSE " << endl;
		return;

	}
	string find; 
	cout << " THE CATEGORY YOU WANT TO FIND \n";
	while (true) {
		getline(cin, find);
		if (!space(find)) break; 
			cout << " INVALID ";
	} 
	find = thuong(find); 
	int cnt = 0;
	cout << " ================ RESULT ================= " << endl;
	for (int i = 0; i < save.size(); i++) {
		if (thuong(save[i].categ) == find) {
			cnt++; 
			cout << i + 1 << " ------------------------------- " << endl;
			save[i].out();
		}
		
	
	}  
	if (cnt == 0) {
		cout << " NOT FOUND \n";
	}
	 
	
	
}

void stat(vector < Expense>& save) {
	if (save.empty()) {
		cout << " NO EXPENSE " << endl;
		return;

	}
	map <string, ll > key; 
	for (int i = 0; i < save.size(); i++) {
		key[thuong(save[i].categ)] += save[i].money; 
	}
	ll sum = 0; 
	cout << " =================== STATISTICS =================== " << endl; 
	for (auto& x : key) {
		cout << x.first <<" "<<  nghin(x.second) << " VND" << endl;
		sum += x.second;
	}
	cout << " TOTAL  :  " << nghin(sum) << " VND" << endl;
}








ll n;
void nhap(vector<Expense>& save) {
	cout << " HOW MANY EXPENSE : ";
	dk(n);

	if (n == 0) {
		cout << " EMPTY\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "---------------------------\n";
		Expense a;
		a.in();
		save.push_back(a);
	}
}

void xuat(vector<Expense>& save) {
	if (save.empty()) {
		cout << " NO EXPENSE " << endl;
		return;

	}
	cout << " ========== LIST EXPENSE =========== \n ";

	for (int i = 0; i < save.size(); i++) {
		cout << " ------------------------ \n";
		cout << i + 1;
		save[i].out();
	}
} 

// =================   Functionality   =======================  

void deleteEX(vector<Expense> &save) {
	if (save.empty()) {
		cout << " NO EXPENSE " << endl;
		return;

	}
	xuat(save); 
	ll del;
	cout << " WHERE YOU WANT DELETE : ";
	dk(del);
	while (del < 1 || del >(ll)save.size()) {
		cout << " INVALID, try again: ";
		dk(del);
	}

	save.erase(save.begin() + (del - 1));
	cout << " DELETED!" << endl;
	
}
// ==================== FILE ==========================================
void input(vector<Expense> save) {
	ofstream up("expense.txt");
	if (!up ){

		cout << " CAN'T OPEN FILE \n"; 
		return ;
	}
	for (int i = 0; i < save.size(); i++) {
		up << save[i].name << "|" << save[i].money << "|" << save[i].categ << "|" << save[i].date<<endl ;
	}
	
}
void output(vector<Expense> &save) {
	ifstream dow("expense.txt");
	if (!dow) {

		cout << " CAN'T OPEN FILE \n";
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

		bool hopLe = true;

		if (p2.empty())
			continue;

		for (char x : p2) {
			if (!isdigit(x)) {
				hopLe = false;
				break;
			}
		}
m
		if (!hopLe)
			continue;

		Expense a;                       
		a.name = p1;
		a.money = stoll(p2);
		a.categ = p3;
		a.date = p4;
		save.push_back(a);               
	}
	dow.close();

	

	
}
// ========================================================================
void clearAll(vector<Expense> save) {
	if (save.empty()) {
		cout << " NO EXPENSE " << endl;
		return;

	}
	string sure;
	cout << " DELETED ALL DATA ? \n"; 
	getline(cin, sure);

	if (sure != "y" && sure != "Y") {
		cout << " CANCELED \n";
		return;
	}
	else {
		save.clear();
		input(save); 

	} 

}
void up(vector <Expense>& save) {

	for (int i = 1; i < save.size(); i++) {
		Expense x  = save[i]; ll pos = i - 1;
		while (pos >= 0 && save[pos].money > x.money) {
			save[pos + 1] = save[pos]; 
			pos--; 
		}
		save[pos + 1] = x;

	}
	xuat(save); 

}
void down(vector <Expense>& save) {

	for (int i = 1; i < save.size(); i++) {
		Expense x = save[i]; ll pos = i - 1;
		while (pos >= 0 && save[pos].money < x.money) {
			save[pos + 1] = save[pos];
			pos--;
		}
		save[pos + 1] = x;

	}
	xuat(save);

}


int main() {
	ll choice;
	vector < Expense > save;
	cout << " ================================================================= " << endl;
	cout << "                       EXPENSE MANAGE                              " << endl;
	cout << " ================================================================= " << endl;
	output(save);
	while (true) {
		cout << endl;
		cout << " ------------------------------------------------------------------------------------------------------------------ " << endl;
		cout << " I   . Add Expense " << endl;
		cout << " II  . View Expenses " << endl;
		cout << " III . Calculate Total Spending " << endl;
		cout << " IV  . Find Largest Expense " << endl;
		cout << " V   . Search by Category " << endl;
		cout << " VI  . Delete Expense " << endl;
		cout << " VII . Statistics " << endl;
		cout << " VIII. Sort Expense " << endl;
		cout << " IX  . CLEAR DATA  " << endl;
		cout << " X   . Exit       " << endl;
		cout << " CHOOSE FUNCTIONALITY : " << endl;


		dk(choice);

		cout << " ------------------------------------------------------------------------------------------------------------------ " << endl;

		while (choice < 1 || choice > 10) {
			cout << " INVALID, try again \n ";

			dk(choice);
		}
		switch (choice) {

		case 1: {
			nhap(save);
			input(save); break;
		}
		case 2: {
			xuat(save);
			break;
		}
		case 3: {
			Sum(save); break;
		}
		case 4: {
			biggest(save);break;
		}
		case 5: {
			search(save);break;
		}
		case 6: {
			deleteEX(save);
			input(save); break;
		}
		case 7: {
			stat(save);break;
		}
		case 8: {
			int i;
			cout << " Choose type of Sort : \n";
			cout << "1. Up \n";
			cout << "2. Down \n";
			cout << " 3 Back \n"; 
			cin >> i; 
			switch (i) {
			case 1: {
				up(save);
				break;
			}
			case 2: {
				down(save);
				break;
			}
			case 3: {

				break;
			}
			default:
				break;
			}
			break;
		case 9: {
			clearAll(save); break;
		}
		case 10: {
			return 0; break;

		}
		default: cout << " INVALID \n ";


		}




		}
	}
}