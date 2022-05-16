#include<iostream>
#include<string>
using namespace std;
#include"ArrayTable.h"
class ScanTable :public ArrayTable {
public:
	//полностью наша
	ScanTable(int Size = TabMaxSize) : ArrayTable(Size) {};
	virtual bool FindRecord(TKey k);//найти запись
	virtual bool InsRecord(Record rec);
	virtual bool DelRecord(TKey k);

};