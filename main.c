#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alphanum.h"

int main()
{
    int length;
    char c[999999];
    int frequency[70];
    int i=0;
    int k=0;
    srand(time(NULL));
  printf("How long should it be? (cannot exceed 999999)\n");
  scanf("%d",&length);

  char password[length];

  FILE *f;
  f = fopen("password.txt", "w");
   if(f == NULL)
   {
      printf("Error!");
      exit(1);
   }
  for(k;k<length;k++){
    password[k]=alphanum[rand()%70];
    fprintf(f,"%c",password[k]);
    }
    fprintf(f,"\n");
   fclose(f);

    if ((f = fopen("password.txt", "r")) == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fscanf(f,"%[^\n]", c);

    for(k=0; k<70;k++){
       for(i = 0; c[i] != '\0'; ++i)
   {
       if(alphanum[k] == c[i])
           ++frequency[k];
   }
   printf("Frequency of %c = %d\n", alphanum[k], frequency[k]);
    }
    fclose(f);
    return 0;
}
