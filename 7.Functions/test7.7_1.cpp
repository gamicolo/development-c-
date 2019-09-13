#include <iostream>
#include <stdio.h>
#include <string.h>

struct User{
    char* name;
    char* id;
    int dept;
};

User heads[]={
    "Richie", "dmr", 1,
    "Sethi", "ravi",2,
    "Tanenbaum", "tnm",3,
    "Kernighan", "bwk",4
};

void print_id(User* v, int n)
{
    for (int i=0; i<n;i++)
        std::cout<<v[i].name<<'\t'<<v[i].dept<<'\t'<<v[i].dept<<'\n'<<std::endl;
}

int cmp1( const void* p, const void* q ) //compare name strings
{
    return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
}

int cmp2( const void* p, const void* q ) //compare dept numbers
{
    return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
}

typedef int(*CFT) (const void*, const void*) ;

void ssort (void* base, size_t n, size_t sz, CFT cmp)
/*
Sort the "n" elements of vector "base" into increasing order
using the comparison function pointed to by "cmp".
The elements are of size "sz".
Shell sort (Knuth, Vol3, pg84)
*/
{
    for ( int gap = n/2; 0<gap; gap/=2 ){
        for (int i = gap; i!=n; i++){
            for (int j = i−gap; 0<=j; j−=gap) {
                char∗ b = static_cast<char∗>(base); // necessar y cast
                char∗ pj = b+j∗sz;                  // &base[j]
                char∗ pjg = b+(j+gap)∗sz;           // &base[j+gap]

                if (cmp( pjg,pj )<0) {             // swap base[j] and base[j+gap]:
                    for (int k=0; k!=sz; k++) {
                        char temp = pj[k];
                        pj[k] = pjg[k];
                        pjg[k] = temp;
                    }
                }
            }
        }
    }
}

int main()
{
    std::cout<<"Heads in alphabetical order:\n";
    ssort(heads,4,sizeof(User),cmp1);
    print_id(heads,4);
    std::cout<<"\n";

    //std::cout<<"Heads in alphabetical order:\n";
    //ssort(heads,4,sizeof(User),cmp2);
    //print_id(heads,4);
    //std::cout<<"\n";
}
