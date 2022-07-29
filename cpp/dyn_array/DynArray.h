template <typename T>
class DynArray{
public:

	DynArray():
		m_capacity(4),
		m_size(0),
		m_data(new T[m_capacity])
	{}
	
	DynArray(const DynArray<T>& dynArr);
	DynArray(DynArray<T>&&) = delete;
	DynArray<T>& operator=(const DynArray<T>&);
	
	~DynArray()
	{
	    free();
	}
	
	T& at(size_t index) const
	{
		return m_data[index];
	}
	
	void push_back(T elem)
	{
		if(m_size<=m_capacity)
		{
			m_data[m_size] = elem;
			m_size++;
		}
		else
		{
			m_capacity*=2;
			T* tempData = new T[m_capacity];
			
			for(size_t i=0; i< size(); i++)
			{
				tempData[i] = at(i);
			}
	
			delete[] m_data;
			
			m_data = tempData;
			
			m_data[m_size] = elem;
			m_size++;
			
		}
	}
	
	size_t size() const
	{
		return m_size;
	}
	
	size_t capacity() const
	{
		return m_capacity;
	}

private:
	size_t m_capacity;
	size_t m_size;
	T* m_data;
	void copy(const DynArray<T>& src);
	void free();
};

template<typename T>
void DynArray<T>::free()
{
    if(m_data)
    {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity=0; 
    }
}

template<typename T>
void DynArray<T>::copy(const DynArray<T>& src)
{
    for(size_t i=0; i<src.size(); i++)
    {
        push_back(src.at(i));
    }
}

// copy constructor
template<typename T>
DynArray<T>::DynArray(const DynArray<T>& src)
    : DynArray()
{
    copy(src);
}

template<typename T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& rhs)
{
    if(this == &rhs) return *this;
        
    free();
    m_capacity = 4;
    m_data = new T[m_capacity];
    
    copy(rhs);
        
   return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const DynArray<T>& dynArr)
{
	os<< "[ ";
	for(size_t i=0; i< dynArr.size(); i++)
	{
		os << dynArr.at(i) << " ";
	}
	 return os << "]" << std::endl;
}

template <typename T>
void dynArrInfo(const DynArray<T>& dynArr)
{
    std::cout << dynArr;
    std::cout << "size = " << dynArr.size() << " capacity = " << 
        dynArr.capacity() << std::endl;
}

