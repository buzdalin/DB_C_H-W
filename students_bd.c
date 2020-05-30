
int cmd_s(char cmdi[], char usr[])
{
    comd[0].cmd="0";
    comd[1].cmd="List";
    comd[2].cmd="Delete";
    comd[3].cmd="BackUp";
    comd[4].cmd="Find";
    comd[5].cmd="Restore";
    comd[6].cmd="Find_Book";
    comd[7].cmd="Find_Book";
    comd[8].cmd="Edit";


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
          fprintf(log, "\"%s\";%s;\"Student_%s\"\n", atime, usr, comd[i].cmd);
          fclose(log);

           return i;
        }
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

void edit_s()
{
  int i=0;
  FILE *st_bd;
  
  st_bd = fopen("students.csv", "r");
  while (fscanf (st_bd, "%[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^;] %*c %[^\t^;^\n]%*c", olds[i].zach, olds[i].ser, olds[i].nam, olds[i].last, olds[i].fc, olds[i].sp)!=EOF)
    {
      i++;
    }
  fclose(st_bd);
  struct students new;
  char zach[14];
  printf("zach:\n");
  scanf("%s", zach);
  for (int j = 0; j < i; ++j)
  {
    if (!strcmp(zach, olds[j].zach))
      {
        printf("Old ser:\n%s\nEnter new:\n", olds[j].ser);
        scanf("\n%[^\t^\n]%*c", new.ser);
        printf("Old name:\n%s\nEnter new:\n", olds[j].nam);
        scanf("\n%[^\t^\n]%*c", new.nam);
        printf("Old last name:\n%s\nEnter new:\n", olds[j].last);
        scanf("%s", new.last);
        printf("Old fc:\n%s\nEnter new:\n", olds[j].fc);
        scanf("%s", new.fc);
        printf("Old sp:\n%s\nEnter new:\n", olds[j].sp);
        scanf("\n%[^\t^\n]%*c", new.sp);

        
        st_bd = fopen("students.csv", "w");
        for (int k = 0; k < i; ++k)
        {
          if (k==j)
          {
            fprintf(st_bd, "%s;%s;%s;%s;%s;%s\n", zach, new.ser, new.nam, new.last, new.fc, new.sp);
            k++;
          }
          fprintf(st_bd, "%s;%s;%s;%s;%s;%s\n", olds[k].zach, olds[k].ser, olds[k].nam, olds[k].last, olds[k].fc, olds[k].sp);
        }
        fclose(st_bd);
        printf("SUCCES!\n");
        return;
      }
  }
  printf("No such student\n");
  return;
}


void main_s(char* usr)
{ 
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
   switch(cmd_s(cmdi, usr))
   {
     case 1:
        all_s();
        return main_s(usr);
        break;
     case 2:
        dell_s();
        return main_s(usr);
        break;
     case 3:
        back_s();
        return main_s(usr);
        break;
     case 4:
        find_s();
        return main_s(usr);
        break;
     case 5:
        restore_s();
        return main_s(usr);
        break;
     case 6:
        add_s();
        return main_s(usr);
        break;
     case 7:
        fnd_s_b();
        return main_s(usr);
        break;
     case 8:
        edit_s();
        return main_s(usr);
        break;
     case -1:
        printf("ERROR. Wrong comand\n");
        return main_s(usr);
        break;
      case 0:
        return;
   }
}
