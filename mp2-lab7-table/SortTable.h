#include<iostream>
#include<string>
using namespace std;
#include"ScanTable.h"

class SortTable :public ScanTable 
{
private:
	Record* pBuff;
public:
	SortTable(int Size = TabMaxSize) :ScanTable(Size) {
		pBuff = new Record[DataCount];
	}
	~SortTable() {
		delete[]pBuff;
	}
	SortTable(const ScanTable& tab);

	virtual bool FindRecord(TKey k);//найти запись
	virtual bool InsRecord(Record rec);
	virtual bool DelRecord(TKey k);
	void QuickSorter(int start, int finish);
	SortTable& operator=(const ScanTable& tab);

	void SortData();
	void SelectSort();
	void QuickSort();
	
	
	
	
	
	
	
};