// CmdPaste.cpp: implementation of the CCmdPaste class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hl.h"
#include "CmdPaste.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCmdPaste::CCmdPaste(CHLDoc *pDoc)
{
	commandName.LoadString(IDS_COMMAND_PASTE);
	m_pDoc=pDoc;
//	m_chainOld=pDoc->GetChain();
	m_chainOld.StoreChain(pDoc->GetChain());
	m_pDoc->PasteCmd();
//	m_chainNew=pDoc->GetChain();
	m_chainNew.StoreChain(pDoc->GetChain());
	m_bFirst=TRUE;
}

CCmdPaste::~CCmdPaste()
{

}

BOOL CCmdPaste::Do(BOOL bRedo )
{	
	if(m_bFirst)
		m_bFirst=FALSE;
	else
		m_pDoc->SetChain(m_chainNew);
	return TRUE;
}

BOOL CCmdPaste::Undo(BOOL bRedo)
{
	m_pDoc->SetChain(m_chainOld);
	return TRUE;
}
