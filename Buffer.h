/*
 * Copyright (C) 2004-2007  See the AUTHORS file for details.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 */

#ifndef _BUFFER_H
#define _BUFFER_H

#include "String.h"
#include <vector>
using std::vector;

class CBufLine {
public:
	CBufLine(const CString& sPre, const CString& sPost, bool bIncNick);
	virtual ~CBufLine();
	void GetLine(const CString& sTarget, CString& sRet);

	const CString& GetPre() const { return m_sPre; }
	const CString& GetPost() const { return m_sPost; }
	bool GetIncNick() const { return m_bIncNick; }

	void SetPre(const CString& s) { m_sPre = s; }
	void SetPost(const CString& s) { m_sPost = s; }
	void SetIncNick(bool b) { m_bIncNick = b; }

private:
protected:
	CString	m_sPre;
	CString	m_sPost;
	bool	m_bIncNick;
};

class CBuffer : private vector<CBufLine> {
public:
	CBuffer(unsigned int uLineCount = 100);
	virtual ~CBuffer();

	int AddLine(const CString& sPre, const CString& sPost, bool bIncNick = true);
	/// Same as AddLine, but if there is already a line with sPre it is replaced.
	int UpdateLine(const CString& sPre, const CString& sPost, bool bIncNick = true);
	bool GetNextLine(const CString& sTarget, CString& sRet);
	bool GetLine(const CString& sTarget, CString& sRet, unsigned int uIdx);
	bool IsEmpty() { return empty(); }
	void Clear() { clear(); }

	// Setters
	void SetLineCount(unsigned int u) { m_uLineCount = u; }
	// !Setters

	// Getters
	unsigned int GetLineCount() const { return m_uLineCount; }
	// !Getters
private:
protected:
	unsigned int	m_uLineCount;
};

#endif // !_BUFFER_H
