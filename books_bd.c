
int cmd_b(char cmdi[], char usr[])
{
    comd[0].cmd="0";
    comd[1].cmd="List";
    comd[2].cmd="Delete";
    comd[3].cmd="BackUp";
    comd[4].cmd="Find";
    comd[5].cmd="Restore";
    comd[6].cmd="Add_Book";
    comd[7].cmd="Find_Student";
    comd[8].cmd="Sdat'_Vidat'";

  for (int i=0; i < 9; ++i)
    {
        if (!strcmp(cmdi, comd[i].cmd))
        {
          char atime[32];
          long int stime;
          struct tm *ltime;
          FILE *log;
          stime = time (NULL);
          ltime = localtime (&stime);
          strftime (atime, 32, "%d.%m.%Y_%X", ltime);
          log=fopen("library.log", "a");
          fprintf(log, "\"%s\";%s;\"Books_%s\"\n", atime, usr, comd[i].cmd);
          fclose(log);

           return i;
        }
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

void sdch_vdch()
{
  int cmd;
  printf("1: Sdat'\n2: Vidat'\n");
  scanf("%d", &cmd);
  if (!((cmd==1)||(cmd==2)))
  {
    sdch_vdch();
  }
  int i=0, j=0, k=0, l=0, m=0, p=0;
  char ISBN[14], zach[7];
  printf("Zach:\n");
  scanf("%s", zach);
  printf("ISBN:\n");
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

  FILE *bk_bd;
  bk_bd = fopen("books.csv", "r");
  while (fscanf (bk_bd, "%[^;] %*c %[^\t^;] %*c %[^\t^;] %*c %[^;] %*c  %[^;^\n]%*c", oldb[m].ISBN, oldb[m].FIO, oldb[m].naz, oldb[m].vs, oldb[m].rk)!=EOF)
    {
      m++;
    }
  fclose(bk_bd);
  while (j!=i)
  {
    if (!strcmp(zach, olds[j].zach))
    {
      while(l!=k)
      {
        if (!strcmp(ISBN, oldb[l].ISBN))
        {
          if (cmd==1) //sdacha
          {
            long int stime;
            struct tm *ltime;
            stime = time (NULL);
            ltime = localtime (&stime);
            char atime[32];
            strftime (atime, 32, "%d.%m.%Y", ltime); //%x и %X не робят(
            FILE *bd;
            bd=fopen("students_books.csv", "a");
            fprintf(bd, "%s;%s;\"%s\"\n", oldb[l].ISBN, olds[j].zach, atime);
            fclose(bd);

            while(oldb[l].rk[p+1]!='\0')
            {
              p++;
            }
            if (oldb[l].rk[p]=='9')
            {
              oldb[l].rk[p]='0';
              oldb[l].rk[p-1]++;
            }
            else
              ++oldb[l].rk[p];
            bk_bd = fopen("books.csv", "w");
            for (int n=0; n < m; ++n)
            {
              fprintf(bk_bd, "%s;%s;%s;%s;%s\n", oldb[n].ISBN, oldb[n].FIO, oldb[n].naz, oldb[n].vs, oldb[n].rk);
            }
            fclose(bk_bd);
            printf("SUCESS\n");
            return;
          }
          if (cmd==2) //vidacha
          {
              printf("Data sdachi\n");
              printf("DD.MM.YYYY\n");
              char atime[32];
              scanf("%s", atime);
              FILE *bd;
              bd=fopen("students_books.csv", "a");
              fprintf(bd, "%s;%s;\"%s\"\n", oldb[l].ISBN, olds[j].zach, atime);
              fclose(bd);
              while(oldb[l].rk[p+1]!='\0')
              {
                p++;
              }
              if (oldb[l].rk[p]=='0')
              {
                if (oldb[l].rk[p-1]=='0')
                {
                  printf("NEVOZMOZNO\n");
                  return;
                }

                oldb[l].rk[p]='9';
                oldb[l].rk[p-1]--;
              }
              else
                --oldb[l].rk[p];
              printf("%s\n", oldb[l].rk);
              bk_bd = fopen("books.csv", "w");
              for (int n=0; n < m; ++n)
              {
                fprintf(bk_bd, "%s;%s;%s;%s;%s\n", oldb[n].ISBN, oldb[n].FIO, oldb[n].naz, oldb[n].vs, oldb[n].rk);
              }
              fclose(bk_bd);
              printf("SUCESS\n");
              return;
          }
        }
        l++;
      }
      printf("No such book\n");
      return;
    }
    j++;
  }
  printf("No such student\n");
  return;
}

void main_b(char* usr)
{ 
  int i=0;
  char cmdi[50], c;
  c=getchar();
  if (c=='\n')
  {
    return main_b(usr);
  }
  if (c==EOF)
  {
    char atime[32];
    long int stime;
    struct tm *ltime;
    FILE *log;
    stime = time (NULL);
    ltime = localtime (&stime);
    strftime (atime, 32, "%d.%m.%Y_%X", ltime);
    log=fopen("library.log", "a");
    fprintf(log, "\"%s\";%s;\"Books_End_of_session\"\n", atime, usr);
    fclose(log);
   exit(0);
  }  
  while(c!='\n')
    { 
     cmdi[i]=c;
     i++;
     c=getchar();
   }
   cmdi[i]='\0';
   switch(cmd_b(cmdi, usr))
   {
     case 1:
        all_b();
        return main_b(usr);
        break;
     case 2:
        dell_b();
        return main_b(usr);
        break;
     case 3:
        back_b();
        return main_b(usr);
        break;
     case 4:
        find_b();
        return main_b(usr);
        break;
     case 5:
        restore_b();
        return main_b(usr);
        break;
     case 6:
        add_b();
        return main_b(usr);
        break;
     case 7:
        fnd_b_s();
        return main_b(usr);
        break;
     case 8:
        sdch_vdch();
        return main_b(usr);
        break;
     case -1:
        printf("ERROR. Wrong comand\n");
        return main_b(usr);
        break;
     case 0:
        return;
   }
}
