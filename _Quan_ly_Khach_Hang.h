#ifndef _Quan_ly_Khach_Hang_h
#define _Quan_ly_Khach_Hang_h
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>


struct KhachHang
{
	char HoTen[26];
	char QueQuan[26];
	char DOB[26];
	int SDT;
};
typedef KhachHang ItemType;

struct SNode
{
	ItemType Info;
	SNode *Next;
};
struct SList
{
	SNode *Head;
	SNode *Tail;
};
void nhapTTKhachHang(ItemType &X);
void xuatTTKhachHang(ItemType X);
void loadTTKhachHang(FILE *fi, ItemType &X);
void createSList_LoadTextFile(SList &sl, char TenFile[]);
void SaveTextFile_FromSList(SList sl, char TenFile[]);
void saveTTKhachHang(FILE *fo, ItemType X);
SNode *findSNode_theoHoTen(SList sl, char HoTen[]);
bool deleteKhachHang(SList &sl, int sdt);

SNode *createSNode(ItemType x);
void showSNode(SNode *p);
void initSList(SList &sl);
int isEmpty(SList sl);
void showSList(SList sl);
int insert(SList &sl, SNode *p);
void createSList_ByHand(SList &sl);
char* formatSDT(int sdt);


#endif _Quan_ly_Khach_Hang_h