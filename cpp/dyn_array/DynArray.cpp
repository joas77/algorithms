#include <iostream>

class DynArray{
public:

	DynArray():
		m_capacity(4),
		m_size(0),
		m_data(new int[m_capacity])
	{}
	
	~DynArray()
	{
		delete[] m_data;
	}
	
	int at(size_t index) const
	{
		return m_data[index];
	}
	
	void push_back(int elem)
	{
		if(m_size<=m_capacity)
		{
			m_data[m_size] = elem;
			m_size++;
		}
		else
		{
			m_capacity*=2;
			int* tempData = new int[m_capacity];
			
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
	int* m_data;
};

std::ostream& operator<<(std::ostream& os, const DynArray& dynArr)
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
	DynArray dynArray;
	
	for(size_t i=1; i<=100; ++i)
	{
		dynArray.push_back(i);
	}
	std::cout << dynArray;
	std::cout << "size = " << dynArray.size() << " capacity = " << dynArray.capacity() << std::endl;
	std::cout << "hola mundo c++ windows\n";
	
	return 0;
}
