#include<stdio.h>
#include<conio.h>
main()
{
      char str[30];
      int i,len,nsp=0,psn=0;
      printf("ENTER THE STRING\n");
      gets(str);                            //GETTING THE STRING
      for(i=0;str{i]!='\0';i++);            //CALCULATION OF LENGTH OF STRING
      len=i;                                //LENGTH OF STRING BECOMES len
      for(i=0;str[i]!='\0';i++)             //CALCULATION OF NUMBER OF SPACES
      {                                     
      if(str[i]==32)
      nsp=nsp+1;
      }
      
      if (nsp==0)
      {
      printf("%s",str);
      }
      else
      {
      printf("%c. ",str[0]);
      for(i=1;i<len;i++)
      {
                        if ((psn!=nsp)&&(str[i]!=32))
                        continue;
                        else if ((psn!=nsp)&&(str[i]==32))
                        {
                             psn=psn+1;
                             if(psn==nsp)
                             printf("%c",str[i]);
                             else
                             {
                             printf("%c. ",str[i+1]);
                             continue;
                             }
                        }
                        else
                        printf("%c",str[i]);
      }
      }
      getch();
      }
