class MyQueue 
{
	class  elem
	{
	public:
		int data;
		elem *prev;
		elem *next;
	};
	int size;
	elem *head;
	elem* tail;
};