// SHELL CODE

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int run,count,count2=1,n,coun,coun1;
	char name[20],c,cmd[50],line[80],*ch;
	FILE*fp;
	while(1)
	{
		printf("\n");
		printf("%s","18230$");
		scanf("%s",cmd);
		scanf("%s",name);
		count=0;
		if((strcmp(cmd,"CountCW"))==0)    //count character and word   CountCW 
		{
			fp=fopen(name,"r");
			if(fp==NULL)
			{
				printf("\n FILE NOT EXITS");exit(0);
			}
			else
			{
				do
				{
					c=getc(fp);
					count=count+1;
					if(c==' ')
						count2=count2+1;

				}while(!feof(fp));
				printf("\n NO OF CHARACTER=%d",count-1);
				printf("\n NO OF WORD=%d",count2);

			}
		}//if

		else if((strcmp(cmd,"exit"))==0)    // exit from shell
		{
			exit(0);break;
		}

		else if((strcmp(cmd,"Typeline"))==0)    // frist n line  Typline +n
		{
			scanf("%d",&n);
			fp=fopen(name,"r");
			count2=0;
			if(fp==NULL)
			{
				printf("\n FILE NOT EXITS");exit(0);
			}
			else
			{
				coun=0;
				do
				{
					ch=fgets(line,80,fp);
					if(coun<n)
					{
						printf("%s",ch);
						coun=coun+1;
					}

					else{break;}
				}while(!feof(fp));
			}
		}// else if

		else if((strcmp(cmd,"Typelinea"))==0)   // all line print  Typeline a
		{

			fp=fopen(name,"r");
			count2=0;  //line 
			if(fp==NULL)
			{
				printf("\n FILE NOT EXITS");exit(0);
			}
			else
			{
				do
				{
					ch=fgets(line,80,fp);
					printf("%s",ch);
				}while(!feof(fp));
			}
		}//else if
		// print -n line
		else if((strcmp(cmd,"Typeline-a"))==0)   // Typeline -n
		{
		
			scanf("%d",&n);  //scan value of how many line
			fp=fopen(name,"r");
			count2=0;
			if(fp==NULL)
			{
				printf("\n FILE NOT EXITS");exit(0);
			}
			else
			{
				do
				{
					c=getc(fp);
					if(c=='\n')    //line count 
						count2=count2+1;
				}while(!feof(fp));

				rewind(fp);
				coun=count2-n;
				coun1=0;//counter for line
				do
				{
					ch=fgets(line,80,fp);

					if(coun1<coun)
					{
						coun1=coun1+1;
					}
					else
					{
						printf("%s",ch);
						coun1=coun1+1;
					}


				}while(!feof(fp));
			}
		}//else if
		//countCL
		else if((strcmp(cmd,"CountCL"))==0)   // character and line CountCL
		{
			fp=fopen(name,"r");
			count2=0;//count character
			if(fp==NULL)
			{
				printf("\n FILE NOT EXITS");exit(0);
			}
			else
			{
				do
				{
					c=getc(fp);
					count2=count2+1;
				}while(!feof(fp));

				rewind(fp);
				coun1=0;//count line
				do
				{

					ch=fgets(line,80,fp);
					coun1=coun1+1;

				}while(!feof(fp));

				printf("\n NUMBER OF CHARACTER=%d",count2);
				printf("\n NUMBER OF LINE=%d",coun1-1);
			}//else
		}//else if

		//count  character word and line
		else if((strcmp(cmd,"CountCWL"))==0)    //count character and word  line  CountCWL 
		{
			fp=fopen(name,"r");
			count=0;//count character
			count2=0;//count word
			if(fp==NULL)
			{
				printf("\n FILE NOT EXITS");exit(0);
			}
			else
			{

				do
				{
					c=getc(fp);
					count=count+1;
					if(c==' ')
						count2=count2+1;

				}while(!feof(fp));
				rewind(fp);
				coun1=0;//count line
				do
				{

					ch=fgets(line,80,fp);
					coun1=coun1+1;

				}while(!feof(fp));
				printf("\n NO OF CHARACTER=%d",count-1);
				printf("\n NO OF WORD=%d",count2);
				printf("\n NO OF LINE=%d",coun1-1);

			}
		}//elseif
		else if((strcmp(cmd,"CountWL"))==0)    //count Word and Line   CountCW 
		{
			fp=fopen(name,"r");

			count2=0;//count word
			if(fp==NULL)
			{
				printf("\n FILE NOT EXITS");exit(0);
			}
			else
			{
				do
				{
					c=getc(fp);
					if(c==' ')
						count2=count2+1;

				}while(!feof(fp));
				rewind(fp);
				coun1=0;//count line
				do
				{

					ch=fgets(line,80,fp);
					coun1=coun1+1;

				}while(!feof(fp));

				printf("\n NO OF WORD=%d",count2);
				printf("\n NO OF LINE=%d",coun1-1);

			}//else
		}//else if

		else
		{
			printf("\n WRONG COMMAND U ARE EXITED FROM SHELL ");
      exit(0);
		}
	}   
}
