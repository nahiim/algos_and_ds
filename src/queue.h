
// Queue data structure

#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 5

class Queue
{
private:
    int m_items[SIZE], m_front, m_rear;

public:
    Queue()
    {
        m_front = -1;
        m_rear = -1;
    }

    bool isFull()
    {
        return (m_front == 0 && m_rear == SIZE - 1);
    }

    bool isEmpty()
    {
        return (m_front == -1);
    }

    void enQueue(int element)
    {
        if (isFull())
        {
            std::cout << "Queue is full";
        }
        else
        {
            if (m_front == -1)
            {
                m_front = 0;
            }
            m_rear++;
            m_items[m_rear] = element;
            std::cout << std::endl << "Inserted " << element << std::endl;
        }
    }

    int deQueue()
    {
        int element;
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return (-1);
        }
        else
        {
            element = m_items[m_front];
            if (m_front >= m_rear)
            {
                m_front = -1;
                m_rear = -1;
            } /* Q has only one element, so we reset the queue after deleting it. */
            else
            {
                m_front++;
            }
            std::cout << std::endl << "Deleted -> " << element << std::endl;

            return (element);
        }
    }

    void display()
    {
        /* Function to display elements of Queue */
        int i;
        if (isEmpty())
        {
            std::cout << std::endl << "Empty Queue" << std::endl;
        }
        else
        {
            std::cout << std::endl << "m_Front index-> " << m_front;
            std::cout << std::endl << "m_Items -> ";
            for (i = m_front; i <= m_rear; i++)
            {
                std::cout << m_items[i] << "  ";                
            }
            std::cout << std::endl << "Rear index-> " << m_rear << std::endl;
        }
    }
};


#endif





// Driver code
// int main()
// {
//     std::cout << "\n\t\t:: ::\n\n";


//     Queue q;

//     //deQueue is not possible on empty queue
//     q.deQueue();

//     //enQueue 5 elements
//     q.enQueue(1);
//     q.enQueue(2);
//     q.enQueue(3);
//     q.enQueue(4);
//     q.enQueue(5);

//     // 6th element can't be added to because the queue is full
//     q.enQueue(6);

//     q.display();

//     //deQueue removes element entered first i.e. 1
//     q.deQueue();

//     //Now we have just 4 elements
//     q.display();


//     std::cout << "\n\n\n\n  PRESS ENTER TO EXIT(): ";
//     std::cin.get();
//     std::cin.get();
// }