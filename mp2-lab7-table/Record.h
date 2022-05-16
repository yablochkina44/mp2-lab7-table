#include<iostream>
#include<string>
using namespace std;
typedef int TKey;
typedef string TValue;

class Record {
protected: 
	TKey Key;	 
	TValue Value;
	virtual void Print(ostream& os) { os << Key << " " << Value; }

public:
	Record() {}
	Record(TKey k) { Key = k; }
	Record(TKey k, TValue Val) {
		Key = k;
		Value = Val;
	}
	void SetKey(TKey k) { Key = k; }
	TKey GetKey(void) { return Key; }
	void SetValue(TValue p) { Value = p; }
	TValue GetValue() { return Value; }
	virtual int operator==(const Record& tr) { return Key == tr.Key; }
	virtual int operator!=(const Record& tr) { return Key != tr.Key; }
	virtual int operator>(const Record& tr) { return Key < tr.Key; }
	virtual int operator<(const Record& tr) { return Key > tr.Key; }
	virtual int operator>=(const Record& tr) { return Key <= tr.Key; }
	virtual int operator<=(const Record& tr) { return Key >= tr.Key; }
	friend class ArrayTable;
	friend class ScanTable;
	friend class SortTable;
};
