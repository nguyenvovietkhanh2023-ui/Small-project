
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <random>
#include <fstream>
using namespace std;


// ============================================================
// EASY AI
// ============================================================

void aibegin(char board[3][3], char Ai, char human)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = Ai;
                return;
            }
        }
    }
}


// ============================================================
// CHECK WIN
// ============================================================

bool checkWin(char board[3][3], char player)
{
    // 3 hàng
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
        return true;

    if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
        return true;

    if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
        return true;


    // 3 cột
    if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
        return true;

    if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
        return true;

    if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
        return true;


    // 2 đường chéo
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;


    return false;
}

void input(int best[5]) {
    ofstream up("result.txt");
    if (!up) {

        cout << " CAN'T OPEN FILE \n";
        return;
    }

    for (int i = 1; i < 5; i++) {
        up << i << "|" << best[i] << "\n";
    }

}
void output(int best[5]) {
    ifstream dow("result.txt");
    for (int i = 1; i < 5; i++) {
        best[i] = 0;
    }
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
        if (dem != 1) {
            continue;
        }
        int s1 = s.find('|', 0);



        string p1 = s.substr(0, s1);
        string p2 = s.substr(s1 + 1);


        int d = stol(p1);
        int score = stol(p2);
        if (d >= 1 && d <= 4) {
            best[d] = score;
        }

    }
    dow.close();




}
// ============================================================
// OPPOSITE CORNER
// ============================================================

bool aiopposite(char board[3][3], char player, char human)
{
    if (board[0][0] == human && board[2][2] == ' ') {
        board[2][2] = player;
        return true;
    }

    if (board[2][2] == human && board[0][0] == ' ') {
        board[0][0] = player;
        return true;
    }

    if (board[0][2] == human && board[2][0] == ' ') {
        board[2][0] = player;
        return true;
    }

    if (board[2][0] == human && board[0][2] == ' ') {
        board[0][2] = player;
        return true;
    }

    return false;
}


// ============================================================
// FORK
// ============================================================

bool fork(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {

                // Thử đặt nước fork
                board[i][j] = player;

                // Nếu nước này tự thắng thì không phải fork
                if (checkWin(board, player)) {
                    board[i][j] = ' ';
                    continue;
                }

                // Count phải reset cho MỖI nước thử
                int count = 0;

                // Tìm các nước thắng tiếp theo
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {

                        if (board[x][y] == ' ') {

                            board[x][y] = player;

                            if (checkWin(board, player)) {
                                count++;
                            }

                            board[x][y] = ' ';
                        }
                    }
                }

                // Có ít nhất 2 nước thắng tiếp theo
                if (count >= 2) {
                    return true;
                }

                // Không phải fork -> hoàn tác
                board[i][j] = ' ';
            }
        }
    }

    return false;
}


// ============================================================
// MEDIUM AI
// ============================================================

void aipro(char board[3][3], char player, char human)
{
    // WIN hoặc BLOCK
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {




                // Thử BLOCK
                board[i][j] = human;

                if (checkWin(board, human)) {
                    board[i][j] = player;
                    return;
                }
                else {
                    board[i][j] = ' ';
                }
            }
        }
    }


    // CENTER
    if (board[1][1] == ' ') {
        board[1][1] = player;
        return;
    }


    // CORNER
    if (board[0][0] == ' ') {
        board[0][0] = player;
        return;
    }

    if (board[0][2] == ' ') {
        board[0][2] = player;
        return;
    }

    if (board[2][2] == ' ') {
        board[2][2] = player;
        return;
    }

    if (board[2][0] == ' ') {
        board[2][0] = player;
        return;
    }


    // ANY EMPTY
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {
                board[i][j] = player;
                return;
            }
        }
    }
}


// ============================================================
// HARD AI
// ============================================================

void aipromax(char board[3][3], char player, char human)
{
    // ========================================================
    // 1. WIN
    // 2. BLOCK
    // ========================================================

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {

                // WIN
                board[i][j] = player;

                if (checkWin(board, player)) {
                    return;
                }
                else {
                    board[i][j] = ' ';
                }


                // BLOCK
                board[i][j] = human;

                if (checkWin(board, human)) {
                    board[i][j] = player;
                    return;
                }
                else {
                    board[i][j] = ' ';
                }
            }
        }
    }


    // ========================================================
    // 3. FORK
    // ========================================================

    if (fork(board, player)) {
        return;
    }


    // ========================================================
    // 4. CENTER
    // ========================================================

    if (board[1][1] == ' ') {
        board[1][1] = player;
        return;
    }


    // ========================================================
    // 5. OPPOSITE CORNER
    // ========================================================

    if (aiopposite(board, player, human)) {
        return;
    }


    // ========================================================
    // 6. CORNER
    // ========================================================

    if (board[0][0] == ' ') {
        board[0][0] = player;
        return;
    }

    if (board[0][2] == ' ') {
        board[0][2] = player;
        return;
    }

    if (board[2][2] == ' ') {
        board[2][2] = player;
        return;
    }

    if (board[2][0] == ' ') {
        board[2][0] = player;
        return;
    }


    // ========================================================
    // 7. ANY EMPTY
    // ========================================================

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {
                board[i][j] = player;
                return;
            }
        }
    }
}
// ============================================================
//  HELLLLLLLLLLLLLLLLLLLLLL MODEEEEEEEEEEEEEEEEEEEEEEEEEEEE
// ============================================================


