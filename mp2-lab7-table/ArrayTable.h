#include<iostream>
#include<string>
using namespace std;
#include"Table.h"

//enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };
class ArrayTable :public Table
{
protected:
	Record* pRecs;
	int TabSize;
	int CurrPos;
public:
	ArrayTable(int Size = TabMaxSize)
	{
		pRecs = new Record[Size];
		TabSize = Size;
		for (int i = 0; i < Size; i++)
			pRecs[i] = NULL;
		DataCount = CurrPos = 0;
	}
	~ArrayTable()
	{
		delete[]pRecs;
	}

	virtual bool IsFull() const { return DataCount >= TabSize; }
	
	int GetTabSize() const { return TabSize; }
	virtual TKey GetKey(void) const { return pRecs[CurrPos].GetKey();}
	virtual TValue GetValue(void) const { return pRecs[CurrPos].GetValue(); }
	virtual int Reset() { CurrPos = 0; return IsEnd(); };
	virtual int GoNext()
	{
		if (!IsEnd())
		{
			CurrPos++;
		}
		return IsEnd();
	};
	virtual int IsEnd() const{ return CurrPos >= DataCount; };
	
	virtual int GetCurrentPos() { return CurrPos; }
	virtual int SetCurrentPos(int pos)
	{
		CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
		return IsEnd();
	};
	
	friend SortTable;
};
