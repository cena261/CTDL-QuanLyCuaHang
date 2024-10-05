#ifndef _Quan_ly_Hang_Hoa_h
#define _Quan_ly_Hang_Hoa_h

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string>


struct HangHoa
{
	char TenHang[26];
	int SoLuong;

};
typedef HangHoa Itemtype2;

struct SNode2
{
	Itemtype2 Info;
	SNode2 *Next;
};

struct SList2
{
	SNode2 *Head;
	SNode2 *Tail;
};

SNode2 *createSNode2(Itemtype2 x);
void showSNode2(SNode2* p);
void initSList2(SList2& sl);
int isEmty(SList2 sl);
void showSList2(SList2 sl);
int inserHead(SList2& sl, SNode2* p);

void NhapTTHangHoa(Itemtype2 &x);
void XuatTTHangHoa(Itemtype2 x);

void create_ByHand(SList2 &sl, Itemtype2 &x);
void LoadTextFile(FILE *fi, Itemtype2 &x);
void create_LoadTextFile(SList2 &sl, char TenFile[]);


void saveTextFile(FILE* fi, Itemtype2 &x);
void writeAddFile(char* TenFile, Itemtype2 x);

void XuatFile(char* TenFile, Itemtype2 x, SList2 sl);

#endif _Quan_ly_Hang_Hoa_h