
// Stack data structure

#ifndef STACK_H
#define STACK_H


#define MAX 10


class Stack
{
private:
	int m_items[MAX];
	int m_top;
	int m_size;


public:

	Stack()
	{
		m_top = -1;
		m_size = 0;
	}

	// Check if the stack is full
	bool isFull()
	{
	    return (m_top == MAX);
	}

	// Check if the stack is empty
	bool isEmpty()
	{
	    return (m_top == -1);
	}

	// Add elements into stack
	void push(int new_item)
	{
		if (isFull())
		{
	    	std::cout << " STACK FULL";
		}
		else
		{
		    m_top++;
		    m_items[m_top] = new_item;
			m_size++;
		}
	}

	// Remove element from stack
	void pop()
	{
		if (isEmpty())
		{
	    	std::cout << "\n STACK EMPTY \n";
	  	}
	  	else
	  	{
	    	std::cout << " Item popped = " << m_items[m_top];
	    	m_top--;
		  	m_size--;
		}
	  	std::cout << std::endl;
	}

	// Print elements of stack
	void printStack()
	{
		std::cout << " Stack: ";
		for (int i = 0; i < m_size; i++)
		{
			std::cout << m_items[i] << " ";
		}
	  	std::cout << std::endl;
	}
};


#endif






// int int main(int argc, char const *argv[])
// {
//     Stack *s = new Stack();

//     s->push(1);
//     s->push(2);
//     s->push(3);
//     s->push(4);

//     s->printStack();

//     s->pop();
    
//     std::cin >> a;

//     std::cout << "\n After popping out\n";
//     s->printStack();

// 	return 0;
// }