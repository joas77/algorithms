#include <iostream>

template <typename T>
class DynArray{
public:

	DynArray():
		m_capacity(4),
		m_size(0),
		m_data(new T[m_capacity])
	{}
	
	~DynArray()
	{
		delete[] m_data;
	}
	
	T at(size_t index) const
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
};

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

int main()
{
	DynArray<int> dynArray;
	DynArray<float> dynFloat;
	
	float eps = 0.1;
	
	for(size_t i=1; i<=100; ++i)
	{
		dynArray.push_back(i);
		dynFloat.push_back(eps*i);
	}
	std::cout << dynArray;
	std::cout << "size = " << dynArray.size() << " capacity = " << dynArray.capacity() << std::endl;
	
	std::cout << dynFloat;
	std::cout << "size = " << dynFloat.size() << " capacity = " << dynFloat.capacity() << std::endl;
	
	return 0;
}
