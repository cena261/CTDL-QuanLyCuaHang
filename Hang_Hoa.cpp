#include"_Quan_ly_Hang_Hoa.h"

SNode2 *createSNode2(Itemtype2 x)
{
	SNode2 *p = new SNode2;
	if (p == NULL)
	{
		printf("khong du bo nho de cap phat");
		getch();
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
void showSNode2(SNode2* p)
{
	XuatTTHangHoa(p->Info);
}
void initSList2(SList2& sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
int isEmty(SList2 sl)
{
	if (sl.Head == NULL)
	{
		return 1;

	}
	else
		return 0;
}
void showSList2(SList2 sl)
{

	if (isEmty(sl) == 1)
	{
		printf(" Khong co hang hoa");
		return;
	}
	printf("%-5s%-26s%-s\n", "STT", "Hang Hoa", "So Luong");
	int stt = 1;
	SNode2* p = sl.Head;
	while (p != NULL)
	{
		printf("%-5d", stt++);
		showSNode2(p);
		p = p->Next;
	}
}
int inserHead(SList2& sl, SNode2* p)
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
//****************************************************
// case 1
void NhapTTHangHoa(Itemtype2 &x)
{
	printf("Nhap ten hang hoa: "); fflush(stdin); gets(x.TenHang);
	printf("Nhap So Luong hang hoa: "); scanf("%d", &x.SoLuong);

}

void XuatTTHangHoa(Itemtype2 x)
{
	printf("%-26s%-d\n", x.TenHang, x.SoLuong);

}
// case 2
void create_ByHand(SList2 &sl, Itemtype2 &x)
{
	int n;
	initSList2(sl);
	printf("Nhap so luong Hang Hoa:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		NhapTTHangHoa(x);
		SNode2 *p = createSNode2(x);
		if (inserHead(sl, p) == 0)
			continue;
	}
}
// case 3
void LoadTextFile(FILE *fi, Itemtype2 &x)
{
	fscanf(fi, "%[^#]%*c%d\n", &x.TenHang, &x.SoLuong);
}
void create_LoadTextFile(SList2 &sl, char TenFile[])
{
	FILE *fi = fopen(TenFile, "rt");
	if (fi == NULL)
	{
		printf("loi doc file");
		return;
	}
	initSList2(sl);
	SNode2 *p;
	Itemtype2 x;
	while (!feof(fi))// (end of file) đọc hết những ký tự có trong file cho đến khi không còn gì
	{
		Itemtype2 x;
		LoadTextFile(fi, x);
		p = createSNode2(x);
		if (inserHead(sl, p) == 0)
			continue;
	}
	fclose(fi);
}
//case 4 
// show thông tin hàng hóa bằng showSList2
// case 5
void saveTextFile(FILE* fi, Itemtype2 &x)
{
	if (strlen(x.TenHang) == 0) return;//viết danh sách vào file cho tới khi tên hàng không còn nữa thì ngưng
	fprintf(fi, "\n%s#%d", x.TenHang, x.SoLuong);
}

void writeAddFile(char* TenFile, Itemtype2 x)
{
	FILE* fi = fopen(TenFile, "a");// a là add để viết thêm vào file cũ
	if (!fi)
	{
		printf("Loi doc file");
		return;
	}
	saveTextFile(fi, x);
	fclose(fi);
	printf("Them thanh cong");
}

// case 6
void XuatFile(char* TenFile, Itemtype2 x, SList2 sl)
{
	FILE* fi = fopen(TenFile, "w");
	if (!fi)
	{
		printf("Loi doc file");
		return;
	}
	SNode2* p = sl.Head;
	while (p != NULL)
	{
		saveTextFile(fi, p->Info);
		p = p->Next;
	}
	printf("Xuat file thanh cong");
	fclose(fi);
}
