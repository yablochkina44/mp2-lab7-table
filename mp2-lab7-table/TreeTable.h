#pragma once
#include <stack>
#include <stdio.h>
#include "Table.h"
#include "TreeNode.h"
#include "Record.h"
using namespace std;

struct TreeNode
{
public:
	TKey Key;
	TValue Value;
	TreeNode* pLeft;
	TreeNode* pRight;
	int Balance = 0;
	virtual void Print(ostream& os) { os << Key << " " << Value; }
	/*TreeNode()
	{
		pLeft = NULL;
		pRight = NULL;
	}*/

	TreeNode(TKey _key = -1, TValue _val = "", TreeNode* _pLeft = NULL,
		TreeNode* _pRight = NULL)
	{
		Key = _key;
		Value = _val;
		pRight = _pRight;
		pLeft = _pLeft;
	}
	virtual int operator==(const TreeNode& tr) { return Key == tr.Key; }
	virtual int operator!=(const TreeNode& tr) { return Key != tr.Key; }
	virtual int operator>(const TreeNode& tr) { return Key < tr.Key; }
	virtual int operator<(const TreeNode& tr) { return Key > tr.Key; }
	virtual int operator>=(const TreeNode& tr) { return Key <= tr.Key; }
	virtual int operator<=(const TreeNode& tr) { return Key >= tr.Key; }
	friend class TreeTable;

};





class TreeTable : public Table
{
protected:
	TreeNode* pRoot;
	TreeNode* pCurr;
	TreeNode* pPrev;
	int CurrPos;
	stack<TreeNode*> stack;
	//void PrintTreeTab(TreeNode* pNode);
	void DrawTreeTab(TreeNode* pNode, int Level);
	void DelTreeTab(TreeNode* pNode);
public:
	TreeTable() : Table()
	{
		CurrPos = 0;
		pRoot = NULL;
		pCurr = NULL;
	}
	~TreeTable()
	{
		DelTreeTab(pRoot);
	}

	virtual bool IsFull() const;

	bool FindRecord(TKey);
	bool InsRecord(Record);
	bool DelRecord(TKey);

	TKey GetKey() const;
	TValue GetValue() const;
	const Record& GetCurrentRecord() const override;
	void Reset();
	bool IsEnd() const;
	void GoNext();

	//void PrintTab();
	void DrawTab();
};