#include"define.h"
//#include"table.h"

void remove_scrollbar()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), new_size);
	//system("color F0");
	string title = ("       QUAN LY DIEM SINH VIEN THEO TIN CHI - SV: LE VAN LUONG & PHAM VAN THANH");
	SetConsoleTitle(title.c_str());
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int getX()//lay toa do x hien tai cua con tro console.
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int getY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void Color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int GetKey()//bat phim
{
	char key;
	key = _getch();
	if (key == -32 || key == 0)
		return -_getch();
	else return key;
}
/*=====================================================*/
/*=================       KHUNG      ==================*/
/*=====================================================*/
void kekhung(){
	Color(7);
	for(int yi=0;yi<30;yi++){
		gotoxy(30,yi);
		cout<< char(khungdoc);
	}
	for(int xi=0;xi<30;xi++){
		gotoxy(xi,18);
		cout << char(khungngang);
	}
	for(int xi=31;xi<120;xi++){
		gotoxy(xi,27);
		cout << char(khungngang);
	}
}


void boxmenu(int x,int y, int w,int h,int c_text,int c_bg,char text[]){
	Color(c_bg);
	for(int iy=y;iy<=y+h;iy++){
			gotoxy(x,iy);cout<<"                           ";
	}
		
	for(int ix=x;ix<=x+w;ix++){
		gotoxy(ix,y);
		cout<< char(196);
		gotoxy(ix,y+h);
		cout<< char(196);
	}
		for(int iy=y;iy<=y+h;iy++){
		gotoxy(x,iy);
		cout<< char(179);
		gotoxy(x+w,iy);
		cout<< char(179);
	}
	gotoxy(x,y);cout << char(218);
	gotoxy(x+w,y);cout <<char(191);
	gotoxy(x,y+h);cout << char(192);
	gotoxy(x+w,y+h);cout <<char(217);
	Color(c_text);
	gotoxy(x+8,y+1);cout  << text;
	gotoxy(x,y);
}
void khungNhapLTC(){
	Color(228);
	gotoxy(60,0); cout <<"NHAP LOP TIN CHI";
	gotoxy(35, 2); cout << "    MA LOP     MA MON HOC      NIEN KHOA    HOC KI    NHOM    SVMAX    SVMIN     ";
	gotoxy(35, 3); cout << "                                                                                 ";
	gotoxy(35, 4); cout << "                                                                                 ";
	Color(12);
	gotoxy(37, 3); cout << "         ";
	gotoxy(49, 3); cout << "            ";
	gotoxy(67, 3); cout << "       ";
	gotoxy(80,3);cout <<"    ";
	gotoxy(89,3);cout<<"     ";
	gotoxy(97, 3); cout << "     ";
	gotoxy(106,3);cout <<"     ";
}

//