void aihell(char board[3][3], char player, char human) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                board[i][j] = player;

        }
    }

}

// ============================================================
// WHO WIN
// ============================================================

char who(char board[3][3])
{
    if (checkWin(board, 'X')) {
        return 'X';
    }

    else if (checkWin(board, 'O')) {
        return 'O';
    }

    return ' ';
}


// ============================================================
// TIE
// ============================================================

bool tie(char board[3][3])
{
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {
                count++;
            }
        }
    }

    if (count == 0) {
        return true;
    }

    return false;
}


// ============================================================
// SCORE
// ============================================================

void ratio(int win, int loss)
{
    cout << " You < " << win << " : " << loss << " > Ai " << endl;
}


// ============================================================
// PRINT BOARD
// ============================================================

void printBoard(char board[3][3])
{
    for (int r = 0; r < 3; r++) {

        for (int c = 0; c < 3; c++) {

            cout << board[r][c];

            if (c < 2)
                cout << " | ";
        }

        cout << endl;

        if (r < 2)
            cout << "--+---+--" << endl;
    }
}


// ============================================================
// FUNCTION POINTER
// ============================================================

void (*nah)(char board[3][3], char Ai, char human);

void clearAll(int best[5]) {

    string sure;
    cout << " DELETED ALL SCORE ? \n";
    cin >> sure;

    if (sure != "y" && sure != "Y") {
        cout << " CANCELED \n";
        return;
    }
    else {
        for (int i = 0; i < 5; i++) {
            best[i] = 0;
        }
        input(best);

    }

}

// ============================================================
// MAIN
// ============================================================

