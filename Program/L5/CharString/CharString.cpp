#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 
 //字元
 char a=33;
 char b='B';  
 printf("%d %c\n",a,a);
 printf("%d %c\n",b,b);
 a=a+b;
 printf("%d %c\n",a,a);
 //字串
 char c[4];
 c[0]='H';
 c[1]=105;
 c[2]=0;
 printf("%s\n",c);
 
 //字串處理函式
  
  char D[20], E[20];  
  strcpy(D,c);
  strcat(D,"story");
  printf("%s\n",D);
  while(strcmp(D,E)!=0)
  {
   printf("Input a string:");
   scanf("%s",E);  
  }	
  
  //檔案處理函式
  FILE* Read=fopen("ReadTest.txt","r");
  FILE* Write=fopen("WriteTest.txt","w"); 
  char Name[4][20], Date[20];
  float Index[3];
  fscanf(Read,"%s %s %s %s", Name[0],Name[1],Name[2],Name[3]);
  printf("%7s %7s %7s %9s\n", Name[0],Name[1],Name[2],Name[3]);
  while(fscanf(Read,"%s %f %f %f",Date,&Index[0],&Index[1],&Index[2])!=EOF)
  {
   printf("%7s %7.2f %7.2f %7.2f\n",Date,Index[0],Index[1],Index[2]);
   fprintf(Write, "%f %f %f %s\n", Index[0],Index[1],Index[2],Date);
  }
  fclose(Write);
  fclose(Read);

system("pause");
return 0;
}
