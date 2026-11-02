#include <iostream>
#include <string>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 6);
    uniform_int_distribution<int> chance(1, 100);
    uniform_int_distribution<int> cheat(3, 6);

    string choice;
    string guess;
    int tk = 10;
    int luck = 0;
    int j = 0;
    int bet = 0;

    while (true) {
        cout << "\n---D-E-A-T-H---------M---E---N--U--------L-I-V-E--" << endl;
        cout << " --- I. BET YOUR LIFE ---\n";
        cout << " --- II. HOW TO ESCAPE ( RULE ) --- \n";
        cout << " --- III. GIVE UP ---\n";
        cout << " Choose your fate (1-3): ";
        cin >> j;

        if (j <= 0 || j >= 4) {
            cout << " TRY AGAIN !!" << endl;
            continue;
        }
        else if (j == 2) {
            cout << "\n=======================================================================" << endl;
            cout << " Bet big, get rich, and win your freedom." << endl;
            cout << " Think it's easy? It's as easy as KICKING THE BUCKET." << endl;
            cout << "=======================================================================" << endl;
            continue;
        }
        else if (j == 3) {
            cout << "\n WELCOME TO HELL !! THERE IS NO GIVING UP!" << endl;
            j = 1; // Ép vào game
        }

        // Bắt đầu chơi game khi j == 1
        if (j == 1) {
            do {
                if (tk < 1) {
                    cout << "\n Your body was found in the working-class district... You kicked the bucket !!! " << endl;
                    return 0; // End Game Over
                }
                if (tk >= 30) {
                    cout << "\n YOU ESCAPED FROM US? THAT'S IMPRESSIVE... NOW WAKE UP !!! \n";
                    return 0; // End Win
                }

                // Nhập tiền cược
                while (true) {
                    cout << "\n Enter your bet (1 - " << tk << "): ";
                    cin >> bet;
                    if (cin || (bet >= 1 && bet <= tk))  break;
                    cout << " YOU CAN'T BET WHAT YOU DON'T HAVE!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                // Chọn Tài / Xỉu
                while (true) {
                    cout << "-----------------------------------------------------------------------" << endl;
                    cout << " Choose whatever you want ( Tai / Xiu ): ";
                    cin >> guess;
                    if (guess == "Tai" || guess == "Xiu") break;
                    cout << " WRONG , TRY AGAIN !!" << endl;
                }

                int ch = chance(gen);
                int a = distrib(gen);
                int b = distrib(gen);
                int c = distrib(gen);
                int sum = 0;

                // Kiểm tra Bão (3 xúc xắc giống nhau) ngay từ đầu
                if (a == b && b == c) {
                    cout << a << " " << b << " " << c << endl;
                    cout << " GOD BLESS YOU " << endl;
                    tk -= bet;
                    if (luck > 0) {
                        tk -= luck;
                    }
                    luck = 0;
                    cout << " Your money has decreased : " << tk << endl;
                }
                else {
                    sum = a + b + c;

                    // Nếu tổng ban đầu là Xỉu (4 - 10), kích hoạt tỷ lệ nhà cái gian lận (50%)
                    if (sum >= 4 && sum <= 10 && ch <= 50) {
                        a = cheat(gen);
                        b = cheat(gen);
                        c = cheat(gen);
                        sum = a + b + c;
                    }

                    cout << a << " " << b << " " << c << endl;

                    // Kiểm tra nếu xúc xắc sau khi gieo/cheat ra Bão
                    if (a == b && b == c) {
                        cout << " GOD BLESS YOU " << endl;
                        tk -= bet;
                        if (luck > 0) {
                            tk -= luck;
                        }
                        luck = 0;
                        cout << " Your money has decreased : " << tk << endl;
                    }
                    else {
                        string result = (sum >= 11 && sum <= 17) ? "Tai" : "Xiu";
                        cout << " " << (result == "Tai" ? "TAI !!" : "XIU !!") << " \n";

                        if (guess != result) {
                            cout << " Unlucky! You'll get 'em next time. " << endl;
                            tk -= bet;
                            if (luck > 0) {
                                tk -= luck;
                            }
                            luck = 0;
                            cout << " Your money has decreased : " << tk << endl;
                        }
                        else {
                            cout << " CONGRATULATIONS! SPOT ON! !! \n";
                            tk += bet;
                            luck += 1;
                            cout << " Your money has increased: " << tk << endl;
                        }
                    }
                }

                bet = 0;
                cout << " -----------------------------------------------------------------" << endl;

                // Hỏi tiếp tục chơi hay ngưng
                while (true) {
                    cout << " EVERYTHING HAS A COST : " << luck << endl;
                    cout << " YOUR ODDS HAVE INCREASED, ONE MORE TRY ?? (y/n) " << endl;
                    cin >> choice;
                    if (choice == "n" || choice == "N" || choice == "y" || choice == "Y") break;
                    cout << " Seeing double? Try entering again :>\n";
                }

                // Nếu người chơi chọn "n", nhà cái ép chơi tiếp
                if (choice == "n" || choice == "N") {
                    cout << " DO YOU THINK YOU CAN RUN , BREAK YOUR LEG \n\n";
                    choice = "y";
                }

            } while (choice == "y" || choice == "Y");
        }
    }

    return 0;
}