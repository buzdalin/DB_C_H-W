
int cmd_b(char cmdi[])
{
  char cmd[100]="add_buk6all_buk1del_buk2bup_buk3fnd_buk4rtr_buk5fnd_b_s7";
  if (cmdi[0]=='0')
  {
    return 0;
  }
  int i=0, j=0, k=0;
  while(cmd[i]!='\0')
  {
    while(cmdi[j]!='\0')
    {
      if (cmd[i]==cmdi[j])
      {
        k++;
      }
      i++;
      j++;
    }
    if (k==7)
    {
      return (cmd[i]-'0');
    }
    k=0;
    j=0;
    i++;
  }
    return -1;
}

int serch_b(char* ISBN)
{
  int i=0, j=0;

  FILE *bd;
  bd=fopen("students_books.csv", "r");

  while (fscanf (bd, "%[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", BD[i].ISBN, BD[i].zach, BD[i].date)!=EOF)
    {
      i++;
    }
  fclose(bd);
    while (j!=i)
  {
    if (!strcmp(ISBN, BD[j].ISBN))
    {
      return 1;
    }
    j++;
  }
  return 0;
}

void all_b()
{
  int i=0;
  FILE *bk_bd;
  
 
  bk_bd = fopen("books.csv", "r");
  while (fscanf (bk_bd, "%[^;] %*c %[^\t^;] %*c %[^\t^;] %*c %[^;] %*c  %[^;^\n]%*c", oldb[i].ISBN, oldb[i].FIO, oldb[i].naz, oldb[i].vs, oldb[i].rk)!=EOF)
    {
      printf("| %s |%-20s|%-15s|%-3s|%-3s|\n", oldb[i].ISBN, oldb[i].FIO, oldb[i].naz, oldb[i].vs, oldb[i].rk);
      i++;
    }
  fclose(bk_bd);
}
void add_b()
{
  int i=0, j=0;
  FILE *bk_bd;
  
 
  bk_bd = fopen("books.csv", "r");
  while (fscanf (bk_bd, "%[^;] %*c %[^\t^;] %*c %[^\t^;] %*c %[^;] %*c  %[^;^\n]%*c", oldb[i].ISBN, oldb[i].FIO, oldb[i].naz, oldb[i].vs, oldb[i].rk)!=EOF)
    {
      i++;
    }
  fclose(bk_bd);
   
  struct books new;
  printf("ISBN:\n");
  scanf("%s", new.ISBN);
  while (j!=i)
  {
    if (!strcmp(new.ISBN, oldb[j].ISBN))
    {
      printf("Reserved ISBN\n");
      return;
    }
    j++;
  }
  printf("FIO:\n");
  scanf("\n%[^\t^\n]%*c", new.FIO);
  printf("naz:\n");
  scanf("\n%[^\t^\n]%*c", new.naz);
  printf("vs:\n");
  scanf("%s", new.vs);

  printf("rk :\n");
  scanf("%s", new.rk);
  
  bk_bd = fopen("books.csv", "a");
  fprintf(bk_bd, "%s;%s;%s;%s;%s\n", new.ISBN, new.FIO, new.naz, new.vs, new.rk);
  printf("SUCCES!\n");
  fclose(bk_bd);
}
void dell_b() // problema s poslednimi kikami
{
  int i=0, j=0;
  FILE *bk_bd;
  
 
  bk_bd = fopen("books.csv", "r");
  while (fscanf (bk_bd, "%[^;] %*c %[^\t^;] %*c %[^\t^;] %*c %[^;] %*c  %[^;^\n]%*c", oldb[i].ISBN, oldb[i].FIO, oldb[i].naz, oldb[i].vs, oldb[i].rk)!=EOF)
    {
      i++;
    }
  fclose(bk_bd);
  struct books dell;
  printf("Kogo kikaem:\n");
  scanf("%s", dell.ISBN);
  while (j!=i)
  {
    if (!strcmp(dell.ISBN, oldb[j].ISBN))
    {
      if (!serch_b(dell.ISBN))
      {
        bk_bd = fopen("books.csv", "w");
        for (int n=0; n < i; ++n)
        {
          if (n==j)
          {
            n++;
          }
          fprintf(bk_bd, "%s;%s;%s;%s;%s\n", oldb[n].ISBN, oldb[n].FIO, oldb[n].naz, oldb[n].vs, oldb[n].rk);
        }
        fclose(bk_bd);
        printf("SUCCES\n");
        return;
      }
      else
        printf("Est' u studenta\n");
      return;
      j++;
    }
  }
    printf("No such ISBN\n");
}
void find_b()
{
  int i=0, j=0;
  FILE *bk_bd;
  
 
  bk_bd = fopen("books.csv", "r");
  while (fscanf (bk_bd, "%[^;] %*c %[^\t^;] %*c %[^\t^;] %*c %[^;] %*c  %[^;^\n]%*c", oldb[i].ISBN, oldb[i].FIO, oldb[i].naz, oldb[i].vs, oldb[i].rk)!=EOF)
    {
      i++;
    }
  fclose(bk_bd);
  struct books find;
  printf("Kogo ishem?\n");
  scanf("%s", find.ISBN);
  while (j!=i)
  {
    if (!strcmp(find.ISBN, oldb[j].ISBN))
    {
      printf("| %s |%-20s|%-15s|%-3s|%-3s|\n", oldb[j].ISBN, oldb[j].FIO, oldb[j].naz, oldb[j].vs, oldb[j].rk);
      printf("SUCCES\n");
      return;
    }
    j++;
  }
  printf("Takih net\n");  
}
void back_b()
{
  int i=0;
  FILE *bk_bd;
  
  bk_bd = fopen("books.csv", "r");
  while (fscanf (bk_bd, "%[^;] %*c %[^\t^;] %*c %[^\t^;] %*c %[^;] %*c  %[^;^\n]%*c", oldb[i].ISBN, oldb[i].FIO, oldb[i].naz, oldb[i].vs, oldb[i].rk)!=EOF)
    {
      i++;
    }
  fclose(bk_bd);

  long int stime;
  struct tm *ltime;
  
  stime = time (NULL);
  ltime = localtime (&stime);
  char naze[32];
  strftime (naze, 32, "bk_bd_%d.%m.%Y_%H:%M.csv", ltime); //%x и %X не робят(
 
  char *mode="w";
  FILE *file;
  file = fopen(naze, mode);
   
  int v=i-1;
  for (int i = 0; i <= v; ++i)
  {
    fprintf(bk_bd, "%s;%s;%s;%s;%s\n", oldb[i].ISBN, oldb[i].FIO, oldb[i].naz, oldb[i].vs, oldb[i].rk);
  }
  fclose(file);
  printf("SUCCES\n");
  printf("File: %s\n", naze);
}
void restore_b()
{
  char resore[50];
  scanf("%s", resore);
  int i=0;
  FILE *rest_f;
  struct books rest[N];
  FILE *bk_bd;
  bk_bd = fopen("books.csv", "w");
  rest_f = fopen(resore, "r");
  while (fscanf (bk_bd, "%[^;] %*c %[^\t^;] %*c %[^\t^;] %*c %[^;] %*c  %[^;^\n]%*c", rest[i].ISBN, rest[i].FIO, rest[i].naz, rest[i].vs, rest[i].rk)!=EOF)
    {
      fprintf(bk_bd, "%s;%s;%s;%s;%s\n", rest[i].ISBN, rest[i].FIO, rest[i].naz, rest[i].vs, rest[i].rk);
      i++;
    }
  fclose(rest_f);

  fclose(bk_bd);
  printf("SUCCES\n");
}

