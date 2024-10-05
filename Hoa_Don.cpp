#include"_Quan_ly_Hoa_Don.h"
#include"_Quan_ly_Khach_Hang.h"


SNode3 *createSNode3(Itemtype3 &x)
{
	SNode3 *p = new SNode3;
	if (p == NULL)
	{
		printf("khong du bo nho de cap phat");
		getch();
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
void showSNode3(SNode3* p)
{
	XuatTTHoaDon(p->Info);
}
void initSList3(SList3& sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
int isEmty(SList3 sl)
{
	if (sl.Head == NULL)
	{
		return 1;

	}
	else
		return 0;
}
void showSList3(SList3 sl)
{

	if (isEmty(sl) == 1)
	{
		printf(" Khong co hang hoa");
		return;
	}
	printf("************************************************\n");
	printf("%-26s%-26s%-26s%-26s%-s\n", "Ngay Nhap Hoa Don", "Ma Khach Hang", "Ho Ten", "Ma Hoa Don", "Tong Tien");
	SNode3* p = sl.Head;
	while (p != NULL)
	{
		showSNode3(p);
		p = p->Next;
	}
}
int inserHead(SList3& sl, SNode3* p)
{
	if (p == NULL)
	{
		return 0;
	}
	if (isEmty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;
}
//case 1
void NhapTTHoaDon(Itemtype3 &x)
{
	printf("Nhap Ngay: "); scanf("%d", &x.Ngay);
	printf("Nhap Thang: "); scanf("%d", &x.Thang);
	printf("Nhap Nam: "); scanf("%d", &x.Nam);
	printf("Nhap Ma Khach Hang: "); scanf("%s", &x.MaKH);
	printf("Nhap Ten Khach Hang: "); fflush(stdin); gets(x.HoTen);
	printf("Nhap Ma Hoa Don: "); scanf("%s", &x.MaHoaDon);
	printf("Nhap Tong Tien: "); scanf("%d", &x.TongTien);
}

void XuatTTHoaDon(Itemtype3 x)
{
	printf("%d/%d/%-24d%-23s%-26s%-26s%-d\n", x.Ngay, x.Thang, x.Nam, x.MaKH, x.HoTen, x.MaHoaDon, x.TongTien);
}

//So sánh tên hóa đơn mới với danh sách khách hàng
int SoSanh(SList sl,SList3 sl3)
{
	//SList sl là danh sách khách hàng
	SNode3 *q = sl3.Head;
	SNode *p = sl.Head;
	while (p != NULL)
	{
		if (strcmp(p->Info.HoTen, q->Info.HoTen)==0)
		{
			return 0;
		}
		p = p->Next;
	}
	return 1;
}
//case 2
// đọc thông tin file
void LoadTextFile(FILE *fi, Itemtype3 &x)
{
	fscanf(fi, "%d %d %d #%[^#]#%[^#]#%[^#]#%d\n", &x.Ngay, &x.Thang, &x.Nam, x.MaKH, x.HoTen, x.MaHoaDon, &x.TongTien);
}
void create_LoadTextFile(SList3 &sl, char TenFile[])
{
	FILE *fi = fopen(TenFile, "rt");
	if (fi == NULL)
	{
		printf("loi doc file");
		return;
	}
	initSList3(sl);
	SNode3 *p;
	Itemtype3 x;
	int n;
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		LoadTextFile(fi, x);
		p = createSNode3(x);
		if (inserHead(sl, p) == 0)
			continue;
	}
	fclose(fi);
}
// case 3
//lưu thông tin file 
void saveTextFile(FILE* fi, Itemtype3 &x)
{

	fprintf(fi, "*****************************\n");
	fprintf(fi, "%-10s%-26s%-26s%-26s%-s\n", "Ngay", "Ma Khach Hang", "Ho Ten", "Ma Hoa Don", "Tong Tien");
	fprintf(fi, "%d/%d/%-8d%-26s%-26s%-26s%-d\n", x.Ngay, x.Thang, x.Nam, x.MaKH, x.HoTen, x.MaHoaDon, x.TongTien);
}

void XuatFile(char* TenFile, Itemtype3 x, SList3 sl)
{
	FILE* fi = fopen(TenFile, "wt");
	if (fi == NULL)
	{
		printf("Loi doc file");
		return;
	}
	SNode3* p = sl.Head;
	while (p != NULL)
	{
		saveTextFile(fi, p->Info);
		p = p->Next;
	}
	printf("Xuat file thanh cong");
	fclose(fi);
}
//case 4
// Sắp xếp theo tổng tiền
void SapxepTongTien(SList3 &sl)
{
	for (SNode3 *p = sl.Head; p != NULL; p = p->Next)
	{
		for (SNode3 *q = p->Next; q != NULL; q = q->Next)
		{
			if (p->Info.TongTien <= q->Info.TongTien)
			{
				HoanVi(p->Info, q->Info);
			}
		}
	}
}
//case 5
//sắp xếp theo mã khách hàng
void SapXepMaKH(SList3 &sl)
{
	for (SNode3 *p = sl.Head; p != NULL; p = p->Next)
	{
		for (SNode3 *q = p->Next; q != NULL; q = q->Next)
		{
			if (strcmp(p->Info.MaKH, q->Info.MaKH)>0)
			{
				HoanVi(p->Info, q->Info);
			}
		}
	}
}
//Hoán đổi vị trí
void HoanVi(Itemtype3 &x, Itemtype3 &y)
{
	Itemtype3 temp;
	temp = x;
	x = y;
	y = temp;
}

//case 6
// tìm thông tin của tổng tiền lớn nhất
Itemtype3 TimTongTienLonNhat(SList3 sl) {
	SNode3* p = sl.Head;
	Itemtype3 maxHoaDon = p->Info;
	while (p != NULL) {
		if (p->Info.TongTien > maxHoaDon.TongTien) {
			maxHoaDon = p->Info;
		}
		p = p->Next;
	}
	return maxHoaDon;
}
//=======================================================================
//case 7
SNode3 *findSNode3_theoMaHoaDon(SList3 &sl, char MaHoaDon[])
{
	SNode3 *p = sl.Head;
	while (p != NULL)
	{
		if (stricmp(p->Info.MaHoaDon, MaHoaDon) == 0)
		{
			return p;
		}
		p = p->Next;
	}
	return NULL;
}
//=======================================================================
//case 8
void giaodien()
{
	printf("%-26s%-26s%-26s%-26s%-s\n","Ngay Nhap Hoa Don","Ma Khach Hang","Ho Ten","Ma Hoa Don","Tong Tien");
}
void LietKeTheoMaKH(SList3 sl, char MaKH[])
{
	SNode3 *p = sl.Head;
	int count = 0;
	printf("Cac hoa don cua khach hang co ma %s:\n",MaKH);
	giaodien();
	while (p != NULL)
	{
		if (strcmp(p->Info.MaKH, MaKH) == 0)
		{
			XuatTTHoaDon(p->Info);
			count++;
		}
		p = p->Next;
	}
	if (count == 0)
	{
		printf("Khong tim thay hoa don nao cua khach hang co ma %s\n",MaKH);
	}
}
//=======================================================================
//case 9
int ThongKeTheoNgay(SList3 sl, int ngay, int thang, int nam)
{
	SNode3 *p = sl.Head;
	int doanhThuNgay = 0;
	while (p != NULL)
	{
		if (p->Info.Ngay == ngay && p->Info.Thang == thang && p->Info.Nam == nam)
		{
			doanhThuNgay += p->Info.TongTien;
		}
		p = p->Next;
	}
	return doanhThuNgay;
}

int ThongKeTheoThang(SList3 sl, int thang, int nam)
{
	SNode3 *p = sl.Head;
	int doanhThuThang = 0;
	while (p != NULL)
	{
		if (p->Info.Thang == thang && p->Info.Nam == nam)
		{
			doanhThuThang += p->Info.TongTien;
		}
		p = p->Next;
	}
	return doanhThuThang;
}

int ThongKeTheoQuy(SList3 sl, int quy, int nam)
{
	SNode3 *p = sl.Head;
	int doanhThuQuy = 0;
	while (p != NULL)
	{
		int quyHoaDon;
		if (p->Info.Thang >= 1 && p->Info.Thang <= 3)
			quyHoaDon = 1;
		else if (p->Info.Thang >= 4 && p->Info.Thang <= 6)
			quyHoaDon = 2;
		else if (p->Info.Thang >= 7 && p->Info.Thang <= 9)
			quyHoaDon = 3;
		else
			quyHoaDon = 4;

		if (quyHoaDon == quy && p->Info.Nam == nam)
		{
			doanhThuQuy += p->Info.TongTien;
		}
		p = p->Next;
	}
	return doanhThuQuy;
}

int ThongKeTheoNam(SList3 sl, int nam)
{
	SNode3 *p = sl.Head;
	int doanhThuNam = 0;
	while (p != NULL)
	{
		if (p->Info.Nam == nam)
		{
			doanhThuNam += p->Info.TongTien;
		}
		p = p->Next;
	}
	return doanhThuNam;
}

void ThongKeDoanhThu(SList3 sl) {
	int choices;
	int ngay, thang, quy, nam;

	do {
		printf("==================================================================\n");
		printf("                     THONG KE DOANH THU                           \n");
		printf("==================================================================\n");
		printf("1. Theo ngay\n");
		printf("2. Theo thang\n");
		printf("3. Theo quy\n");
		printf("4. Theo nam\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choices);

		switch (choices) {
		case 1:
			printf("Nhap Ngay: ");
			scanf("%d", &ngay);
			printf("Nhap Thang: ");
			scanf("%d", &thang);
			printf("Nhap Nam: ");
			scanf("%d", &nam);
			printf("Doanh thu theo ngay %d/%d/%d la : %d\n", ngay, thang, nam, ThongKeTheoNgay(sl, ngay, thang, nam));
			break;
		case 2:
			printf("Nhap Thang: ");
			scanf("%d", &thang);
			printf("Nhap Nam: ");
			scanf("%d", &nam);
			printf("Doanh thu theo thang %d/%d la : %d\n", thang, nam, ThongKeTheoThang(sl, thang, nam));
			break;
		case 3:
			printf("Nhap quy: ");
			scanf("%d", &quy);
			printf("Nhap nam: ");
			scanf("%d", &nam);
			printf("Doanh thu theo quy %d nam %d la: %d\n", quy, nam, ThongKeTheoQuy(sl, quy, nam));
			break;
		case 4:
			printf("Nhap nam: ");
			scanf("%d", &nam);
			printf("Doanh thu nam %d la: %d\n", nam, ThongKeTheoNam(sl, nam));
			break;
		case 0:
			printf("Thoat chuong trinh!\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long thu lai!\n");
			break;
		}
	} while (choices != 0);
}
