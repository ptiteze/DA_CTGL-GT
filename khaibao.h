#include"define.h"
#include<iostream>
#define MAXLTC  10000
#define MAXL  100
/*=====================================================*/
/*=================  struct   ==================*/
/*=====================================================*/
// khai bao mon hoc
struct monhoc{
	char mmh[11];
	char tmh[50];
	char stclt[2];
	char stcth[2];
};
struct nodemonhoc{
	monhoc data;
	nodemonhoc* left;
	nodemonhoc* right;
};
typedef nodemonhoc* PTRMH;
// tao sv
struct sinhvien{
	char mssv[15];
	char ho[30];
	char ten[20];
	char phai[4];
	char sdt[12];
	char malop[15];
};
struct NodeSV{
	sinhvien data;
	NodeSV* next;
};
typedef NodeSV* PTRSV;
// lop quan li sinh vien 
struct Nodelop{
	char malop[15];
	char tenlop[35];
	char nienkhoa[5];
	PTRSV DSSV;
};
struct ListLop{
	Nodelop ds[MAXL];
	int soluong;
};
//dang ki 
struct dangki{
	char mssv[15];
	char diem[4];
	bool huydk = 0 ;
};
struct nodedangki{
	dangki data;
	nodedangki* next;
};
typedef nodedangki* PTRDK;
// tao lop tin chi
struct loptc{
	int maLoptc;
	char mmh[11];
	char nienkhoa[5];
	char hocki[2];
	char nhom[2];
	char svMax[4];
	char svMin[4]; 
	PTRDK DSDK;
};
struct DSloptc{
	loptc* ds[MAXLTC];
	int soluong ;
};
/*==============================================================*/
PTRMH MH ;
DSloptc DSLTC;
ListLop DSL;
void initLTC(DSloptc& DSLTC){
	DSLTC.soluong=0;
}
void initMH(PTRMH &DSMH){
	DSMH = NULL;
}
void initLop(ListLop& ds) {
	ds.soluong = 0;
}
/*=====================================================*/
/*=================xu li AVL  ==================*/
/*=====================================================*/
int getHeight(PTRMH t){
	if(t){
		int t1=getHeight(t->left);
		int t2=getHeight(t->right);
		return (t1>t2?t1:t2)+1;
	}else return 0;
}

PTRMH rightRotate(PTRMH root){
    PTRMH x = root->left;
    // B?t d?u quay ph?i
    root->left = x->right;
    x->right = root;
    // Return x - tr? v? root m?i
    return x;
}

