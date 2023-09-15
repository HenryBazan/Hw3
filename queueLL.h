
class queueLL
{
private:
	//put what you need here...
	class Node
	{
		public:
			int data;
			Node *next;
	};
	Node *front = NULL;
	Node *rear = NULL;
	
public:
	queueLL()
	{
		front = nullptr;
		rear = nullptr;
	}

	~queueLL()
	{}

	//add item to back of queue
	void enqueue(int x)
	{
		Node *ptr = new Node();
		ptr->data = x;
		ptr->next = NULL;

		if (front == NULL)
		{
			front = ptr;
			rear = ptr;
		}
		else
		{
			rear ->next = ptr;
			rear = ptr;
		}
	}

	//remove and return first item from queue
	int dequeue()
	{
		if(front == rear)
		{
			int data =  front->data;
			delete(front);
			front = rear = NULL;
			return data;
		}
		else
		{
			int data = front->data;
			Node *ptr = front;
			front = front ->next;
			delete(ptr);
			return data;
		}
		return -1;
	}

    bool empty() const
    {
        return front==nullptr;
    }

	//For the final part of the test program, template this class
	//and add a decimate method.

	void decimate(int n)
{
    if (n <= 1)
    {
        // Nothing to do if n is less than or equal to 1.
        return;
    }

    if (n == 2)
    {
        // If n is 2, we can optimize the process to avoid unnecessary removals.
        // We'll just dequeue every alternate element starting from the front.
        Node *current = front;
        Node *prev = nullptr;
        bool remove = false;

        while (current != nullptr)
        {
            if (remove)
            {
                Node *next = current->next;
                if (prev == nullptr)
                {
                    front = next;
                }
                else
                {
                    prev->next = next;
                }
                delete current;
                current = next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
            remove = !remove;
        }

        if (prev == nullptr)
        {
            // All elements were removed; update rear.
            rear = nullptr;
        }
        else
        {
            // Update rear to the last remaining element.
            rear = prev;
        }

        return;
    }

    // General case: Remove every nth element.
    Node *current = front;
    Node *prev = nullptr;
    int count = 1;

    while (current != nullptr)
    {
        if (count % n == 0)
        {
            Node *next = current->next;
            if (prev == nullptr)
            {
                front = next;
            }
            else
            {
                prev->next = next;
            }
            delete current;
            current = next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
        count++;
    }

    if (prev == nullptr)
    {
        // All elements were removed; update rear.
        rear = nullptr;
    }
}

};