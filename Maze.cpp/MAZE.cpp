#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm> 
#include <climits>
#include <cctype>
#include <random>
#include <fstream> 
#include <filesystem>
#include <queue>
using namespace std;
mt19937 rng(random_device{}()); // biến random 

// ------------------------------------------------------------------------ ĐỤC TƯỜNG ( RANDOM ) -------------------------------------------------------------
void net(int i, int j, vector<string> & maze) { // biến tạo ra bảng ngẫu nhiên 
    int n = (int)maze.size();  // xét n bằng maze.size() ; với maze là vector < string > hay là cái map của màn 
    int di[4] = { 2,-2,0,0 };  // tạo ra hai độ lệch tạo ra các phòng cách 2 ô tại mọi phía cả cột và dòng
    int dj[4] = { 0,0,2,-2 };
    
    int order[4] = { 0,1,2,3 }; // xét các gtri để tạo ra di[0 - 3 ] và dr[0-3] 
    shuffle(order, order + 4, rng); // xáo trộn, tạo ngẫu nhiên order theo 4 hướng 
    int nj, ni;
    maze[i][j] = '.'; // xét điểm i , j , lúc đầu là '.' 

    for (int k = 0; k < 4; k++) { 
        int d = order[k]; 
        ni = i + di[d]; // xét dòng và cột mới thành dòng và cột hiện tại độ lệch 2 ô và ngẫu nhiên bởi d 
        nj = j + dj[d]; // vd : order xếp ngẫu nhiên { 1,2,0,3 }.d = order[1] tức di[2] và dj[2] --> ni = i -2 , nj = j +0

        if (nj >= 1 && nj <= n - 2 && ni >= 1 && ni <= n - 2 && maze[ni][nj] == '#') { 
   // nếu cột và dòng mới đó >=1 và nhỏ hơn n-2 ( vì n-1 là tường bên ngoài ) và nó phải bằng # để thế vào
            maze[i + di[d] / 2][j + dj[d] / 2] = '.';  // vd : i,j = 1,1. thì khi 1(-2/2)  và 1+(0/2) == (0 ,1). Tọa độ đó trở thành '.' 
         
            net(ni, nj, maze); // gọi đệ quy để đục tiếp
             
        }
       
    }
}
// -------------------------------------------------------------------- TẠO BẢN ĐỒ ( RANDOM ) -----------------------------------------------------
vector < string > makeMaze(int n) {
    vector<string> maze(n, string(n, '#')); // cho toàn bộ bản đồ n*n toàn # để đục 
    net(1, 1, maze); // set i,j = 1,1  
    return maze; //trả về ảnh bản dồ 
}
// ------------------------------------------------------------------- CẤU TRÚC BẢN ĐỒ ( CLASSIC ) ---------------------------------
struct Level {

