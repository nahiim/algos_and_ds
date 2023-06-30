
// Linkd List implementation

#include "node.h"

class LList
{
	Node *m_head = nullptr;

	friend std::ostream& operator<<(std::ostream& out, LList list);

public:
	LList()
	{}

	void setHead(Node *node)
	{
		m_head = node;
	}

	void prepend(int data)
	{
		Node *new_node = new Node(data);
		new_node->setNext(m_head);
		setHead(new_node);
	}

	void insert(int data, int index)
	{
		if(index == 0)
		{
			prepend(data);
		}
		else if(index > 0)
		{
			Node *new_node = new Node(data);
			int position = index;
			Node *current = m_head;
			while(position > 1)
			{
				current = current->getNext();
				position -= 1;
			}
			Node *prev = current;
			Node *next = current->getNext();

			prev->setNext(new_node);
			new_node->setNext(next);
		}
		else
		{
			std::cout << "invalid index" << std::endl;
		}
	}


	// void append(int data)
	// {
	// 	Node *new_node = new Node(data);
	// 	new_node->setNext(m_head);
	// 	while(new_node != nullptr)
	// 	{
	// 		new_node = new_node->getNext();
	// 	}
	// 	new_node->setData(data);
	// 	new_node->setNext(nullptr);
	// }

	bool isEmpty()
	{
		return m_head == nullptr;
	}

	int size()
	{
		int count = 0;
		Node *current = m_head;

		while (current != nullptr)
		{
			count++;
			current = current->getNext();
		}

		return count;
	}

	Node* search(int data)
	{
		Node *current = m_head;
		while(current != nullptr)
		{
			if(current->getData() == data)
			{
				current->setData(data);
				return current;
			}
			else
			{
				current = current->getNext();
			}
		}

		return nullptr;
	}
};


std::ostream& operator<<(std::ostream& out, LList list)
{
	Node *current = list.m_head;

	while(current != nullptr)
	{
		std::cout << current << " ";
		current = current->getNext();
	}

	return out;
}



// Driver code
// int main()
// {
//     std::cout << "\n\t\t:: ::\n\n";


//     LList al;
//     Node *n;

//     al.prepend(3);
//     al.prepend(9);
//     al.prepend(1);
//     al.prepend(5);
//     al.prepend(7);
//     al.prepend(4);
//     al.insert(6, 4);

//     std::cout << al << std::endl;


//     std::cout << "\n\n\n\n  PRESS ENTER TO EXIT(): ";
//     std::cin.get();
// }