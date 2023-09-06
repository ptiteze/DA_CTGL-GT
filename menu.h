#include"console.h"
#include"khaibao.h"

/*=====================================================*/
/*=================    LOP TIN CHI  =======================*/
/*=====================================================*/
void ThemLTC(DSloptc& DSLTC,PTRMH DSMH){
	xoascreen(); 
	int key;
	int STT = 1;
	int vitri = 0, x = 39, y = 3 , svIndexmax,svIndexmin;
	int check_trung;
	int pochinki;
	loptc lopTc;
	lopTc.maLoptc = 0; lopTc.mmh[0] = NULL; lopTc.nienkhoa[0] = NULL; lopTc.hocki[0] = NULL; lopTc.nhom[0] = NULL; lopTc.svMax[0] = NULL;
	lopTc.svMin[0]=NULL;
	nhacnhonhapLTC();
	khungNhapLTC();
	Color(12);
	gotoxy(x, y);
MALOPTC:
		lopTc.maLoptc=DSLTC.ds[DSLTC.soluong-1]->maLoptc+1;
		Color(14);
		gotoxy(x,y);
		cout << lopTc.maLoptc;
MAMH:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so & chu: (A-Z) && (0-9). Toi da 10 ki tu!";
		Color(14);
		gotoxy(49 + vitri, y);
		key = GetKey();
		if (lopTc.maLoptc == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap ma lop", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(x, y);
			goto MALOPTC;
		}
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			lopTc.mmh[vitri] = char(key);
			lopTc.mmh[vitri] = toupper(lopTc.mmh[vitri]);
			cout << lopTc.mmh[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.mmh[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc.mmh);
			if (temp == 1) {
				vitri = strlen(lopTc.nienkhoa);
				gotoxy(67 + vitri, y);
				goto NIENKHOA;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 60, 28, 79, 700);
				gotoxy(49 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(49 + vitri, y);
			cout << " ";
			gotoxy(49 + vitri, y);
		}
		if (key == RIGHT)
		{
			lopTc.mmh[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc.mmh);
			if (temp == 1) {
				vitri = strlen(lopTc.nienkhoa);
				gotoxy(67 + vitri, y);
				goto NIENKHOA;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 60, 28, 79, 700);
				gotoxy(49 + vitri, y);
				continue;
			}
		}
		if(key==F1){
			XemMonHoc(DSLTC,DSMH,3);
		}
		if (key == ESC )
		{
			chaymenultc();
		}
	}
