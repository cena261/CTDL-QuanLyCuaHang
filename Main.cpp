#include"_Quan_ly_Khach_Hang.h"
#include"_Quan_ly_Hang_Hoa.h"
#include"_Quan_ly_Hoa_Don.h"

void Menu();
void Menu1();
void process1();
void Menu2();
void process2();
void Menu3();
void process3();

int main()
{
	int choice;

	do
	{
		Menu();
		printf("\nNhap chuc nang ban muon su dung: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			process1();
			break;
		case 2:
			process2();
			break;
		case 3:
			process3();
			break;
		}
	} while (choice != 0);
}

void Menu()
{ 
	printf("\n************************************************");
	printf("\n*0. Thoat chuong trinh                         *");
	printf("\n*1. Thong tin quan ly khach hang               *");
	printf("\n*2. Thong tin hang hoa                         *");
	printf("\n*3. Hoa don khach hang                         *");
	printf("\n************************************************");
}
//***********************************************************************************
// phần quản lý khách hàng
void Menu1()
{
	printf("\n******************************************************************");
	printf("\n*                                  MENU						   *");
	printf("\n******************************************************************");
	printf("\n0. Tro lai menu   											    ");
	printf("\n1. Them moi thong khach hang                                      ");
	printf("\n2. Tao moi danh sach (Nhap truc tiep tu ban phim)				    ");
	printf("\n3. Tao moi danh sach (Doc tu file du lieu)						");
	printf("\n4. Tim ten khach hang											    ");
	printf("\n5. Luu danh sach vao file										    ");
	printf("\n6. Xem noi dung danh sach										    ");
	printf("\n7. Xoa mot khach hang khoi danh sach							    ");
	printf("\n******************************************************************");
}
void process1()
{
	ItemType X, Y;
	SNode *P, *Q;
	SList SL;
	initSList(SL);
	int choices, kq, sdt;
	char TenFile[] = "TTKhachHang.txt";
	char TenFile_out[] = "TTKhachHang_out.txt";
	char HoTen[31];
	do
	{
		Menu1();
		printf("\nVui long chon chuc nang: ");
		scanf("%d", &choices);
		switch (choices)
		{
		case 0:
			break;
		case 1:
			nhapTTKhachHang(X);
			P = createSNode(X);
			printf("Thong tin khach hang vua nhap la:  \n");
			showSNode(P);
			insert(SL, P);
			printf("Noi dung danh sach sau khi nhap: \n");
			showSList(SL);
			break;
		case 2:
			createSList_ByHand(SL);
			printf("Danh sach khach hang vua nhap la: \n");
			showSList(SL);
			break;
		case 3:
			createSList_LoadTextFile(SL, TenFile);
			printf("Noi dung danh sach vua doc la: \n");
			showSList(SL);
			break;
		case 4:
			printf("Nhap ten khach hang can tim:  "); fflush(stdin); gets(HoTen);
			P = findSNode_theoHoTen(SL, HoTen);
			if (P != NULL)
			{
				printf("Thong tin khach hang la: \n");
				xuatTTKhachHang(P->Info);
			}
			else
				printf("Khong tim thay khach hang trong danh sach\n");
			break;
		case 5:
			SaveTextFile_FromSList(SL, TenFile_out);
			break;
		case 6:
			printf("Noi dung danh sach la: \n");
			showSList(SL);
			break;
		case 7:
			printf("Nhap SDT khach hang can xoa:  \n"); scanf("%d", &sdt);
			if (deleteKhachHang(SL, sdt) == true)
			{
				printf("Xoa thanh cong\n");
				printf("Danh sach sau khi xoa\n");
				showSList(SL);
				printf("\n");
			}
			else printf("Khong tim thay\n");
			break;
		default:
			printf("Vui long chon dung so chuc nang\n");
			break;
		}
	} while (choices != 0);

}
//***********************************************************************************
// phần quản lý hàng hóa
void Menu2()
{
	printf("\n************************************************");
	printf("\n*0. Tro lai menu                               *");
	printf("\n*1. Them thong tin Hang Hoa                    *");
	printf("\n*2. Nhap thong tin Hang Hoa ( bang tay )       *");
	printf("\n*3. Doc thong tin Hang Hoa ( bang file )       *");
	printf("\n*4. Xem thog tin Hang Hoa                      *");
	printf("\n*5. Them thong tin Hang Hoa vao file           *");
	printf("\n*6. Xuat thong tin ra file moi                 *");
	printf("\n************************************************");
}
void process2()
{
	int choice;
	Itemtype2 X;
	SNode2* p;
	SList2 SL;
	initSList2(SL);
	char TenFile[] = "HangHoa.txt";
	do{
		Menu2();
		printf("\nNhap chuc nang ban muon su dung: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			NhapTTHangHoa(X);
			p = createSNode2(X);
			printf("\nThong tin hang hoa vua nhap la: \n");
			inserHead(SL, p);
			showSList2(SL);
			break;
		case 2:
			create_ByHand(SL, X);
			showSList2(SL);
			break;
		case 3:
			create_LoadTextFile(SL, TenFile);
			showSList2(SL);
			break;
		case 4:
			showSList2(SL);
			break;
		case 5:
			printf("Ban hay nhap ten Hang Hoa muon them:"); flushall(); gets(X.TenHang);
			printf("Ban hay nhap so luong: "); scanf("%d", &X.SoLuong);
			p = createSNode2(X);
			inserHead(SL, p);
			writeAddFile(TenFile, X);
			break;
		case 6:
			XuatFile("HangHoa_out", X, SL);
			break;
		}

	} while (choice != 0);

}
//***********************************************************************************
// Phần quản lý hóa đơn
void Menu3()
{
	printf("\n************************************************");
	printf("\n*0. Tro lai menu                               *");
	printf("\n*1. Them thong tin Hoa Don                     *");
	printf("\n*2. Doc thong tin Hoa Don ( bang file )        *");
	printf("\n*3. Xuat thong tin ra file moi                 *");
	printf("\n*4. Sap xep theo tong tien                     *");
	printf("\n*5. Sap xep theo ma khach hang                 *");
	printf("\n*6. Thong tin hoa don co tong tien lon nhat    *");
	printf("\n*7. Tim kiem hoa don dua tren Ma hoa don       *");
	printf("\n*8. Liet ke thong tin khi biet Ma khach hang   *");
	printf("\n*9. Thong ke doanh thu theo ngay/thang/quy/nam *");
	printf("\n************************************************");
}
void process3()
{
	int choice,n,m;
	Itemtype3 X;
	ItemType X2;
	SNode3* p;
	SNode *q;
	SList3 SL3;
	SList SL;
	initSList3(SL3);
	char TenFileKH[] = "TTKhachHang.txt";
	char TenFile[] = "HoaDon.txt";
	char TenFile_out[] = "TTKhachHang_out.txt";
	char MaHoaDon[30];
	char MaKH[30];
	do{
		Menu3();
		printf("\nNhap chuc nang ban muon su dung: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			NhapTTHoaDon(X);
			p = createSNode3(X);
			inserHead(SL3, p);
			showSList3;
			createSList_LoadTextFile(SL,TenFileKH); // load thông tin file khách hàng để so sánh
			n = SoSanh(SL, SL3);
			if (n == 1) // n=1 thì không có khách hàng
			{
				
				printf("Co luu them thong tin khach hang %s moi khong(0.Khong/1.Co)?", p->Info.HoTen);
				scanf("%d", &m);
				if (m == 1)
				{
					//lưu thông tin khách hàng mới
					nhapTTKhachHang(X2);
					q = createSNode(X2);
					insert(SL, q);
					printf("luu thong tin thanh cong.\n");
					showSList(SL);
					SaveTextFile_FromSList(SL, TenFile_out); // Lưu thông tin vào file out
				}
			}
			break;

		case 2:
			create_LoadTextFile(SL3, TenFile);
			showSList3(SL3);
			break;
		case 3:
			XuatFile("HoaDon_out.txt", X, SL3);
			break;
		case 4:
			SapxepTongTien(SL3);
			showSList3(SL3);
			break;
		case 5:
			SapXepMaKH(SL3);
			showSList3(SL3);
			break;
		case 6:
		{
			Itemtype3 maxHoaDon = TimTongTienLonNhat(SL3);
				  printf("Thong tin hoa don co tong tien lon nhat:\n");
				  giaodien();
				  XuatTTHoaDon(maxHoaDon);
				  break;
		}
		case 7:
			printf("Nhap ma hoa don can tim:  "); fflush(stdin); gets(MaHoaDon);
			p = findSNode3_theoMaHoaDon(SL3, MaHoaDon);
			if (p != NULL)
			{
				printf("Thong tin hoa don la: \n");
				giaodien();
				XuatTTHoaDon(p->Info);
			}
			else
				printf("Khong tim thay hoa don\n");
			break;
		case 8:
			printf("Nhap ma khach hang can tim hoa don:  \n"); fflush(stdin); gets(MaKH);
			LietKeTheoMaKH(SL3, MaKH);
			break;
		case 9:
			ThongKeDoanhThu(SL3);
			break;
		}

	} while (choice != 0);

}