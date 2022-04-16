#pragma once

class Nothing
{
public:
    Nothing() {sNumAllocations++;}
    ~Nothing() {sNumDeletions--;}
    static int sNumAllocations;
    static int sNumDeletions;
};

int Nothing::sNumAllocations = 0;
int Nothing::sNumDeletions = 0;
