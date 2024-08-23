#include <iostream >
#include <math.h >
using namespace std;
void upper (char p);
void lower (char p);
int main ()
{
    char a[50]= "extempore" ;
    int i ;
    for (i=0;a[i]!='\0';i++)
    {
        if (i%2==0)
        {
            upper (a[i]);
        }
        else
        {
            lower (a[i]);
        }
    }
}
void upper ( char p ) // for telling the values
{
    if (p>=97 && p<=122)
    {
        p=p-32;
    }
     cout <<p;
}
void lower (char p)
{
if (p>=65  && p<= 90 )
{
    p=p+32;
}
cout <<p ;
}