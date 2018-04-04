#pragma once

#include <list>

class CObject {
public:
	virtual ~CObject();
	CObject();
};

class CDerived : public CObject {
public:
	~CDerived();
	CDerived();
};

class CStack {
public:
	void Push(CObject* obj);
	void Pop();
	int size() const;
	void Unwind(const int size);
private:
	std::list<CObject*> stack;
};