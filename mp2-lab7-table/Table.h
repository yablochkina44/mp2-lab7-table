#include<iostream>
#include<string>
using namespace std;
#include"Record.h"
#define TabEmpty -101
#define TabFull -102
#define TabNoRec -103
#define TabRecDblr -104//дублирования записи, т.к запись уже была
#define TabMaxSize 100
#define TabCorrect


class Table
{
protected:
	int DataCount; // кол-во записей в таблице
	int Efficiency; // показатель эффективности выполнениия операций
public:
	Table() { DataCount = 0; Efficiency = 0; }
	virtual ~Table(){}
	int GetDataCount()const { return DataCount; }
	int GetEfficiency()const { return Efficiency; }
	void SetDataCount(int D) { DataCount = D; }
	void SetEfficiency(int D) { Efficiency = D; }
	void ClearEfficiency() { Efficiency = 0; }
	
	bool IsEmpty() const { return DataCount == 0; }
	virtual bool IsFull() const = 0;

	//наши
	virtual bool FindRecord(TKey k) = 0;//найти запись
	virtual bool InsRecord(Record rec) = 0;
	virtual bool DelRecord(TKey k) = 0;
	

	virtual int Reset() = 0;
	virtual int GoNext() = 0;
	virtual int IsEnd() const = 0;

	virtual TKey GetKey() const = 0;
	virtual TValue GetValue() const = 0;
	friend ostream& operator<<(ostream& os, Table& tab)
	{
		os << "Printing a table ..." << endl;
		for (tab.Reset(); !tab.IsEnd(); tab.GoNext())
		{
			os << "Key:" << tab.GetKey()
			   << " Value:" << tab.GetValue() << endl;
		}
		return os;
	}
};