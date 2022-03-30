#include <iostream>
#include "DynArray.h"


int main()
{
	DynArray<int> dynArray;
	DynArray<float> dynFloat;
	DynArray<DynArray<int> > dynDynArr;
	
	float eps = 0.1;
	
	for(size_t i=1; i<=100; ++i)
	{
		dynArray.push_back(i);
		dynFloat.push_back(eps*i);
		
		//dynDynArr.push_back(dynArray); // double free or corruption
	}

	dynArrInfo(dynArray);
	dynArrInfo(dynFloat);
	dynArrInfo(dynDynArr);
	
	return 0;
}
