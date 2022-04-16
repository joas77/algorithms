#include <iostream>
#include "Nothing.h"
#include "SuperSmartPointer.h"

int main()
{
    Nothing* myNothing = new Nothing();
    
    {
        SuperSmartPointer<Nothing> ptr1(myNothing);
        SuperSmartPointer<Nothing> ptr2(myNothing);
    }

    if(Nothing::sNumAllocations != Nothing::sNumDeletions)
    {
        std::cout << "TEST FAILED: " << Nothing::sNumAllocations <<
                " allocations and " << Nothing::sNumDeletions <<
                " deletions" << std::endl;
    }
    else
    {
        std::cout << "TEST PASSED" << std::endl;
    }
    

    return 0;
}