void Khung_Them_MonHoc() {
	Color(228);
	gotoxy(35, 2); cout << "     MA MON HOC                    TEN MON HOC          STCLT   STCTH ";
	gotoxy(35, 3); cout << "                                                                      ";
	gotoxy(35, 4); cout << "                                                                      ";
	Color(228);	gotoxy(73, 4); cout << "Enter:";
	gotoxy(95, 4); cout << "ESC:";
	Color(225);	gotoxy(80, 4); cout << "OK";
	gotoxy(100, 4); cout << "Exit";
	Color(12);
	gotoxy(37, 3); cout << "                ";
	gotoxy(55, 3); cout << "                                   ";
	gotoxy(92, 3); cout << "   ";
	gotoxy(100, 3); cout << "   ";
	//Color(228);
	//gotoxy(52,18); cout << " STCLT     : So tin chi li thuyet ";
	//gotoxy(52,20); cout << " STCTH     : So tin chi thuc hanh ";
}
void khunginMH(){
	for(int iy=6;iy<26;iy++){
		gotoxy(35,iy);
		cout<<"|      |            |                                        |       |       |";
	}
		gotoxy(35,7);
		cout<<"______________________________________________________________________________";
		Color(7);
			gotoxy(36,6);cout<<" STT";
			gotoxy(44,6);cout<<"MA MON";
			gotoxy(65,6);cout<<"TEN MON HOC";
			gotoxy(98,6);cout<<"STCLT";
			gotoxy(106,6);cout<<"STCTH";
}
void Khung_Sua_MonHoc() {
	Color(228);
	gotoxy(40, 2); cout << "                                 ";
	gotoxy(40, 3); cout << "                                 ";
	gotoxy(40, 4); cout << "                                 ";
	gotoxy(43, 2); cout << "Nhap Ma Mon Hoc Can Sua";
	Color(228); gotoxy(43, 4); cout << "Enter:";
	gotoxy(61, 4); cout << "ESC:";
	Color(225); gotoxy(50, 4); cout << "OK";
	gotoxy(66, 4); cout << "Exit";
	Color(4);
	gotoxy(43, 3); cout << "                           ";
}
void Khung_Xoa_MonHoc() {
	Color(228);
	gotoxy(40, 2); cout << "                                 ";
	gotoxy(40, 3); cout << "                                 ";
	gotoxy(40, 4); cout << "                                 ";
	gotoxy(43, 2); cout << "Nhap Ma Mon Hoc Can Xoa";
	Color(228); gotoxy(43, 4); cout << "Enter:";
	gotoxy(61, 4); cout << "ESC:";
	Color(225); gotoxy(50, 4); cout << "OK";
	gotoxy(66, 4); cout << "Exit";
	Color(14);	gotoxy(43, 3); cout << "                           ";
}
void khunginLTC(){
	Color(2);
	for(int iy=6;iy<26;iy++){
		gotoxy(35,iy);
		cout<<"|     |           |            |           |       |      |         |         |";
	}     //      5      12            12    
		gotoxy(35,7);
		cout<<"_______________________________________________________________________________";
		Color(7);
			gotoxy(36,6);cout<<" STT";
			gotoxy(44,6);cout<<"MA LTC";
			gotoxy(57,6);cout <<"MA MON";
			gotoxy(68,6);cout<<"NIEN KHOA";
			gotoxy(80,6);cout<<"HOC KI";
			gotoxy(88,6);cout<<"NHOM";
			gotoxy(94,6);cout<<"SO SV MAX";
			gotoxy(104,6);cout <<"SO SV MIN";
}
void KhungInSV_LTC(){
		Color(2);
	for(int iy=6;iy<26;iy++){
		gotoxy(35,iy);
		cout<<"|     |          |            |                       |         |        |    |";
	}     //      5      12            12    
		gotoxy(35,7);
		cout<<"_______________________________________________________________________________";
		Color(7);
			gotoxy(36,6);cout<<" STT";
			gotoxy(44,6);cout<<"MA LTC";
			gotoxy(56,6);cout <<"MA MON";
			gotoxy(70,6);cout<<"TEN MON";
			gotoxy(90,6);cout<<"NIEN KHOA";
			gotoxy(101,6);cout<<"HOC KI";
			gotoxy(109,6);cout<<"NHOM";
}
KhungThemLop(){
		Color(228);
	gotoxy(35, 2); cout << "     MA LOP                   TEN LOP HOC                   NIEN KHOA ";
	gotoxy(35, 3); cout << "                                                                      ";
	gotoxy(35, 4); cout << "                                                                      ";
	Color(228);	gotoxy(80, 4); cout << "Enter:";
	gotoxy(95, 4); cout << "ESC:";
	Color(225);	gotoxy(87, 4); cout << "OK";
	gotoxy(100, 4); cout << "Exit";
	Color(12);
	gotoxy(37, 3); cout << "                ";
	gotoxy(55, 3); cout << "                                       ";
	
	gotoxy(97, 3); cout << "     ";
}
void KhungInLop(){
	Color(7); 
	for(int iy=6;iy<26;iy++){
		gotoxy(35,iy);
		cout<<"|      |                 |                                        |          |";
	}
		gotoxy(35,7);
		cout<<"______________________________________________________________________________";
		Color(7);
			gotoxy(36,6);cout<<" STT";
			gotoxy(49,6);cout<<"MA LOP";
			gotoxy(75,6);cout<<"TEN LOP";
			gotoxy(102,6);cout<<"NIEN KHOA";
}
void KhungThemSV(){
	Color(228);
	gotoxy(35, 2); cout << "     MA LOP         MA SINH VIEN       HO       TEN             PHAI    SO DT    ";
	gotoxy(35, 3); cout << "                                                                                 ";
	gotoxy(35, 4); cout << "                                                                                 ";
	Color(228);	gotoxy(80, 4); cout << "Enter:";  
	gotoxy(95, 4); cout << "ESC:";
	Color(225);	gotoxy(87, 4); cout << "OK";
	gotoxy(100, 4); cout << "Exit";
		Color(12);
	gotoxy(37, 3); cout << "               ";
	gotoxy(54, 3); cout << "              ";
	gotoxy(69, 3); cout << "         ";
	gotoxy(80, 3); cout << "                ";
	gotoxy(98, 3); cout << "     ";
	gotoxy(105, 3); cout << "          ";
}
void KhungInSV(){
	Color(7);
	for(int iy=6;iy<26;iy++){
		gotoxy(35,iy);
		cout<<"|     |             |            |                        |      |            |";
	}     //      5      12            12    
		gotoxy(35,7);
		cout<<"_______________________________________________________________________________";
		Color(7);
			gotoxy(36,6);cout<<" STT";
			gotoxy(44,6);cout<<"MA SV";
			gotoxy(57,6);cout <<"HO";
			gotoxy(77,6);cout<<"TEN";
			gotoxy(95,6);cout<<"PHAI";
			gotoxy(105,6);cout<<"SDT";
}
void KhungDkLTC(){
	Color(228);
	gotoxy(40, 2); cout << "                                   ";
	gotoxy(40, 3); cout << "                                   ";
	gotoxy(40, 4); cout << "                                   ";
	gotoxy(43, 2); cout << "         Nhap Ma Sinh Vien ";
	Color(4);
	gotoxy(43, 3); cout << "                     ";
}
void KhungDk_NKHK(){
	Color(228);
	gotoxy(40, 2); cout << "                                      ";
	gotoxy(40, 3); cout << "                                      ";
	gotoxy(40, 4); cout << "                                      ";
	gotoxy(43, 2); cout << "Nhap Nien Khoa";
	gotoxy(60, 2);cout <<"Nhap Hoc Ki";
	Color(225); gotoxy(50, 4); cout << "OK";
	gotoxy(66, 4); cout << "Exit";
	Color(4);
	gotoxy(43, 3); cout << "          ";
	gotoxy(62,3); cout << "     ";
}
void KhungInDK(){
	Color(7);
		for(int iy=6;iy<26;iy++){
		gotoxy(35,iy);
		cout<<"|       |                 |                               |       |          |";
	}
		gotoxy(35,7);
		cout<<"______________________________________________________________________________";
		Color(7);
			gotoxy(36,6);cout<<" MA LTC";
			gotoxy(49,6);cout<<"MA MON";
			gotoxy(75,6);cout<<"TEN MON";
			gotoxy(95,6);cout<<"SV DK";
			gotoxy(102,6);cout<<"Slot Trong";
}
/*=====================================================*/
void KhungNhapDiem(){
		Color(7); 
	for(int iy=6;iy<26;iy++){
		gotoxy(35,iy);
		cout<<"|      |                 |             |                          |          |";
	}
		gotoxy(35,7);
		cout<<"______________________________________________________________________________";
		Color(7);
			gotoxy(36,6);cout<<" STT";
			gotoxy(49,6);cout<<"MA SV";
			gotoxy(65,6);cout<<"HO";
			gotoxy(88,6);cout<<"TEN";
			gotoxy(105,6);cout<<"DIEM";
}
void KhungTongKet(){
		Color(7); 
	for(int iy=6;iy<26;iy++){
		gotoxy(35,iy);
		cout<<"|      |            |         |                   |        |        |        |";
	}
		gotoxy(35,7);
		cout<<"______________________________________________________________________________";
		Color(7);
			gotoxy(36,6);cout<<" STT";
			gotoxy(47,6);cout<<"MA SV";
			gotoxy(59,6);cout<<"HO";
			gotoxy(73,6);cout<<"TEN";
}
/*=====================================================*/
void xoaghichu(){
	Color(7);
	gotoxy(31,28);
	cout<<"                                                                                    ";
	gotoxy(31,29);
	cout<<"                                                                                    ";
}
void xoamenu(){
	for(int iy=0;iy<18;iy++){
			gotoxy(0,iy);
			cout<<"                             ";
		}
}
void xoascreen(){
	Color(7);
		for(int iy=0;iy<27;iy++){
			gotoxy(31,iy);
			cout<<"                                                                                         ";
		}
}
void xoanhacnho(){
	Color(7);
	for(int i = 19;i<30;i++){
		gotoxy(0,i);
		cout <<"                              ";
	}
}
/*=====================================================*/
void nhacnhomenu(){
	xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout<<"ENTER:  NHAN CHON";
	gotoxy(2,24);
	cout	<<"ESC:   THOAT";
}
void nhacnhonhapLTC(){
	xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout <<"<: QUA TRAI    >:   QUA PHAI";
	gotoxy(2,24);
	cout<<"F1:    BANG TRA CUU";
	gotoxy(2,26);
	cout<<"ENTER:  NHAN CHON";
	gotoxy(2,28);
	cout	<<"ESC:   THOAT";
}
void nhacnhoxsLTC(){
	xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout <<"<: QUA TRAI    >:   QUA PHAI";
	gotoxy(2,24);
	cout<<"F2:    SUA LOP TIN CHI";
	gotoxy(2,26);
	cout<<"F3:    XOA LOP TIN CHI";
	gotoxy(2,28);
	cout	<<"ENTER: CHON    ESC:  THOAT";
}
void nhacnhoLopSV(){
		xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout <<"<: QUA TRAI    >:   QUA PHAI";
	gotoxy(2,24);
	cout<<"F2:    SUA SINH VIEN";
	gotoxy(2,26);
	cout<<"F3:    XOA SINH VIEN";
	gotoxy(2,28);
	cout	<<"ENTER: CHON    ESC:  THOAT";
}
void nhacnhoTimSV(){
	xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout <<"<: QUA TRAI   >:  QUA PHAI";
	gotoxy(2,24);
	cout<<"ENTER:  NHAN CHON";
	gotoxy(2,26);
	cout	<<"ESC:   THOAT";
	gotoxy(2,28);
	Color(3);
	cout << "*Color: Da Huy Dang Ki ";
}
void nhacnhoAutoXoaLTC(){
		xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout <<"<: QUA TRAI   >:  QUA PHAI";
		gotoxy(2,24);
	cout<<"F3:    AUTO XOA LTC";
	gotoxy(2,26);
	cout<<"ESC:   THOAT";
	gotoxy(2,28);
	Color(3);
	cout	<<"*Color: Du Dieu Kien De Xoa ";
}
void nhacnhoLop(){
		xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout <<"<: QUA TRAI   >:  QUA PHAI";
	gotoxy(2,24);
	cout<<"ENTER:  NHAN CHON";
	gotoxy(2,26);
	cout	<<"ESC:   THOAT";
	gotoxy(2,28);
	cout << "F1: Them Lop   F3: Xoa Lop ";
}
void nhacnhosv(){
	xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout <<"<: QUA TRAI   >:  QUA PHAI";
	gotoxy(2,24);
	cout<<"ENTER:  NHAN CHON";
	gotoxy(2,26);
	cout	<<"ESC:   THOAT";
}
void nhacnhomh(){
	xoanhacnho();
	Color(7);
	gotoxy(2,20);
	cout <<"^:   UP     v:    DOWM";
	gotoxy(2,22);
	cout <<"<: QUA TRAI    >:   QUA PHAI";
	gotoxy(2,24);
	cout<<"F1:    THEM MON HOC";
	gotoxy(2,26);
	cout<<"F2:    SUA MON HOC";
	gotoxy(2,28);
	cout	<<"F3:    XOA MON HOC";
}
/*=====================================================*/
void GhiChu(char c[], int x, int y, int color, int sleep){

	gotoxy(x, y);
	cout << c;
	Sleep(sleep);
	gotoxy(x, y);
	Color(color);
	xoaghichu();

}
void HienThiTrang(int trang, int tongtrang, int x, int y) {
	Color(174);	gotoxy(x, y); cout << " Trang:        ";
	gotoxy(x + 8, y); cout << trang << "/" << tongtrang;
	Color(14);
}
/*=====================================================*/
/*================= CHAR MENU   ==================*/
/*=====================================================*/
char mainMENU[4][25]={//index 0
	"LOP TIN CHI",
	"SINH VIEN/LOP",
	"MON HOC",
	"DIEM",
};
void updown(char key,char menu[][25],int &iy,int &i_text){
	if(key == UP){
		if(iy==yMenu1){
	   			boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubg,menu[i_text]);
	   			iy = iy+3*distance;
	   			i_text += 3;
	   			gotoxy(xMenu,iy);
	   			boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
			   }
			   else{
			   	boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubg,menu[i_text]);
			   	iy -= distance;
			   	i_text--;
			   	gotoxy(xMenu,iy);
			   	boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
			   }
	}
	else{
		if(iy==yMenu1+3*distance){
				boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubg,menu[i_text]);
				iy = yMenu1;
	   			i_text = 0;
	   			gotoxy(xMenu,iy);
	   			boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
				   }
	   		 	else{
	   		 		boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubg,menu[i_text]);
	   				iy += distance;
			   		i_text++;
			   		gotoxy(xMenu,iy);
			   		boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
				   }
	}
}
void menuchinh(char menu[][25]){

	int text=0;
	for(int yi=yMenu1;yi<15;yi+=distance){
		boxmenu(xMenu,yi ,wMenu,hMenu,mauchu,maubg,menu[text]);
		text++;
	}
	gotoxy(xMenu,yMenu1);
}
void menumh(char menu[][25]){

	int text=0;
	for(int yi=yMenu1;yi<11;yi+=distance){
		boxmenu(xMenu,yi ,wMenu,hMenu,mauchu,maubg,menu[text]);
		text++;
	}
	gotoxy(xMenu,yMenu1);
}