void fnd_b_s()
{
  int i=0, j=0, k=0, l=0;
  char ISBN[14];
  scanf("%s", ISBN);
  FILE *bd;
  bd=fopen("students_books.csv", "r");
  while (fscanf (bd, "%[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", BD[i].ISBN, BD[i].zach, BD[i].date)!=EOF)
    {
      i++;
    }
  fclose(bd);

  FILE *st_bd;
  st_bd = fopen("students.csv", "r");
  while (fscanf (st_bd, "%[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", olds[k].zach, olds[k].ser, olds[k].nam, olds[k].last, olds[k].fc, olds[k].sp)!=EOF)
    {
      k++;
    }
  fclose(st_bd);
  while (j!=i)
  {
    if (!strcmp(ISBN, BD[j].ISBN))
    {
      while (l!=k)
      {
        if (!strcmp(BD[j].zach, olds[l].zach))
        {
          printf("%s %s %s %s %s %s ", olds[l].zach, olds[l].ser, olds[l].nam, olds[l].last, olds[l].fc, olds[l].sp);
          printf(" -- %s\n", BD[j].date);
        }
        l++;
      }
      l=0;
    }
    j++;
  }
}

void main_b()
{ 
  int i=0;
  char cmdi[50], c;
  c=getchar();
  if (c=='\n')
  {
    return main_b();
  }
  if (c==EOF)
  {
   exit(0);
  }  
  while(c!='\n')
    { 
     cmdi[i]=c;
     i++;
     c=getchar();
   }
   cmdi[i]='\0';
   switch(cmd_b(cmdi))
   {
     case 6:
        add_b();
        return main_b();
        break;
     case 1:
        all_b();
        return main_b();
        break;
     case 2:
        dell_b();
        return main_b();
        break;
     case 3:
        back_b();
        return main_b();
        break;
     case 4:
        find_b();
        return main_b();
        break;
     case 5:
        restore_b();
        return main_b();
        break;
     case 7:
        fnd_b_s();
        return main_b();
        break;
     case -1:
        printf("ERROR. Wrong comand\n");
        return main_b();
        break;
     case 0:
        return;
   }
}