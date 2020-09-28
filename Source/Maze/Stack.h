#pragma once
#include <stdexcept>

template<typename T>
class Stack
{

public:
	Stack()
	{
		phead = NULL;
		size = 0;
	}

	~Stack()
	{
		if (phead)
			ReleaseNode(phead);
	}

	size_t Size()const
	{
		return size;
	}

	bool Empty()const
	{
		return size == 0;
	}

	void Push(const T& val)
	{
		if (size == 0)
		{
			phead = new Node;
			phead->content = val;
			size = 1;
		}
		else
		{
			Node* pnew = new Node;
			pnew->content = val;
			size += 1;
			pnew->pnext = phead;
			phead = pnew;
		}
	}
	T& Top()
	{
		if (phead)
			return phead->content;
		else
			throw std::out_of_range("the size is zero");
	}
	const T& Top()const
	{
		if (phead)
			return phead->content;
		else
			throw std::out_of_range("the size is zero");
	}
	void Pop()
	{
		if (phead)
		{
			size -= 1;
			Node* pbuffer = phead->pnext;
			delete phead;
			phead = pbuffer;
		}
		else
			throw std::out_of_range("the size is zero");
	}
private:

	struct Node
	{
		T content;
		Node* pnext;

		Node()
		{
			pnext = NULL;
		}
	};

	void ReleaseNode(Node* p)
	{
		if (p->pnext)
			ReleaseNode(p->pnext);
		delete p;
	}

	Node* phead;

	size_t size;
};