
int cmd_s(char cmdi[])
{
  char cmd[200]="add_stu6all_stu1del_stu2bup_stu3fnd_stu4rtr_stu5fnd_s_b7";
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

int serch_s(char* zach)
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
    if (!strcmp(zach, BD[j].zach))
    {
      return 1;
    }
    j++;
  }
  return 0;
}

void all_s()
{
  int i=0;
  FILE *st_bd; 
  st_bd = fopen("students.csv", "r");
  while (fscanf (st_bd, "%[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", olds[i].zach, olds[i].ser, olds[i].nam, olds[i].last, olds[i].fc, olds[i].sp)!=EOF)
    {
      printf("%s %s %s %s %s %s\n", olds[i].zach, olds[i].ser, olds[i].nam, olds[i].last, olds[i].fc, olds[i].sp);
      i++;
    }
  fclose(st_bd);
}
void add_s()
{
  int i=0, j=0;
  FILE *st_bd;
  
 
  st_bd = fopen("students.csv", "r");
  while (fscanf (st_bd, "%[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", olds[i].zach, olds[i].ser, olds[i].nam, olds[i].last, olds[i].fc, olds[i].sp)!=EOF)
    {
      i++;
    }
  fclose(st_bd);
   
  struct students new;
  printf("Zach:\n");
  scanf("%s", new.zach);
  while (j!=i)
  {
    if (!strcmp(new.zach, olds[j].zach))
    {
      printf("Seserved zach\n");
      return;
    }
    j++;
  }
  printf("ser nam last:\n");
  scanf("%s %s %s", new.ser, new.nam, new.last);
  printf("fc sp:\n");
  scanf("%s %[^\t^\n]%*c", new.fc, new.sp);
  st_bd = fopen("students.csv", "a");
  fprintf(st_bd, "%s;%s;%s;%s;%s;%s\n", new.zach, new.ser, new.nam, new.last, new.fc, new.sp);
  printf("SUCCES!\n");
  fclose(st_bd);
}
void dell_s()
{
  int i=0, j=0;
  FILE *st_bd;
  st_bd = fopen("students.csv", "r");
  while (fscanf (st_bd, "%[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", olds[i].zach, olds[i].ser, olds[i].nam, olds[i].last, olds[i].fc, olds[i].sp)!=EOF)
    {
      i++;
    }
  fclose(st_bd);
  struct students dell;
  printf("Kogo kikaem:\n");
  scanf("%s", dell.zach);
  while (j!=i)
  {
    if (!strcmp(dell.zach, olds[j].zach))
      {
        if (!serch_s(dell.zach))
        {
          st_bd = fopen("students.csv", "w");
          for (int n=0; n < i; ++n)
          {
            if (n==j)
            {
              n++;
            }
            fprintf(st_bd, "%s;%s;%s;%s;%s;%s\n", olds[n].zach, olds[n].ser, olds[n].nam, olds[n].last, olds[n].fc, olds[n].sp);
          }
          fclose(st_bd);
          printf("SUCCES\n");
          return;
        }
        else
          printf("U nego kniga\n");
        return;
      }
    j++;
  }
    printf("No such zach\n");
}
void find_s()
{
  int i=0, j=0, k=0;
  FILE *st_bd;
  
 
  st_bd = fopen("students.csv", "r");
  while (fscanf (st_bd, "%[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", olds[i].zach, olds[i].ser, olds[i].nam, olds[i].last, olds[i].fc, olds[i].sp)!=EOF)
    {
      i++;
    }
  fclose(st_bd);
  struct students find;
  printf("Kogo ishem?\n");
  scanf("%s", find.ser);
  while (j!=i)
  {
    if (!strcmp(find.ser, olds[j].ser))
    {
      printf("%s %s %s %s %s %s\n", olds[j].zach, olds[j].ser, olds[j].nam, olds[j].last, olds[j].fc, olds[j].sp);
      k++;
    }
    j++;
  }
  if (k==0)
  {
    printf("Takih net\n");
  }
}
void back_s()
{
  int i=0;
  FILE *st_bd;
  
  st_bd = fopen("students.csv", "r");
  while (fscanf (st_bd, "%[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", olds[i].zach, olds[i].ser, olds[i].nam, olds[i].last, olds[i].fc, olds[i].sp)!=EOF)
    {
      i++;
    }
  fclose(st_bd);

  long int stime;
  struct tm *ltime;
  
  stime = time (NULL);
  ltime = localtime (&stime);
  char name[32];
  strftime (name, 32, "st_bd_%d.%m.%Y_%H:%M.csv", ltime); //%x и %X не робят(
 
  char *mode="w";
  FILE *file;
  file = fopen(name, mode);
   
  int v=i-1;
  for (int i = 0; i <= v; ++i)
  {
    fprintf(st_bd, "%s;%s;%s;%s;%s;%s\n", olds[i].zach, olds[i].ser, olds[i].nam, olds[i].last, olds[i].fc, olds[i].sp);
  }
  fclose(file);
  printf("SUCCES\n");
  printf("File: %s\n", name);
}
void restore_s()
{
  char resore[50];
  scanf("%s", resore);
  int i=0;
  FILE *rest_f;
  struct students rest[N];
  FILE *st_bd;
  st_bd = fopen("students.csv", "w");
  rest_f = fopen(resore, "r");
  while (fscanf (rest_f, "%[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", rest[i].zach, rest[i].ser, rest[i].nam, rest[i].last, rest[i].fc, rest[i].sp)!=EOF)
    {
      fprintf(st_bd, "%s;%s;%s;%s;%s;%s\n", rest[i].zach, rest[i].ser, rest[i].nam, rest[i].last, rest[i].fc, rest[i].sp);
      i++;
    }
  fclose(rest_f);

  fclose(st_bd);
  printf("SUCCES\n");
}

