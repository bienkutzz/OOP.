#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
float n;

int f( float n,bool isRoundedTo100){

if(isRoundedTo100==false)
    return round(n);

return n*100;


}
int main()
{

scanf("%f",&n);
int rasp=f(n,false);
printf("%d ", rasp);
    return 0;
}
