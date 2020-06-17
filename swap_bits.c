#include <stdio.h>

void swap_bits(unsigned int* pNum,  unsigned int p1,  unsigned int p2, int numbits)
{
    unsigned int mask;
    for(int i =0; i < numbits; i++, p1++, p2++)
    {
        if(((*pNum >> p1) & 1) != ((*pNum >> p2) & 1))
        {
            mask = (1u << p1) | (1u << p2) ;
            printf("P1 = %d, P2 = %d, Mask = %X\n", p1, p2, mask);
            (*pNum)^=mask;
            printf("Num after Mask = %X\n", *pNum);
        }
        else
        {
            printf(" Bits %d and %d are same\n ", p1, p2);
        }
    }
}

int main(void)
{
    unsigned int num = 0x1000;
    int pos1 = 0, pos2=12;
    int num_bits = 1;
    swap_bits(&num, pos1, pos2, num_bits);
    printf("Number after swap: %X\n", num);

}