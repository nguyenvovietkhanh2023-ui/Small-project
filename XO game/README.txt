README 

# XO game 

 - Game XO (Tic-Tac-Toe) trên bàn cờ 3x3, viết bằng C++ và chạy trên console.

# Tính năng 

  + Bàn cờ XO 3x3, sau khi thắng sẽ đổi lượt đi ( X hoặc O ) 
  + Khi kết thúc ván cờ có lựa chọn rematch 
  + Kiểm tra thắng, bên ngoài bản đồ , ô đã đánh dấu và hòa 
  + Các chế độ của trò chơi được goi là " AI " bao gồm các chức năng : 
    . Nhận biết ô có thể thắng 
    . Nhận biết ô để chặn người chơi 
    . Ưu tiên chiếm ô giữa, sau đó là ô góc 
    . Nhận biết các trường hợp Fork và các ô góc đối diện với ô mà player đánh
    . Nếu không có tìm được các ô như trên thì sẽ chọn ô trống 
  + Lưu được số điểm bestscore với từng chế độ chơi 
  + Phần UI game thiết kế trong terminal để dễ dàng theo dõi  

## Cách chạy

Cần cài sẵn trình biên dịch g++. Mở terminal tại thư mục chứa file rồi chạy  
   g++ XO_game.cpp -o xo_game
   ./xo_game

# Cách chơi 

 + Bắt đầu với MENU game nơi player có thể lựa chọn : | Play | Rule | Highscore | Quit | 
   ( thông qua các con số và báo lỗi nếu không nhập đúng yêu cầu ) 
 + Khi play, player có quyền lựa chọn độ khó ( chế độ chơi ) với các mức : | Easy | Medium | Hard | Hell | 
   ( thông qua các con số và báo lỗi nếu không nhập đúng yêu cầu )
 + Bảng trò chơi được chia ra làm 9 ô với các lượt đi giữa player và Ai sẽ được thông báo ở dưới bảng chơi 
    . Bạn sẽ nhập số 1 - 9 để đánh  X / O vào trong bàn cờ và lượt tiếp sẽ đến lượt Ai đánh 
    . Khi cả bàn cờ không còn ô trống, lúc đó sẽ kiểm trả Win và Tie 
 + Sau khi ván đấu kết thúc, player có thể lựa chọn rematch với AI đánh đầu tiên và bản điểm của ván trước và lưu lại trong hệ thống

# Kiến thức : 
- Biết được cách sử dụng ma trận để tạo ra bản đồ 
- Sử dụng file bên ngoài để lưu số điểm 
- Cách hoạt động thuật toán của Ai trong việc thử nước đi 
- Học thuật toán hoán đổi lượt X / O của player và Ai 