PTRMH leftRotate(PTRMH root) {
    PTRMH y = root->right;
 
    // B?t d?u quay trái
    root->right = y->left;
    y->left = root;
 
    // Return y - tr? v? root m?i
    return y;
}
PTRMH Create_node(monhoc data){
	PTRMH new_node =  new nodemonhoc;
	malloc(sizeof(PTRMH));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return (new_node);
}
int balanceFactor(PTRMH t){
	if(t==NULL)return 0;
	 return getHeight(t->left) - getHeight(t->right);
}
PTRMH InsertMH(PTRMH t, monhoc value){
	if(t == NULL){
		return Create_node(value);
	}
	if(strcmp(value.mmh , t->data.mmh) > 0){
		t->right = InsertMH(t->right,value);
	}
	else if(strcmp(value.mmh , t->data.mmh) < 0){
		t->left = InsertMH(t->left,value);
	}else return t;
	// chenh lech 2 ben cay
	int val = balanceFactor(t);
	// cay lech trai trai
	if(val > 1 && strcmp(value.mmh , t->left->data.mmh) < 0){
		return rightRotate(t);
	}
	// cay lech phai phai
	if(val < -1 && strcmp(value.mmh , t->right->data.mmh) > 0){
		return leftRotate(t);
	}
	//cay lech trai phai
	if(val > 1 && strcmp(value.mmh , t->left->data.mmh) > 0){
		t->left = leftRotate(t->left);
		return rightRotate(t);
	}
	// cay lech phai trai
	if(val < -1 && strcmp(value.mmh , t->right->data.mmh) < 0){
		t->right = rightRotate(t->right);
		return leftRotate(t);
	}
	return t;
}
PTRMH Minvalue(PTRMH t){
	PTRMH temp;
	while(temp->left!=NULL) temp=temp->left;
	return temp;
}
PTRMH xoa_node_MH(PTRMH &dsmh, char mmh[]){
	if(dsmh == NULL) return dsmh;
		if(strcmp(dsmh->data.mmh,mmh) > 0){
				xoa_node_MH(dsmh->left,mmh);
			}
		else if(strcmp(dsmh->data.mmh,mmh) < 0){
			xoa_node_MH(dsmh->right,mmh);
			}
			else{
			if(dsmh->left==NULL||dsmh->right==NULL){
				PTRMH temp = (dsmh->left)?dsmh->left : dsmh->right;
					if (temp == NULL) {
        			temp = dsmh;
       				 dsmh = NULL;
      			}else
      				*dsmh=*temp;
      				free(temp);
				  }else{
				  	PTRMH temp = Minvalue(dsmh->right);
				  	dsmh->data=temp->data;
				  	dsmh->right= xoa_node_MH(dsmh->right,temp->data.mmh);
				  }
			}
	 		if (dsmh == NULL) return dsmh;
    // can bang lai cay
    int balance = balanceFactor(dsmh);
    if (balance > 1 && balanceFactor(dsmh->left) >= 0)
    return rightRotate(dsmh);

  if (balance > 1 && balanceFactor(dsmh->left) < 0) {
    dsmh->left = leftRotate(dsmh->left);
    return rightRotate(dsmh);
  }

  if (balance < -1 && balanceFactor(dsmh->right) <= 0)
    return leftRotate(dsmh);

  if (balance < -1 && balanceFactor(dsmh->right) > 0) {
    dsmh->right = rightRotate(dsmh->right);
    return leftRotate(dsmh);
  }
  return dsmh;
}
int DemMonHoc(PTRMH DSMH) {
	if (DSMH != NULL)
	{
		return (DemMonHoc(DSMH->left) + DemMonHoc(DSMH->right) + 1);
	}
	else return 0;
}
void Sort_MangMH(monhoc a[], int n) {  //Dung SS 
	monhoc min;
	int vitrimin;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		min = a[i];
		vitrimin = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(min.tmh, a[j].tmh) > 0)
			{
				min = a[j];
				vitrimin = j;
			}
		}
		min = a[vitrimin];
		a[vitrimin] = a[i];
		a[i] = min;
	}
}
void MangTam_MonHoc(PTRMH DSMH, monhoc mh[], int& dem) {
	//phep duyet LNR
	if (DSMH != NULL)
	{
		MangTam_MonHoc(DSMH->left, mh, dem);
		mh[dem++] = DSMH->data;
		MangTam_MonHoc(DSMH->right, mh, dem);
	}
}
PTRMH Search_MH(PTRMH &DSMH, char mh[]) {
	if (DSMH == NULL) { return NULL; }
	else {
		if (0 == strcmp(DSMH->data.mmh, mh)) {
			return DSMH;
		}
		else if (0< strcmp(DSMH->data.mmh, mh)) {
			Search_MH(DSMH->left, mh);
		}
		else {
			Search_MH(DSMH->right, mh);
		}
	}
}

/*==============================================================*/

