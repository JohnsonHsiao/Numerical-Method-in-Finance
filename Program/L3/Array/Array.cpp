#include<stdio.h>
#include<stdlib.h>

int main()
{
   
   //�ܼƫŧi
	int l,m;
	float a;
    float IntFix[7];
    //��Ʀs��:
    a=0.01;
    IntFix[0]=a;
    IntFix[1]=a+IntFix[0];
    //��ƪ���J��X
    scanf("%f",&IntFix[2]);
    printf("%f",IntFix[2]);
    


	//�Q�v����J�Ωw�s��FV���p��
   printf("�Q�v����J�Ωw�s��FV���p��\n");
	for(int i=0;i<7;i=i+1)
	{//�Q�v��ƿ�J��}�C��,�ϥα����ܼ� i�M�w����\���m
	 printf("IntFix[%d]=",i);
	 scanf("%f",&IntFix[i]);
	}
    a=1*(1+IntFix[0]/12);
	printf("�@�Ӥ�w�sFV:%f\n",a);
	a=1*(1+IntFix[1]/4);
	printf("�T�Ӥ�w�sFV:%f\n",a);
	a=1*(1+IntFix[2]/2);
	printf("���Ӥ�w�sFV:%f\n",a);
	a=1*(1+IntFix[4]/2)*(1+IntFix[4]/2);
	printf("�@�~�w�sFV:%f\n",a);
	
    //�G���}�C��ƪ��ϥ�
	
	printf("�G���}�C��ƪ��ϥ�\n");
	 //�ܼƫŧi:
	
     float b[3][4];
      //��Ʀs��:
     a=0.01;
     b[0][0]=a;
     b[0][1]=a+b[0][0];
     //��ƪ���J��X
     scanf("%f",&b[0][2]);
     printf("%f",b[0][2]);
        
	
     //�ϥα_���j���J�Q�v���
	 printf("�ϥα_���j���J�Q�v���\n");
	 float Int[2][7];
	 //�Q�v��J
	 for(l=0;l<7;l++)
	 {
	  for(m=0;m<2;m++)
	  {
	    printf("Int[%d][%d]=",m,l);
		scanf("%f",&Int[m][l]);
	  }
	 }
	 //�Q�v�C�L
     printf("�T�w�Q�v\n");
	 for(l=0;l<7;l++)
	 {
	  printf("Int[0][%d]=%f\n",l, Int[0][l]);
	 }
	 printf("���ʧQ�v\n");
	 for(l=0;l<7;l++)
	 {
	  printf("Int[1][%d]=%f\n",l, Int[1][l]);
	 }   
return 0;

}