void fnd_s_b()
{
  int i=0, j=0, k=0, l=0;
  printf("Ishem po zach\n");
  char zach[7];
  scanf("%s", zach);
  FILE *bd;
  bd=fopen("students_books.csv", "r");
  while (fscanf (bd, "%[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", BD[i].ISBN, BD[i].zach, BD[i].date)!=EOF)
    {
      i++;
    }
  fclose(bd);

  FILE *bk_bd;
  bk_bd = fopen("books.csv", "r");
  while (fscanf (bk_bd, "%[^;] %*c %[^\t^;] %*c %[^\t^;] %*c %[^;] %*c  %[^;^\n]%*c", oldb[k].ISBN, oldb[k].FIO, oldb[k].naz, oldb[k].vs, oldb[k].rk)!=EOF)
    {
      k++;
    }
  fclose(bk_bd);
  while (j!=i)
  {
    if (!strcmp(zach, BD[j].zach))
    {
      while (l!=k)
      {
        if (!strcmp(BD[j].ISBN, oldb[l].ISBN))
        {
          printf("%s -- ", BD[j].date);
          printf("%s, %s, %s, %s, %s\n", oldb[l].ISBN, oldb[l].FIO, oldb[l].naz, oldb[l].vs, oldb[l].rk);
        }
        l++;
      }
      l=0;
    }
    j++;
  }
}

void main_s(char* usr)
{ 
  long int stime;
  struct tm *ltime;
  FILE *log;
  int i=0;
  char cmdi[50], c;
  c=getchar();
  if (c=='\n')
  {
    return main_s(usr);
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
   switch(cmd_s(cmdi))
   {
     case 6:
        add_s();
            stime = time (NULL);
            ltime = localtime (&stime);
            char atime[32];
            strftime (atime, 32, "%d.%m.%Y_%X", ltime);
            log=fopen("library.log", "a");
            fprintf(log, "\"%s\";%s;\"StudentAdd\"\n", atime, usr);
            fclose(log);
        return main_s(usr);
        break;
     case 1:
        all_s();
            stime = time (NULL);
            ltime = localtime (&stime);
            strftime (atime, 32, "%d.%m.%Y_%X", ltime);
            log=fopen("library.log", "a");
            fprintf(log, "\"%s\";%s;\"StudentTable\"\n", atime, usr);
            fclose(log);
        return main_s(usr);
        break;
     case 2:
        dell_s();
            stime = time (NULL);
            ltime = localtime (&stime);
            strftime (atime, 32, "%d.%m.%Y_%X", ltime);
            log=fopen("library.log", "a");
            fprintf(log, "\"%s\";%s;\"StudentDelete\"\n", atime, usr);
            fclose(log);
        return main_s(usr);
        break;
     case 3:
        back_s();
            stime = time (NULL);
            ltime = localtime (&stime);
            strftime (atime, 32, "%d.%m.%Y_%X", ltime);
            log=fopen("library.log", "a");
            fprintf(log, "\"%s\";%s;\"StudentBackUp\"\n", atime, usr);
            fclose(log);
        return main_s(usr);
        break;
     case 4:
        find_s();
            stime = time (NULL);
            ltime = localtime (&stime);
            strftime (atime, 32, "%d.%m.%Y_%X", ltime);
            log=fopen("library.log", "a");
            fprintf(log, "\"%s\";%s;\"StudentSerch\"\n", atime, usr);
            fclose(log);
        return main_s(usr);
        break;
     case 5:
        restore_s();
            stime = time (NULL);
            ltime = localtime (&stime);
            strftime (atime, 32, "%d.%m.%Y_%X", ltime);
            log=fopen("library.log", "a");
            fprintf(log, "\"%s\";%s;\"StudentRestore\"\n", atime, usr);
            fclose(log);
        return main_s(usr);
        break;
     case 7:
        fnd_s_b();
            stime = time (NULL);
            ltime = localtime (&stime);
            strftime (atime, 32, "%d.%m.%Y_%X", ltime);
            log=fopen("library.log", "a");
            fprintf(log, "\"%s\";%s;\"StudentFindBook\"\n", atime, usr);
            fclose(log);
        return main_s(usr);
        break;
     case -1:
        printf("ERROR. Wrong comand\n");
        return main_s(usr);
        break;
      case 0:
            stime = time (NULL);
            ltime = localtime (&stime);
            strftime (atime, 32, "%d.%m.%Y_%X", ltime);
            log=fopen("library.log", "a");
            fprintf(log, "\"%s\";%s;\"StudentBackToMenu\"\n", atime, usr);
            fclose(log);
        return;
   }
}
