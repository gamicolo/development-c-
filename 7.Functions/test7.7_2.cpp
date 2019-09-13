#include <iostream>
#include <stdio.h>
#include <string.h>

void loop_aux(void* base, size_t n, size_t sz)
{
    for ( int gap=n/2; 0<gap; gap/=2 )
        for (int i = gap; i != n; i++)
            for (int j=i-gap; 0<=j;j -=gap){
                char* b = static_cast<char*> (base);
                char* pj = b + j * sz;
                char* pjg = b + (j + gap) * sz;
            }
}
int main()
{
}