    vector < string> maze; // map 
    int p1, p2; // điểm player hiện tại 
    int e1, e2;// điểm thoát khỏi maze
    int po1, po2; 
    int pe1, pe2; 



};
vector<Level> game{

    {
        {
     "########",
     "##.....#",
     "##.###.#",
     "##.##.##",
     "##....##",
     "#..#####",
     "##.#####",
     "########"
       },
      5,1,2,6

     },
    {
        {
            "############",
            "##.###.#####",
            "#..#.#.#...#",
            "#.#..#.#.#.#",
            "#.##.#...#.#",
            "#.##...#.#.#",
            "#.##.#...#.#",
            "#.##...###.#",
            "#...#.####.#",
            "###.#.######",
            "###...######",
            "############"
        },

            1,2,8,10


            },

    {
        { 
    "#################",
    "##.##############",
    "##.#.......#...##",
    "##.#.###.#.#.#.##",
    "##.#.#...#.#.#.##",
    "##.#.#.###.###.##",
    "##.#(#.#.#...#.##",
    "##.###.#.###.#.##",
    "##.....#(..#...##",
    "##########.###.##",
    "##.........#...##",
    "##.###.#####.####",
    "##.#.#.#...#.#.##",
    "##.#.#.#.#.#.#.##",
    "##...#...#.....##",
    "##############.##",
    "#################"

},
1,2,15,14,6,4,8,8
},









{
        {

"################",
"##...####....###",
"#..#.##...##...#",
"##.#.##.#####.##",
"##.#.##.....#.##",
"##.#.######.#.##",
"####.#...##.#..#",
"##.....#.##.##.#",
"##.#####.#..#..#",
"##.##.##.#.##.##",
"##.##.##...#(.##",
"##.##.#######.##",
"##.#...........#",
"##(#.#########.#",
"####.###########",
"################"
},
2,1,
14, 4,13,2,10,12
},
{
    {
"######################",
"####.#################",
"####.......######....#",
"##...#.###.##.....#.##",
"##.###.###....###.#.##",
"##.##..######.#.....##",
"##....##......#.###..#",
"##.#.##..###.####.)#.#",
"##.#.##.####.#######.#",
"##.#.##.#...##.....#.#",
"##.#.##...#####.##.#.#",
"##.#.##.####.####..#.#",
"#(.#..##........#....#",
"#####..#.######.##.###",
"######.#.######.##.###",
"######....#...#.##..##",
"#..######...#.#.###..#",
"##..######.##.#.##..##",
"###......#.##...#..###",
"###.####.#.##.#...####",
"###....#......########",
"######################",


},
    16,1,9,12,12,1,7,18
},
{

    {
            "#########################",
            "###.......#.......#..)..#",
            "#...#.###.##.####.#.###.#",
            "#####.#......#....#...#.#",
            "#.##..######.#.######.#.#",
            "#....##......#.###....#.#",
            "#.#.##..###.####...####.#",
            "#.#.##.####.#######.....#",
            "#.#....#...##.....#.###.#",
            "#.#.####.#####.##.#.#...#",
            "#.#.##.####.####..#.#.#.#",
            "#...#..##........#..#.#.#",
            "#.##..#.#(####.##.##..#.#",
            "#..##.#.######.##.##.##.#",
            "##.......#...#.##..#.##.#",
            "..######...#.#.###.#....#",
            "#..######.##.#.##..####.#",
            "##......#.##...#..##....#",
            "##.####.#.##.#...###.##.#",
            "##....#......#######.##.#",
            "#####.######...#.....##.#",
            "#...#......###.#.######.#",
            "#.#.######...#.#.#......#",
            "#.#........#..##.#.####.#",
            "#########################"
    },
    2,1,23,23,12,9,1,21
}

};


// ------------------------------------------------------------- IN BẢN ĐỒ SAU MỖI NƯỚC ----------------------------------------------
void printB(const Level &cur , int p1 ,int p2) {
    for (int i = 0; i < cur.maze.size(); i++) {
        for (int j = 0; j < cur.maze[0].size(); j++) {

            if (i == p1 && j == p2) {
                cout << "* ";
            }
            else if (i == cur.e1 && j == cur.e2) {
                cout << "E ";
            }
           
           
            else {
                cout << cur.maze[i][j]<<" ";
            }
        }
        cout << '\n';
    }
    cout << endl;
}
// ------------------------------------------------------------- ĐƯỜNG HẦM ( CLASSIC ) ----------------------------------------------
void portal(int& i, int& j, const Level& cur) { 

    if (i == cur.po1 && j == cur.po2) {
        i = cur.pe1; j = cur.pe2;
       
    }
    else if (i == cur.pe1 && j == cur.pe2) {
        i = cur.po1; j = cur.po2;
        
    }
    
}

// ---------------------------------------------------- CÁC NÚT DI CHUYỂN --------------------------------------------
int moveP(int& i, int& j,const Level &cur) {
    string mov;
    while (true) {
        cout << "Enter your move (w a s d) :  " << endl;
        getline(cin, mov); 
        if (cin.fail()) {
            cin.clear();
            return 1; 

        }
        if (mov.length() != 1) {
            cout << "INVALID, TRY AGAIN " << endl;
                continue;
                return 1; 
        }
        char m = mov[0]; 
        m = tolower(m); 
        int newi;
        int newj;
        // các biến khi lệnh w,a,s,d sắp thay đổi 
       
        if (m == 'w') {
            newi = i - 1;newj = j; // giảm dòng
           
          
        }
        else if ( m== 's')  {
            newi = i + 1;newj = j;// tăng dòng
           
           
        }
        else if ( m == 'a') {
            newj = j - 1; newi = i;// giảm cột 
            
        }
        else if ( m ==  'd') {
            newj = j + 1; newi = i; // tăng cột 
            
        }
        else if (m == 'q') { // dừng giữa chừng 
            cout << " QUIT?, NAH JUST A BREAK " << endl; 
            return 0; 
        }
        else if (m == 'h') {
            cout << endl;
            cout << " HERE [" << i +1  << "]" << "[" << j +1  << "]" << " don't lost again " << endl;
            return 3; 
        }
       
        else { 
            cout << " ERROR, TYPE AGAIN" << endl;
           
            continue; 
            return 1;
        }

        // Các đk xảy ra khi cho di chuyển 
        // khi ra khỏi bảng maze
        if (newi< 0  || newj < 0 || newi >= cur.maze.size() || newj >= cur.maze[0].size()  ) { 
            cout << "INVALID, TRY AGAIN " << endl;
            
           
            return -1;
        }
        // khi vào đc chỗ có thể đi 
        if (cur.maze[ newi][ newj] != '#') {
            i = newi ; 
            j = newj ;
            portal(i, j, cur); 
            return -1 ; 
        }

        // khi dụng tường
        else {
            cout << " OUCH !! THE WALL" << endl;
            
            
            return 2;
        }
        
       
    }
}

