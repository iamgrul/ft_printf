#include "ft_printf.h"
#include <stdio.h> 
//accuracy, width, type, flags
void foo(char *fmt, ...)
{

//printf("LOOL %s%u%$d$ LOOOL\n", "A", 2, 1234);
 //   ft_printf("LOOL %s%u%$d$ LOOOL\n", "A", 2, 1234);

//      printf("REAL:  LOOL %s%u%$d$ LOOOL\n %a", "A", 2, 1234);
//  ft_printf("MINE:  LOOL %s%u%$d$ LOOOL\n %a", "A", 2, 1234);

// a = printf("MINE:  LOOL %s - %d - %d - %F LOOOL\n", NULL, NULL, NULL, NULL);
//  b = ft_printf("MINE:  LOOL %s - %d - %d - %F LOOOL\n", "Aaaa", 0x12, 12, 1.45);
}
char    *ft_itoa_base(long long int value, char base);

#include <unistd.h>



int main()
{
//_:,digits,*, digit+$, +-#, space, ' .,
    // char c = 255;
    int a, b;
    // printf("INT: %d, %d, %d, %d, %d, %d\n", sizeof(signed char), 
    // sizeof(short int), sizeof(long int),  sizeof(long long int),
    //  sizeof(size_t),sizeof(intmax_t));
    // printf("F/D: %d, %d, %d\n", sizeof(float),
    // sizeof(double),sizeof(long double));
    // a = printf("REAL: %-120§1±1!1@1#1$1%1^1&1*1(1)1_1+QWERTYUIOP1{1{1{1}ASDFGHJKL1:\"1|1~1Z1X1C1V1B1N1M1<1>1?1}1}  Q d\n","123ааа", 2,3,4, 0.256119 , 5);
    //   a = printf("REAL: %*Q %d d\n","123ааа", 2,3,4, 0.256119 , 5); - interesniy error;

// char *str = "123";
    // a = printf("REAL: %d %5d  \n",  1000000, 2 ,3 , 5);

//  b = ft_printf("MINE:\n %3$1231231.:021390123.s:213-#x %1 0.4#-0+f %#x %#x  %#x  %#x  \n",  -5,3,4, 0.256119 , 6);
	b = ft_printf("MINE: %d %5d  \n",  1, 2 ,3 , 5);
    printf("\n");
    printf("YOUR: %d %5d  \n",  1, 2 ,3 , 5);
    // printf("R = %d :: M = %d\n", a, b);

//  long long int aaa = 9,223,372,036,854,775,807;
// long long int bbb = aaa;
// printf("%llu", bbb);
	return (0);

}

