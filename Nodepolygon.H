// NodePolygon.h: interface for the CNodePolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODEPOLYGON_H__839F81C6_5196_11D4_9563_00105A6155CA__INCLUDED_)
#define AFX_NODEPOLYGON_H__839F81C6_5196_11D4_9563_00105A6155CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Node.h"
class CNodePolygon : public CNode  
{
public:
	virtual void DelRect(CWnd *pWnd);
	virtual void AddRect(CWnd *pWnd);
	virtual BOOL Create(CQuad &rect);
	virtual BOOL Track(CWnd* pWnd, CPoint ptOrg);
	virtual void Serialize(FILE* fp,BOOL bFlag);

	CNodePolygon();
	virtual ~CNodePolygon();

private:
	int m_nNum;			//����α���
	int m_nPolygon;		//���������
	int m_nCross;		//��������ѡ��
	int m_nStar;		//����ѡ��

};

#endif // !defined(AFX_NODEPOLYGON_H__839F81C6_5196_11D4_9563_00105A6155CA__INCLUDED_)