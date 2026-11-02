#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm> 
#include <climits>
#include <random>

using namespace std;

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    string choice;
    while (true) {
        cout << " ****---------M----E-----N-----U-----------------***" << endl;
        int cho; 
        cout << "  ---- I. PlAY ---- " << endl;
        cout << " ---- II.RULE ---- " << endl;
        cout << " ---- III. EXIT ---- " << endl;
        cin >> cho;
        if (cho == 2) {
            cout << " -----------R---U---L---E-------------------" << endl;
            cout << " Nhap so n de lua chon khoang doan tu  0 - n " << endl;
            cout << " Cu moi luoc ban nhap so e hien ra ' Lon hon '  hoac ' Nho hon '\n";
            cout << " Doan den khi nao ban CHINH XAC \n";
            cout << " Hay thu doan voi so luong doan nho nhat , cung nhu Range n cua ban cao nhat \n ";
            cout << " Good Luck " << endl;
        }
        else if (cho == 3) {
            cout << " Hen gap lai !!";
            break; 
        }
        else if (cho == 1) {

            do {
                cout << " |||------------R--A--N--G--E-----------------|||" << endl;
                int n;
                cout << " Lua chon khoang ban muon doan : "; cin >> n;
                std::uniform_int_distribution<int> chance(1, n);
                int guess = chance(gen);

                int dem = 0;



                int a;
                dem += 1; 
                cout << "------------S---T---A---R---T-----------------\n";
                cout << " Moi nhap so bat dau : " << endl;
                while (true) {
                    cin >> a;
                    if (a > guess) {
                        cout << " Lon hon so ban dang doan !! " << endl;
                        dem += 1;
                    }
                    else if (a < guess) {
                        cout << " Nho hon so ban dang doan !! " << endl;
                        dem += 1;
                    }
                    else {
                        cout << " BAM DA DOAN DUNG,CHUC MUNG !!" << endl;
                        break;
                    }
                }


                while (true) {
                    cout << "---------------C--O--N--T--I--N--U--E---?--------------\n";
                    cout << " BAN DA DOAN DUNG SO VOI " << dem << " LAN DOAN " << endl;
                    cout << " Tiep tuc choi (y/n)\n";
                    cin >> choice;
                    if (choice == "n" || choice == "N" || choice == "y" || choice == "Y") {
                        break;
                    }
                    else {
                        cout << " Chac ban hoi bi hoa mat nhap lai di :>\n";
                    }
                }

                if (choice == "n" || choice == "N") {
                    cout << " Quay lai MENU ... " << endl;

                }
            } while (choice == "y" || choice == "Y");
        } 
    }






}
  