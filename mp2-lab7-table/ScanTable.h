#include<iostream>
#include<string>
using namespace std;
#include"ArrayTable.h"
class ScanTable :public ArrayTable {
public:
	//��������� ����
	ScanTable(int Size = TabMaxSize) : ArrayTable(Size) {};
	virtual bool FindRecord(TKey k);//����� ������
	virtual bool InsRecord(Record rec);
	virtual bool DelRecord(TKey k);

};