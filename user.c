#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 100 //кол-во выводимых строк из бд

struct cmd
{
    char* cmd;   
} comd[10];

struct students
{
  char zach[7]; 
  char ser[24]; 
  char nam[24];
  char last[24];
  char fc[24];
  char sp[100];
} olds[N];

struct students_books
{
  char ISBN[14];
  char zach[7];
  char date[16];
} BD[N];

struct books
{
  char ISBN[14]; 
  char FIO[24]; 
  char naz[24];
  char vs[24];
  char rk[24];
} oldb[N];

struct user
{
  char lgn[50]; 
  char psw[50]; 
  int bk; //pomenyzt' na char
  int st; 
} lin[N];

#include "books_bd.c"
#include "students_bd.c"


void login(int* bk, int* us, char* login)
{
	int i=0;
  	FILE *bk_bd;

  	bk_bd = fopen("users.csv", "r");
  	while ((fscanf (bk_bd, "%[^;]%*c %[^;]%*c", lin[i].lgn, lin[i].psw)!=EOF)&&(fscanf (bk_bd, "%d;%d\n", &lin[i].bk, &lin[i].st)!='\n'))
  	  {
  	    i++;
  	  }
  	fclose(bk_bd);
	char pass[50];
	int j=0;
	while (j!=i)
	{
	    if (!strcmp(login, lin[j].lgn))
	    {
	    	scanf("%s", pass);
	      if (!strcmp(pass, lin[j].psw))
	      {
	      	char atime[32];
			long int stime;
			struct tm *ltime;
			FILE *log;
			stime = time (NULL);
			ltime = localtime (&stime);
			strftime (atime, 32, "%d.%m.%Y_%X", ltime);
			log=fopen("library.log", "a");
			fprintf(log, "\"%s\";%s;\"Start_of_session\"\n", atime, login);
			fclose(log);

	      	*bk=lin[j].bk;
			*us=lin[j].st;
	    	return;
	      }
	      else
	      {
	      	printf("Wrong password\n");
	      	return;
	      }
	    }
	    j++;
	}
	printf("No such user\n");
	exit(-1);
}

int main()
{
	
	int bk=0, us=0;	
	char c, lgn[50];
	printf("Please login:\n");
	scanf("%s", lgn);
	login(&bk, &us, lgn);
	if ((bk==us)&&(bk==1))
	{
		printf("1: Students\n2: Books\n");
		while(c!=EOF)
		{
			c=getchar();
			if (c=='1')
			{
				printf("---Students---\n");
				main_s(lgn);
				printf("1: Students\n2: Books\n");
			}
			if (c=='2')
			{
				printf("---Books---\n");
				main_b(lgn);
				printf("1: Students\n2: Books\n");
			}
		}
	}
	else if ((bk!=us)&&(bk==1))
	{
		printf("---Books---\n");
		main_b(lgn);
		return 0;
	}
	else if ((bk!=us)&&(us==1))
	{
		printf("---Students---\n");
		main_s(lgn);
	}
	return 0;
}
