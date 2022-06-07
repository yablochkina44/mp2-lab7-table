#pragma once

#include<iostream>
#include<string>
using namespace std;
#include"ArrayTable.h"
class ScanTable :public ArrayTable {
public:
	
	ScanTable(int Size = 100) : ArrayTable(Size) {}
	bool FindRecord(TKey);
	bool InsRecord(Record);
	bool DelRecord(TKey);

};