int Search_mmh(DSloptc DSLTC, char mmh[], int dem) {
	for (int i = 0; i < dem; i++)
	{
		//so sanh bang ma mon hoc
		if ((strcmp(DSLTC.ds[i]->mmh, mmh)) == 0)
		{
			return i; //neu phan trung thi tra ve vi tri i
		}
	}
	return -1; //khong tim thay trung
}
int  FullLTC(DSloptc DSLTC){
	return(DSLTC.soluong == MAXLTC ? TRUE : FALSE);
}
int KTMH(PTRMH DSMH, char mh[]) {   // kiem tra mon hoc
	if (DSMH == NULL)
	{
		return 0;
	}
	else {
		if (strcmp(DSMH->data.mmh, mh) == 0)
		{
			return 1;
		}
		else if (strcmp(DSMH->data.mmh, mh) >0)
		{
			KTMH(DSMH->left, mh);
		}
		else {
			KTMH(DSMH->right, mh);
		}
	}
}
int checkNienKhoa(DSloptc DSLTC,char NiemKhoa[]){
	if (DSLTC.soluong == 0)
		return 0;
	for (int i = 0; i <= DSLTC.soluong; i++)					
	{
		if (DSLTC.soluong == i) { continue; }
		if (strcmp(DSLTC.ds[i]->nienkhoa,NiemKhoa)==0)
			return -1;
	}
	return 0;
}
int checkHK_NK(DSloptc DSLTC,char HocKi[],char NienKhoa[]){
	if (DSLTC.soluong == 0)
		return 0;
	for (int i = 0; i <= DSLTC.soluong; i++)						
	{
		if (DSLTC.soluong == i) { continue; }
		if (strcmp(DSLTC.ds[i]->hocki,HocKi)==0&&strcmp(DSLTC.ds[i]->nienkhoa,NienKhoa)==0)
			return -1;
	}
	return 0;
}
int mangLTC(DSloptc DSLTC,char HocKi[],char NienKhoa[],loptc* Loptc[]){ //dua ltc vao mang
	int soluongltc=0;
	if (DSLTC.soluong == 0)
		return 0;
	for (int i = 0; i <= DSLTC.soluong; i++)					
	{
		if (DSLTC.soluong == i) { continue; }
		if (strcmp(DSLTC.ds[i]->hocki,HocKi)==0){		
			if(strcmp(DSLTC.ds[i]->nienkhoa,NienKhoa)==0){
				Loptc[soluongltc]=DSLTC.ds[i];
				soluongltc++;
				}
			}
		}
	return soluongltc;
}
int DoSV_LTC(DSloptc DSLTC, char mssv[],loptc* Loptc[]){
	int soloptc =0;
	PTRDK p;
		for(int i = 0; i<DSLTC.soluong;i++){
	for ( p = DSLTC.ds[i]->DSDK; p != NULL; p = p->next)
	{	
		if (strcmp(p->data.mssv, mssv) == 0) {
			Loptc[soloptc]  =   DSLTC.ds[i];
			soloptc++;
		}
	}	
}
	return soloptc;
}
int KiemtraBo4_v2(DSloptc DSLTC, loptc lopTc) {
	for (int i = 0; i < DSLTC.soluong; i++) {
		if (strcmp(DSLTC.ds[i]->mmh, lopTc.mmh) == 0) {
			if (strcmp(DSLTC.ds[i]->nienkhoa, lopTc.nienkhoa) == 0) {
				if (strcmp(DSLTC.ds[i]->hocki, lopTc.hocki) == 0) {
					if (strcmp(DSLTC.ds[i]->nhom, lopTc.nhom) == 0) {
						return -2;
					}
				}
			}
		}
	}
	return -1;
}
loptc* TaoLTC()
{
	loptc* ltc = new loptc;
	ltc->maLoptc = 0;
	ltc->mmh[0] = NULL;
	ltc->hocki[0] = NULL;
	ltc->nienkhoa[0] = NULL;
	ltc->nhom[0] = NULL;
	ltc->svMax[0] = NULL;
	ltc->svMin[0] = NULL;
	ltc->DSDK = NULL;
	return ltc;
}
int	 InsertLTC(DSloptc& DSLTC, loptc lopTc, int i){
	//kiem tra xem danh sach full hay chua
	if (FullLTC(DSLTC))
		return 0;
	else
	{
		//them vao cuoi
		DSLTC.ds[i] = TaoLTC();
		DSLTC.ds[i]->maLoptc = lopTc.maLoptc;
		strcpy(DSLTC.ds[i]->mmh, lopTc.mmh);
		strcpy(DSLTC.ds[i]->hocki, lopTc.hocki);
		strcpy(DSLTC.ds[i]->nhom, lopTc.nhom);
		strcpy(DSLTC.ds[i]->nienkhoa, lopTc.nienkhoa);
		strcpy(DSLTC.ds[i]->svMax, lopTc.svMax);
		strcpy(DSLTC.ds[i]->svMin, lopTc.svMin);
	}
	//them thanh cong, tang so luong phan tu len 1
	DSLTC.soluong++;
}
int EmptyLTC(DSloptc DSLTC)
{
	return(DSLTC.soluong == 0 ? TRUE : FALSE);
}
void DeleteLTC(DSloptc& DSLTC, int i)
{
	//cac truong hop chi so dua vao khong hop le
	if (i<0 || i>DSLTC.soluong || EmptyLTC(DSLTC))
	{
		return;
	}
	if (i == DSLTC.soluong)
	{
		delete DSLTC.ds[DSLTC.soluong];
		DSLTC.soluong--;
		DSLTC.ds[DSLTC.soluong] = NULL;
		return;
	}
	else
	{
		delete DSLTC.ds[i];
		for (int temp = i + 1; temp < DSLTC.soluong; temp++)
		{
			DSLTC.ds[temp - 1] = DSLTC.ds[temp];
		}
		DSLTC.soluong--;
		DSLTC.ds[DSLTC.soluong] = NULL; 
	}
	return;
}
int Search_malopTc(DSloptc DSLTC,int Maloptc){
		for(int i=0 ;i<DSLTC.soluong;i++){
			if(DSLTC.ds[i]->maLoptc==Maloptc){
				return i;
			}
		}
	return -1;
}
int Search_MH_LTC(DSloptc DSLTC, char mh[]) {
	for (int i = 0; i < DSLTC.soluong; i++) {
		if (0 == strcmp(DSLTC.ds[i]->mmh, mh)) {
			return i;
		}
	}
	return -1;
}
void SortDSLTC(DSloptc& DSLTC) {
		int pos ,i;
	loptc* x;
	for(i=1;i<DSLTC.soluong;i++){
		x=DSLTC.ds[i];pos=i-1;
		while(pos>=0&&(DSLTC.ds[pos]->maLoptc>x->maLoptc)){
			DSLTC.ds[pos+1]=DSLTC.ds[pos];
			pos--;
		}
		DSLTC.ds[pos+1]=x;
	}
}
void SortLTC_Nam(DSloptc& DSLTC){
	int pos ,i;
	loptc* x;
	for(i=1;i<DSLTC.soluong;i++){
		x=DSLTC.ds[i];pos=i-1;
		while(pos>=0&&(strcmp(DSLTC.ds[pos]->nienkhoa,x->nienkhoa)>0)){
			DSLTC.ds[pos+1]=DSLTC.ds[pos];
			pos--;
		}
		DSLTC.ds[pos+1]=x;
	}
}
 int kt_Lop_MSV_MH(ListLop ds, PTRMH DSMH, char c[], int n)
{
	for (int i = 0; i <= n; i++)						// tra ve -1 : trung Ma lop
	{													// tra ve -2 : trung Ma SV
		if (ds.soluong == i) { continue; }					// tra ve -3 : trung Ma MH
		if (strcmp(ds.ds[i].malop, c) == 0) return -1;	// tra ve 0 : khong trung
		for (PTRSV p = ds.ds[i].DSSV; p != NULL; p = p->next)
		{
			if (strcmp(p->data.mssv, c) == 0) return -2;
		}
	}
	if (KTMH(DSMH, c) == 1) return -3;
	return 0;
}
int Search_lop_MSV(ListLop lop,char c[]){
	for(int i=0;i<=lop.soluong;i++){
			if (lop.soluong == i) { continue; }	
				for (PTRSV p = lop.ds[i].DSSV; p != NULL; p = p->next)
		{
			if (strcmp(p->data.mssv, c) == 0) return i;
		}
	}
	return -1;
}
int	 KTMaLop(ListLop lop, char c[], int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (strcmp(lop.ds[i].malop, c) == 0)
		{
			return i;	// neu trung tra ve vi tri
		}
	}
	return -1;		// khong tim thay ptu tra 0
}
/*void ISortLop(ListLop& lop) {
	int i, hole;
	Nodelop value;
	for (i = 1; i < lop.soluong; i++) {
		value = lop.ds[i];
		hole = i;
		while (hole > 0 && strcmp(lop.ds[hole - 1].malop, value.malop) > 0) {
			lop.ds[hole] = lop.ds[hole - 1];
			hole--;
		}
		lop.ds[hole] = value;
	}
	
}*/
void ISortLop(ListLop& l) {  // sap xep chon
	Nodelop lopMin;
	int vitriMin;
	int n = l.soluong;
	for(int i = 0; i < n -1; i++){
		lopMin = l.ds[i]; // gan gia tri can hoan doi cho min
		vitriMin = i; // vi tri can hoan doi
		for(int j = i + 1; j < n; j++){
			if(strcmp(l.ds[j].malop,lopMin.malop) < 0){
				lopMin = l.ds[j]; // lay du lieu de hoan doi
				vitriMin = j;   // giu vi tri nho do de hoan doi
			}
		}
		l.ds[vitriMin] = l.ds[i]; // gan du lieu tai vi tri be nhat cho vi tri can hoan doi
		l.ds[i] = lopMin; // gan du lieu cua vi tri can hoan doi cho lop be nhat (da lay ra)
	}
}
int Full_Lop(ListLop &lop){
	if (lop.soluong == MAXL - 1) {
		GhiChu("Danh sach Lop Da Day. Khong the them!", 60, 28, 79, 700);
		return 1;
	}
	return 0;
}
void Insert_TailSV(PTRSV& DSSV, sinhvien sv) {
	PTRSV p = new NodeSV;
	p->data = sv;
	p->next = NULL;
	if (DSSV == NULL) {
		DSSV = p;
	}
	else {
		for (PTRSV k = DSSV; k != NULL; k = k->next)
		{
			if (k->next == NULL)	//Tim ra Node Tail
			{
				k->next = p;
				k = p;
			}
		}
		return;
	}
}
int DemSinhVien(PTRSV DSSV)
{
	int dem = 0;
	for (PTRSV p = DSSV; p != NULL; p = p->next) { dem++; }
	return dem;
}
void SapXepSV(PTRSV& DSSV)
{
	PTRSV tam, p, q;
	sinhvien sv;	//Sap xep theo Selection Sort, tai vi 1 lop khoang 100sv
	if (DSSV == NULL) { return; }
	for (p = DSSV; p->next != NULL; p = p->next) //p nhu mang di tu i = 0 den n-1
	{
		tam = p; sv = p->data; //dia chi nho nhat gan vao tam, gia tri nho nhat gan vao sv
		for (q = p->next; q != NULL; q = q->next) //q nhu mang di tu i+1 den n
		{
			if (strcmp(tam->data.ten, q->data.ten) > 0) //So sanh Ten truoc'
			{
				tam = q;
			}
			else {
				if (strcmp(tam->data.ten, q->data.ten) == 0) //Neu Ten bang nhau so sanh tiep Ho
				{
					if (strcmp(tam->data.ho, q->data.ho) > 0)
					{
						tam = q;
					}
				}
			}
		}
		//sv = p->data;
		p->data = tam->data;
		tam->data = sv;
	}
}
PTRSV Search_MSV(PTRSV DSSV, char msv[]) {
	if (NULL == DSSV) {
		return NULL;
	}
	for (PTRSV p = DSSV; p != NULL; p = p->next) {
		if (strcmp(p->data.mssv, msv) == 0) {
			return p;
		}
	}return NULL;
}
int KTSV(PTRSV DSSV, char c[])
{
	for (PTRSV p = DSSV; p != NULL; p = p->next)
	{
		if ((strcmp(p->data.mssv, c)) == 0 && p == DSSV)
		{
			return 1;
		}
		if ((strcmp(p->data.mssv, c) == 0) && (p->next == NULL)) //Luu y: phai so sanh Tail truoc' giua neu khong roi vao truong hop giua~ truoc
		{
			return -1;
		}
		if (strcmp(p->data.mssv, c) == 0)
		{
			return 0;
		}
	}	return 2;
}
PTRDK SearchSV_LTC(DSloptc& DSLTC, char c[])
{
	for (int i = 0; i < DSLTC.soluong; i++) //Duyet Lop
	{
		if (DSLTC.ds[i]->DSDK == NULL) { continue; } //Lop khong co sinh vien => continue
		for (PTRDK p = DSLTC.ds[i]->DSDK; p != NULL; p = p->next)
		{
			if (strcmp(p->data.mssv, c) == 0) { return p; } //Tim thay sinh vien => tra ve nút svien 
		}
	}return NULL;
}
void XoaDauSV(PTRSV& DSSV) {
	PTRSV p = DSSV;	DSSV = DSSV->next;	delete p;
}
void XoaGiuaSV(PTRSV& DSSV, char c[]) {
	PTRSV temp = NULL;
	for (PTRSV p = DSSV; p != NULL; p = p->next)
	{
		if (strcmp(p->data.mssv, c) == 0)
		{
			temp->next = p->next;	delete p;	return;
		}
		temp = p; // temp luon la con tro truoc ben trai' cua con tro dang duyet
	}
}
void XoaCuoiSV(PTRSV& DSSV)
{
	PTRSV temp = NULL;
	for (PTRSV p = DSSV; p != NULL; p = p->next)
	{
		if (p->next == NULL)
		{
			temp->next = NULL;	delete p;	return;
		}
		temp = p; // temp luon la con tro truoc ben trai' cua con tro dang duyet
	}
}
int DemSVDK(PTRDK DSDK)
{
	int dem = 0;
	for (PTRDK p = DSDK; p != NULL; p = p->next) { dem++; }
	return dem;
}
PTRDK Search_msvdk(PTRDK DSDK, char masv[]) {
	for (PTRDK p = DSDK; p != NULL; p = p->next)
	{
		if (strcmp(p->data.mssv, masv) == 0) {
			return p;
		}
	}
	return NULL;
}
void Insert_NodeDk(PTRDK& DSDK,dangki svdk) {
	PTRDK p = new nodedangki;
	p->data = svdk;
	p->next = NULL;
	if (DSDK == NULL) {
		DSDK = p;
		return;
	}
	else {
		for (PTRDK k = DSDK; k != NULL; k = k->next)
		{
			if (k->next == NULL)	//Tim ra Node Tail
			{
				k->next = p;
				k = p;
			}
		}
		return;
	}
}
/*==============================================================*/
void Sort_MangSV(sinhvien a[], int n) { 
	sinhvien min;
	int vitrimin;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		min = a[i];
		vitrimin = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(min.ten, a[j].ten) > 0)
			{
				min = a[j];
				vitrimin = j;
			}
			else {
				if (strcmp(min.ten, a[j].ten) == 0)
				{
					if (strcmp(min.ho, a[j].ho) > 0)
					{
						min = a[j];
						vitrimin = j;
					}
				}
			}
		}
		min = a[vitrimin];
		a[vitrimin] = a[i];
		a[i] = min;
	}
}
PTRSV Search_MSV_DSLOP(ListLop lop, char msv[]) {
	for (int i = 0; i < lop.soluong; i++) {
		for (PTRSV p =lop.ds[i].DSSV; p != NULL; p = p->next) {
			if (strcmp(p->data.mssv, msv) == 0) {
				return p;
			}
		}
	}return NULL;
}
/*==============================================================*/
void DiemTKet(ListLop &lop, PTRMH DSMH,DSloptc DSLTC,int vitriMang);
void XemDiemLop(DSloptc &DSLTC, ListLop lop, PTRMH DSMH,int vitriMang);
void ThemLTC(DSloptc& DSLTC,PTRMH DSMH);
void XemLTC(DSloptc& DSLTC,PTRMH DSMH,int chedoxem);
//
void ThemLop(ListLop& lop,PTRMH DSMH);
// xoa lop : da xong
void ThemSV( ListLop& lop, PTRMH DSMH,int vitriMang);
void SuaSV(PTRSV& DSSV, ListLop lop, PTRMH DSMH, DSloptc &DSLTC, char c[]);
void XemSV(ListLop& lop, PTRMH DSMH, DSloptc &DSLTC, int vitriMang);
void XemLop(ListLop& lop, PTRMH DSMH,DSloptc& DSLTC,int chedoxem);//chua lam
void SuaMonHoc(DSloptc& DSLTC,PTRMH &DSMH);
void XoaMonHoc(DSloptc &DSLTC , PTRMH &DSMH);//mat
void XemMonHoc(DSloptc&DSLTC, PTRMH& DSMH, int chedoxem);


