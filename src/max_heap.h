
// Max Heap Implementation

#include <vector>


#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define INIT_SIZE 20

class MaxHeap
{
private:
	int m_size, m_count;
	std::vector<int> m_arr;

	friend std::ostream& operator<<(std::ostream& out, MaxHeap heap);


public:

	MaxHeap()
	{
		m_count = 0;
		m_size = INIT_SIZE;
		m_arr.resize(m_size);
	}

	int getCount()
	{
		return m_count;
	}

	int getSize()
	{
		return m_arr.size();
	}

	int peek()
	{
		return m_arr[0];
	}

	void heapify(int index)
	{
		int left, right, largest;

		left  = 2*index + 1;
		right = 2*index + 2;

		largest = index;

		if(left <= m_count && m_arr[left] > m_arr[largest])
		{
			largest = left;
		}
		if(right <= m_count && m_arr[right] > m_arr[largest])
		{
			largest = right;
		}
		if(largest != index)
		{
			int temp = m_arr[index];
			m_arr[index] = m_arr[largest];
			m_arr[largest] = temp;

			heapify(largest);
		}
	}

	void push(int value)
	{
		if(m_count == m_size)
		{
			m_size++;
			m_arr.resize(m_size);
		}
		m_count++;
		m_arr[m_count-1] = value;
		int current = m_count-1;

		// Percolate up
		while(current > 0 && m_arr[(current-1) / 2] < m_arr[current])
		{
			int temp = m_arr[(current-1) / 2];
			m_arr[(current-1) / 2] = m_arr[current];
			m_arr[current] = temp;

			current = (current-1) / 2;
		}
	}


	int pop()
	{
		if(m_count <= 0)
		{
			std::cout << " Underflow" << std::endl;
			return -1;
		}

		int current = 0;
		int popped = m_arr[0];
		m_arr[0] = m_arr[m_count-1];
		m_count--;

		heapify(0);

		return popped;
	}
};


std::ostream& operator<<(std::ostream& out, MaxHeap heap)
{
	for(int i = 0; i < heap.m_count; i++)
	{
		out << "|" << heap.m_arr[i] << "| ";
	}

	return out;
}


#endif





// Driver code
// int main()
// {
//     std::cout << "\n\t\t:: ::\n\n";


//     MaxHeap heap;
//     heap.push(1);
//     heap.push(5);
//     heap.push(3);
//     heap.push(7);
//     heap.push(9);
//     heap.push(8);


//     std::cout << heap;

//     heap.pop();
//     std::cout << "\n" << heap;

//     heap.pop();
//     std::cout << "\n" << heap;

//     heap.pop();
//     std::cout << "\n" << heap;

//     heap.pop();
//     std::cout << "\n" << heap;

//     std::cout << "\n\n\n\n  PRESS ENTER TO EXIT(): ";
//     std::cin.get();
// }