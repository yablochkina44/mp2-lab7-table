#include<iostream>
#include<string>
using namespace std;
#include"ScanTable.h"

class SortTable :public ScanTable 
{
private:
	Record* pBuff;
public:
	SortTable(int Size = 100) :ScanTable(Size) {
		pBuff = new Record[DataCount];
	}
	~SortTable() {
		delete[]pBuff;
	}
	SortTable(const ScanTable& tab);

	bool FindRecord(TKey) ;//найти запись
	bool InsRecord(Record);
	bool DelRecord(TKey) ;

	void SelectSort();
	void QuickSorter(int start, int finish);
	void QuickSort();
	SortTable& operator=(const ScanTable& tab);

	
	
	
	
	
	
	
	
	
};