/*==============================================================*/
/*=====================     FILE     ===========================*/
/*==============================================================*/
void DocFileDSLTC(DSloptc &DSLTC)
{
	ifstream infile;
	infile.open("DATA\\DSLTC.txt", ios::in);
	if (!infile)
	{	
		GhiChu("File Khong Ton Tai!",60,28,7,1000);
		return;
	}
	int i = 0 ;
	loptc lopTc;
	while (infile.good())
	{
		infile >> lopTc.maLoptc;
		infile.ignore();
		infile.getline(lopTc.mmh, 11);
		infile.getline(lopTc.nienkhoa, 5);
		infile.getline(lopTc.hocki, 2);
		infile.getline(lopTc.nhom, 2);
		infile.getline(lopTc.svMax, 4);
		infile.getline(lopTc.svMin,4);
		if (infile.eof()) break;
		if (i<MAXLTC)
		{
		 InsertLTC(DSLTC, lopTc, DSLTC.soluong);
			i++;
		}
	}
	infile.close();
}
void GhiFileDSLTC(DSloptc DSLTC)
{
	ofstream outfile;
	outfile.open("DATA\\DSLTC.txt");
	for (int i = 0; i < DSLTC.soluong; i++)
	{
		outfile << DSLTC.ds[i]->maLoptc << endl;
		outfile << DSLTC.ds[i]->mmh << endl;
		outfile << DSLTC.ds[i]->nienkhoa << endl;
		outfile << DSLTC.ds[i]->hocki << endl;
		outfile << DSLTC.ds[i]->nhom << endl;
		outfile << DSLTC.ds[i]->svMax << endl;
		outfile << DSLTC.ds[i]->svMin << endl;
	}
	outfile.close();
}
/*==============================================================*/
void GhiFile_LNR(ofstream& file, PTRMH DSMH) 
{
	if (DSMH != NULL)
	{
		GhiFile_LNR(file, DSMH->left);
		file << DSMH->data.mmh << endl
			<< DSMH->data.tmh << endl
			<< DSMH->data.stclt << endl
			<< DSMH->data.stcth << endl;
		GhiFile_LNR(file, DSMH->right);
	}
}
void GhiFileMH(PTRMH DSMH) {
	ofstream outfile;
	outfile.open("DATA\\DSMH.txt", ios::out);
	GhiFile_LNR(outfile, DSMH);
	outfile.close();
}
void DocFileMH(PTRMH &DSMH) {
	ifstream infile;
	string data;
	infile.open("DATA\\DSMH.txt", ios::in);
	if (!infile) { GhiChu("Khong tim thay file", 35, 27, 79, 2000); return; } //Khong tim thay file
	while (infile.good())
	{
		monhoc mh;
		getline(infile, data);
		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
		strcpy(mh.mmh, data.c_str());
		getline(infile, data);		strcpy(mh.tmh, data.c_str());
		getline(infile, data);		strcpy(mh.stclt, data.c_str());
		getline(infile, data);		strcpy(mh.stcth, data.c_str());
		DSMH = InsertMH(DSMH, mh);
	}
	infile.close();
}
/*==============================================================*/
void DocFileLop(ListLop& lop)
{
	for (int i = 0; i < MAXL; i++)	//Khoi tao Mang rong~
	{
		lop.ds[i].malop[0] = NULL;
		lop.ds[i].tenlop[0] = NULL;
		lop.ds[i].nienkhoa[0] = NULL;
		lop.ds[i].DSSV = NULL;
	}
	fstream infile; string data;
	infile.open("DATA\\DSLOP.txt", ios::in);
	if (!infile) { GhiChu("Khong tim thay file", 60, 28, 79, 2000); return; } //Khong tim thay file 
	while (infile.good())
	{
		getline(infile, data);
		if (data.size() == 0) { break; } // Khi da co file va du lieu rong~
		strcpy(lop.ds[lop.soluong].malop, data.c_str());
		getline(infile, data);
		strcpy(lop.ds[lop.soluong].tenlop, data.c_str());
		getline(infile, data);
		strcpy(lop.ds[lop.soluong].nienkhoa, data.c_str());
		lop.ds[lop.soluong].DSSV = NULL;	//Khoi tao con tro dau` DSSV NULL
		lop.soluong++;
	}
	infile.close();
}
void GhiFileLop(ListLop ds)
{
	int n = 0;
	ofstream outfile;
	outfile.open("DATA\\DSLOP.txt", ios::out);
	while (n < ds.soluong)
	{
		outfile << ds.ds[n].malop << endl
			<< ds.ds[n].tenlop << endl
			<< ds.ds[n].nienkhoa << endl;
		n++;
	}
	outfile.close();
}
void GhiFileSV(ListLop lop)
{
	ofstream outfile;
	outfile.open("DATA\\DSSV.txt", ios::out);
	for (int i = 0; i < lop.soluong; i++)
	{
		if (lop.ds[i].DSSV != NULL) //Kiem tra Lop có Sinh Vien moi' nap. vao`
		{
			//outfile << lop.ds[i].malop << endl;
			for (PTRSV p = lop.ds[i].DSSV; p != NULL; p = p->next)
			{
				strcpy(p->data.malop,lop.ds[i].malop);
				outfile << p->data.malop << endl
					<< p->data.mssv << endl
					<< p->data.ho << endl
					<< p->data.ten << endl
					<< p->data.phai << endl
					<< p->data.sdt << endl;
			}
		}
	}
	outfile.close();
}
void DocFileSV(ListLop& lop)
{
	int temp, vitri;
	char a[20];
	string data;
	ifstream infile;
	infile.open("DATA\\DSSV.txt", ios::in);
	if (!infile) { return; }
	while (infile.good())
	{
		sinhvien sv;
		getline(infile, data);
		if (data.size() == 0) { break; }
		strcpy(sv.malop, data.c_str());
		temp = KTMaLop(lop, sv.malop, lop.soluong);
		if (temp != -1)
		{
			vitri = temp;
		}
		else {		
			strcpy(sv.mssv, data.c_str());
			getline(infile, data);		strcpy(sv.ho, data.c_str());
			getline(infile, data);		strcpy(sv.ten, data.c_str());
			getline(infile, data);		strcpy(sv.phai, data.c_str());
			getline(infile, data);		strcpy(sv.sdt, data.c_str());
			Insert_TailSV(lop.ds[vitri].DSSV, sv);
		}
	}
	infile.close();
}
/*==============================================================*/
void GhiFileDK(DSloptc DSLTC)
{
	ofstream outfile;
	outfile.open("DATA\\DSDK.txt", ios::out);
	for (int i = 0; i < DSLTC.soluong; i++)
	{
		if (DSLTC.ds[i]->DSDK != NULL) //Kiem tra Lop có Sinh Vien moi' nap. vao`
		{
				outfile << DSLTC.ds[i]->maLoptc << endl;
			for (PTRDK p = DSLTC.ds[i]->DSDK; p != NULL; p = p->next)
			{
					if(p->data.huydk){
				outfile << p->data.mssv << endl
					<< p->data.diem << endl
					<<  "true"<< endl;
					}else {
				outfile << p->data.mssv << endl
					<< p->data.diem << endl
					<< "false" <<endl;
					}
			}
		}
	}
	outfile.close();
}
void DocFileDSDK(DSloptc& DSLTC)
{
	int temp, vitri;
	string data;
	char a[11];
	int malopTc;
	ifstream infile;
	infile.open("DATA\\DSDK.txt", ios::in);
	if (!infile) { return; }
	while (infile.good())
	{
		dangki svdk;
		getline(infile, data);
		if (data.size() == 0) { break; }
		strcpy(a, data.c_str());
		malopTc = atoi(a);
		temp = Search_malopTc(DSLTC, malopTc);
		if (temp != -1)
		{
			vitri = temp;
		}
		else {
			strcpy(svdk.mssv, data.c_str());
			getline(infile, data);		strcpy(svdk.diem, data.c_str());
			getline(infile, data);
			if(strcmp(data.c_str(),"true")==0){
				svdk.huydk=true;
			}else{
				svdk.huydk=false;
			}
			Insert_NodeDk(DSLTC.ds[vitri]->DSDK, svdk);

		}
	}
	infile.close();
}




