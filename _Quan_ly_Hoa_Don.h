#ifndef _Quan_ly_Hoa_Don_h
#define _Quan_ly_Hoa_Don_h
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include <time.h>
#include <iomanip>


#include"_Quan_ly_Khach_Hang.h"
struct HoaDon
{
	char MaKH[26];
	char HoTen[31];
	char MaHoaDon[26];
	int TongTien;
	int Ngay, Thang, Nam;
};
typedef HoaDon Itemtype3;

struct SNode3
{
	Itemtype3 Info;
	SNode3 *Next;

};

struct SList3
{
	SNode3 *Head;
	SNode3 *Tail;

};

SNode3 *createSNode3(Itemtype3 &x);
void showSNode3(SNode3* p);
void initSList3(SList3& sl);
int isEmty(SList3 sl);
void showSList3(SList3 sl);
int inserHead(SList3& sl, SNode3* p);

void NhapTTHoaDon(Itemtype3 &x);
void XuatTTHoaDon(Itemtype3 x);

void LoadTextFile(FILE *fi, Itemtype3 &x);
void create_LoadTextFile(SList3 &sl, char TenFile[]);
void saveTextFile(FILE* fi, Itemtype3 &x);
void XuatFile(char* TenFile, Itemtype3 x, SList3 sl);

int SoSanh(SList sl, SList3 sl3);
void SapXepMaKH(SList3 &sl);
void HoanVi(Itemtype3 &x, Itemtype3 &y);
void SapxepTongTien(SList3 &sl);

Itemtype3 TimTongTienLonNhat(SList3 sl);
SNode3 *findSNode3_theoMaHoaDon(SList3 &sl, char MaHoaDon[]);
void LietKeTheoMaKH(SList3 sl, char MaKH[]);
void ThongKeDoanhThu(SList3 sl);
void giaodien();
#endif _Quan_ly_Hang_Hoa_h