// ------------------------------------------ LƯU BESTSCORE ------------------------------------------
void input(int total ) {   
    ofstream up("MAZE.txt");
    if (!up) {

        cout << " CAN'T OPEN FILE \n";
        return;
    }

    up << total; 

}
int output(int total) {
    ifstream dow("MAZE.txt");
   
    if (!dow) {

        cout << " CAN'T OPEN FILE \n";
        return 100000000 ;
    }
    int score;
    if (dow >> score) {
        return score;
    }
    return 100000000;
    }
// -------------------------------------------- KIỂM TRA ĐK BEST ---------------------------------------------------------------
bool checkBest(int total, int& best) {
    if (total < best) {
        best = total;
       input(best);
        return true;
    }
    return false;
}
// --------------------------------------------- BFS ----------------------------------------------------------------------
int shortest(const Level& cur) {
    // Tính đường di ngắn nhất 
    queue < pair <int, int> > wait; // Đây là hàm mới ( hàm chờ ) với nguyên tắc First In First Out 
    vector<vector<int>> dist(cur.maze.size(), vector<int>(cur.maze[0].size(), -1));
    // vector<int>(cur.maze[0].size(), -1) là một hàng: một dãy số nguyên có số phần tử bằng số cột của bản đồ (cur.maze[0].size(), chiều dài của dòng đầu)
    // vector<vector<int>> dist( cur.maze.size(), <hàng đó> ) là cả bảng: một dãy gồm cur.maze.size() phần tử (bằng số hàng của bản đồ)
    dist[cur.p1][cur.p2] = 0; // đặt nơi người chơi mới vào bằng 0 --> đánh dấu và khởi đầu
    wait.push({ cur.p1 ,cur.p2 }); // đưa điểm bắt đầu vào hàng chờ ( cột , dòng )  
    while (!wait.empty()) {
       
        int r = wait.front().first;
        int c = wait.front().second;

        wait.pop();
        if (r == cur.e1 && c == cur.e2) { // khi r,c bằng  với E thì sẽ trả về khoảng cách ngắn nhất 
            return dist[r][c]; 
        }
       
            for (int i = 0; i < 4;i++) {
                // xét từ 0 - 3 cho nr ,nc để tinh tọa độ mới 
                int nr[4] = { -1,1,0,0 };
                int nc[4] = { 0,0,1,-1 };
                int newr = r + nr[i];
                int newc = c + nc[i];
                if (((newc < cur.maze[0].size() && newc >= 0) && (newr < cur.maze.size() && newr >= 0)) && (cur.maze[newr][newc] != '#') ) { 
                    // Xét đk nếu dòng và cột mới có quá bản ko và có phải là tường
                    portal(newr, newc, cur);
                    // Tính cả portal 

                    if (dist[newr][newc] == -1) { // Nếu như ô đó chưa đc ghé thăm 
                        dist[newr][newc] = dist[r][c] + 1; // đánh dấu ô đó đã được ghé thăm 
                        wait.push({ newr,newc });// đưa dòng và cột mới vào vòng dợi 
                    }
                        
                    


                }
            }
        





    }
    return -1; 
}
// ------------------------------------------ TÌM VỊ TRÍ XA NHẤT ĐỂ ĐẶT E --------------------------------- 
pair<int, int> farthest(int i, int j, vector<string>& maze) {
    queue < pair <int, int> > wait;
    // Lại hàm đợi lần này là lưu tọa độ E 
    vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), -1));
    dist[i][j] = 0; // Tại vị trí ban đầu, khoảng cách bằng 0  
    wait.push({ i,j });
    while (!wait.empty()) {

        int r = wait.front().first;
        int c = wait.front().second;

        wait.pop();
        for (int i = 0; i < 4;i++) {

            int nr[4] = { -1,1,0,0 };
            int nc[4] = { 0,0,1,-1 };
            int newr = r + nr[i];
            int newc = c + nc[i];
            if (((newc < maze[0].size() && newc >= 0) && (newr <maze.size() && newr >= 0)) && (maze[newr][newc] != '#')) {

                if (dist[newr][newc] == -1) {
                    dist[newr][newc] = dist[r][c] + 1;
                    wait.push({ newr,newc });
                }




            }
        }
    }
    int far = 0; 
    int besti = i;
    int bestj = j; 
    for (int a = 0; a < maze.size(); a++) {
        for (int b = 0; b < maze[0].size(); b++) {
            // xét distance theo a ,b ,
            if (dist[a][b] > far) {
                // Nếu khoảng cách cảu a,b > far thì cập nhật
                far = dist[a][b]; 
                besti = a; 
                bestj = b; 
            }
        }
    }
    return { besti, bestj };

}
// ---------------------------------------------- MAP [ RANDOM ] -----------------------------------
Level randommap(int n) {
    uniform_int_distribution<int> obr(0, (n - 3) / 2);
    // 2*k + 1 <= n - 2
    // 2 * k <= n - 3
    //  k <= (n - 3) / 2
 
    // Random cột và dòng 
    int row = obr(rng);
    int col = obr(rng);

    Level tmp{
        makeMaze(n), 1, 1, n - 2, n - 2, -1, -1, -1, -1
    };
    tmp.p1 = 2 * row + 1; // chuyển đổi sang tọa độ map 
    tmp.p2 = 2 * col + 1;

    pair<int, int> farn = farthest(tmp.p1, tmp.p2, tmp.maze); 
    // lưu tọa độ xa nhất vào biến để có thể lấy nó ra
    tmp.e1 = farn.first;
    tmp.e2 = farn.second;

    return tmp;
}
// -------------------------------------------- CƠ CHẾ CHÍNH -------------------------------------------
int playlevel(const Level& cur) {
    int p1 = cur.p1;
    int p2 = cur.p2;
    int cnt = 0;

    cout << " SPOT IN [" << cur.p1 + 1 << "]" << "[" << cur.p2 +1  << "]" << endl;
    cout << " EXIT IN [" << cur.e1 + 1 << "]" << "[" << cur.e2  + 1 << "]" << endl; 
   

    while (true) {
        cout << endl;
        cout << " Press 'q' to exit " << endl;
        cout << " Press 'h' to spot again " << endl; 

        cout << endl; 
        printB(cur, p1, p2);
        int r = moveP(p1, p2, cur);

        if (r == 0) {
            return -1;             
        }
        
        if (r == -1 || r == 2) {
            cnt++;                 
        }

        if (p1 == cur.e1 && p2 == cur.e2) {
            cout << " YOU FOUND A WAY OUT !!" << endl;
            printB(cur, p1, p2);
            cout << " STEP : " << cnt << endl;
            cout << "  " << "MIN : " << shortest(cur) << endl;
            return cnt;
        }
    }
}
// ------------------------------------------------- CLASSIC MODE --------------------------------------------
void playclassic(int& best) {
    int total = 0;
    bool quit = false;

    for (int i = 0; i < game.size(); i++) {
        int steps = playlevel(game[i]); 
        // Ta có  r = moveP(p1, p2, cur) nên khi bấm q nó se returrn 0 mà khi return 0 thì r ==0 --> return -1
        // Vì thế khi step = playlevel nó sẽ trả về -1 đk để quit = true 

        if (steps == -1) {          
            quit = true;
            break;
        }

        total += steps;
        cout << "--------------------------------------------------------------" << endl;
        cout << " TOTAL : " << total << endl;
        cout << "---------|#|----|#|-- NEXT FLOORS --|#|----|#|--------- " << endl;
    }

    if (quit == false) { // Nếu ko quit 
        cout << " COMPLETE ALL, CONGRATULATION YOU ESCAPE!!" << endl;
        checkBest(total, best);
    }
}