int main()
{
    char board[3][3];

    int n, i, j;
    int difficulty;

    int loss = 0;
    int win = 0;

    char human, Ai, swap, choice, turn;

    human = 'X';
    swap = human;
    int best[5];
    output(best);
    // ========================================================
    // TITLE
    // ========================================================

    cout << " ========================================================================================================= " << endl;
    cout << " ----x----o----x----o---- TIC ----x----o----x----o---- TAC ----x----o----x----o---- TOE ----x----o----x---" << endl;
    cout << " ========================================================================================================= " << endl;


    // ========================================================
    // MENU
    // ========================================================

    while (true) {

        cout << "\n---X-O-----M---E---N--U-----O-X---" << endl;
        cout << " --- I.PLAY ---\n";
        cout << " --- II. RULE --- \n";
        cout << " --- III. HIGHSCORE ---\n";
        cout << " --- IV. QUIT ---\n";
        cout << " Choose your fate (1-4): ";

        cin >> j;


        // INPUT ERROR
        if (cin.fail()) {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "That not a good choice " << endl;

            continue;
        }


        // INVALID MENU
        if (j <= 0 || j >= 5) {

            cout << " TRY AGAIN !!" << endl;

            continue;
        }


        // QUIT
        if (j == 4) {

            cout << " GOOD BYE " << endl;

            break;
        }


        // RULE
        else if (j == 2) {

            cout << "DON'T TELL ME YOU DON'T KNOW HOW TO PLAY X-O! " << endl;
        }

        string name[5] = { " ","EASY : ","MEDIUM : ","HARD : " };
        if (j == 3) {
            for (int i = 1;i < 4; i++) {
                cout << name[i] << best[i] << endl;
            }
            cout << "HELL : YOU CAN'T BEAT DEVIL " << endl;

            int lmao;

            cout << "1. CLEAR DATA " << endl;
            cout << "0. BACK " << endl;
            cin >> lmao;
            if (cin.fail()) {
                cout << " That not a good choice !!" << endl;
                cin.clear();
                cin.ignore(1000, '\n'); 
            } 
            switch (lmao) {

            case 1: {
                clearAll(best);
                break;

            }
            default:
                break;

            }
        }

        // ====================================================
        // PLAY
        // ====================================================

        else if (j == 1) {


            // =================================================
            // CHOOSE DIFFICULTY
            // CHỈ HỎI 1 LẦN KHI VÀO PLAY
            // =================================================

            while (true) {

                cout << " ================================================================================ " << endl;
                cout << "                         CHOOSE YOUR DIFFICULTY                                   " << endl;
                cout << " ================================================================================ " << endl;

                cout << " --------*----------- I. EASY -----------*-----------" << endl;
                cout << " -----*-----*-------- II. MEDIUM ------*----*--------" << endl;
                cout << " --*-----*---*---*--- III. HARD ---*---*---*---*-----" << endl;
                cout << " w̵̛͗̃̓͛͒́̈͠ IV. HELL  w̵̛͗̃̓͛͒́̈͠" << endl;
                cout << " Choose your mode : ";

                cin >> difficulty;


                // INPUT ERROR
                if (cin.fail()) {

                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "That not a good choice ;(" << endl;

                    continue;
                }


                // INVALID DIFFICULTY
                if (difficulty < 1 || difficulty > 4) {

                    cout << " TRY AGAIN !!" << endl;

                    continue;
                }


                // CHOOSE AI
                if (difficulty == 1) {

                    nah = aibegin;
                    break;
                }

                else if (difficulty == 2) {

                    nah = aipro;
                    break;
                }

                else if (difficulty == 3) {

                    nah = aipromax;
                    break;
                }
                else if (difficulty == 4) {
                    nah = aihell;
                    break;
                }
            }


            // =================================================
            // REMATCH LOOP
            // Difficulty KHÔNG nằm trong đây
            // =================================================

            while (true) {


                // =================================================
                // RESET BOARD
                // =================================================

                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        board[r][c] = ' ';
                    }
                }


                // =================================================
                // PLAYER / AI
                // =================================================

                human = swap;

                if (human == 'X') {
                    Ai = 'O';
                }
                else {
                    Ai = 'X';
                }

                turn = 'X';


                cout << " YOU : " << human << endl;
                cout << " Ai  : " << Ai << endl;

                cout << endl;

                printBoard(board);


                // =================================================
                // GAME LOOP
                // =================================================

                while (true) {


                    // =================================================
                    // HUMAN TURN
                    // =================================================

                    if (turn == human) {

                        cout << " Player " << human << " turn " << endl;


                        while (true) {

                            cout << "Enter a number between 1 and 9 to place your mark (X or O): ";

                            cin >> n;


                            if (cin.fail()) {

                                cin.clear();
                                cin.ignore(1000, '\n');

                                cout << "Out of board ;(" << endl;

                                continue;
                            }


                            if (n > 9 || n < 1) {

                                cout << " Please try again " << endl;

                                continue;
                            }


                            i = (n - 1) / 3;
                            j = (n - 1) % 3;


                            if (board[i][j] != ' ') {

                                cout << " OCCUPIED !! " << endl;

                                continue;
                            }


                            break;
                        }


                        board[i][j] = human;

                        printBoard(board);
                    }


                    // =================================================
                    // AI TURN
                    // =================================================

                    else {

                        cout << endl;
                        cout << " Player " << Ai << " turn " << endl;



                        nah(board, Ai, human);


                        printBoard(board);
                    }


                    // =================================================
                    // CHECK WIN / TIE
                    // =================================================

                    if (who(board) == human) {

                        cout << "PLAYER " << human << " WIN" << endl;

                        win++;
                        if (win > best[difficulty]) {
                            best[difficulty] = win;
                            input(best);

                        }

                        break;
                    }

                    else if (who(board) == Ai) {

                        cout << " PLAYER " << Ai << " WIN " << endl;

                        loss++;

                        break;
                    }

                    else if (tie(board)) {

                        cout << " TIE !! " << endl;

                        break;
                    }


                    // =================================================
                    // CHANGE TURN
                    // =================================================

                    if (turn == 'X') {
                        turn = 'O';
                    }
                    else {
                        turn = 'X';
                    }
                }


                // =================================================
                // REMATCH
                // =================================================
                cout << " ------------------ SCORE -------------------------" << endl;

                ratio(win, loss);
                while (true) {



                    cout << "ONE MORE GAME ?? (y/n (reset)) " << endl;

                    cin >> choice;


                    if (choice == 'n' ||
                        choice == 'N' ||
                        choice == 'y' ||
                        choice == 'Y') {

                        break;
                    }

                    else {

                        cout << " I think you need to sleep \n";
                    }
                }


                // =================================================
                // NO REMATCH
                // =================================================

                if (choice == 'n' || choice == 'N') {

                    win = 0;
                    loss = 0;

                    cout << " GOOD GAME !!" << endl;

                    break;
                }


                // =================================================
                // REMATCH -> ĐỔI NGƯỜI CHƠI X/O
                // =================================================

                if (swap == 'X') {

                    cout << " NOW, PLAYER O TURN " << endl;

                    swap = 'O';
                }

                else {

                    cout << " NOW, PLAYER X TURN " << endl;

                    swap = 'X';
                }


                // Y -> quay lại đầu REMATCH LOOP
                // KHÔNG hỏi difficulty lại
            }
        }
    }


    return 0;
}
