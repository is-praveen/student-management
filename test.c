#include<stdio.h>
#include<stdlib.h>
int main()
{
    char c;
    FILE *fp;
    fp=fopen("record.txt","r");
    if(fp==NULL)
    {
        printf("Error opening file");
        exit(0);
    }

    printf("\nThe data in the file is \n");
    while(!feof(fp))
    {
        c=getc(fp);
        printf("%c",c);
    }
    fclose(fp);
}