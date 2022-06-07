#include "TreeTable.h"
#include "Record.h"

//
//void TreeTable::PrintTreeTab(TreeNode* pNode)
//{
//	if (pNode)
//	{
//		for (int i = 0; i < Level; i++)
//		{
//			std::cout << " ";
//		}
//		std::cout << pNode->Key << std::endl;
//		Level++;
//		PrintTreeTab(pNode->pRight);
//		PrintTreeTab(pNode->pLeft);
//		Level--;
//	}
//}

//void TreeTable::PrintTab()
//{
//	std::cout << "Table:" << std::endl;
//	Level = 0;
//	PrintTreeTab(pRoot);
//}

//const Record& TreeTable::GetCurrentRecord() const
//{
//	if (pCurr)
//	{
//		return pCurr->rec;
//	}
//	else
//	{
//		throw std::exception("Table is empty\n");
//	}
//}

void TreeTable::DrawTreeTab(TreeNode* pNode, int Level)
{
	if (pNode)
	{
		DrawTreeTab(pNode->pRight, Level + 1);
		for (int i = 0; i < 2 * Level; i++)
		{
			cout << "  ";
		}
		//std::cout << *pNode;
		cout << "Key:" << pNode->Key << "  Value: " << pNode->Value;
		cout << std::endl;
		DrawTreeTab(pNode->pLeft, Level + 1);
	}
}

void TreeTable::DrawTab()
{
	std::cout << "Table:" << std::endl;
	DrawTreeTab(pRoot, 0);
}

void TreeTable::DelTreeTab(TreeNode* pNode)
{
	if (pNode)
	{
		DelTreeTab(pNode->pLeft);
		DelTreeTab(pNode->pRight);
		delete pNode;
	}
}

bool TreeTable::IsFull() const
{
	TreeNode* pNode = new TreeNode();
	if (pNode)
	{
		delete pNode;
		return false;
	}
	return true;
}

bool TreeTable::FindRecord(TKey _key)
{
	pPrev = NULL;
	pCurr = pRoot;
	while (pCurr)
	{
		Efficiency++;
		if (pCurr->Key == _key)
		{
			break;
		}
		pPrev = pCurr;
		if (pCurr->Key < _key)
		{
			pCurr = pCurr->pRight;
		}
		else
		{
			pCurr = pCurr->pLeft;
		}
	}
	if (pCurr)
	{
		return true;
	}
	else
	{
		pCurr = pPrev;
		return false;
	}
}

bool TreeTable::InsRecord(Record rec)
{
	if (IsFull())
	{
		return 0;
	}
	else
	{
		if (FindRecord(rec.Key))
		{
			return 0;
		}
		else
		{
			TreeNode* tmp = new TreeNode(rec.Key,rec.Value);
			if (!pRoot)
			{
				pRoot = tmp;
			}
			else
			{
				if (rec.Key < pCurr->Key)
				{
					pCurr->pLeft = tmp;
				}
				else
				{
					pCurr->pRight = tmp;
				}
			}
			Efficiency++;
			DataCount++;
			return 1;
		}
	}
}

bool TreeTable::DelRecord(TKey _key)
{
	if (!FindRecord(_key))
	{
		return 0;
	}
	else
	{
		TreeNode* pNode = pCurr;
		if (!pNode->pRight)
		{
			if (!pPrev)
			{
				pRoot = pNode->pLeft;
			}
			else
			{
				if (pPrev->pRight == pNode)
				{
					pPrev->pRight = pNode->pLeft;
				}
				else
				{
					pPrev->pLeft = pNode->pLeft;
				}
			}
			Efficiency++;
		}
		else
		{
			if (!pNode->pLeft)
			{
				if (!pPrev)
				{
					pRoot = pNode->pRight;
				}
				else
				{
					if (pPrev->pRight == pNode)
					{
						pPrev->pRight = pNode->pRight;
					}
					else
					{
						pPrev->pLeft = pNode->pRight;
					}
				}
				Efficiency++;
			}
			else
			{
				TreeNode* pN = pNode->pLeft;
				pPrev = pNode;
				while (pN->pRight)
				{
					pPrev = pN;
					pN = pN->pRight;
					Efficiency++;
				}
				pNode->Value = pN->Value;
				pNode->Key = pN->Key;
				if (pPrev->pRight == pN)
				{
					pPrev->pRight = pN->pLeft;
				}
				else
				{
					pPrev->pLeft = pN->pLeft;
				}
				pNode = pN;
				Efficiency++;
			}
		}
		delete pNode;
		DataCount--;
		return 1;
	}
}

TKey TreeTable::GetKey() const
{
	if (!pCurr)
	{
		throw NULL;
	}
	return pCurr->Key;
}

TValue TreeTable::GetValue() const
{
	if (!pCurr)
	{
		throw NULL;
	}
	return pCurr->Value;
}


void TreeTable::Reset()
{//drugaya
	TreeNode* pNode = pCurr = pRoot;
	while (!stack.empty())
	{
		stack.pop();
	}
	CurrPos = 0;
	while (pNode)
	{
		stack.push(pNode);
		pCurr = pNode;
		pNode = pNode->pLeft;
	}
	
}

bool TreeTable::IsEnd() const
{
	return CurrPos >= DataCount;
}

void TreeTable::GoNext()
{
	//drugaya
	if (!IsEnd() && (pCurr != NULL))
	{
		TreeNode* pNode = pCurr = pCurr->pRight;
		stack.pop();
		while (pNode)
		{
			stack.push(pNode);
			pCurr = pNode;
			pNode = pNode->pLeft;
		}
		if ((pCurr == NULL) && !stack.empty())
		{
			pCurr = stack.top();
		}
		CurrPos++;
	}
	
}