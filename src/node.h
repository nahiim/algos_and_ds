


#include <iostream>

class Node
{
	int m_data;
	Node *m_next = nullptr;

	friend std::ostream& operator<<(std::ostream& out, Node node);

public:
	Node()
	{}

	Node(int data)
	{
		m_data = data;
	}

	int getData()
	{
		return m_data;
	}

	void setData(int data)
	{
		m_data = data;
	}

	Node* getNext()
	{
		return m_next;
	}

	void setNext(Node *node)
	{
		m_next = node;
	}
};

std::ostream& operator<<(std::ostream& out, Node *node)
{
	out << node->getData();
	return out;
}