NIENKHOA:
	while (1){
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so: (0-9). Toi da 4 ki tu!";
		Color(14);
		gotoxy(67 + vitri, y);
		key = GetKey();
		if (lopTc.mmh[0] == '\0')		//kiemtra du lieu field truoc
		{
			GhiChu("Ban chua nhap ma mon hoc", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(49, y);
			goto MAMH;
		}
		if ((key <= '9' && key >= '0') && (vitri < 4))
		{
			lopTc.nienkhoa[vitri] = char(key);
			cout << lopTc.nienkhoa[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.nienkhoa[vitri] = '\0';
			if (strcmp(lopTc.nienkhoa, "2017") == 1)
			{
				vitri = strlen(lopTc.hocki);
				gotoxy(80 + vitri, y);
				goto HOCKI;
			}
			else {
				GhiChu("              NAM KHONG HOP LE               ", 60, 28, 79, 700);
				gotoxy(67 + vitri, y);
				continue;
			}

		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(67 + vitri, y);
			cout << " ";
			gotoxy(67 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.nienkhoa[vitri] = '\0';
			vitri = strlen(lopTc.mmh);
			gotoxy(49 + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT)
		{
			lopTc.nienkhoa[vitri] = '\0';
			if (strcmp(lopTc.nienkhoa, "2017") > 0)
			{
				vitri = strlen(lopTc.hocki);
				gotoxy(80 + vitri, y);
				goto HOCKI;
			}
			else {
				GhiChu("              NAM KHONG HOP LE               ", 60, 28, 79, 700);
				gotoxy(67 + vitri, y);
				continue;
			}
		}
		if (key == ESC || key == F1)
		{
			chaymenultc();
		}
	}
HOCKI:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so: (0-9). Toi da 1 ki tu!";
		Color(14);
		gotoxy(80 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.nienkhoa[0] == '\0')
		{
			GhiChu("Ban chua nhap nien khoa", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(67, y);
			goto NIENKHOA;
		}
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			lopTc.hocki[vitri] = char(key);
			cout << lopTc.hocki[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.hocki[vitri] = '\0';
			vitri = strlen(lopTc.nhom);
			gotoxy(89 + vitri, y);
			goto NHOM;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(80 + vitri, y);
			cout << " ";
			gotoxy(80 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.hocki[vitri] = '\0';
			vitri = strlen(lopTc.nienkhoa);
			gotoxy(67 + vitri, y);
			goto NIENKHOA;
		}
		if (key == RIGHT)
		{
			lopTc.hocki[vitri] = '\0';
			vitri = strlen(lopTc.nhom);
			gotoxy(89 + vitri, y);
			goto NHOM;
		}
		if (key == ESC || key == F1)
		{
			chaymenultc();
		}
	}
NHOM:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so : (0-9). Toi da 1 ki tu!";
		Color(14);
		gotoxy(89 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.hocki[0] == '\0')		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap hoc ki", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(80, y);
			goto HOCKI;
		}
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			lopTc.nhom[vitri] = char(key);
			cout << lopTc.nhom[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.nhom[vitri] = '\0';
			pochinki = KiemtraBo4_v2(DSLTC, lopTc);
			if (-1 == pochinki) {
				vitri = strlen(lopTc.svMax);
				gotoxy(97 + vitri, y);
				goto SOLUONGMAX;
			}
			if (-2 == pochinki) {
				GhiChu("Thong tin 4 field Ma mon hoc, Nien Khoa, Hoc ki, Nhom khong duoc trung", 35, 28, 79, 2000);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(89 + vitri, y);
			cout << " ";
			gotoxy(89 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.nhom[vitri] = '\0';
			vitri = strlen(lopTc.hocki);
			gotoxy(80 + vitri, y);
			goto HOCKI;
		}
		if (key == RIGHT)
		{
			lopTc.nhom[vitri] = '\0';
			vitri = strlen(lopTc.svMax);
			gotoxy(97 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == ESC || key == F1)
		{
			chaymenultc();
		}
	}
SOLUONGMAX:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so : (0-9). Toi da 500 sinh vien!";
		Color(14);
		gotoxy(97 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.nhom[0] == '\0')		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap nhom", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(89, y);
			goto NHOM;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			lopTc.svMax[vitri] = char(key);
			cout << lopTc.svMax[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{	
			lopTc.svMax[vitri]='\0';
			svIndexmax = atoi(lopTc.svMax);
			if(svIndexmax<501&&svIndexmax>9){
			vitri=strlen(lopTc.svMin);
			gotoxy(106+vitri,y);
			goto SOLUONGMIN;
			}else{
				GhiChu("so luong sinh vien max sai yeu cau!",60,28,79,500);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(97 + vitri, y);
			cout << " ";
			gotoxy(97 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.svMax[vitri] = '\0';
			vitri = strlen(lopTc.nhom);
			gotoxy(89 + vitri, y);
			goto NHOM;
		}
			if (key == RIGHT)
		{	
			svIndexmax = atoi(lopTc.svMax);
			if(svIndexmax<501&&svIndexmax>9){
			lopTc.svMax[vitri]='\0';
			vitri=strlen(lopTc.svMin);
			gotoxy(106+vitri,y);
			goto SOLUONGMIN;
			}else{
				GhiChu("so luong sinh vien max sai yeu cau!",60,28,79,500);
				continue;
			}
		}
		if (key == ESC || key == F1)
		{
			chaymenultc();
		}
	}
SOLUONGMIN:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so : (0-9). Toi thieu 10 sinh vien!";
		Color(14);
		gotoxy(106 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.svMax[0] == '\0')		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap so luong sinh vien max", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(97, y);
			goto SOLUONGMAX;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			lopTc.svMin[vitri] = char(key);
			cout << lopTc.svMin[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{	
			lopTc.svMin[vitri] = '\0';
			svIndexmax = atoi(lopTc.svMax);
			svIndexmin = atoi(lopTc.svMin);
			if(svIndexmin>9&&svIndexmin<=svIndexmax){
			InsertLTC(DSLTC, lopTc, DSLTC.soluong);
			GhiFileDSLTC(DSLTC);
			GhiChu("Da luu vao bo nho", 60, 28, 228, 500);
			ThemLTC(DSLTC,DSMH);
			}
			else{
				GhiChu("so luong sinh vien min sai yeu cau!",60,28,79,500);
				continue;
			}
			
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(106 + vitri, y);
			cout << " ";
			gotoxy(106 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.svMin[vitri] = '\0';
			vitri = strlen(lopTc.svMax);
			gotoxy(97 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == ESC || key == F1)
		{
			chaymenultc();
		}
	}
}
void SuaLTC(DSloptc& DSLTC,PTRMH DSMH, int vitri_LTC){
	int key;
	int x = 43, y = 3;
	int vitri = 0;
	int check_trung;
	int pochinki,svIndexmax,svIndexmin;
	loptc lopTc;
				vitri =0 ;
				khungNhapLTC();
				lopTc.maLoptc=DSLTC.ds[vitri_LTC]->maLoptc;
				strcpy(lopTc.mmh,DSLTC.ds[vitri_LTC]->mmh);
				strcpy(lopTc.nienkhoa,DSLTC.ds[vitri_LTC]->nienkhoa);
				strcpy(lopTc.hocki,DSLTC.ds[vitri_LTC]->hocki);
				strcpy(lopTc.nhom,DSLTC.ds[vitri_LTC]->nhom);
				strcpy(lopTc.svMax,DSLTC.ds[vitri_LTC]->svMax);
				strcpy(lopTc.svMin,DSLTC.ds[vitri_LTC]->svMin);
				gotoxy(39,y);cout << lopTc.maLoptc;
				gotoxy(49,y);cout << lopTc.mmh;
				gotoxy(67,y);cout << lopTc.nienkhoa;
				gotoxy(80,y);cout << lopTc.hocki;
				gotoxy(89,y);cout << lopTc.nhom;
				gotoxy(97,y);cout << lopTc.svMax;
				gotoxy(106,y);cout << lopTc.svMin;
				vitri=strlen(lopTc.mmh);
				goto MAMH;
 MAMH:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so & chu: (A-Z) && (0-9). Toi da 10 ki tu!";
		Color(12);
		gotoxy(49 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			lopTc.mmh[vitri] = char(key);
			lopTc.mmh[vitri] = toupper(lopTc.mmh[vitri]);
			cout << lopTc.mmh[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.mmh[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc.mmh);
			if (temp == 1) {
				vitri = strlen(lopTc.nienkhoa);
				gotoxy(67 + vitri, y);
				goto NIENKHOA;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 60, 28, 79, 700);
				gotoxy(49 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(49 + vitri, y);
			cout << " ";
			gotoxy(49 + vitri, y);
		}
		if (key == RIGHT)
		{
			lopTc.mmh[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc.mmh);
			if (temp == 1) {
				vitri = strlen(lopTc.nienkhoa);
				gotoxy(67 + vitri, y);
				goto NIENKHOA;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 60, 28, 79, 700);
				gotoxy(49 + vitri, y);
				continue;
			}
		}
		if (key == ESC )
		{
			xoascreen();
			XemLTC(DSLTC,DSMH,2);
		}
	}
NIENKHOA:
	while (1){
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so: (0-9). Toi da 4 ki tu!";
		Color(12);
		gotoxy(67 + vitri, y);
		key = GetKey();
		if (lopTc.mmh[0] == '\0')		//kiemtra du lieu field truoc
		{
			GhiChu("Ban chua nhap ma mon hoc", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(49, y); 
			goto MAMH;
		}
		if ((key <= '9' && key >= '0') && (vitri < 4))
		{
			lopTc.nienkhoa[vitri] = char(key);
			lopTc.nienkhoa[vitri] = toupper(lopTc.nienkhoa[vitri]);
			cout << lopTc.nienkhoa[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.nienkhoa[vitri] = '\0';
			if (strcmp(lopTc.nienkhoa, "2017") == 1)
			{
				vitri = strlen(lopTc.hocki);
				gotoxy(80 + vitri, y);
				goto HOCKI;
			}
			else {
				GhiChu("              NAM KHONG HOP LE               ", 60, 28, 79, 700);
				gotoxy(67 + vitri, y);
				continue;
			}

		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(67 + vitri, y);
			cout << " ";
			gotoxy(67 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.nienkhoa[vitri] = '\0';
			vitri = strlen(lopTc.mmh);
			gotoxy(49 + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT)
		{
			lopTc.nienkhoa[vitri] = '\0';
			if (strcmp(lopTc.nienkhoa, "2017") > 0)
			{
				vitri = strlen(lopTc.hocki);
				gotoxy(80 + vitri, y);
				goto HOCKI;
			}
			else {
				GhiChu("              NAM KHONG HOP LE               ", 60, 28, 79, 700);
				gotoxy(67 + vitri, y);
				continue;
			}
		}
		if (key == ESC || key == F2)
		{
			xoascreen();
			XemLTC(DSLTC,DSMH,2);
		}
	}
HOCKI:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so: (0-9). Toi da 1 ki tu!";
		Color(12);
		gotoxy(80 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.nienkhoa[0] == '\0')
		{
			GhiChu("Ban chua nhap nien khoa", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(67, y);
			goto NIENKHOA;
		}
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			lopTc.hocki[vitri] = char(key);
			lopTc.hocki[vitri] = toupper(lopTc.hocki[vitri]);
			cout << lopTc.hocki[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.hocki[vitri] = '\0';
			vitri = strlen(lopTc.nhom);
			gotoxy(89 + vitri, y);
			goto NHOM;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(80 + vitri, y);
			cout << " ";
			gotoxy(80 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.hocki[vitri] = '\0';
			vitri = strlen(lopTc.nienkhoa);
			gotoxy(67 + vitri, y);
			goto NIENKHOA;
		}
		if (key == RIGHT)
		{
			lopTc.hocki[vitri] = '\0';
			vitri = strlen(lopTc.nhom);
			gotoxy(89 + vitri, y);
			goto NHOM;
		}
		if (key == ESC || key == F2)
		{
			xoascreen();
			XemLTC(DSLTC,DSMH,2);
		}
	}
NHOM:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so : (0-9). Toi da 1 ki tu!";
		Color(12);
		gotoxy(89 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.hocki[0] == '\0')		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap hoc ki", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(80, y);
			goto HOCKI;
		}
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			lopTc.nhom[vitri] = char(key);
			lopTc.nhom[vitri] = toupper(lopTc.nhom[vitri]);
			cout << lopTc.nhom[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.nhom[vitri] = '\0';
			pochinki = KiemtraBo4_v2(DSLTC, lopTc);
			if (-1 == pochinki) {
				vitri = strlen(lopTc.svMax);
				gotoxy(97 + vitri, y);
				goto SOLUONGMAX;
			}
			if (-2 == pochinki) {
				GhiChu("Thong tin 4 field Ma mon hoc, Nien Khoa, Hoc ki, Nhom khong duoc trung", 35, 28, 79, 2000);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(89 + vitri, y);
			cout << " ";
			gotoxy(89 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.nhom[vitri] = '\0';
			vitri = strlen(lopTc.hocki);
			gotoxy(80 + vitri, y);
			goto HOCKI;
		}
		if (key == RIGHT)
		{
			lopTc.nhom[vitri] = '\0';
			vitri = strlen(lopTc.svMax);
			gotoxy(97 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == ESC || key == F1)
		{
			xoascreen();
			XemLTC(DSLTC,DSMH,2);
		}
	}
SOLUONGMAX:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so : (0-9). Toi da 500 sinh vien!";
		Color(12);
		gotoxy(97 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.nhom[0] == '\0')		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap nhom", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(89, y);
			goto NHOM;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			lopTc.svMax[vitri] = char(key);
			lopTc.svMax[vitri] = toupper(lopTc.svMax[vitri]);
			cout << lopTc.svMax[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{	
			lopTc.svMax[vitri]='\0';
			svIndexmax = atoi(lopTc.svMax);
			if(svIndexmax<501&&svIndexmax>9){
			vitri=strlen(lopTc.svMin);
			gotoxy(106+vitri,y);
			goto SOLUONGMIN;
			}else{
				GhiChu("so luong sinh vien max sai yeu cau!",60,28,79,500);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(97 + vitri, y);
			cout << " ";
			gotoxy(97 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.svMax[vitri] = '\0';
			vitri = strlen(lopTc.nhom);
			gotoxy(89 + vitri, y);
			goto NHOM;
		}
			if (key == RIGHT)
		{	
			svIndexmax = atoi(lopTc.svMax);
			if(svIndexmax<501&&svIndexmax>9){
			lopTc.svMax[vitri]='\0';
			vitri=strlen(lopTc.svMin);
			gotoxy(106+vitri,y);
			goto SOLUONGMIN;
			}else{
				GhiChu("so luong sinh vien max sai yeu cau!",60,28,79,500);
				continue;
			}
		}
		if (key == ESC || key == F2)
		{
			xoascreen();
			XemLTC(DSLTC,DSMH,2);
		}
	}
SOLUONGMIN:
	while (1)
	{
		Color(245);
		gotoxy(35, 4); cout << "Ki tu so : (0-9). Toi thieu 10 sinh vien!";
		Color(12);
		gotoxy(106 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.svMax[0] == '\0')		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap so luong sinh vien max", 60, 28, 79, 700);
			vitri = 0;
			gotoxy(97, y);
			goto SOLUONGMAX;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			lopTc.svMin[vitri] = char(key);
			cout << lopTc.svMin[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{	
			lopTc.svMin[vitri] = '\0';
			svIndexmax = atoi(lopTc.svMax);
			svIndexmin = atoi(lopTc.svMin);
			if(svIndexmin>9&&svIndexmin<=svIndexmax){
			strcpy(DSLTC.ds[vitri_LTC]->mmh,lopTc.mmh);
			strcpy(DSLTC.ds[vitri_LTC]->nienkhoa,lopTc.nienkhoa);
			strcpy(DSLTC.ds[vitri_LTC]->hocki,lopTc.hocki);
			strcpy(DSLTC.ds[vitri_LTC]->nhom,lopTc.nhom);
			strcpy(DSLTC.ds[vitri_LTC]->svMax,lopTc.svMax);
			strcpy(DSLTC.ds[vitri_LTC]->svMin,lopTc.svMin);
			GhiFileDSLTC(DSLTC);
			GhiChu("Da luu vao bo nho", 60, 28, 228, 500);
			xoascreen();
			XemLTC(DSLTC,DSMH,2);
			}
			else{
				GhiChu("so luong sinh vien min sai yeu cau!",60,28,79,500);
				continue;
			}
			
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(106 + vitri, y);
			cout << " ";
			gotoxy(106 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.svMin[vitri] = '\0';
			vitri = strlen(lopTc.svMax);
			gotoxy(97 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == ESC || key == F1)
		{
			xoascreen();
			chaymenultc();
		}
	}
}
void XoaLTC(DSloptc& DSLTC,PTRMH DSMH,int vitri_LTC){
	int key;
				if(DSLTC.ds[vitri_LTC]->DSDK != NULL){
					GhiChu("LOP TIN CHI DA CO SINH VIEN. KHONG THE XOA!", 55, 28, 79, 700);
					xoascreen();
					XemLTC(DSLTC,DSMH,2);
				}else{
						gotoxy(50,28); Color(4);
					cout << "BAN CO MUON XOA LOP TIN CHI NAY KHONG ???";
					gotoxy(55,29); cout << "YES";
					gotoxy(70,29); cout << "NO";
					YES: 
						while(1){
							gotoxy(55,29);
							cout << "YES";
							key = GetKey();
							if(key == ENTER){
								DeleteLTC(DSLTC, vitri_LTC);
								GhiFileDSLTC(DSLTC);
								GhiChu("XOA THANH CONG LTC!", 60, 29, 79, 500);
								xoascreen();
								XemLTC(DSLTC,DSMH,2);
							}
							if(key == RIGHT){
								goto NO;
							}
						}
					NO:
						while(1){
							gotoxy(70,29);
							cout << "NO";
							key = GetKey();
							if(key == ENTER){
								GhiChu("KHONG XOA THANH CONG LTC!", 60, 29, 79, 500);
								xoascreen();
								XemLTC(DSLTC,DSMH,2);
							}
							if(key == LEFT){
								goto YES;
							}
						}	
				}
		if (key == ESC || key == F2)
		{
			xoascreen();
			XemLTC(DSLTC,DSMH,2);
		}
 }
void AutoXoaLTC(DSloptc& DSLTC){
	nhacnhoAutoXoaLTC();
		char key;
	int  trang = 0, tongtrang = 0;
	int  dem = 0, demdong = 0;
	while(1){
		if(DSLTC.soluong==0){
			GhiChu("Chua co du lieu Lop Tin Chi!", 60, 28, 79, 3000);
			chaymenultc();
		}else{
			if(DSLTC.soluong<18){
				tongtrang = 1;
				trang = 0;
			}else {
				tongtrang = ((DSLTC.soluong - 1) / 18 + 1);
			}
		}
		dem = 0 ; demdong = 0;
			khunginLTC();
		for (int i = trang * 18; i < 18 + trang * 18 && i < DSLTC.soluong; i++)
		{
			if(DemSVDK(DSLTC.ds[i]->DSDK)<atoi(DSLTC.ds[i]->svMin)){
				Color(3);
				//gotoxy(35,8+demdong);cout<<"|     |           |            |           |       |      |         |         |";
			}else Color(7);
			 gotoxy(36, 8 + demdong); cout << (i + 1);
			gotoxy(44,8+demdong);cout << DSLTC.ds[i]->maLoptc;
			gotoxy(57,8+demdong);cout << DSLTC.ds[i]->mmh;
			gotoxy(70,8+demdong);cout << DSLTC.ds[i]->nienkhoa;
			gotoxy(82,8+demdong);cout << DSLTC.ds[i]->hocki;
			gotoxy(90,8+demdong);cout << DSLTC.ds[i]->nhom;
			gotoxy(97,8+demdong);cout << DSLTC.ds[i]->svMax;
			gotoxy(106,8+demdong);cout << DSLTC.ds[i]->svMin;
			demdong++;
			}
		HienThiTrang(trang + 1, tongtrang, 90, 26);
			gotoxy(31, 0); cout << "                                 TU DONG XOA LTC!                      ";
			gotoxy(31,2); cout <<"                  XOA LOP CO SINH VIEN DANG KI < SO SINH VIEN TOI THIEU  ";
			gotoxy(98,26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if(key==ESC){
			xoascreen();
			chaymenultc();
							}
		if(key==F3){
				gotoxy(50,28); Color(4);
					cout << "BAN CO MUON XOA MON HOC NAY KHONG ???";
					gotoxy(55,29); cout << "YES";
					gotoxy(70,29); cout << "NO";
					YES: 
						while(1){
							gotoxy(55,29);
							cout << "YES";
							key = GetKey();
							if(key == ENTER){
								for (int i = trang * 18; i < 18 + trang * 18 && i < DSLTC.soluong; i++){
									if(DemSVDK(DSLTC.ds[i]->DSDK)<atoi(DSLTC.ds[i]->svMin)){
										DeleteLTC(DSLTC,i);
										i--;
										}
									}
								GhiFileDK(DSLTC);
								GhiFileDSLTC(DSLTC);
								GhiChu("XOA THANH CONG LTC!", 60, 29, 79, 500);
								xoascreen();
								AutoXoaLTC(DSLTC);
							}
							if(key == RIGHT){
								goto NO;
							}
							if(key==ESC){
								xoascreen();
								AutoXoaLTC(DSLTC);
							}
						}
					NO:
						while(1){
							gotoxy(70,29);
							cout << "NO";
							key = GetKey();
							if(key == ENTER){
								GhiChu("KHONG XOA THANH CONG LTC!", 60, 29, 79, 500);
								xoascreen();
								AutoXoaLTC(DSLTC);
							}
							if(key == LEFT){
								goto YES;
							}
							if(key==ESC){
								xoascreen();
								AutoXoaLTC(DSLTC);
							}
						}	
 		}
 	}
}
void InLTC(ListLop lop,DSloptc DSLTC,PTRMH DSMH,int vitriltc){
	int key;
	int vitri = 0;
	int STT = 1;
	int trang = 0, tongtrang = 0, soluongsv = 0;
	int  dem = 0,dem1=0;
		soluongsv = DemSVDK(DSLTC.ds[vitriltc]->DSDK);
	if (soluongsv == 0)
	{
		GhiChu("Chua co du lieu sinh vien", 60, 28, 79, 500);
		XemLTC(DSLTC,DSMH,1);
	}else {
		if (soluongsv < 18)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongsv - 1) / 18 + 1);
		}
	}
	int ktrasv;
		PTRSV svdk;
		sinhvien* SV = new sinhvien[soluongsv + 1]; // chua thong tin sinh vien
		dangki* Diem = new dangki[soluongsv + 1]; // chua diem cua sinh vien

	for (PTRDK p = DSLTC.ds[vitriltc]->DSDK; p != NULL; p = p->next) {
		svdk = Search_MSV_DSLOP(lop, p->data.mssv);// truy xuat den danh sach lop tim thong tin sinh vien
		SV[dem1] = svdk->data; //tim duoc thong tin chua vao mang thong tin sinh vien
		dem1++;
	}

	xoascreen();	
		gotoxy(40,0);
		Color(3);
		cout <<"Ma LTC:  " <<DSLTC.ds[vitriltc]->maLoptc<<"   Ma Mon: "<< DSLTC.ds[vitriltc]->mmh<<"   Nien Khoa: "<<DSLTC.ds[vitriltc]->nienkhoa
				<<"   Hoc Ki:  "<< DSLTC.ds[vitriltc]->hocki<<"   Nhom: "<<DSLTC.ds[vitriltc]->nhom;
	while(1){
		
			KhungInSV();			
		dem = 0;
	for (int i = trang * 18; i < 18 + trang * 18 && i < soluongsv; i++)
		{
			Color(12); gotoxy(37, 8 + dem); cout << (i + 1);
			Color(7);
			gotoxy(44,8+dem);cout <<SV[i].mssv;
			gotoxy(58,8+dem);cout<<SV[i].ho;
			gotoxy(72,8+dem);cout<<SV[i].ten;
			gotoxy(96,8+dem);cout<<SV[i].phai;
			gotoxy(102,8+dem);cout<<SV[i].sdt;
			dem++;
		}
			HienThiTrang(trang + 1, tongtrang, 90, 26);
			key=GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == ESC)
			{
			xoascreen();	delete(SV); delete(Diem); XemLTC(DSLTC,DSMH,1);
			}
	}	
}
void XemLTC(DSloptc& DSLTC,PTRMH DSMH,int chedoxem){
	char key;
	int  trang = 0, tongtrang = 0,vitriltc;
	int  dem = 0, demdong = 0,dong=0;
	nhacnhoxsLTC();
	while(1){
		if(DSLTC.soluong==0){
			GhiChu("Chua co du lieu Lop Tin Chi!", 60, 28, 79, 3000);
		}else{
			if(DSLTC.soluong<18){
				tongtrang = 1;
				trang = 0;
			}else {
				tongtrang = ((DSLTC.soluong - 1) / 18 + 1);
			}
		}
		dem = 0 ; demdong = 0;
		khunginLTC();
		SortDSLTC(DSLTC);
		for (int i = trang * 18; i < 18 + trang * 18 && i < DSLTC.soluong; i++)
		{
			Color(7); gotoxy(37, 8 + demdong); cout << (i + 1);
			gotoxy(44,8+demdong);cout << DSLTC.ds[i]->maLoptc;
			gotoxy(57,8+demdong);cout << DSLTC.ds[i]->mmh;
			gotoxy(70,8+demdong);cout << DSLTC.ds[i]->nienkhoa;
			gotoxy(82,8+demdong);cout << DSLTC.ds[i]->hocki;
			gotoxy(90,8+demdong);cout << DSLTC.ds[i]->nhom;
			gotoxy(97,8+demdong);cout << DSLTC.ds[i]->svMax;
			gotoxy(106,8+demdong);cout << DSLTC.ds[i]->svMin;
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 90, 26);
		while(1){
			if (chedoxem == 1)//Dang o che do xem
		{
			gotoxy(31, 0); cout << "                     DANG O CHE DO XEM LTC!                      ";
			nhacnhosv();
			}
			gotoxy(37,8 + dong);
			key = GetKey(); //Bat Phim
			if(key == DOWN){
				if(dong < 17&&(dong<(DSLTC.soluong-18*trang)-1)){
					gotoxy(37, 8 + ++dong);
				}else{
					if(trang < tongtrang - 1){
						trang++;
						dong = 0;
						break;
					}else if(trang == tongtrang - 1 && dong > (DSLTC.soluong % 18)){
						trang = 0;
						dong = 0;
						break;
					}
				}
			}
			if(key == UP){
				if(dong > 0){
					gotoxy(37, 8 + --dong);
				}else{
					if(trang > 0){
						trang--;
						dong = 0;
						break;
					}else{
						trang = tongtrang - 1;
						dong = 0;
						break;
					}
				}
			}
			if (key == RIGHT) {
			 	if(trang < tongtrang - 1){
						trang++;
						dong = 0;
						break;
					}else{
						trang = 0;
						dong = 0;
						break;
				}
			}
			if (key == LEFT) {
			 	if(trang > 0){
						trang--;
						dong = 0;
						break;
					}else{
						trang = tongtrang - 1;
						dong = 0;
						break;
				}
			}
		if(key==ENTER&&chedoxem==1){
			xoascreen();
			vitriltc=	trang*18+dong;
			InLTC(DSL,DSLTC,DSMH,vitriltc);
		}
		if (key == F2 && chedoxem == 2)
		{
			vitriltc=	trang*18+dong;
			SuaLTC(DSLTC, DSMH,vitriltc);
		}
		if (key == F3 && chedoxem == 2)
		{
			vitriltc=	trang*18+dong;
			XoaLTC(DSLTC,DSMH,vitriltc);
		}
		if (key == ESC && (chedoxem==1||chedoxem==2))
		{
			xoascreen();
			chaymenultc();
		}	
}
		
	}
}
/*=====================================================*/
/*=================    LOP/SINH VIEN  =======================*/
/*=====================================================*/
void ThemLop(ListLop& lop,PTRMH DSMH){
	int key;
	int check_trung;
	int vitri = 0, x = 37, y = 3;
	KhungThemLop(); gotoxy(x,y);
MALOP:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 15";
		Color(12); gotoxy(x + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') ||(key == '-') || (key >= 'a' && key <= 'z')) && (vitri < 15))
		{
			lop.ds[lop.soluong].malop[vitri] = char(key);
			lop.ds[lop.soluong].malop[vitri] = toupper(	lop.ds[lop.soluong].malop[vitri]);
			cout << lop.ds[lop.soluong].malop[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lop.ds[lop.soluong].malop[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, lop.ds[lop.soluong].malop, lop.soluong);
			if (check_trung == -1) {
				GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(x + vitri, y);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(x + vitri, y);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(x+ vitri, y);
				continue;
			}
			vitri = strlen(lop.ds[lop.soluong].tenlop);
			gotoxy(55 + vitri, y);
			goto TENLOP;
		}
			if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(x + vitri, y);
			cout << " ";
			gotoxy(x + vitri, y);
		}
		if(key == RIGHT){
			lop.ds[lop.soluong].malop[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, lop.ds[lop.soluong].malop, lop.soluong);
			if (check_trung == -1) {
				GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(x + vitri, y);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(x + vitri, y);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(x+ vitri, y);
				continue;
			}
			vitri = strlen(lop.ds[lop.soluong].tenlop);
			gotoxy(55 + vitri, y);
			goto TENLOP;
		}
		if(key == ESC ){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,1);
		}
	}
TENLOP:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 35";
		Color(12); gotoxy(55 + vitri, y); //Ghi chú
		key = GetKey();
		if(lop.ds[lop.soluong].malop[0]=='\0'){
			GhiChu("Ban Chua Nhap Ma Lop!", 60, 28, 79, 700);
			gotoxy(x, y);
			goto MALOP;
		}
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key == '-') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			lop.ds[lop.soluong].tenlop[vitri] = char(key);
			lop.ds[lop.soluong].tenlop[vitri] = toupper(lop.ds[lop.soluong].tenlop[vitri]);
			cout << lop.ds[lop.soluong].tenlop[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (lop.ds[lop.soluong].tenlop[vitri-1] == ' ') { vitri--; }  //KT khi enter truoc do co phai khoang trang-> chuan hoa
			lop.ds[lop.soluong].tenlop[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, lop.ds[lop.soluong].tenlop, lop.soluong);
			if (check_trung == -1) {
				GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(55 + vitri, y);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(55 + vitri, y);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(55 + vitri, y);
				continue;
			}
			vitri = strlen(lop.ds[lop.soluong].nienkhoa);
			gotoxy(97 + vitri, y);
			goto NIENKHOA;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(55 + vitri, y);
			cout << " ";
			gotoxy(55 + vitri, y);
		}
		if (key == SPACE && lop.ds[lop.soluong].tenlop[vitri-1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{
			gotoxy(55 + vitri, y);
			cout << " ";
			lop.ds[lop.soluong].tenlop[vitri] = ' ';
			vitri++;
		}	
		if (key == LEFT)
		{
			lop.ds[lop.soluong].tenlop[vitri] = '\0';
			vitri = strlen(lop.ds[lop.soluong].malop);
			gotoxy(x + vitri, y);
			goto MALOP;
		}
		if(key==RIGHT){
			if (lop.ds[lop.soluong].tenlop[vitri-1] == ' ') { vitri--; }  //KT khi enter truoc do co phai khoang trang-> chuan hoa
			lop.ds[lop.soluong].tenlop[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, lop.ds[lop.soluong].tenlop, lop.soluong);
			if (check_trung == -1) {
				GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(55 + vitri, y);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(55 + vitri, y);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!", 60, 28, 79, 500);
				gotoxy(55 + vitri, y);
				continue;
			}
			vitri = strlen(lop.ds[lop.soluong].nienkhoa);
			goto NIENKHOA;
		}
		if(key== ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,1);
		}
	}
NIENKHOA:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (0-9). Toi da: 4         ";
		Color(12); gotoxy(97 + vitri, y); // Ghi chú
		key = GetKey();
		if(lop.ds[lop.soluong].tenlop[0] == '\0'){
			GhiChu("Ban Chua Nhap Ten Lop!", 60, 28, 79, 700);
			gotoxy(55, y);
			goto TENLOP;
		}
		if ((key <= '9' && key >= '0') && (vitri < 4))
		{
			lop.ds[lop.soluong].nienkhoa[vitri] = char(key);
			lop.ds[lop.soluong].nienkhoa[vitri] = toupper(lop.ds[lop.soluong].nienkhoa[vitri]);
			cout << lop.ds[lop.soluong].nienkhoa[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (strcmp(lop.ds[lop.soluong].nienkhoa, "2010") < 0 || strcmp(lop.ds[lop.soluong].nienkhoa, "2025") > 0 || vitri < 4) {
				GhiChu("Nien khoa chua hop le !", 50, 28, 79, 700);
				continue;
			}
			lop.ds[lop.soluong].nienkhoa[vitri] = '\0';
			GhiChu("Da luu vao bo nho", 60, 28, 79, 1000);
			lop.soluong++;
			GhiFileLop(lop);
			xoascreen();
			XemLop(lop,DSMH,DSLTC,1);
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(97 + vitri, y);
			cout << " ";
			gotoxy(97 + vitri, y);
		}
		if (key == LEFT)
		{
			lop.ds[lop.soluong].nienkhoa[vitri] = '\0';
			vitri = strlen(lop.ds[lop.soluong].tenlop);
			goto TENLOP;
		}
		if(key== ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,1);
		}
	}
}
void ThemSV( ListLop& lop, PTRMH DSMH,int vitriMang){
	int key;
	int check_trung;
	int vitri = 0, x = 37, y = 3;
	sinhvien sv;
	sv.malop[0]= NULL;
	sv.mssv[0] = NULL; sv.ho[0] = NULL; sv.ten[0] = NULL; sv.phai[0] = NULL; sv.sdt[0] = NULL;
	xoascreen();
	gotoxy(50,0); 
	Color(12);
	cout << lop.ds[vitriMang].malop<<"    "<<lop.ds[vitriMang].tenlop<<"     "<<lop.ds[vitriMang].nienkhoa;
	Color(12);
	KhungThemSV();
	strcpy(sv.malop,lop.ds[vitriMang].malop);
	gotoxy(x,y); cout <<lop.ds[vitriMang].malop;
MASV:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 35";
		Color(12); gotoxy(54 + vitri, y); //Ghi chú
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key == '-') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			sv.mssv[vitri] = char(key);
			sv.mssv[vitri] = toupper(sv.mssv[vitri]);
			cout << sv.mssv[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(54 + vitri, y);
			cout << " ";
			gotoxy(54 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.mssv[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.mssv, lop.soluong);
			if (check_trung == -1) {
				GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			vitri = strlen(sv.ho);
			goto HO;
		}
		if(key==RIGHT){
			sv.mssv[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.mssv, lop.soluong);
			if (check_trung == -1) {
				GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,8,79,500);
				continue;
			}
			vitri = strlen(sv.ho);
			goto HO;
		}
		if(key==ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,2);
		}
	}
HO:
	while(1){
			Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z)         . Toi da: 15";
		Color(12); gotoxy(69 + vitri, y); //Ghi chú
		key = GetKey();
		if (sv.mssv[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Sinh Vien!", 60, 28, 79, 700);
			vitri = 0;
			goto MASV;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 15))
		{
			sv.ho[vitri] = char(key);
			sv.ho[vitri] = toupper(sv.ho[vitri]);
			cout << sv.ho[vitri];
			vitri++;
		}
			if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(69 + vitri, y);
			cout << " ";
			gotoxy(69 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (sv.ho[vitri - 1] == ' ') { vitri--; }	//KT khi enter truoc do co phai khoang trang
			sv.ho[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.ho, lop.soluong);
			if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			vitri = strlen(sv.ten);
			goto TEN;
	 		}
	 		if (key == SPACE && sv.ho[vitri - 1] != ' ' && vitri > 0 && vitri < 15)
			{
			gotoxy(69 + vitri, y);
			cout << " ";
			sv.ho[vitri] = ' ';
			vitri++;
			}
			if (key == LEFT)
		{
			sv.ho[vitri] = '\0';
			vitri = strlen(sv.mssv);
			goto MASV;
		}
		if(key==RIGHT){
			if (sv.ho[vitri - 1] == ' ') { vitri--; }	//KT khi enter truoc do co phai khoang trang
			sv.ho[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.ho, lop.soluong);
			if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			vitri = strlen(sv.ten);
			goto TEN;
		}
		if(key==ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,2);
		}
  }
TEN:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z)         . Toi da: 30";
		Color(12); gotoxy(80 + vitri, y); //Ghi chú
		key = GetKey();
		if (sv.ho[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ho !", 60, 28, 79, 700);
			vitri = 0;
			goto HO;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			sv.ten[vitri] = char(key);
			sv.ten[vitri] = toupper(sv.ten[vitri]);
			cout << sv.ten[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(80 + vitri, y);
			cout << " ";
			gotoxy(80 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.ten[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.ten, lop.soluong);
			if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			gotoxy(98,3);
			goto PHAI;
		}
		if (key == LEFT)
		{
			sv.ten[vitri] = '\0';
			vitri = strlen(sv.ho);
			goto HO;
		}
		if (key == SPACE && sv.ten[vitri - 1] != ' ' && vitri > 0 && vitri < 30)
			{
			gotoxy(80 + vitri, y);
			cout << " ";
			sv.ten[vitri] = ' ';
			vitri++;
			}
		if(key==RIGHT){
			sv.ten[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.ten, lop.soluong);
			if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			gotoxy(98,3);
			goto PHAI;
		}
		if(key==ESC){
				xoascreen();
			XemLop(lop,DSMH,DSLTC,2);
		}
	}
PHAI:
	if (sv.ten[0] == '\0')
		{
			GhiChu("Ban Chua Nhap TEN Sinh Vien!", 60, 28, 79, 700);
			vitri = 0;
			goto TEN;
		}
	while(1){
		vitri=0;
		key = GetKey();
		if(key==LEFT){
			 vitri = strlen(sv.ten);
			goto TEN;
		}
		if(key==ENTER){
			Color(12);
		gotoxy(98,y);cout<<"    ";
						gotoxy(50,28); Color(4);
					cout << "NHAP GIOI TINH CHO SINH VIEN NAY ???";
					gotoxy(55,29); cout << "NAM";
					gotoxy(70,29); cout << "NU";
					NAM: 
						while(1){
							gotoxy(55,29);
							cout << "NAM";
							key = GetKey();
							if(key == ENTER){
								strcpy(sv.phai,"NAM");
								gotoxy(98,y);
								cout << sv.phai;
								xoaghichu();
								vitri= strlen(sv.sdt);
								goto SDT;
							}
							if(key == RIGHT){
								goto NU;
							}
						}
					NU:
						while(1){
							gotoxy(70,29);
							cout << "NU";
							key = GetKey();
							if(key == ENTER){
								strcpy(sv.phai,"NU");
								gotoxy(98,y);
								cout << sv.phai;
								xoaghichu();
								vitri= strlen(sv.sdt);
								goto SDT;
							}
							if(key == LEFT){
								goto NAM;
							}
						}	
		}
		if(key==RIGHT){
			vitri= strlen(sv.sdt);
			goto SDT;
		}
		if(key==ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,2);
		}
	}
SDT:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (0-9)         . Toi da: 10";
		Color(12); gotoxy(105 + vitri, y); //Ghi chú
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 10))
		{
			sv.sdt[vitri] = char(key);
			cout << sv.sdt[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(105 + vitri, y);
			cout << " ";
			gotoxy(105 + vitri, y);
		}
		if(key==ENTER){
			sv.sdt[vitri] = '\0';
			Insert_TailSV(lop.ds[vitriMang].DSSV, sv);
			GhiFileSV(lop);
			GhiChu("Them thanh cong", 60, 28, 79, 1000);
				xoascreen();
			ThemSV(lop,DSMH,vitriMang);
		}
		if (key == LEFT)
		{
			gotoxy(98,3);
			goto PHAI;
		}
		if(key == ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,2);
		}
	}
}
void SuaSV(PTRSV& DSSV, ListLop lop, PTRMH DSMH, DSloptc &DSLTC, char c[]){
	int key;
	int check_trung;
	PTRSV p; //vi tri cua sinh vien trong dssv, tra ve con tro
	int vitri = 0, x = 37, y = 3, temp = 0;
	sinhvien sv;
	sv.mssv[0] = NULL; sv.ho[0] = NULL; sv.ten[0] = NULL; sv.phai[0] = NULL; sv.sdt[0] = NULL;
	strcpy(sv.mssv, c);
	p = Search_MSV(DSSV, sv.mssv);
	KhungThemSV();
	strcpy(sv.malop,p->data.malop);
	strcpy(sv.mssv, p->data.mssv);
	strcpy(sv.ho, p->data.ho);
	strcpy(sv.ten, p->data.ten);
	strcpy(sv.phai, p->data.phai);
	strcpy(sv.sdt, p->data.sdt);
	Color(12);
	gotoxy(x,y); cout<< sv.malop;
	gotoxy(54, y); cout << sv.mssv;
	gotoxy(69, y); cout << sv.ho;
	gotoxy(80, y); cout << sv.ten;
	gotoxy(98, y); cout << sv.phai;
	gotoxy(105, y); cout << sv.sdt;
	vitri = strlen(sv.mssv);
MASV:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 35";
		Color(12); gotoxy(54 + vitri, y); //Ghi chú
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key == '-') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			sv.mssv[vitri] = char(key);
			sv.mssv[vitri] = toupper(sv.mssv[vitri]);
			cout << sv.mssv[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(54 + vitri, y);
			cout << " ";
			gotoxy(54 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.mssv[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.mssv, lop.soluong);
			if(strcmp(sv.mssv, p->data.mssv) != 0){
				if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
					continue;
				}
				if (check_trung == -2) {
					GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
					continue;
				}
				if (check_trung == -3) {
					GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
					continue;
				}
			}
			vitri = strlen(sv.ho);
			goto HO;
		}
		if(key==RIGHT){
			sv.mssv[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.mssv, lop.soluong);
			if(strcmp(sv.mssv, p->data.mssv) != 0){
				if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
					continue;
				}
				if (check_trung == -2) {
					GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
					continue;
				}
				if (check_trung == -3) {
					GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,8,79,500);
					continue;
				}
			}
			vitri = strlen(sv.ho);
			goto HO;
		}
		if(key==ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,3);
		}
	}
HO:
	while(1){
			Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z)         . Toi da: 15";
		Color(12); gotoxy(69 + vitri, y); //Ghi chú
		key = GetKey();
		if (sv.mssv[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Sinh Vien!", 60, 28, 79, 700);
			vitri = 0;
			goto MASV;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 15))
		{
			sv.ho[vitri] = char(key);
			sv.ho[vitri] = toupper(sv.ho[vitri]);
			cout << sv.ho[vitri];
			vitri++;
		}
			if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(69 + vitri, y);
			cout << " ";
			gotoxy(69 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (sv.ho[vitri - 1] == ' ') { vitri--; }	//KT khi enter truoc do co phai khoang trang
			sv.ho[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.ho, lop.soluong);
			if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			vitri = strlen(sv.ten);
			goto TEN;
	 		}
	 		if (key == SPACE && sv.ho[vitri - 1] != ' ' && vitri > 0 && vitri < 15)
			{
			gotoxy(69 + vitri, y);
			cout << " ";
			sv.ho[vitri] = ' ';
			vitri++;
			}
			if (key == LEFT)
		{
			sv.ho[vitri] = '\0';
			vitri = strlen(sv.mssv);
			goto MASV;
		}
		if(key==RIGHT){
			if (sv.ho[vitri - 1] == ' ') { vitri--; }	//KT khi enter truoc do co phai khoang trang
			sv.ho[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.ho, lop.soluong);
			if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			vitri = strlen(sv.ten);
			goto TEN;
		}
		if(key==ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,3);
		}
  }
TEN:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z)         . Toi da: 30";
		Color(12); gotoxy(80 + vitri, y); //Ghi chú
		key = GetKey();
		if (sv.ho[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ho !", 60, 28, 79, 700);
			vitri = 0;
			goto HO;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			sv.ten[vitri] = char(key);
			sv.ten[vitri] = toupper(sv.ten[vitri]);
			cout << sv.ten[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(80 + vitri, y);
			cout << " ";
			gotoxy(80 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.ten[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.ten, lop.soluong);
			if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			gotoxy(98,3);
			goto PHAI;
		}
		if (key == LEFT)
		{
			sv.ten[vitri] = '\0';
			vitri = strlen(sv.ho);
			goto HO;
		}
		if (key == SPACE && sv.ten[vitri - 1] != ' ' && vitri > 0 && vitri < 30)
			{
			gotoxy(80 + vitri, y);
			cout << " ";
			sv.ten[vitri] = ' ';
			vitri++;
			}
		if(key==RIGHT){
			sv.ten[vitri] = '\0';
			check_trung = kt_Lop_MSV_MH(lop, DSMH, sv.ten, lop.soluong);
			if (check_trung == -1) {
					GhiChu("Trung Ma Lop Tin Chi. Vui Long Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -2) {
				GhiChu("Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
			if (check_trung == -3) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,79,500);
				continue;
			}
			gotoxy(98,3);
			goto PHAI;
		}
		if(key==ESC){
				xoascreen();
			XemLop(lop,DSMH,DSLTC,3);
		}
	}
PHAI:
	if (sv.ten[0] == '\0')
		{
			GhiChu("Ban Chua Nhap TEN Sinh Vien!", 60, 28, 79, 700);
			vitri = 0;
			goto TEN;
		}
	while(1){
		vitri=0;
		key = GetKey();
		if(key==LEFT){
			 vitri = strlen(sv.ten);
			goto TEN;
		}
		if(key==ENTER){
			Color(12);
		gotoxy(98,y);cout<<"    ";
						gotoxy(50,28); Color(4);
					cout << "NHAP GIOI TINH CHO SINH VIEN NAY ???";
					gotoxy(55,29); cout << "NAM";
					gotoxy(70,29); cout << "NU";
					NAM: 
						while(1){
							gotoxy(55,29);
							cout << "NAM";
							key = GetKey();
							if(key == ENTER){
								strcpy(sv.phai,"NAM");
								gotoxy(98,y);
								cout << sv.phai;
								xoaghichu();
								vitri= strlen(sv.sdt);
								goto SDT;
							}
							if(key == RIGHT){
								goto NU;
							}
						}
					NU:
						while(1){
							gotoxy(70,29);
							cout << "NU";
							key = GetKey();
							if(key == ENTER){
								strcpy(sv.phai,"NU");
								gotoxy(98,y);
								cout << sv.phai;
								xoaghichu();
								vitri= strlen(sv.sdt);
								goto SDT;
							}
							if(key == LEFT){
								goto NAM;
							}
						}	
		}
		if(key==RIGHT){
			vitri= strlen(sv.sdt);
			goto SDT;
		}
		if(key==ESC){
			xoascreen();
		XemLop(lop,DSMH,DSLTC,3);
		}
	}
SDT:
	while(1){
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (0-9)         . Toi da: 10";
		Color(12); gotoxy(105 + vitri, y); //Ghi chú
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 10))
		{
			sv.sdt[vitri] = char(key);
			cout << sv.sdt[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(105 + vitri, y);
			cout << " ";
			gotoxy(105 + vitri, y);
		}
		if(key==ENTER){
			sv.sdt[vitri] = '\0';
			for (int i = 0; i < DSLTC.soluong; i++) {
				for (PTRDK q = DSLTC.ds[i]->DSDK; q != NULL; q = q->next) {
					if (strcmp(q->data.mssv, p->data.mssv) == 0) {
						strcpy(q->data.mssv, sv.mssv);
					}
				}
			}
			p->data = sv;
			GhiChu("Sua thanh cong", 60, 28, 79, 1000);
				xoascreen();
			XemLop(lop,DSMH,DSLTC,3);
		}
		if (key == LEFT)
		{
			gotoxy(98,3);
			goto PHAI;
		}
		if(key == ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,3);
		}
	}
	
}
void XemSV(ListLop& lop, PTRMH DSMH, DSloptc &DSLTC, int vitriMang){
	int key, vitriSV;
	int dem1=0,dem = 0, dong = 0;//dem la dem dong`.  dem1 la vitri phan tu sv
	int trang = 0, tongtrang = 0,soluongsv;
	bool check_change = false;
	gotoxy(40,0);
	cout<<lop.ds[vitriMang].malop<<"    "<<lop.ds[vitriMang].tenlop<<"     "<<lop.ds[vitriMang].nienkhoa;
	while(1){
		dem1 = 0;
		soluongsv = DemSinhVien(lop.ds[vitriMang].DSSV);
		if (soluongsv == 0)
		{
			GhiChu("Chua co du lieu sinh vien", 60, 28, 79, 500);
			XemLop(lop,DSMH,DSLTC,3);
		}else{
			if(soluongsv<18){
				tongtrang = 1;
				trang = 0;
			}else{
				tongtrang = ((soluongsv - 1) / 18 + 1);
			}
		}
		SapXepSV(lop.ds[vitriMang].DSSV); 	//Sap Xep danh sach theo Ten Ho
		sinhvien* SV = new sinhvien[soluongsv + 1];
		for (PTRSV p = lop.ds[vitriMang].DSSV; p != NULL; p = p->next)
		{
			SV[dem1] = p->data;
			dem1++;
		} //Dô? DSSV vào mang?
		xoascreen();
		KhungInSV();
		dem=0;
			for (int i = trang * 18; i < 18 + trang * 18 && i < soluongsv; i++)
		{
			Color(12); gotoxy(37, 8 + dem); cout << (i + 1);
			Color(7);
			gotoxy(44,8+dem);cout <<SV[i].mssv;
			gotoxy(58,8+dem);cout<<SV[i].ho;
			gotoxy(72,8+dem);cout<<SV[i].ten;
			gotoxy(96,8+dem);cout<<SV[i].phai;
			gotoxy(102,8+dem);cout<<SV[i].sdt;
			dem++;
		}
		HienThiTrang(trang + 1, tongtrang, 90, 26);
		while(1){
			gotoxy(37, 8 + dong);
			key = GetKey(); //Bat Phim
			if (key == DOWN){
				if (dong < 17&&(dong<(soluongsv-trang*18)-1)) { //
					gotoxy(37, 8 + ++dong);
				}else{
					if (trang < tongtrang - 1) {
						trang++;
						dong = 0;
						break;
					}
					else if (trang == tongtrang - 1 && dong > (soluongsv%18)) {
						trang = 0;
						dong = 0;
						break;
					}
				}
		}
		if(key==UP){
			if (dong > 0) {
					gotoxy(37, 8 + --dong);
				}
				else {
					if (trang > 0) {
						trang--;
						dong = 0;
						break;
					}
					else {
						trang = tongtrang - 1;
						dong = 0;
						break;
					}
				}
		}
		if (key == RIGHT) {
				if (trang < tongtrang - 1) {
					trang++;
					dong = 0;
					break;
				}
				else {
					trang = 0;
					dong = 0;
					break;
				}
			}
		if (key == LEFT) {
				if (trang > 0) {
					trang--;
					dong = 0;
					break;
				}
				else {
					trang = tongtrang - 1;
					dong = 0;
					break;
				}
			}
		if(key==F2){
			vitriSV = (trang * 18) + (dong);
				SuaSV(lop.ds[vitriMang].DSSV,lop,DSMH,DSLTC,SV[vitriSV].mssv);
		}
		if (key == F3) {
	int  temp;
	PTRDK p;
	gotoxy(50, 28); Color(4);
	cout << "BAN CO MUON XOA SINH VIEN NAY KHONG ???";
	gotoxy(55, 29); cout << "YES";
	gotoxy(70, 29); cout << "NO";
YES:
	while (1) {
		gotoxy(55, 29);
		cout << "YES";
		key = GetKey();
		if (key == ENTER) {
			vitriSV = (trang * 18) + (dong);
			temp = KTSV(lop.ds[vitriMang].DSSV, SV[vitriSV].mssv);//KT trung sinh vien trong Listlop
				p = SearchSV_LTC(DSLTC, SV[vitriSV].mssv);
			if (temp != 2) {
				if (p != NULL) {
					GhiChu("Sinh Vien Da Dang Ki Mon. Khong Duoc Xoa!", 60, 28, 79, 700);
					xoascreen();
					XemSV(lop, DSMH, DSLTC, vitriMang);
				}
				else {
					if (temp == 1) XoaDauSV(lop.ds[vitriMang].DSSV);
					if (temp == 0) XoaGiuaSV(lop.ds[vitriMang].DSSV, SV[vitriSV].mssv);
					if (temp == -1) XoaCuoiSV(lop.ds[vitriMang].DSSV);
					GhiFileSV(lop);
					GhiChu("Da Xoa Thanh Cong", 60, 28, 79, 500);
					xoascreen();
					XemSV(lop,DSMH,DSLTC,vitriMang);
				}
			}
		}
		if (key == RIGHT) {
						goto NO;
					}
	}//don khuc sau len
			NO:
				while (1) {
					gotoxy(70, 29);
					cout << "NO";
					key = GetKey();
					if (key == ENTER) {
						GhiChu("KHONG XOA SINH VIEN HOC NAY!", 60, 28, 79, 500);
						break;
					}
					if (key == LEFT) {
						goto YES;
					}
				}
		}
		if(key==ESC){
			xoascreen();
			XemLop(lop,DSMH,DSLTC,3);
		}
	}
 }
}
void XemLop(ListLop& lop, PTRMH DSMH,DSloptc& DSLTC,int chedoxem){
	int key, vitriMang;
	int dem = 0, dong = 0;
	int trang = 0, tongtrang = 0;
	while (1)
	{
		if (lop.soluong == 0)
		{
			GhiChu("Chua co Danh Sach Lop", 60, 28, 79, 1000);
		}
		else {
			if (lop.soluong < 18)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((lop.soluong - 1) / 18 + 1);
			}
		}
		ISortLop(lop);
		Color(4);
		xoascreen();
		KhungInLop();
		dem = 0;
		for (int i = trang * 18; i < 18 + trang * 18 && i < lop.soluong; i++)
		{
			Color(12); gotoxy(37, 8 + dem); cout << (i + 1);
			Color(14);
			gotoxy(47, 8 + dem); cout << lop.ds[i].malop;
			gotoxy(78, 8 + dem); cout << lop.ds[i].tenlop;
			gotoxy(105, 8 + dem); cout << lop.ds[i].nienkhoa;
			dem++;
		}
		HienThiTrang(trang + 1, tongtrang, 90, 26);
		if(chedoxem==1)	nhacnhoLop();else nhacnhosv();
		if(chedoxem==3)nhacnhoLopSV();
		while(1){
			gotoxy(37,8 + dong);
			key = GetKey(); //Bat Phim
			if(key == DOWN){
				if(dong < 17&&(dong<(lop.soluong-18*trang)-1)){
					gotoxy(37, 8 + ++dong);
				}else{
					if(trang < tongtrang - 1){
						trang++;
						dong = 0;
						break;
					}else if(trang == tongtrang - 1 && dong > (lop.soluong % 18)){
						trang = 0;
						dong = 0;
						break;
					}
				}
			}
			if(key == UP){
				if(dong > 0){
					gotoxy(37, 8 + --dong);
				}else{
					if(trang > 0){
						trang--;
						dong = 0;
						break;
					}else{
						trang = tongtrang - 1;
						dong = 0;
						break;
					}
				}
			}
			if (key == RIGHT) {
			 	if(trang < tongtrang - 1){
						trang++;
						dong = 0;
						break;
					}else{
						trang = 0;
						dong = 0;
						break;
				}
			}
			if (key == LEFT) {
			 	if(trang > 0){
						trang--;
						dong = 0;
						break;
					}else{
						trang = tongtrang - 1;
						dong = 0;
						break;
				}
			}
			if(key==F1&&chedoxem==1){
				ThemLop(lop,DSMH);
			}
			if(key==F3&&chedoxem==1){
				vitriMang=(trang*18)+dong;
				Nodelop Lop;
				KhungThemLop();
				strcpy(Lop.malop, lop.ds[vitriMang].malop);
				strcpy(Lop.tenlop, lop.ds[vitriMang].tenlop);
				strcpy(Lop.nienkhoa, lop.ds[vitriMang].nienkhoa);
				Color(12);
				gotoxy(37, 3); cout << Lop.malop;
				gotoxy(55, 3); cout << Lop.tenlop;
				gotoxy(97, 3); cout << Lop.nienkhoa;
				if (lop.ds[vitriMang].DSSV != NULL)
				{
					GhiChu("Lop nay da co Sinh Vien khong the Xoa!", 60, 28, 79, 500);
					xoascreen();
							XemLop(lop,DSMH,DSLTC,1);
				}
					gotoxy(50, 28); Color(4);
	cout << "BAN CO MUON XOA LOP NAY KHONG ???";
	gotoxy(55, 29); cout << "YES";
	gotoxy(70, 29); cout << "NO";
YES:
	while (1) {
		gotoxy(55, 29);
		cout << "YES";
		key = GetKey();
		if (key == ENTER) {
				for (int i = vitriMang; i < lop.soluong; i++) {
					lop.ds[i] = lop.ds[i + 1];
			}//don khuc sau len
							GhiChu("Da Xoa Thanh Cong", 60, 28, 79, 500);
							lop.soluong--;
							GhiFileLop(lop);
							xoascreen();
							XemLop(lop,DSMH,DSLTC,1);
		}
		if (key == RIGHT) {
						goto NO;
					}
	}
			NO:
				while (1) {
					gotoxy(70, 29);
					cout << "NO";
					key = GetKey();
					if (key == ENTER) {
						GhiChu("KHONG XOA LOP HOC NAY!", 60, 28, 79, 500);
							xoascreen();
							XemLop(lop,DSMH,DSLTC,1);
					}
					if (key == LEFT) {
						goto YES;
					}
				}
			}
			if(key==ENTER&&chedoxem==2){
				vitriMang=(trang*18)+dong;
				ThemSV(lop,DSMH,vitriMang);
			}
			if(key==ENTER&&chedoxem==3){
				vitriMang=(trang*18)+dong;
				XemSV(lop,DSMH,DSLTC,vitriMang);
			}
			if(key==ENTER&&chedoxem==4){
				vitriMang=(trang*18)+dong;
				xoascreen();
				XemDiemLop(DSLTC,lop,DSMH,vitriMang);
			}
			if(key==ENTER&&chedoxem==5){
				vitriMang=(trang*18)+dong;
				xoascreen();
				DiemTKet(lop,DSMH,DSLTC,vitriMang);
			}
			if(key==ESC&&(chedoxem==5||chedoxem==4)){
				xoascreen();
				chaymenudiem();
			}
			if(key==ESC){
				xoascreen();
				chaymenusv();
			}
		}
	}
}
//
void TimSV(ListLop& lop,PTRMH DSMH,DSloptc& DSLTC){
	nhacnhoTimSV();
	int key,trang=0,tongtrang=0,dong=0;
	int vitri = 0, x = 43, y = 3,vitrilop,soloptc=0;
	loptc* Lop[100];
	PTRMH mh;
	dangki sv;
	sv.mssv[0] = NULL;
	PTRSV p;
	xoascreen();
	KhungDkLTC();
	while(1){
		Color(250);	gotoxy(43, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 15";
		Color(12); gotoxy( x+vitri, y); //Ghi chú
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0')  || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			sv.mssv[vitri] = char(key);
			sv.mssv[vitri] = toupper(sv.mssv[vitri]);
			cout << sv.mssv[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(x + vitri, y);
			cout << " ";
			gotoxy(x + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.mssv[vitri] = '\0';
			vitrilop = Search_lop_MSV(lop,sv.mssv);
			if (vitrilop > -1) {
				p = Search_MSV(lop.ds[vitrilop].DSSV,sv.mssv);
				goto XULY;
			}else{
				GhiChu("Khong Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
		}
		if(key==ESC){
			xoascreen();
			chaymenusv();
		}
	}
XULY:
	xoascreen();
	gotoxy(35,0);
	cout << "Lop: "<< lop.ds[vitrilop].malop << "  Ma SV: "<< p->data.mssv<< "  Ho Ten: "<< p->data.ho<<" "<<p->data.ten;
	gotoxy(90,2);
	cout<<"  Phai: "<<p->data.phai;
	gotoxy(90,4);
	cout <<"  SDT: "<< p->data.sdt;
	soloptc = DoSV_LTC(DSLTC,sv.mssv,Lop);
	while (1)
	{
		if (soloptc == 0)
		{
			GhiChu("Chua co Danh Sach Lop", 60, 28, 79, 1000);
			xoascreen();
			TimSV(lop,DSMH,DSLTC);
		}
		else {
			if (soloptc < 18)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soloptc - 1) / 18 + 1);
			}
		}
		KhungInSV_LTC();
		dong = 0;
		for (int i = trang * 18; i < 18 + trang * 18 && i < soloptc; i++)
		{
			Color(12); gotoxy(37, 8 + dong); cout << (i + 1);
			if(Lop[i]->DSDK->data.huydk){
				Color(3);
			}else Color(7);
			gotoxy(45,8+dong);cout << Lop[i]->maLoptc;
			gotoxy(56,8+dong);cout << Lop[i]->mmh;
				mh=Search_MH(DSMH,Lop[i]->mmh);
			gotoxy(67,8+dong);cout << mh->data.tmh;
			gotoxy(93,8+dong);cout << Lop[i]->nienkhoa;
			gotoxy(103,8+dong);cout << Lop[i]->hocki;
			gotoxy(111,8+dong);cout << Lop[i]->nhom;
			dong++;
		}
		HienThiTrang(trang + 1, tongtrang, 90, 26);
		dong--;
		gotoxy(37,8+dong);
		while(1){
			key = GetKey(); //Bat Phim
			if(key == DOWN){
				if(dong < 17&&(dong<(soloptc-18*trang)-1)){
					gotoxy(37, 8 + ++dong);
				}else{
					if(trang < tongtrang - 1){
						trang++;
						dong = 0;
						break;
					}else if(trang == tongtrang - 1 && dong > (soloptc % 18)){
						trang = 0;
						dong = 0;
						break;
					}
				}
			}
			if(key == UP){
				if(dong > 0){
					gotoxy(37, 8 + --dong);
				}else{
					if(trang > 0){
						trang--;
						dong = 0;
						break;
					}else{
						trang = tongtrang - 1;
						dong = 0;
						break;
					}
				}
			}
			if (key == RIGHT) {
			 	if(trang < tongtrang - 1){
						trang++;
						dong = 0;
						break;
					}else{
						trang = 0;
						dong = 0;
						break;
				}
			}
			if (key == LEFT) {
			 	if(trang > 0){
						trang--;
						dong = 0;
						break;
					}else{
						trang = tongtrang - 1;
						dong = 0;
						break;
				}
			}
			if(key==ENTER){
				vitrilop=trang*18+dong;
					gotoxy(50,28); Color(4);
					cout << "BAN CO MUON HUY DANG KI LOP TIN CHI NAY KHONG ???";
					gotoxy(55,29); cout << "YES";
					gotoxy(70,29); cout << "NO";
					YES: 
						while(1){
							gotoxy(55,29);
							cout << "YES";
							key = GetKey();
							if(key == ENTER){
								
					for(int i = 0; i<DSLTC.soluong;i++){
			if(DSLTC.ds[i]->maLoptc==Lop[vitrilop]->maLoptc){
			for (PTRDK k = DSLTC.ds[i]->DSDK; k != NULL; k = k->next){	
			if (strcmp(k->data.mssv, sv.mssv) == 0&&k->data.huydk==true) {
					GhiChu("LTC DA BI HUY TRUOC DO!", 60, 29, 79, 1000);
							xoascreen();
							 goto XULY;
			}else{
				k->data.huydk=true;
				GhiFileDK(DSLTC);
					GhiChu("XOA THANH CONG LTC!", 60, 29, 79, 500);
					xoascreen();
				 goto XULY;
			}
		}	
	}		
}	
						}
							if(key == RIGHT){
								goto NO;
							}
						}
					NO:
						while(1){
							gotoxy(70,29);
							cout << "NO";
							key = GetKey();
							if(key == ENTER){
								GhiChu("KHONG THAY DOI THANH CONG LTC!", 60, 29, 79, 500);
								xoascreen();
								TimSV(lop,DSMH,DSLTC);
							}
							if(key == LEFT){
								goto YES;
							}
						}
			}
			if(key==ESC){
			xoascreen();
			chaymenusv();
		}
		}
}
}
/*=====================================================*/
/*=================    MON HOC  =======================*/
/*=====================================================*/
  void DKMon(ListLop& lop, PTRMH DSMH, DSloptc& DSLTC){
	int key,trang=0,tongtrang=0,dem=0,dong=0;
	int check_trung,vitrilop,vitriloptc;
	int soluongloptc=0;
	int vitri = 0, x = 43, y = 3;
	loptc* Lop[100];
	PTRMH mh;
	dangki sv;
	sv.mssv[0] = NULL;
	loptc Loptc;
	Loptc.nienkhoa[0]=NULL;Loptc.hocki[0]=NULL;
	PTRSV p;
	xoascreen();
	KhungDkLTC();
MASV:
	while(1){
		Color(250);	gotoxy(43, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 15";
		Color(12); gotoxy( x+vitri, y); //Ghi chú
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0')  || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			sv.mssv[vitri] = char(key);
			sv.mssv[vitri] = toupper(sv.mssv[vitri]);
			cout << sv.mssv[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(x + vitri, y);
			cout << " ";
			gotoxy(x + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.mssv[vitri] = '\0';
			vitrilop = Search_lop_MSV(lop,sv.mssv);
			if (vitrilop > -1) {
				p = Search_MSV(lop.ds[vitrilop].DSSV,sv.mssv);
				vitri = strlen(Loptc.nienkhoa);
				goto NIENKHOA;
			}else{
				GhiChu("Khong Trung Ma Sinh Vien. Nhap Lai!",60,28,79,500);
				continue;
			}
		}
		if(key==ESC){
			xoascreen();
			chaymenumh();
		}
	}
NIENKHOA:	
xoascreen();
	gotoxy(38,0);
	cout << "Lop: "<< lop.ds[vitrilop].malop << "  Ma SV: "<< p->data.mssv<< "  Ho Ten: "<< p->data.ho<<" "<<p->data.ten;
	gotoxy(80,2);
			cout<<"  Phai: "<<p->data.phai;
	gotoxy(80,4);
			cout<<"  SDT: "<< p->data.sdt;
	KhungDk_NKHK();
while(1){
	Color(250);	gotoxy(43, 4);
		cout << "Ki tu:  (0-9).    Toi da: 4";
		Color(12); gotoxy( x+vitri, y); //Ghi chú
		key = GetKey();
		if ( (key <= '9' && key >= '0')  && (vitri < 5))
		{
			Loptc.nienkhoa[vitri] = char(key);
			cout << Loptc.nienkhoa[vitri];
			vitri++;
		}
			if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(43 + vitri, y);
			cout << " ";
			gotoxy(43 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			Loptc.nienkhoa[vitri]='\0';
			if( checkNienKhoa(DSLTC,Loptc.nienkhoa)==-1){
				vitri = strlen(Loptc.hocki);
				goto HOCKI;
			}else{
				GhiChu("Khong Trung Nien Khoa. Nhap Lai!",60,28,79,500);
				continue;
			}
		}
		if(key==ESC){
			xoascreen();
			chaymenumh();
		}
	}
HOCKI:
	while(1){
		Color(250);	gotoxy(43, 4);
		cout << "Ki tu:  (0-9).    Toi da: 2";
		Color(12); gotoxy( 63+vitri, y); //Ghi chú
		key = GetKey();
		if ( (key <= '9' && key >= '0')  && (vitri < 2))
		{
			Loptc.hocki[vitri] = char(key);
			cout << Loptc.hocki[vitri];
			vitri++;
		}
			if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(63 + vitri, y);
			cout << " ";
			gotoxy(63 + vitri, y);
		}
			if (key == ENTER && vitri != 0)
		{
			Loptc.hocki[vitri]='\0';
			if(checkHK_NK(DSLTC,Loptc.hocki,Loptc.nienkhoa)==-1){
				goto XULY;
			}else{
				GhiChu("Khong Trung Nien Khoa. Nhap Lai!",60,28,79,500);
				continue;
			}
		}
		if(key==ESC){
			xoascreen();
			chaymenumh();
		}
	}
XULY:
	gotoxy(2,26);
	Color(3);
	cout	<<"*Color: LTC Da Duoc Dang Ki ";
	soluongloptc=mangLTC(DSLTC,Loptc.hocki,Loptc.nienkhoa,Lop);
	while(1){
		if (soluongloptc == 0)
		{
			GhiChu("Chua co Danh Sach Lop", 60, 28, 79, 1000);
		}
		else {
			if (soluongloptc < 18)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluongloptc - 1) / 18 + 1);
			}
		}
		KhungInDK();
		dem = 0;
		for (int i = trang * 18; i < 18 + trang * 18 && i < soluongloptc; i++)
		{
			Color(12); gotoxy(36, 8 + dem); cout << Lop[i]->maLoptc;
			if(Search_msvdk(Lop[i]->DSDK, sv.mssv) != NULL)Color(3);
			else Color(7);
			gotoxy(49, 8 + dem); cout << Lop[i]->mmh;
			mh=Search_MH(DSMH,Lop[i]->mmh);
			gotoxy(65, 8 + dem); cout <<mh->data.tmh;
			gotoxy(96, 8 + dem); cout <<  DemSVDK(Lop[i]->DSDK);
			gotoxy(104,8+dem);cout <<(atoi(Lop[i]->svMax)-DemSVDK(Lop[i]->DSDK));
			dem++;
		}
		HienThiTrang(trang + 1, tongtrang, 90, 26);
		while(1){
			gotoxy(37,8 + dong);
			key = GetKey(); //Bat Phim
			if(key == DOWN){
				if(dong < 17&&(dong<(soluongloptc-18*trang)-1)){
					gotoxy(37, 8 + ++dong);
				}else{
					if(trang < tongtrang - 1){
						trang++;
						dong = 0;
						break;
					}else if(trang == tongtrang - 1 && dong > (soluongloptc % 18)){
						trang = 0;
						dong = 0;
						break;
					}
				}
			}
			if(key == UP){
				if(dong > 0){
					gotoxy(37, 8 + --dong);
				}else{
					if(trang > 0){
						trang--;
						dong = 0;
						break;
					}else{
						trang = tongtrang - 1;
						dong = 0;
						break;
					}
				}
			}
			if (key == RIGHT) {
			 	if(trang < tongtrang - 1){
						trang++;
						dong = 0;
						break;
					}else{
						trang = 0;
						dong = 0;
						break;
				}
			}
			if (key == LEFT) {
			 	if(trang > 0){
						trang--;
						dong = 0;
						break;
					}else{
						trang = tongtrang - 1;
						dong = 0;
						break;
				}
			}
			if(key==ENTER){
				vitrilop=(trang*18)+dong;
				if (Search_msvdk(Lop[vitrilop]->DSDK, sv.mssv) != NULL) {
							GhiChu("SINH VIEN DA DANG KI LOP! KHONG DUOC DANG KI TIEP", 60, 28, 79, 2000);
							continue;
							}else{
								GhiChu("DANG KI THANH CONG", 60, 28, 79, 1000);
								vitriloptc = Search_malopTc(DSLTC,Lop[vitrilop]->maLoptc);
								Insert_NodeDk(DSLTC.ds[vitriloptc]->DSDK, sv);	
								GhiFileDK(DSLTC);
								xoascreen();
								DKMon(lop,DSMH,DSLTC);
							}				
			}
			if(key==ESC){
				xoascreen();
				DKMon(lop,DSMH,DSLTC);
			}
			
			
		}
	}
	
}
//
void ThemMonHoc(PTRMH &DSMH)
{
	nhacnhosv();
	int key, vitri = 0, x = 37, y = 3, check_trung;
	monhoc mh;	mh.mmh[0] = NULL;	mh.tmh[0] = NULL;	mh.stclt[0] = NULL;	mh.stcth[0] = NULL;
	Khung_Them_MonHoc(); gotoxy(x, y);
MAMH:
	while (1)
	{
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		Color(12); gotoxy(x + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			mh.mmh[vitri] = char(key);
			mh.mmh[vitri] = toupper(mh.mmh[vitri]);
			cout << mh.mmh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(x + vitri, y);
			cout << " ";
			gotoxy(x + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.mmh[vitri] = '\0';
			check_trung = KTMH(DSMH, mh.mmh);
			if (check_trung == 1) {
				Color(78);
					gotoxy(60, 28);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			vitri = strlen(mh.tmh);
			gotoxy(55 + vitri, y);
			goto TENMH;
		}
		if (key == RIGHT)
		{
			mh.mmh[vitri] = '\0';
			check_trung = KTMH(DSMH, mh.mmh);
			if (check_trung == 1) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,78,500);
			}
			vitri = strlen(mh.tmh);
			gotoxy(55 + vitri, y);
			goto TENMH;
		}
		if (key == ESC ) { 
		xoascreen();
		chaymenumh(); }
	}
TENMH:
	while (1)
	{
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 35";
		Color(12); gotoxy(55 + vitri, y); //Ghi chú
		key = GetKey();
		if (mh.mmh[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Mon Hoc!", 60, 28, 250, 700);
			gotoxy(x, y);
			goto MAMH;
		}
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			mh.tmh[vitri] = char(key);
			mh.tmh[vitri] = toupper(mh.tmh[vitri]);
			cout << mh.tmh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(55 + vitri, y);
			cout << " ";
			gotoxy(55 + vitri, y);
		}
		if (key == SPACE && mh.tmh[vitri - 1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{
			gotoxy(55 + vitri, y);
			cout << " ";
			mh.tmh[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (mh.tmh[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.tmh[vitri] = '\0';
			vitri = strlen(mh.stclt);
			gotoxy(92 + vitri, y);
			goto STCLT;
		}
		if (key == LEFT)
		{
			mh.tmh[vitri] = '\0';
			vitri = strlen(mh.mmh);
			gotoxy(x + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT)
		{
			if (mh.tmh[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.tmh[vitri] = '\0';
			vitri = strlen(mh.stclt);
			gotoxy(92 + vitri, y);
			goto STCLT;
		}
		if (key == ESC ) { 
		xoascreen();
		chaymenumh(); }
	}
STCLT:
	while (1)
	{
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (0-9). Toi da: 3         ";
		Color(12); gotoxy(92 + vitri, y); // Ghi chú
		key = GetKey();
		if (mh.tmh[0] == '\0')
		{
			GhiChu("Ban Chua Nhap TEN Mon Hoc!", 60, 28, 250, 700);
			gotoxy(55, y);
			goto TENMH;
		}
		if ((key <= '9' && key >= '0') && (vitri < 2))
		{
			mh.stclt[vitri] = char(key);
			mh.stclt[vitri] = toupper(mh.stclt[vitri]);
			cout << mh.stclt[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(92 + vitri, y);
			cout << " ";
			gotoxy(92 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.stclt[vitri] = '\0';
			vitri = strlen(mh.stcth);
			gotoxy(100 + vitri, y);
			goto STCTH;
		}
		if (key == LEFT)
		{
			mh.stclt[vitri] = '\0';
			vitri = strlen(mh.tmh);
			gotoxy(55 + vitri, y);
			goto TENMH;
		}
		if (key == RIGHT && vitri != 0)
		{
			mh.stclt[vitri] = '\0';
			vitri = strlen(mh.stcth);
			gotoxy(100 + vitri, y);
			goto STCTH;
		}
		if (key == ESC ) { 
		xoascreen();
		chaymenumh(); }
	}
STCTH:
	while (1)
	{
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (0-9). Toi da: 2         ";
		Color(12); gotoxy(100 + vitri, y); // Ghi chú
		key = GetKey();
		if (mh.stclt[0] == '\0')
		{
			GhiChu("Ban Chua Nhap STCLT Mon Hoc!", 60, 28, 250, 700);
			gotoxy(92, y);
			goto STCLT;
		}
		if ((key <= '9' && key >= '0') && (vitri < 2))
		{
			mh.stcth[vitri] = char(key);
			mh.stcth[vitri] = toupper(mh.stcth[vitri]);
			cout << mh.stcth[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(100 + vitri, y);
			cout << " ";
			gotoxy(100 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.stcth[vitri] = '\0';
			DSMH = InsertMH(DSMH, mh);
			GhiFileMH(DSMH);
			GhiChu("Them Thanh Cong", 60, 28, 250, 1000);
			return;
		}
		if (key == LEFT)
		{
			mh.stcth[vitri] = '\0';
			vitri = strlen(mh.stclt);
			gotoxy(92 + vitri, y);
			goto STCLT;
		}
		if (key == ESC ) { 
		xoascreen();
		chaymenumh(); }
	}
}
//=====sua mh
void SuaMonHoc(DSloptc& DSLTC,PTRMH &DSMH){
	int key, vitri = 0, x = 43, y = 3, check_trung;
	PTRMH p;
	char tam[11]; //de luu ma mon nhap vao
	monhoc mh;	mh.mmh[0] = NULL;	mh.tmh[0] = NULL;	mh.stclt[0] = NULL;	mh.stcth[0] = NULL;
	Khung_Sua_MonHoc(); gotoxy(x, y);
	while(1){
		Color(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 15))
		{
			mh.mmh[vitri] = char(key);
			mh.mmh[vitri] = toupper(mh.mmh[vitri]);
			cout << mh.mmh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(x + vitri, y);
			cout << " ";
			gotoxy(x + vitri, y);
		}
		if (key == ENTER && vitri != 0){
			mh.mmh[vitri] = '\0';	//Ngat chuoi~
			strcpy(tam, mh.mmh);
			check_trung = KTMH(DSMH, mh.mmh); 
		if (check_trung == 1)
			{
				vitri = 0;
				p = Search_MH(DSMH, mh.mmh);
				Khung_Them_MonHoc();
				x = 37, y = 3;
				gotoxy(x, y);
				Color(4);
				strcpy(mh.mmh, p->data.mmh);
				strcpy(mh.tmh, p->data.tmh);
				strcpy(mh.stclt, p->data.stclt);
				strcpy(mh.stcth, p->data.stcth);
				gotoxy(x, y); cout << mh.mmh;
				gotoxy(x+18, y); cout << mh.tmh;
				gotoxy(x+55, y); cout << mh.stclt;
				gotoxy(x+63, y); cout << mh.stcth;
				vitri = strlen(mh.mmh);
				goto MAMH;
				break;
			}
			else {
				GhiChu("Ma Mon Hoc Khong Ton Tai!", 60, 28, 79, 500);	Color(12);	gotoxy(39 + vitri, y);
			}
	}
		if (key == ESC || key == F2) { 
		xoascreen();
		XemMonHoc(DSLTC,DSMH,2); }
}
MAMH:
	while (1)
	{
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		Color(12); gotoxy(x + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			mh.mmh[vitri] = char(key);
			mh.mmh[vitri] = toupper(mh.mmh[vitri]);
			cout << mh.mmh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(x + vitri, y);
			cout << " ";
			gotoxy(x + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.mmh[vitri] = '\0';
			check_trung = KTMH(DSMH, mh.mmh);
			if (check_trung == 1) {
				Color(78);
					gotoxy(60, 28);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			vitri = strlen(mh.tmh);
			gotoxy(55 + vitri, y);
			goto TENMH;
		}
		if (key == RIGHT)
		{
			mh.mmh[vitri] = '\0';
			check_trung = KTMH(DSMH, mh.mmh);
			if (check_trung == 1) {
				GhiChu("Trung Ma Mon Hoc. Nhap Lai!",60,28,78,500);
			}
			vitri = strlen(mh.tmh);
			gotoxy(55 + vitri, y);
			goto TENMH;
		}
		if (key == ESC || key == F1) { chaymenumh(); }
	}
TENMH:
	while (1)
	{
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 35";
		Color(12); gotoxy(55 + vitri, y); //Ghi chú
		key = GetKey();
		if (mh.mmh[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Mon Hoc!", 60, 28, 250, 700);
			gotoxy(x, y);
			goto MAMH;
		}
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			mh.tmh[vitri] = char(key);
			mh.tmh[vitri] = toupper(mh.tmh[vitri]);
			cout << mh.tmh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(55 + vitri, y);
			cout << " ";
			gotoxy(55 + vitri, y);
		}
		if (key == SPACE && mh.tmh[vitri - 1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{
			gotoxy(55 + vitri, y);
			cout << " ";
			mh.tmh[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (mh.tmh[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.tmh[vitri] = '\0';
			vitri = strlen(mh.stclt);
			gotoxy(92 + vitri, y);
			goto STCLT;
		}
		if (key == LEFT)
		{
			mh.tmh[vitri] = '\0';
			vitri = strlen(mh.mmh);
			gotoxy(x + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT)
		{
			if (mh.tmh[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.tmh[vitri] = '\0';
			vitri = strlen(mh.stclt);
			gotoxy(92 + vitri, y);
			goto STCLT;
		}
		if (key == ESC || key == F1) { XemMonHoc(DSLTC,DSMH,2); }
	}
STCLT:
	while (1)
	{
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (0-9). Toi da: 3         ";
		Color(12); gotoxy(92 + vitri, y); // Ghi chú
		key = GetKey();
		if (mh.tmh[0] == '\0')
		{
			GhiChu("Ban Chua Nhap TEN Mon Hoc!", 60, 28, 250, 700);
			gotoxy(55, y);
			goto TENMH;
		}
		if ((key <= '9' && key >= '0') && (vitri < 2))
		{
			mh.stclt[vitri] = char(key);
			mh.stclt[vitri] = toupper(mh.stclt[vitri]);
			cout << mh.stclt[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(92 + vitri, y);
			cout << " ";
			gotoxy(92 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.stclt[vitri] = '\0';
			vitri = strlen(mh.stcth);
			gotoxy(100 + vitri, y);
			goto STCTH;
		}
		if (key == LEFT)
		{
			mh.stclt[vitri] = '\0';
			vitri = strlen(mh.tmh);
			gotoxy(55 + vitri, y);
			goto TENMH;
		}
		if (key == RIGHT && vitri != 0)
		{
			mh.stclt[vitri] = '\0';
			vitri = strlen(mh.stcth);
			gotoxy(100 + vitri, y);
			goto STCTH;
		}
		if (key == ESC || key == F1) { chaymenumh(); }
	}
STCTH:
	while (1)
	{
		Color(250);	gotoxy(35, 4);
		cout << "Ki tu: (0-9). Toi da: 2         ";
		Color(12); gotoxy(100 + vitri, y); // Ghi chú
		key = GetKey();
		if (mh.stclt[0] == '\0')
		{
			GhiChu("Ban Chua Nhap STCLT Mon Hoc!", 60, 28, 250, 700);
			gotoxy(92, y);
			goto STCLT;
		}
		if ((key <= '9' && key >= '0') && (vitri < 2))
		{
			mh.stcth[vitri] = char(key);
			mh.stcth[vitri] = toupper(mh.stcth[vitri]);
			cout << mh.stcth[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(100 + vitri, y);
			cout << " ";
			gotoxy(100 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.stcth[vitri] = '\0';
			for (int i = 0; i < DSLTC.soluong; i++) {
				if (strcmp(DSLTC.ds[i]->mmh, p->data.mmh) == 0) {
					strcpy(DSLTC.ds[i]->mmh, mh.mmh);
				}
			}
			p->data = mh;
			GhiFileMH(DSMH);
			GhiChu("Lop hoc da duoc cap nhat!", 60, 28, 79, 700);
			xoascreen();
			XemMonHoc(DSLTC,DSMH,2);
		}
		if (key == LEFT)
		{
			mh.stcth[vitri] = '\0';
			vitri = strlen(mh.stclt);
			gotoxy(92 + vitri, y);
			goto STCLT;
		}
		if (key == ESC || key == F2) { 
		xoascreen();
		XemMonHoc(DSLTC,DSMH,2); }
	}
}
//
void XoaMonHoc(DSloptc &DSLTC , PTRMH &DSMH)
{
	int key, x = 43, y = 3, vitri = 0;
	monhoc mh;	mh.mmh[0] = NULL;
	Khung_Xoa_MonHoc();	gotoxy(x, y);
	while (1)
	{
		Color(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 15))
		{
			mh.mmh[vitri] = char(key);
			mh.mmh[vitri] = toupper(mh.mmh[vitri]);
			cout << mh.mmh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(x + vitri, y);
			cout << " ";
			gotoxy(x + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.mmh[vitri] = '\0';	//Ngat chuoi~
			int temp1 = KTMH(DSMH, mh.mmh);// kiem tra mon hoc co ton tai khong
			if (temp1 != 0) //ton tai
			{
					PTRMH p;
					p = Search_MH(DSMH,mh.mmh);
					Khung_Them_MonHoc();
					Color(4);
					strcpy(mh.mmh, p->data.mmh);
					strcpy(mh.tmh, p->data.tmh);
					strcpy(mh.stclt, p->data.stclt);
					strcpy(mh.stcth, p->data.stcth);
					gotoxy(37, 3); cout << mh.mmh;
					gotoxy(37+18, 3); cout << mh.tmh;
					gotoxy(37+55, 3); cout << mh.stclt;
					gotoxy(37 + 63, 3); cout << mh.stcth;
					
					int temp2 = Search_MH_LTC(DSLTC, mh.mmh);// kiem tra da mo lop tin chi chua
				if (temp2 == -1) { // chua mo -> xoa
					gotoxy(50,28); Color(4);
					cout << "BAN CO MUON XOA MON HOC NAY KHONG ???";
					gotoxy(55,29); cout << "YES";
					gotoxy(70,29); cout << "NO";
					YES1: 
						while(1){
							gotoxy(55,29);
							cout << "YES";
							key = GetKey();
							if(key == ENTER){
								DSMH = xoa_node_MH(DSMH,mh.mmh);
								GhiFileMH(DSMH);
								GhiChu("XOA THANH CONG MON HOC!", 60, 29, 79, 500);
								xoascreen();
								XemMonHoc(DSLTC,DSMH,2);
							}
							if(key == RIGHT){
								goto NO1;
							}
						}
					NO1:
						while(1){
							gotoxy(70,29);
							cout << "NO";
							key = GetKey();
							if(key == ENTER){
								GhiChu("KHONG XOA THANH CONG MON HOC!", 60, 29, 79, 500);
								xoascreen();
								XemMonHoc(DSLTC,DSMH,2);
							}
							if(key == LEFT){
								goto YES1;
							}
						}	
					}else { //da mo
					int dem = 0;
					for (int i = 0; i < DSLTC.soluong; i++) {
						dem++;
						if (strcmp(DSLTC.ds[i]->mmh, mh.mmh) == 0) {
							if (DSLTC.ds[i]->DSDK != NULL) {
								GhiChu("Mon Hoc da co danh sach dang ki khong the Xoa!", 50, 29, 79, 500); 
								xoascreen();
								XemMonHoc(DSLTC,DSMH,2);
							}
						}
					}
					if (dem == DSLTC.soluong) {
					gotoxy(50,28); Color(4);
					cout << "BAN CO MUON XOA MON HOC NAY KHONG ???";
					gotoxy(55,29); cout << "YES";
					gotoxy(70,29); cout << "NO";
					YES2: 
						while(1){
							gotoxy(55,29);
							cout << "YES";
							key = GetKey();
							if(key == ENTER){
								while (temp2 != -1) {
							DeleteLTC(DSLTC, temp2);
							temp2 = Search_MH_LTC(DSLTC, mh.mmh);
						}
								DSMH = xoa_node_MH(DSMH,mh.mmh);
								GhiFileMH(DSMH);
								GhiChu("XOA THANH CONG MON HOC!", 60, 29, 79, 500);
								xoascreen();
								XemMonHoc(DSLTC,DSMH,2);
							}
							if(key == RIGHT){
								goto NO2;
							}
						}
					NO2:
						while(1){
							gotoxy(70,29);
							cout << "NO";
							key = GetKey();
							if(key == ENTER){
								GhiChu("KHONG XOA THANH CONG MON HOC!", 60, 29, 79, 500);
								xoascreen();
								XemMonHoc(DSLTC,DSMH,2);
							}
							if(key == LEFT){
								goto YES2;
							}
						}	
					}			
			}
		}
			else {
			GhiChu("Ma Mon Hoc Khong Ton Tai!", 60, 28, 79, 500);
				Color(14);
				gotoxy(39 + vitri, y);
			}
	 }

	if (key == ESC || key == F3) {
		xoascreen();
		XemMonHoc(DSLTC,DSMH,2);
		}
 }
}
void XemMonHoc(DSloptc& DSLTC, PTRMH& DSMH, int chedoxem) { // 1 xem,  != 1 xuli
	int key;
	int  trang = 0, tongtrang = 0;
	int soluongmh, dem = 0, demdong = 0, iy =7;
	while (1)
	{
		soluongmh = DemMonHoc(DSMH);
		if (soluongmh == 0)
		{
			GhiChu("Chua co du lieu Mon Hoc", 60, 28, 79, 3000);
		}
		else {
			if (soluongmh < 18)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluongmh - 1) / 18 + 1);
			}
		}
		monhoc* MH = new monhoc[soluongmh + 1];
		MangTam_MonHoc(DSMH, MH, dem); //Dua Cay Nhi Phan ra Mang
		Sort_MangMH(MH, dem);
		dem = 0; demdong = 0;
		//xoascreen();
		khunginMH();
		for (int i = trang * 18; i < 18 + trang * 18 && i < soluongmh; i++)
		{
			Color(7); gotoxy(37, 8 + demdong); cout << (i + 1);
			gotoxy(44, 8 + demdong); cout << MH[i].mmh;
			gotoxy(58, 8 + demdong); cout << MH[i].tmh;
			gotoxy(99, 8 + demdong); cout << MH[i].stclt;
			gotoxy(107, 8 + demdong); cout << MH[i].stcth;
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 90, 26);
		if (chedoxem == 1)//Dang o che do xem
		{
			gotoxy(31, 0); cout << "                     DANG O CHE DO XEM MON HOC!                      ";
			nhacnhosv();
			}else 	nhacnhomh();
		gotoxy(98,26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == F1 && chedoxem == 2)
		{
			ThemMonHoc(DSMH);
		}
		if (key == F2 && chedoxem == 2)
		{
			SuaMonHoc(DSLTC, DSMH);
		}
		if (key == F3 && chedoxem == 2)
		{
			XoaMonHoc(DSLTC, DSMH);
		}
		if(key == F1 && chedoxem == 3){
			gotoxy(49,3);
			break;
		}
		if (key == ESC && (chedoxem==1||chedoxem==2))
		{
			xoascreen();
			chaymenumh();
		}
	}
}
//
/*=====================================================*/
/*=================    DIEM     =======================*/
/*=====================================================*/
void  XemDSLTC_DK(DSloptc &DSLTC, PTRMH DSMH, int chedoxem, int &vitriMang){
	int key;
	int dem = 0, trang = 0, tongtrang = 0, dong = 0;
	while(1){
		if (0 == DSLTC.soluong) {
			GhiChu("Chua co danh sach lop", 60, 28, 79, 1000);
		}
		else {
			if (DSLTC.soluong < 18) {
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((DSLTC.soluong - 1) / 158 + 1);
			}
		}
		SortDSLTC(DSLTC);
		xoascreen();
		khunginLTC();
		dem=0;
			for (int i = trang * 18; i < 18 + trang * 18 && i < DSLTC.soluong; i++)
		{
			Color(7); gotoxy(37, 8 + dem); cout << (i + 1);
			gotoxy(44,8+dem);cout << DSLTC.ds[i]->maLoptc;
			gotoxy(57,8+dem);cout << DSLTC.ds[i]->mmh;
			gotoxy(70,8+dem);cout << DSLTC.ds[i]->nienkhoa;
			gotoxy(82,8+dem);cout << DSLTC.ds[i]->hocki;
			gotoxy(90,8+dem);cout << DSLTC.ds[i]->nhom;
			gotoxy(97,8+dem);cout << DSLTC.ds[i]->svMax;
			gotoxy(106,8+dem);cout << DSLTC.ds[i]->svMin;
			dem++;
		}
		HienThiTrang(trang + 1, tongtrang, 90, 26);
		while(1){
				gotoxy(37, 8 + dong);
			key = GetKey(); //Bat Phim
			if (key == DOWN){
				if (dong < 17&&(dong<(DSLTC.soluong-trang*18)-1)) { //
					gotoxy(37, 8 + ++dong);
				}else{
					if (trang < tongtrang - 1) {
						trang++;
						dong = 0;
						break;
					}
					else if (trang == tongtrang - 1 && dong > (DSLTC.soluong%18)) {
						trang = 0;
						dong = 0;
						break;
					}
				}
		}
		if(key==UP){
			if (dong > 0) {
					gotoxy(37, 8 + --dong);
				}
				else {
					if (trang > 0) {
						trang--;
						dong = 0;
						break;
					}
					else {
						trang = tongtrang - 1;
						dong = 0;
						break;
					}
				}
		}
		if (key == RIGHT) {
				if (trang < tongtrang - 1) {
					trang++;
					dong = 0;
					break;
				}
				else {
					trang = 0;
					dong = 0;
					break;
				}
			}
		if (key == LEFT) {
				if (trang > 0) {
					trang--;
					dong = 0;
					break;
				}
				else {
					trang = tongtrang - 1;
					dong = 0;
					break;
				}
			}
		if(key == ENTER){
					vitriMang = trang * 18 + dong;
					return;
				}
		if(key== ESC){
			xoascreen();
			chaymenudiem();
		}
		}//while2
	}//while1
		
}
void NhapSuaDiem(DSloptc &DSLTC, ListLop lop, PTRMH DSMH,int chedoxem){
	nhacnhosv();
	int key;
	int  y =8;
	int vitri = 0, vitriMang, temp;
	int STT = 1;
	XemDSLTC_DK(DSLTC,DSMH,0,vitriMang);
	int trang = 0, tongtrang = 0, soluongsv = 0;
	int dem1 = 0, dem2 = 0, dem = 0;	//dem la dem dong`.  dem1 la vitri phan tu sv. dem2 dem diem
	soluongsv = DemSVDK(DSLTC.ds[vitriMang]->DSDK);
	if (soluongsv == 0)
	{
		GhiChu("Chua co du lieu sinh vien", 60, 28, 79, 500);
		xoascreen();
		NhapSuaDiem(DSLTC,lop,DSMH,chedoxem);
	}else {
		if (soluongsv < 18)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongsv - 1) / 18 + 1);
		}
	}
	int ktrasv;
		PTRSV svdk;
		sinhvien* SV = new sinhvien[soluongsv + 1]; // chua thong tin sinh vien
		dangki* Diem = new dangki[soluongsv + 1]; // chua diem cua sinh vien

	for (PTRDK p = DSLTC.ds[vitriMang]->DSDK; p != NULL; p = p->next) {
		svdk = Search_MSV_DSLOP(lop, p->data.mssv);// truy xuat den danh sach lop tim thong tin sinh vien
		SV[dem1] = svdk->data; //tim duoc thong tin chua vao mang thong tin sinh vien
		dem1++;
	}
	Sort_MangSV(SV, dem1);
	for (int i = 0; i < dem1; i++) {
		for (PTRDK p = DSLTC.ds[vitriMang]->DSDK; p != NULL; p = p->next) {
			if (strcmp(p->data.mssv, SV[i].mssv) == 0) {
				strcpy(Diem[i].diem, p->data.diem);
			}
		}
	}
	vitri = strlen(Diem[0].diem);	
Reset:
	xoascreen();	
		gotoxy(40,0);
		Color(3);
		cout <<"Ma LTC:  " <<DSLTC.ds[vitriMang]->maLoptc<<"   Ma Mon: "<< DSLTC.ds[vitriMang]->mmh<<"   Nien Khoa: "<<DSLTC.ds[vitriMang]->nienkhoa
				<<"   Hoc Ki:  "<< DSLTC.ds[vitriMang]->hocki<<"   Nhom: "<<DSLTC.ds[vitriMang]->nhom;
		KhungNhapDiem();
		dem = 0;
	for (int i = trang * 18; i < 18 + trang * 18 && i < soluongsv; i++)
		{
			Color(12); gotoxy(37, 8 + dem); cout << i + 1;
			Color(7);
			gotoxy(45, 8 + dem); cout << SV[i].mssv;
			gotoxy(62, 8 + dem); cout << SV[i].ho;
			gotoxy(77, 8 + dem); cout << SV[i].ten;
			gotoxy(106, 8 + dem); cout << Diem[i].diem;
			dem++;
		}
			HienThiTrang(trang + 1, tongtrang, 90, 26);
		while(1){
		if(chedoxem==1){
					gotoxy(106 + vitri, y);
			}else{
				gotoxy(98,26);
			}
			key = GetKey();
				if (((key <= '9' && key >= '0') || key == '.') && (vitri < 3)&& chedoxem==1)
			{
				Diem[dem2].diem[vitri] = char(key);
				cout << Diem[dem2].diem[vitri];
				vitri++;
			}
		if (key == ENTER && dem2 < dem1 && chedoxem==1)
			{
				Diem[dem2].diem[vitri] = '\0';
				if (atoi(Diem[dem2].diem) > 10 || Diem[dem2].diem[0] == '.' || Diem[dem2].diem[2] == '.')
				{
					GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""", 50, 28, 74, 500);	continue;
				}
				if (vitri > 0) { GhiChu("Save Thanh Cong!", 60, 28, 79, 300); Color(7); }
				dem2++;
				vitri = strlen(Diem[dem2].diem);
				if (dem2 % 18 == 0)
				{
					trang++;
					y = 8;
					goto Reset;
				}
				if (dem2 == dem1) {
					continue;
				}
				gotoxy(106 + vitri, ++y);
			}
				if (key == BACKSPACE && vitri > 0&& chedoxem==1)
			{
				vitri--;
				gotoxy(106 + vitri, y);
				cout << " ";
				gotoxy(106 + vitri, y);
			}
				if ((key == RIGHT) && trang < tongtrang - 1)
			{
				Diem[dem2].diem[vitri] = '\0';
				if (atoi(Diem[dem2].diem) > 10 || Diem[dem2].diem[0] == '.' || Diem[dem2].diem[2] == '.')
				{
					GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""", 50, 28, 79, 500);	continue;
				}
				trang++;
				dem2 += 18;
				if (dem2 > soluongsv) //Neu lat qua trang va vuot qua so luong sinh vien
				{
					dem2 = soluongsv - 1;
					y = dem2 % 18 + 8;
				}
				vitri = strlen(Diem[dem2].diem);
				goto Reset;
			}
					if ((key == LEFT) && trang > 0)
				{
				Diem[dem2].diem[vitri] = '\0';
				if (atoi(Diem[dem2].diem) > 10 || Diem[dem2].diem[0] == '.' || Diem[dem2].diem[2] == '.')
				{
					GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""", 50, 28, 74, 500);	continue;
				}
				trang--;
				dem2 -= 18;
				vitri = strlen(Diem[dem2].diem);
				goto Reset;
			}
			if (key == UP && y > 8&& chedoxem==1)
			{
				Diem[dem2].diem[vitri] = '\0';
				if (atoi(Diem[dem2].diem) > 10 || Diem[dem2].diem[0] == '.' || Diem[dem2].diem[2] == '.')
				{
					GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""", 50, 28, 79, 500);	continue;
				}
				dem2--;
				vitri = strlen(Diem[dem2].diem);
				gotoxy(106 + vitri, --y);
			}
			if (key == DOWN && y < 25 && dem2 < dem1 - 1&& chedoxem==1)
			{
				Diem[dem2].diem[vitri] = '\0';
				if (atoi(Diem[dem2].diem) > 10 || Diem[dem2].diem[0] == '.' || Diem[dem2].diem[2] == '.')
				{
					GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""", 50, 28, 79, 500);	continue;
				}
				dem2++;
				vitri = strlen(Diem[dem2].diem);
				gotoxy(106 + vitri, ++y);
			}
			if(key==ESC&& chedoxem==1){
				Diem[dem2].diem[vitri] = '\0';
				putchar(7);
				gotoxy(50,28); Color(4);
					cout << "BAN CO MUON LUU DIEM NAY KHONG ???";
					gotoxy(55,29); cout << "YES";
					gotoxy(70,29); cout << "NO";
					YES: 
						while(1){
							gotoxy(55,29);
							cout << "YES";
							key = GetKey();
							if(key == ENTER){
						for (PTRDK p = DSLTC.ds[vitriMang]->DSDK; p != NULL; p = p->next) {
						for (int i = 0; i < dem1; i++) {
							if (strcmp(p->data.mssv, SV[i].mssv) == 0) {
								strcpy(p->data.diem, Diem[i].diem);
							}
						}
					}
					GhiChu("Luu Vao File Thanh Cong!", 60, 28, 79, 2000);
					GhiFileDK(DSLTC); GhiFileDSLTC(DSLTC);
					delete(SV); delete(Diem); xoascreen();	return;
							}
							if(key == RIGHT){
								goto NO;
							}
						}
					NO:
						while(1){
							gotoxy(70,29);
							cout << "NO";
							key = GetKey();
							if(key == ENTER){
					GhiChu("Luu Vao File Khong Thanh Cong!", 60, 28, 79, 2000);
					delete(SV); delete(Diem); xoascreen();	return;
							}
							if(key == LEFT){
								goto YES;
							}
						}	
				
			}
			if(key==ESC&&chedoxem==2){
				xoascreen();
				NhapSuaDiem(DSLTC,lop,DSMH,2);
			}
		}
}
void XemDiemLop(DSloptc &DSLTC, ListLop lop, PTRMH DSMH,int vitriMang){
	int key;
	int x = 40, y = 2;
	int vitri = 0,  temp;
	int STT = 1;
	int trang = 0, tongtrang = 0, soluongsv = 0;
	int dem1 = 0, dem2 = 0, dem = 0;	//dem la dem dong`.  dem1 tong so phan tu. dem2 dem diem
										//NHAP DIEM

	dem1 = 0;
	soluongsv = DemSinhVien(lop.ds[vitriMang].DSSV);
	if (soluongsv == 0)
	{
		GhiChu("Chua co du lieu sinh vien", 60, 28, 79, 500);
		chaymenudiem();
	}
	else {
		if (soluongsv < 18)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongsv - 1) / 18 + 1);
		}
	}
	PTRSV svdk;
	sinhvien* SV = new sinhvien[soluongsv + 1]; // chua thong tin sinh vien
	for (PTRSV p = lop.ds[vitriMang].DSSV; p != NULL; p = p->next) {
		svdk = Search_MSV_DSLOP(lop, p->data.mssv);// truy xuat den danh sach lop tim thong tin sinh vien
		SV[dem1] = svdk->data; //tim duoc thong tin chua vao mang thong tin sinh vien
		dem1++;
	}	
		Sort_MangSV(SV, dem1);
	float diem[100];
	for (int i = 0; i < dem1; i++) {
		float tongdiem = 0; int tongtinchi = 0;
		for (int j = 0; j < DSLTC.soluong; j++) {
			for (PTRDK p = DSLTC.ds[j]->DSDK; p != NULL; p = p->next) {
				if (p->data.huydk==0&&(strcmp(SV[i].mssv, p->data.mssv) == 0)) {
					PTRMH temp; //cai nay de tim mon hoc roi suy ra so tin chi
					temp = Search_MH(DSMH, DSLTC.ds[j]->mmh);
					tongtinchi = tongtinchi + atoi(temp->data.stclt) + atoi(temp->data.stcth);
					if (p->data.diem != NULL) {
						tongdiem = tongdiem + atof(p->data.diem)*(atoi(temp->data.stclt) + atoi(temp->data.stcth));
					}
					else {
						tongdiem = tongdiem + 0;
					}
				}
			}
		}
		diem[i] = tongdiem / tongtinchi;
	}
	y=8;
	while(1){
		xoascreen();
		KhungNhapDiem();
		dem = 0;
		for (int i = trang * 18; i < 18 + trang * 18 && i < soluongsv; i++)
		{
			Color(12); gotoxy(37, 8 + dem); cout << i + 1;
			Color(7);
			gotoxy(45, 8 + dem); cout << SV[i].mssv;
			gotoxy(62, 8 + dem); cout << SV[i].ho;
			gotoxy(77, 8 + dem); cout << SV[i].ten;
			if (diem[i] > 0) {
				gotoxy(106, 8 + dem); printf("%.1f", diem[i]);
			}
			else {
				gotoxy(106, 8 + dem); cout << "0";
			}
			dem++;
		}
		Color(3);
		gotoxy(55,0);
		cout<<"BANG THONG KE DIEM TRUNG BINH KHOA HOC";
		gotoxy(x, 1); cout << "MA lOP:";
		Color(7);
		gotoxy(x+12, 1); cout << lop.ds[vitriMang].malop;
		HienThiTrang(trang + 1, tongtrang, 90, 26);
		gotoxy(98, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == ESC)
		{
			xoascreen();	delete(SV); chaymenudiem();
		}
		
	}
}
void DiemTKet(ListLop &lop, PTRMH DSMH,DSloptc DSLTC,int vitriMang){
	int key;
	int x = 40, y = 2;
	int vitri = 0, temp;
	int STT = 1, dong = 0, vitrisv;
	int trang = 0, tongtrang = 0, soluongsv = 0;
	int dem1 = 0, dem = 0, demMH = 0,soluongmh, demMon = 0;
	
dem1 = 0;
	soluongsv = DemSinhVien(lop.ds[vitriMang].DSSV);
	if (soluongsv == 0)
	{
		GhiChu("Chua co du lieu sinh vien", 60, 28, 79, 500);
		chaymenudiem();
	}
	else {
		if (soluongsv < 18)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongsv - 1) / 18 + 1);
		}
	}
		sinhvien *SV = new sinhvien[soluongsv + 1];
		for (PTRSV p = lop.ds[vitriMang].DSSV; p != NULL; p = p->next)
		{
			SV[dem1] = p->data;
			dem1++;
		} //Dô? DSSV vào mang?
		
		// do cay mon hoc vao mang
		monhoc *MH = new monhoc[10000 + 1];
		MangTam_MonHoc(DSMH, MH, demMH);
		//Sort_MangMH(MH, demMH);
		soluongmh = DemMonHoc(DSMH);
		while(1){
			xoascreen();
			KhungTongKet();
			gotoxy(88, 6); cout << MH[demMon].mmh;
			gotoxy(96, 6); cout << MH[demMon+1].mmh;
			gotoxy(105, 6); cout << MH[demMon+2].mmh;
			gotoxy(65,0);
			cout <<"BANG DIEM TONG KET";
			gotoxy(40,1);
			cout<<  "MA lOP   :"<< lop.ds[vitriMang].malop << "    TEN LOP:   "	<<	lop.ds[vitriMang].tenlop<< "    NIEN KHOA:  "<< lop.ds[vitriMang].nienkhoa;
			dem=0;
			for (int i = trang * 18; i < 18 + trang * 18 && i < soluongsv; i++){
				Color(12); gotoxy(37, 8 + dem); cout << i + 1;
			Color(7);
			gotoxy(45, 8 + dem); cout << SV[i].mssv;
			gotoxy(57, 8 + dem); cout << SV[i].ho;
			gotoxy(68, 8 + dem); cout << SV[i].ten;
			SortLTC_Nam(DSLTC);
			for (int k = 0; k < DSLTC.soluong; k++) {
				char mmh[11];
				for (PTRDK p = DSLTC.ds[k]->DSDK; p != NULL; p = p->next) {
					if (strcmp(SV[i].mssv, p->data.mssv) == 0&&(p->data.huydk==0)) {
						strcpy(mmh, DSLTC.ds[k]->mmh);
							if((strcmp(mmh, MH[demMon].mmh) == 0)&&p->data.huydk==0){
								gotoxy(88, 8+ dem); cout << p->data.diem;
							}
							if((strcmp(mmh, MH[demMon + 1].mmh) == 0)&&p->data.huydk==0){
								gotoxy(96, 8+ dem); cout << p->data.diem;
							}
							if((strcmp(mmh, MH[demMon + 2].mmh) == 0)&&p->data.huydk==0){
								gotoxy(106, 8+ dem); cout << p->data.diem;
							}
						}
					}
					}
				dem++;
				HienThiTrang(trang + 1, tongtrang, 90, 26);
				gotoxy(96,26);
			}
			SortDSLTC(DSLTC);
			key = GetKey();
			if (key == DOWN && trang < tongtrang - 1) { trang++; }
			if (key == UP && trang > 0) { trang--; }
			if(key == LEFT && demMon >= 3){
				demMon -= 3;
			}
			if(key == RIGHT && demMon < demMH - 3){
				demMon += 3;
			}
			if (key == ESC)
			{
			xoascreen(); XemLop(lop,DSMH,DSLTC,5);
			}
		}	
}
		
/*=====================================================*/
/*=================    OPERATE  =======================*/
/*=====================================================*/
void chaymenultc(){    // lop tin chi
char menu[4][25]={ //index 1
	"BO SUNG LOP TC",
	"XOA/SUA",
	"TU DONG XOA LTC",
	"IN RA",
};
	char key;
	xoascreen();
	nhacnhomenu();
		menuchinh(menu);
		int iy=yMenu1,i_text=0;
		gotoxy(xMenu,iy);
	   	boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
	while(true){
		key = GetKey();
	  switch(key){
	   	case UP:
		case DOWN:
			updown(key,menu,iy,i_text);
			break;	   
			case ENTER:
				switch(iy){
				case yMenu1:    //nhap ltc
				ThemLTC(DSLTC,MH);
				xoascreen();
					break;
				case  yMenu1 + distance:
					XemLTC(DSLTC,MH,2);
					break;
				case yMenu1 + (2*distance):
					AutoXoaLTC(DSLTC);
					break;
				case yMenu1 + (3*distance):
					XemLTC(DSLTC,MH,1);
					break;
			}
			break;
			
			case ESC:
					chaymenu(mainMENU);
				break;
	   }
	}
}
/*=====================================================================*/
void chaymenusv(){    // SINH VIEN
char menu[4][25]={ //index 2
	"BO SUNG LOP",
	"NHAP SINH VIEN",
	"SV DANG KI",
	"IN RA",
};
	char key;
	nhacnhomenu();
		menuchinh(menu);
		int iy=yMenu1,i_text=0;
		gotoxy(xMenu,iy);
	   	boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
	while(true){
		key = GetKey();
	  switch(key){
	   	case UP:
		case DOWN:
			updown(key,menu,iy,i_text);
			break;	   
			case ENTER:
				switch(iy){
				case yMenu1:
				XemLop(DSL,MH,DSLTC,1);
					break;
				case  yMenu1 + distance:
					XemLop(DSL,MH,DSLTC,2);
					break;
				case yMenu1 + (2*distance):
					TimSV(DSL,MH,DSLTC);
					break;
				case yMenu1 + (3*distance):
					XemLop(DSL,MH,DSLTC,3);
					break;
			}	
			break;
			case ESC:
					chaymenu(mainMENU);
				break;
	   }
	}
}
//
/*=====================================================================*/
void chaymenumh(){    // mon hoc
char menu[4][25]={ //index 3
	"THEM MON HOC",
	"SUA/XOA",
	"DANG KI MON",
	"IN MON HOC",
};
	char key;
		nhacnhomenu();
		menuchinh(menu);
		int iy=yMenu1,i_text=0;
		gotoxy(xMenu,iy);
	   	boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
	while(true){
		key = GetKey();
	  switch(key){
	   	case UP:
		case DOWN:
			updown(key,menu,iy,i_text);
			break;	   
			case ENTER:
				switch(iy){
				case yMenu1:
					ThemMonHoc(MH);
					xoascreen();
					chaymenumh();
					break;
				case  yMenu1 + distance:
					XemMonHoc(DSLTC,MH,2);
					break;
				case yMenu1 + 2*distance:
					DKMon(DSL,MH,DSLTC);
					break;
				case yMenu1 + 3*distance:
					XemMonHoc(DSLTC,MH,1);
						break;
			}	
			break;
			case ESC:
					chaymenu(mainMENU);
				break;
	   }
	}
}
/*=====================================================================*/
void chaymenudiem(){    // DIEM
char menu[4][25]={ //index 4
	"NHAP/SUA DIEM",
	"DIEM THEO MON",
	"DIEM TB THEO LOP",
	"DIEM TONG KET",
};
	char key;
		nhacnhomenu();
		menuchinh(menu);
		int iy=yMenu1,i_text=0;
		gotoxy(xMenu,iy);
	   	boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
	while(true){
		key = GetKey();
	  switch(key){
	   	case UP:
		case DOWN:
			updown(key,menu,iy,i_text);
			break;	   
			case ENTER:
				switch(iy){
				case yMenu1:
				NhapSuaDiem(DSLTC,DSL,MH,1);
					break;
				case  yMenu1 + distance:
				NhapSuaDiem(DSLTC,DSL,MH,2);
					break;
				case yMenu1 + (2*distance):
				XemLop(DSL,MH,DSLTC,4);
					break;
				case yMenu1 + (3*distance):
				XemLop(DSL,MH,DSLTC,5);
					break;
			}	
			break;
			
			case ESC:
					chaymenu(mainMENU);
				break;
	   }
	}
}

/*=====================================================*/
/*=================    CHAY MENU   =======================*/
/*=====================================================*/

//
void chaymenu(char menu[][25]){
	char key;
		menuchinh(menu);
		nhacnhomenu();
		int iy=yMenu1,i_text=0;
		gotoxy(xMenu,iy);
	   	boxmenu(xMenu,iy ,wMenu,hMenu,mauchu,maubgs,menu[i_text]);
	while(true){
		key = GetKey();
	  switch(key){
	   	case UP:
		case DOWN:
			updown(key,menu,iy,i_text);
			break;	   
			case ENTER:
				switch(iy){
				case yMenu1:
					chaymenultc();
					break;
				case  yMenu1 + distance:
					chaymenusv();
					break;
				case yMenu1 + (2*distance):
					chaymenumh();
					break;
				case yMenu1 + (3*distance):
					chaymenudiem();
					break;
			}	
			break;
			
			case ESC:
					system("cls");
					exit(1);
				break;
	   }
	}
}
