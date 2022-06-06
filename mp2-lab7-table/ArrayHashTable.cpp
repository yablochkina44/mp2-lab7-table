#include "ArrayHashTable.h"

ArrayHashTable::ArrayHashTable(int Size, int Step) : TabSize(Size), HashStep(Step)
{
	pRecs = new Record[TabSize];
	HashStep = Step;
	Del.Key=-1;
	Free.Key=-2;
	for (int i = 0; i < TabSize; i++)
	{
		pRecs[i] = Del;
	}
}

ArrayHashTable::~ArrayHashTable()
{
	delete[] pRecs;
}

bool ArrayHashTable::FindRecord(TKey key)
{
	int pos = HashFunc(key) % TabSize, DelPos = -1;
	bool res = false;
	for (int i = 0; i < TabSize; ++i, ++Efficiency)
	{
		if (pRecs[pos] == Free)
		{
			CurrPos = pos;
			break;
		}
		else if (pRecs[pos].Key == key)
		{
			CurrPos = pos;
			res = true;
			break;
		}
		else if (pRecs[pos] == Del && DelPos == -1)
		{
			DelPos = pos;
			CurrPos = pos;
		}
		pos = (pos + HashStep) % TabSize;
	}
	if (DelPos != -1 && res == false)
	{
		CurrPos = DelPos;
	}
	return res;
}

bool ArrayHashTable::InsRecord(Record rec)
{
		if (IsFull()) return false;
		if (FindRecord(rec.Key)) return false;
		pRecs[CurrPos] = rec;
		DataCount++;
		Efficiency++;
		return true;
}

bool ArrayHashTable::DelRecord(TKey k)
{
	if (IsEmpty()) return false;
	if (!FindRecord(k)) return false;
	pRecs[CurrPos] = Del;
	DataCount++;
	Efficiency++;
	return true;
}

void ArrayHashTable::Reset()
{
	CurrPos = 0;
	while (CurrPos < TabSize)
	{
		if ((pRecs[CurrPos] != Del) && (pRecs[CurrPos] != Free))
		{
			break;
		}
		else
		{
			CurrPos++;
		}
	}
	
}

bool ArrayHashTable::IsEnd() const
{
	return CurrPos >= TabSize;
}

void ArrayHashTable::GoNext()
{
	if (!(pRecs[CurrPos] == Del) && !(pRecs[CurrPos] == Free))
	{
		CurrPos++;
	}

	while (pRecs[CurrPos] == Del || pRecs[CurrPos] == Free)
	{
		CurrPos++;
	}
}

TKey ArrayHashTable::GetKey() const
{
	return pRecs[CurrPos].Key;
}
const Record& ArrayHashTable::GetCurrentRecord() const
{
	if (!IsEnd() && !IsEmpty())
	{
		return pRecs[CurrPos];
	}
	else
	{
		throw std::exception();
	}
}

TValue ArrayHashTable::GetValue() const
{
	return pRecs[CurrPos].Value;
}