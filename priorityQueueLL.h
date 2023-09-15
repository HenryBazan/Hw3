template <class T>
class priorityQueueLL
{
private:
    class node
    {
    public:
        // Put what you need here.
        T data;
        node* next;
    };

    // Add what you wish here.

public:
    priorityQueueLL()
    {}

    ~priorityQueueLL()
    {}

    // Return true if empty, false if not.
    bool empty()
    {}

    // Add an item.
    void insert(T x)
    {}

    // Remove and return the smallest item.
    T extractMin()
    {}
};

/*
template <class T>
class priorityQueueLL
{
private:
	class node
	{
	public:
		//put what you need here..
		T data;
		int priority;
		node* next;

		node(const T& item, int prio) : data(item), priority(prio), next(nullptr)
		{}
	};

	//add what you wish here
	node *front;
	
public:

	priorityQueueLL() : front(nullptr)
	{}

	~priorityQueueLL()
	{
		while (!empty())
		{
			extractMin();
		}
	}

	//return true if empty, false if not
	bool empty()
	{
		return front == nullptr;
	}

	//add item
	void insert(const T& x, int priority)
	{
		node *newNode = new node(x, priority);

		if (empty() || priority < front->priority)
		{
			newNode->next=front;
			front=newNode;
		}
		else
		{
			node *current=front;
			while(current->next !=nullptr && current->next->priority<=priority)
			{
				current = current->next;
			}
			newNode->next=current->next;
			current->next=newNode;
		}
	}

	//remove and return smallest item
	T extractMin()
	{
		if (empty())
		{
			throw std::runtime_error("Priority queue is empty");
		}

		T data = front->data;
		node *temp=front;
		front=front->next;
		delete temp;
		return data;
	}

};
*/