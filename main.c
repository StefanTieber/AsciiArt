#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ANZ 12

int main()
{
    const char einpfad[128]=
    {"C:\\Users\\Steve\\Pictures\\programme\\ascii\\ascii2\\lt.ppm"};

    FILE *ein;

    int i,j,l;

    char head[256];

    int x,y,t;

    int pixelsumme;
    int farbton;

    char zeichen[ANZ]=
    {'@','Q','W','R','G','E','Y','s','*','!',':','.'};

    system("color F0");

    ein=fopen(einpfad,"rb");

    if(ein==NULL)
    {
        printf("File not found!\n");
    }
    else
    {
        for(j=0; (head[j]=fgetc(ein))!='\n'; j++);
        head[j+1]=0;

        if(!((head[0]=='P')&&(head[1]=='6')))
        {
            printf("Wrong format!\n");
        }
        else
        {
            do
            {
                for(j=0; (head[j]=fgetc(ein))!='\n'; j++);
                head[j+1]=0;
            }
            while(head[0]=='#' || head[0]=='\n');

            sscanf(head,"%d %d",&x,&y);

            for(j=0; (head[j]=fgetc(ein))!='\n'; j++);
            head[j+1]=0;

            sscanf(head,"%d",&t);

            for(i=0; i<y/2; i++)
            {
                for(j=0; j<x; j++)
                {
                    pixelsumme=0;
                    for(l=0; l<3; l++)
                    {
                        pixelsumme+=fgetc(ein);
                    }
                    fseek(ein,(x-1)*3,SEEK_CUR);
                    for(l=0; l<3; l++)
                    {
                        pixelsumme+=fgetc(ein);
                    }
                    if(j<x-1)
                    {
                        fseek(ein,-x*3,SEEK_CUR);
                    }
                    farbton=pixelsumme*ANZ/6/(t+1);

                    printf("%c",zeichen[farbton]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
