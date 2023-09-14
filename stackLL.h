

class stackLL
{
private:
	class node
	{
	public:
		//put what you need in here
		int data;
		node * link;

	};

	node * top = NULL;

public:

	stackLL()
	{
		top = nullptr;
	}

	//Take care of memory leaks...
	~stackLL()
	{
		while (!empty())
		{
			pop();
		}
	}

	//return true if empty, false if not
	bool empty()
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}

	//add item to top of stack
	void push(int x)
	{
		if(empty())
		{
			node *ptr = new node();
			ptr->data = x;
			ptr->link = top;
			top = ptr;	
		}

	}

	//remove and return top item from stack
	int pop()
	{
		if(!empty())
		{
			node *ptr = top;
			int data = ptr->data;
			top = top ->link;
			delete(ptr);
			return data;
		}
		return -1;
	}

	//add item x to stack, but insert it
	//right after the current ith item from the top
	//(and before the i+1 item).
	void insertAt(int x, int i)
	{
		if (i == 0 || empty())
		{
			push(x);
			return;
		}

		node *ptr = top;
		int count = 0;
		
		while (count< i -1 && ptr != nullptr)
		{
			ptr = ptr->link;
			count++;
		}
		
		node *newNode = new node;
		newNode->data = x;
		newNode->link = ptr->link;
		ptr->link = newNode;
	}
};