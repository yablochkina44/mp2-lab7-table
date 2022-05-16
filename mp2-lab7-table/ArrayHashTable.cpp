#include "ArrayHashTable.h"

ArrayHashTable::ArrayHashTable(int Size, int Step) : TabSize(Size), HashStep(Step)
{
	pRecs = new Record[TabSize];
	Empty = Record(-1);
	Mark = Record(-2);
	for (int i = 0; i < TabSize; i++)
	{
		pRecs[i] = Empty;
	}
}

ArrayHashTable::~ArrayHashTable()
{
	delete[] pRecs;
}

bool ArrayHashTable::FindRecord(TKey _key)
{
	bool result = false;
	FreePos = -1;
	CurrPos = HashFunc(_key) % TabSize;
	for (int i = 0; i < TabSize; i++)
	{
		Efficiency++;
		if (pRecs[CurrPos] == Empty)
		{
			break;
		}
		else
		{
			if (pRecs[CurrPos] == Mark)
			{
				if (FreePos == -1)
				{
					FreePos = CurrPos;
				}
			}
			else
			{
				if (pRecs[CurrPos].GetKey() == _key)
				{
					result = true;
					break;
				}
			}
		}
		CurrPos = GetNextPos(CurrPos);
	}
	return result;
}

bool ArrayHashTable::InsRecord(Record rec)
{
		if (IsFull()) return false;
		if (FindRecord(rec.GetKey())) return false;
		pRecs[CurrPos] = rec;
		DataCount++;
		Efficiency++;
		return true;
}

bool ArrayHashTable::DelRecord(TKey k)
{
	if (IsEmpty()) return false;
	if (!FindRecord(k)) return false;
	pRecs[CurrPos] = Empty;
	DataCount++;
	Efficiency++;
	return true;
}

int ArrayHashTable::Reset()
{
	CurrPos = 0;
	while (CurrPos < TabSize)
	{
		if ((pRecs[CurrPos] != Empty) && (pRecs[CurrPos] != Mark))
		{
			break;
		}
		else
		{
			CurrPos++;
		}
	}
	return IsEnd();
}

int ArrayHashTable::IsEnd() const
{
	return CurrPos >= TabSize;
}

int ArrayHashTable::GoNext()
{
	CurrPos++;
	while (CurrPos < TabSize)
	{
		if ((pRecs[CurrPos] != Empty) && (pRecs[CurrPos] != Mark))
		{
			break;
		}
		else
		{
			CurrPos++;
		}
	}
	return IsEnd();
}

TKey ArrayHashTable::GetKey() const
{
	return pRecs[CurrPos].GetKey();
}

TValue ArrayHashTable::GetValue() const
{
	return pRecs[CurrPos].GetValue();
}