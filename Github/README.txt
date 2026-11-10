README 

# Libary books  

 - Đây là một chương trình lưu và quản lí thông tin của sách ( Books )  cũng như là của khách hàng ( Customer ) và lưu các thông tin vào một file .txt 

# Tính năng 

 - Trinh quản lí sách này giúp khách hang mượn và trả sách cũng như lưu trữ thông tin trạng thái của sách 

 - Tuy nhiên, hiện tại các chức năng của chương trình chỉ ở mức cơ bản như : 
   
   + Ghi thông tin của sách ( Code Books , Name , Author , isBorow ) 
   + Ghi thông tin khách hang ( Id , Name , Phone Number ) 

   + Cho phép mượn, trả sách và cập nhật tình trạng của sách 
   + Cho phép xóa thông tin sách và khách hang ( nếu khách hang vẫn đang mượn hoặc sách còn đang mượn ) 
   + Tìm thông tin ( Code , Id , Name , Phone Number , Author ) của cả sách và người dùng 
   + Có thể truy cập vào khách hang đang mượn những cuốn sách nào và tạo giới hạn mượn sách 

# Cách hoạt động 

+ Khi bắt đầu, người dùng sẽ được chọn quản lí Sách ( Books ) hay Khách hàng ( Customer ) và Thoát ( Exit )

+ Nếu chọn sách ( Books ), người dùng sẽ được phép 
   . AddBook : Thêm thông tin Sách ( sẽ không thành công nếu Code bị trùng với sách khác ) 
   . ShowAll : thấy tất cả thông tin sách đã thêm vào 
   . FindBook : có thể tìm theo code , name , author của Books ( cả chữ thường cũng được chap nhận ) 
   . Borow Books : Cho mượn Books theo Code, yêu cầu Id khách  
   . Return Books : Trả sách theo Code 
   . Delete : Xóa thông tin Sách ( trừ các Sách đang mượn )
   . Exit

+ Nếu chọn Khách hang ( Customer ), người dung được phép : 
   . AddCustom : Thêm thông tin Khách ( sẽ không thành công nếu Id bị trùng với khách khác ) 
   . ShowAll : thấy tất cả thông tin Khách đã thêm vào 
   . FindBook : có thể tìm theo Id , name , Phone Number của Customer ( cả chữ thường cũng được chap nhận ) 
   . Delete : Xóa thông tin Khách ( trừ các Khách đang mượn )
   . Exit

# Kiến thức  
* Struct :
  - Private :  Lưu trữ các class của struct vào trong
  - Public : gán gtri + sửa đổi + tạo điều kiện để tránh làm sai lệch

  - name shadowing : Quy tắc chung là khi có nhiều biến cùng tên ở các cấp khác nhau, biến ở cấp trong cùng (gần chỗ dùng nhất) sẽ được chọn. Ở đây nó xuất hiện lại trong ngữ cảnh class: tham số của hàm (cấp trong) che thuộc tính của class (cấp ngoài).


* OOP : Tính đóng gói
  - hàm class có private nhầm ngăn chặn các hàm ngoài như main ... thay đổi là sai gtri mà ko qua các đk. Các hàm private và public quy định hàm nào truy cập được với các gtri trong private bang cách viết hàm đó tại public
  - Hàm thành viên : : là hàm viết bên trong class, thuộc về từng đối tượng. Vì thuộc về đối tượng nên nó tự biết mình đang làm việc với đối tượng nào .

getCode : là một hàm getter dung để đưa gtri trong private ra bên ngoài
      + Cấu trúc :
         . Kiểu trả về : trùng với kiểu thuộc tính
         . Tên hàm : get + " tên thuộc tính "
         . Vd : int getInk () { return ink ;} và cách dung : cout << p.getInk() ;
