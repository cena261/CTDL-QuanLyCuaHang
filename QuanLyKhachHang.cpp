#include"_Quan_ly_Khach_Hang.h"

//=======================================================================
//Ham trung gian
SNode *createSNode(ItemType x)
{
	SNode *p = new SNode;
	if (p == NULL)
	{
		printf("Khong the cap phat node moi\n");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
void showSNode(SNode *p)
{
	xuatTTKhachHang(p->Info);
}
void initSList(SList &sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
int isEmpty(SList sl)
{
	if (sl.Head == NULL)
	{
		return 1;
	}
	else return 0;
}
void showSList(SList sl)
{
	if (isEmpty(sl) == 1)
	{
		printf("Danh sach rong\n");
		return;
	}
	printf("%-5s%-31s%-26s%-26s%-10s\n", "STT", "Ho va Ten", "Nam sinh", "Que quan", "SDT");
	int stt = 1;
	SNode *p = sl.Head;
	while (p != NULL)
	{
		printf("%-5d",stt++);
		showSNode(p);
		p = p->Next;
	}
}
int insert(SList &sl, SNode *p)
{
	if (p == NULL)
	{
		return 0;
	}
	if (isEmpty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}
//=======================================================================
//Ham chuong trinh
//Case 1
void nhapTTKhachHang(ItemType &X)
{
	printf("Nhap ten khach hang: "); fflush(stdin); gets(X.HoTen);
	printf("Nhap que quan khach hang:  "); fflush(stdin); gets(X.QueQuan);
	printf("Nhap ngay thang nam sinh khach hang:  "); fflush(stdin); gets(X.DOB);
	printf("Nhap so dien thoai khach hang: "); scanf("%d", &X.SDT);
}
char* formatSDT(int sdt) 
{//Ham de giu lai so 0 o dau so dien thoai
		static char result[12]; 
		sprintf(result, "%010d", sdt); 
		return result;
}
void xuatTTKhachHang(ItemType X)
{
	printf("%-31s%-26s%-26s%-10s\n", X.HoTen, X.QueQuan, X.DOB, formatSDT(X.SDT));
}
void loadTTKhachHang(FILE *fi, ItemType &X)
{
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%d\n", &X.HoTen, &X.DOB, &X.QueQuan, &X.SDT);
}
//Case 2
void createSList_ByHand(SList &sl)
{
	initSList(sl);
	int n;
	do
	{
		printf("Cho biet so khach hang can nhap: ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		ItemType X;
		nhapTTKhachHang(X);

		SNode *p = createSNode(X);
		if (insert(sl, p) == 0)
			continue;
	}
}
//Case 3
void createSList_LoadTextFile(SList &sl, char TenFile[])
{
	FILE *fi = fopen(TenFile, "rt"); //doc file
	if (fi == NULL)
	{
		printf("Loi doc file\n");
		return;
	}

	initSList(sl);
	int n;
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		ItemType X;
		loadTTKhachHang(fi, X);

		SNode *p = createSNode(X);
		if (insert(sl, p) == 0)
			continue;
	}
	fclose(fi);
}
//Case 4
SNode *findSNode_theoHoTen(SList sl, char HoTen[])
{
	SNode *p = sl.Head;
	while (p != NULL)
	{
		if (stricmp(p->Info.HoTen, HoTen) == 0)
		{
			return p;
		}
		p = p->Next;
	}
	return NULL;
}
//Case 5
void saveTTKhachHang(FILE *fo, ItemType X)
{
	fprintf(fo, "%-31s%-26s%-26s%s", X.HoTen, X.DOB, X.QueQuan, formatSDT(X.SDT));
}
void SaveTextFile_FromSList(SList sl, char TenFile[])
{
	FILE *fo = fopen(TenFile, "wt"); //ghi file
	if (fo == NULL)
	{
		printf("Loi doc file\n");
		return;
	}
	if (isEmpty(sl) == 1)
	{
		printf("hang doi rong\n");
		return;
	}
	int stt = 1;
	SNode *p = sl.Head;
	while (p != NULL)
	{
		fprintf(fo, "\n%-5d", stt++);
		saveTTKhachHang(fo, p->Info);
		p = p->Next;
	}
	printf("\nLuu file thanh cong\n");
	fclose(fo);
}
//Case 7, xoa dua vao so dien thoai cua khach hang
bool deleteKhachHang(SList &sl, int sdt)
{
	SNode* p = sl.Head;
	SNode* q = NULL;

	while (p != NULL) {
		if (p->Info.SDT == sdt) {
			if (p == sl.Head) {
				sl.Head = p->Next;
				if (p == sl.Tail) {
					sl.Tail = NULL;
				}
			}
			else {
				if (p == sl.Tail) {
					sl.Tail = q;
					q->Next = NULL;
				}
				else {
					q->Next = p->Next;
				}
			}
			delete p; 
			return true; 
		}
		q = p;
		p = p->Next;
	}
	return false; 
}