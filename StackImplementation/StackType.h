template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType> *next;
};

template<class ItemType>
class StackType
{
public:
	StackType(void);
	void MakeEmpty();
	bool IsEmpty();
	void Push(ItemType Item);
	void Pop();
	ItemType RetrieveItem(int i);
	~StackType(void);
private:
	NodeType <ItemType> *topPtr;
	int _size;
};

template<class ItemType> StackType<ItemType>::StackType(void)
{
	topPtr = nullptr;
	_size = 0;
}

template<class ItemType> bool StackType<ItemType>::IsEmpty()
{
	return (topPtr == nullptr);
}

template<class ItemType> void StackType<ItemType>::MakeEmpty()
{
	topPtr = nullptr;
	_size = 0;
}


template<class ItemType> void StackType<ItemType>::Push(ItemType newItem)
{
	NodeType<ItemType> *location;
	location = new NodeType<ItemType>;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
	_size++;
}

template<class ItemType> void StackType<ItemType>::Pop()
{
	if(IsEmpty())
	{
		throw("Pop On Empty Stack");
	}
	NodeType<ItemType> *tempPtr;
	tempPtr = topPtr;
	topPtr = topPtr->next;
	delete tempPtr;
	_size--;
}

template<class ItemType>ItemType StackType<ItemType>::RetrieveItem(int index)
{
	if(index>_size)
	{
		throw("index exceeds stack size.");
	}
	NodeType<ItemType> *tempPtr;
	tempPtr = topPtr;
	for(int i =0;i<_size-index-1;i++)
	{
		tempPtr=tempPtr->next;
	}
	return tempPtr->info;
}



template<class ItemType> StackType<ItemType>::~StackType(void)
{
}
