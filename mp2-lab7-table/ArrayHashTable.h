#pragma once
#include "HashTable.h"

#define TabHashStep 7

class ArrayHashTable : public HashTable
{
protected:
	Record* pRecs;
	int TabSize;
	int HashStep;
	int FreePos;
	int CurrPos;
	Record Mark;
	Record Empty;

	int GetNextPos(int pos)
	{
		return (pos + HashStep) % TabSize;
	}
public:
	ArrayHashTable(int Size = TabMaxSize, int Step = TabHashStep);
	~ArrayHashTable();

	virtual bool IsFull() const
	{
		return DataCount >= TabSize;
	}

	virtual bool FindRecord(TKey _key);
	virtual bool InsRecord(Record rec);
	virtual bool DelRecord(TKey k);

	virtual int Reset();
	virtual int IsEnd() const;
	virtual int GoNext();

	virtual TKey GetKey() const;
	virtual TValue GetValue() const;
};