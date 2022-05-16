#pragma once
#include "Table.h"

class HashTable : public Table
{
protected:
	virtual unsigned int HashFunc(const TKey _key)
	{
		unsigned int hashval = _key;
		return hashval;
	}
public:
	HashTable() : Table() {}
};