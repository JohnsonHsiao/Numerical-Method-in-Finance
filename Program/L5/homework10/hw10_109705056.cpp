#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* Read = fopen("Read.txt", "r");
    FILE* Write = fopen("Report.txt", "w");
    char Name[4][20], Date[20];
    float Index[3];
    fscanf(Read, "%s %s %s", Name[0], Name[1], Name[2]); //讀取指數的編號
    fscanf(Read, "%s %s %s %s", Name[0], Name[1], Name[2], Name[3]); //讀取指數名稱

    double AvgTai, AvgEle, AvgFin;
    double MATaiArray[5], MAEleArray[5], MAFinArray[5]; //擺放近五日的台指、電子指、金融指價格
    int ArrayPtr = 0, Count = 0;

    fprintf(Write, "%s %s %s %s %s %s %s %s %s %s\n", "Date", "年", "月", "日", "台指", "台指MA", "電子指", "電子指MA", "金融指", "金融指MA");

    while (fscanf(Read, "%s %f %f %f", Date, &Index[0], &Index[1], &Index[2]) != EOF)
    {
        MATaiArray[ArrayPtr] = Index[0];
        MAEleArray[ArrayPtr] = Index[1];
        MAFinArray[ArrayPtr] = Index[2];
        ArrayPtr = (ArrayPtr + 1) % 5;
        Count = Count + 1;
        if (Count < 5)
            continue;
        AvgTai = 0;
        AvgEle = 0;
        AvgFin = 0;
        for (int i = 0; i < 5; i++)
        {
            AvgTai = AvgTai + MATaiArray[i];
            AvgEle = AvgEle + MAEleArray[i];
            AvgFin = AvgFin + MAFinArray[i];
        }
        AvgTai = AvgTai / 5;
        AvgEle = AvgEle / 5;
        AvgFin = AvgFin / 5;
        int year, month, day;
        sscanf(Date, "%d/%d/%d", &year, &month, &day);
        fprintf(Write, "%s %d %d %d %f %f %f %f %f %f\n", Date, year, month, day, Index[0], AvgTai, Index[1], AvgEle, Index[2], AvgFin);
    }

    fclose(Write);
    fclose(Read);

    return 0;
}
