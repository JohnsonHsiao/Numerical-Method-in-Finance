#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{//�����Ѫk�h�@�M�k�h�����������
  FILE* Read=fopen("R.txt","r");
  FILE* Write=fopen("Report.txt","w"); 
  char Name[4][20], Date[20];
  float Index[3];
  fscanf(Read,"%s %s %s", Name[0],Name[1],Name[2]);  //Ū�����ƪ��s��
  fscanf(Read,"%s %s %s %s", Name[0],Name[1],Name[2],Name[3]);//Ū�����ƦW��
  double Profit=0;   //�p�����
  double Avg=0,PreAvg=0; //�\�񲾰ʥ���
  double BuyCost;  //�\���ʶR���� 
  double MAArray[5]; //�\��񤭤骺�Ъ������� 
  int  Buy=0, ArrayPtr=0, Count=0;
  fprintf(Write, "%s %s %s %s %s\n", "���", "�Ъ���", "�Ъ�������", "�l�q", "����");
  while(fscanf(Read,"%s %f %f %f",Date,&Index[0],&Index[1],&Index[2])!=EOF)
  {
    MAArray[ArrayPtr]=Index[0];
	ArrayPtr=(ArrayPtr+1)%5;
	Count=Count+1;    
    if(Count<5) continue;
	PreAvg=Avg;
	Avg=0;
	for(int i=0;i<5;i++)
	{ Avg=Avg+MAArray[i];}
	Avg=Avg/5;
	if(Count==5) continue;
	if((Buy==0)&&(Avg>=PreAvg)&&(Index[0]>=Avg))
	{//�R�i
	 BuyCost=Index[0];
	 Buy=1;
	}
	if((Buy==1)&&(Avg<=PreAvg)&&(Index[0]<=Avg))
	{//��X
	 Profit=Profit+(Index[0]-BuyCost);
	 Buy=0;
	}
	fprintf(Write, "%s %f %f %f %d\n", Date, Index[0], Avg, Profit, Buy);
  }
   if(Buy==1)
   {
	Profit=Profit+(Index[0]-BuyCost);
    fprintf(Write,"����: %f",Profit);
   }
  fclose(Write);
  fclose(Read);

system("pause");
return 0;
}
