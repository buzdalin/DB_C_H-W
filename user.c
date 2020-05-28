#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 100 //кол-во выводимых строк из бд

struct students {
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

struct books {
  char ISBN[14]; 
  char FIO[24]; 
  char naz[24];
  char vs[24];
  char rk[24];
} oldb[N];

struct user {
  char lgn[50]; 
  char psw[50]; 
  int bk; //pomenyzt' na char
  int st; 
} lin[N];

#include "books_bd.c"
#include "students_bd.c"


void login(int* bk, int* us)
{
	int i=0;
  	FILE *bk_bd;

  	bk_bd = fopen("users.csv", "r");
  	while ((fscanf (bk_bd, "%[^;]%*c %[^;]%*c", lin[i].lgn, lin[i].psw)!=EOF)&&(fscanf (bk_bd, "%d;%d\n", &lin[i].bk, &lin[i].st)!='\n'))
  	  {
  	    i++;
  	  }
  	fclose(bk_bd);
	char login[50];
	char pass[50];
	int j=0;
	scanf("%s", login);
	while (j!=i)
	{
	    if (!strcmp(login, lin[j].lgn))
	    {
	    	scanf("%s", pass);
	      if (!strcmp(pass, lin[j].psw))
	      {
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
	char c;
	printf("Please login:\n");
	login(&bk, &us);
	if ((bk==us)&&(bk==1))
	{
		printf("1: Students\n2: Books\n");
		while(c!=EOF)
		{
			c=getchar();
			if (c=='1')
			{
				printf("---Students---\n");
				main_s();
				printf("1: Students\n2: Books\n");
			}
			if (c=='2')
			{
				printf("---Books---\n");
				main_b();
				printf("1: Students\n2: Books\n");
			}
		}
	}
	else if ((bk!=us)&&(bk==1))
	{
		printf("---Books---\n");
		main_b();
		return 0;
	}
	else if ((bk!=us)&&(us==1))
	{
		printf("---Students---\n");
		main_s();
	}
	return 0;
}