// -------------------------- RANDOM MODE ( ko lưu best ) -------------------------------
void playrandom() {

    int sizes[7] = { 5, 11, 15, 21, 25, 31, 33 };

    for (int i = 0; i < 7; i++) {
        Level lv = randommap(sizes[i]);
        int steps = playlevel(lv);
        if (steps == -1) {
            break;                  // người chơi thoát
        }
        cout << "---------|#|----|#|-- NEXT FLOORS --|#|----|#|--------- " << endl;
    }
    string line; 
    cout << " - hmm, seem like You are very good in escaping - " << endl;
    getline(cin,line) ; 
    cout << " - Honestly,I feel so impressed with your skill - " << endl;
    getline(cin,line) ; 
    cout << " - But you NEVER return to your home - " << endl;
    getline(cin,line) ; 
    cout << " - CUZ YOUR SOUL STILL TRYING TO ESCAPE - " << endl;
    getline(cin, line); 
    cout << " MINOTAURUS MISSED YOU     < (0M3 B4(K > " << endl; 
}
int main() { 
    int menu;
    int total = 0;
    int cnt = 0;
    const int NO_RECORD = 100000000;
    int best = output(total);

    output(total);
    while (true) {
        cout << " _________________________________________________________________________________________ " << endl;
        cout << " ===T===={|}=======M======[|]========A=========[|]=========Z=====[|]========E====[|]=====F==== " << endl;
        cout << " ========[|]==============[|]   I.  PLAY       [|]===============[|]=============[|]========== " << endl;
        cout << " ========[|]==============[|]  II.  RULE       [|]===============[|]=============[|]========== " << endl;
        cout << " ========[|]==============[|] III.  HIGHSCORE  [|]===============[|]=============[|]========== " << endl;
        cout << " ========[|]==============[|]  IV.  QUIT        [|]===============[|]=============[|]========= " << endl;
        cout << " Ready or Not " << endl;
        cin >> menu;
        cin.ignore(10000, '\n');
        if (cin.fail() || menu < 1 || menu > 4) {
            cout << "INVALID, TRY AGAIN" << endl;

            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (menu == 2) {
            cout << " ESCAPE THE MAZE, YEAH JUST EASY LIKE THAT :/ " << endl;
        }
        if (menu == 4) {
            cout << " YOU STILL STUCK IN HERE " << endl;
            break;
        }
        if (menu == 3) {
            if (best == NO_RECORD) {
                cout << " NO ONE ESCAPE !" << endl;
            }
            else {
                cout << "BESTSCORE : " << best << endl;
            }
            string yes;
            while (true) {
                cout << "RESET HIGH SCORE ( y ) " << endl;
                cout << "BACK ( n )  " << endl;
                cin >> yes;
                if (cin.fail()) {

                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "INVALID CHOICE ! " << endl;

                    continue;
                }
                if (yes.size() != 1) {
                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "INVALID CHOICE ! " << endl;
                    continue;

                }
                if (yes == "Y" || yes == "y") {
                    cout << "RESET " << endl;
                    best = 100000000;
                    input(best);
                    break;
                }
                if (yes == "n" || yes == "N") {
                    break;
                }
                else
                    continue;

            }

        }
        if (menu == 1) {
            cout << " =====================MMM================OOOO==========GAMEMODE============DDDD===================EEE================== " << endl; 
            cout << " ============================================= I. CLASSIC MODE ======================================================== " << endl;
            cout << " ============================================= II. RANDOM MODE ======================================================== " << endl;
            cout << " Choose game mode : " << endl; 
            int type;
            while (true) {
                cin >> type;
                if (cin.fail()) {
                    cout << " INVALID " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue; 
                }
                if (type < 1 || type > 2) {
                    cout << " INVALID " << endl; 
                    cin.ignore(1000, '\n');
                    continue; 
                }
                cin.ignore(1000, '\n');
                break;
            }
            switch (type) {
            case 1: {
                playclassic(best); 


                break; 
            }
            case 2 :
                cout << " %$@!*&#^*#*@(E@&*#&@/@$<_  WELCOME TO RANDOM MODE  _>(#*#^*&#&*@()!*@($*@^^$&#/*/##$*( " << endl; 
                playrandom(); 
                break;

            }



        }




    }

}









  
