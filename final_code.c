#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int day;
    int month;
    int year;
} dob;
typedef struct
{
    char first[15];
    char last[15];
    dob dob;
    char address[100];
    char number[100];
    char email[100];
} contact;

contact x[100];
int count ;



int valid_number(char phone[])
{int i;
  for(i=0;i<strlen(phone);i++)
    {

    if(!isdigit(phone[i])) return 0;

  }return 1;
  }
 int  valid_dob(int d,int m,int y)
 {
     if(d>31||d<=0) return 0;
     if(m>12||m<=0) return 0;
     if(y>2021||y<=0) return 0;
return 1;
   }

int valid_email(char em[])
{
    int c1=0,x,y,i=0;
      for(i=0;i<strlen(em);i++){
        if(em[i]=='@'){
            c1++;
            x=i;
        }
        if(em[i]=='.'){

            y=i;
        }

      }
      if(c1==1 && y>x && y-x>1 && em[i-1]!='.')
      {
        return 1;
      }

       return 0;

      }


void load ()


{
    FILE *f=fopen("phonebook.txt","r");
    if(f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],",x[count].first);
            fscanf(f,"%[^,],",x[count].last);
            fscanf(f,"%d-%d-%d,",&x[count].dob.day,&x[count].dob.month,&x[count].dob.year);
            fscanf(f,"%[^,],",x[count].address);
            fscanf(f,"%[^,],",x[count].number);
            fscanf(f,"%s\n",x[count].email);
            count++;
        }
        fclose(f);
        printf("file loaded\n");
}
}


void Query()


{
    char lastname[20];
    int i;
    int flag=0;
    printf("Enter last name: ");
    scanf("%s",lastname);
    for(i=0; i<count; i++)
    {
        if(strcasecmp(x[i].last,lastname)==0)
        {
            flag=1;
            printf("\nFirst name:%s\n",x[i].first);
            printf("Last name:%s\n",x[i].last);
            printf("Date of birth:%d-%d-%d\n",x[i].dob.day,x[i].dob.month,x[i].dob.year);
            printf("Address:%s\n",x[i].address);
            printf("Phone number:%s\n",x[i].number);
            printf("Email address:%s\n\n",x[i].email);
        }
    }
    if(flag==0)
        printf("Search not found\n");

}

void add ()
{
int z;
int flag=0;
    printf("would you like to add an entery?\n1. YES\n2. NO\n");
    scanf("%d",&z);
    if(z==1){

        printf("please enter last name:");
        scanf("%s",&x[count].last);


        printf("please enter first name:");
        scanf("%s",&x[count].first);

        do
        {


             flag =0;

        printf("please enter day of birth:");
        scanf("%d",&x[count].dob.day);



        printf("please enter the month of birth:");
        scanf("%d",&x[count].dob.month);


        printf("please enter year of birth:");
        scanf("%d",&x[count].dob.year);
        if (valid_dob(x[count].dob.day,x[count].dob.month,x[count].dob.year)==0)
        {
            flag=1;
            printf("please enter the days from 1~31\nmonth from 1~12\nyears<=2021\n");
        }
        }

        while(flag==1);



        printf("please enter address:");

        char c=getchar();
          gets(x[count].address);
do
{


        flag=0;
        printf("please enter the phone number:");
        scanf("%s",&x[count].number);
        if((valid_number(x[count].number))==0)
        {
            flag=1;
            printf("please enter a valid number\n");
        }
}
        while(flag==1);

do
{


        flag=0;
        printf("please enter the email:");
        scanf("%s",&x[count].email);
        if((valid_email(x[count].email))==0)
        {
            flag=1;
            printf("please enter a valid email\n");
        }
}
        while(flag==1);
        count++;


}
}


void Delete()


{ int c=0;
    char firstname[50];
    char lastname[50];
    printf("Enter the first name\n");
    int j=0;
    scanf("%s",firstname);
    printf("Enter the last name\n");
    scanf("%s",lastname);
    for(int i=0; i<count; i++)
    {
        if(strcasecmp(x[i].first,firstname)==0&&strcasecmp(x[i].last,lastname)==0)
        { c++;
            for(j=i; j<count-1; j++)
            {
                x[j]=x[j+1];

            }
            count--;
            i--;
        }
    } if(c==0) printf("the entry is not found in the file\n");
    else printf("The process is done.\n");
}


void modify ()
{


char character;
int j,e,t,v=0,g,c,flagg=0;
int rep[100];

 printf("please enter the last name of the wanted contact\n");
 char sample[30];
 char fsample[30];
 scanf("%s",&sample);
 for(j=0;j<count;j++)
 {
     if((strcasecmp(sample,x[j].last)==0))
        {
            rep[v]=j;
            v++;
        }
 }
 if(v==1)
 {


 for(t=0;t<count;t++)
 {
     if(strcasecmp(x[t].last,sample)==0)
     {
         e=t;
     }

 }
         printf("choose which category to edit\n1 for last name\n2 for first name\n3 for address\n4  for number\n5 for email\n6 for date of birth\n");
         int y,c,flag=0;
         scanf("%d",&y);
         switch (y)
         {
             case 1:
                {
                    printf("please enter the last name:");
                     scanf("%s",&x[e].last);
                    break;
                }
             case 2:
                {
                    printf("please enter the first name:");
                     scanf("%s",&x[e].first);
                    break;
                }
             case 3:
                {
                     printf("please enter the address:");
                     character=getchar();
                     gets(x[e].address);
                    break;
                }
             case 4:
                {
                     printf("please enter the number:");
                    do
{


        flag=0;
        printf("please enter the phone number:");
        scanf("%s",&x[e].number);
        if((valid_number(x[e].number))==0)
        {
            flag=1;
            printf("please enter a valid number\n");
        }
}
        while(flag==1);
                    break;
                }
             case 5:
                {
                     do
{

        flag=0;
        printf("please enter the email:");
        scanf("%s",&x[e].email);
        if((valid_email(x[e].email))==0)
        {
            flag=1;
            printf("please enter a valid email\n");
        }
}
        while(flag==1);
                    break;
                }
             case 6:
                {
                    do
        {


             flag =0;

        printf("please enter day of birth:");
        scanf("%d",&x[e].dob.day);



        printf("please enter the month of birth:");
        scanf("%d",&x[e].dob.month);


        printf("please enter year of birth:");
        scanf("%d",&x[e].dob.year);
        if (valid_dob(x[e].dob.day,x[e].dob.month,x[e].dob.year)==0)
        {
            flagg=1;
            printf("please enter the days from 1~31\nmonth from 1~12\nyears<=2021\n");
        }
        }

        while(flag==1);
                    break;
                }

         }


 }
else if (v==0)
{
    printf("the contact was not found\n");

}
else if(v>1)
{
    printf("more than one contact was found please enter the first name\n");
    printf("please choose the number in front of the entery you want changed\n");

        for(j=0;j<v;j++)
        {
            if((strcasecmp(x[rep[j]].last,sample))==0)
            {

                printf("%d for\n %s\n%s\n%s\n%s\n%s\n%d-%d-%d\n",j+1,x[rep[j]].first,x[rep[j]].last,x[rep[j]].email,x[rep[j]].address,x[rep[j]].number,x[rep[j]].dob.day,x[rep[j]].dob.month,x[rep[j]].dob.year,sample);

            }
        }
        scanf("%d",&g);
         for(c=0;c<v;c++)
         {
             if ((c+1)==g)
                flagg=1;
         }
         if(flagg==1)
             {
                 printf("choose which category to edit\n1 for last name\n2 for first name\n3 for address\n4  for number\n5 for email\n6 for date of birth");
         int y,c,flag=0;
         scanf("%d",&y);
         switch (y)
         {
             case 1:
                {
                    printf("please enter the last name:");
                     scanf("%s",&x[rep[g-1]].last);
                    break;
                }
             case 2:
                {
                    printf("please enter the first name:");
                     scanf("%s",&x[rep[g-1]].first);
                    break;
                }
             case 3:
                {
                     printf("please enter the address:");
                     character=getchar();
                     gets(x[rep[g-1]].address);
                    break;
                }
             case 4:
                {
                     printf("please enter the number:");
                    do
{


        flag=0;
        printf("please enter the phone number:");
        scanf("%s",&x[rep[g-1]].number);
        if((valid_number(x[rep[g-1]].number))==0)
        {
            flag=1;
            printf("please enter a valid number\n");
        }
}
        while(flag==1);
                    break;
                }
             case 5:
                {
                     do
{

        flag=0;
        printf("please enter the email:");
        scanf("%s",&x[rep[g-1]].email);
        if((valid_email(x[rep[g-1]].email))==0)
        {
            flag=1;
            printf("please enter a valid email\n");
        }
}
        while(flag==1);
                    break;
                }
             case 6:
                {
                    do
        {


             flag =0;

        printf("please enter day of birth:");
        scanf("%d",&x[rep[g-1]].dob.day);



        printf("please enter the month of birth:");
        scanf("%d",&x[rep[g-1]].dob.month);


        printf("please enter year of birth:");
        scanf("%d",&x[rep[g-1]].dob.year);
        if (valid_dob(x[rep[g-1]].dob.day,x[g-1].dob.month,x[g-1].dob.year)==0)
        {
            flag=1;
            printf("please enter the days from 1~31\nmonth from 1~12\nyears<=2021\n");
        }
        }

        while(flag==1);
                    break;
                }

         }
             }
             if(flagg!=1)
             {
                 printf("please try again and choose one of the shown numbers");
             }

         }

}


void sort ()
{
    printf("please select 1 to sort by name\nplease select 2 to sort by dob of birth\n");
    int ch,i;
    scanf("%d",&ch);
    if(ch==1)
    {
        int i,j;
        int num=count;
 contact temp;
 for(i=0;i<num-1;i++)
 {
     for(j=0;j<num-i-1;j++)
     {
         if(strcasecmp(x[j].first,x[j+1].first)>0)
         {
             strcpy(temp.last,x[j].last);
             strcpy(temp.first,x[j].first);
             strcpy(temp.address,x[j].address);
             strcpy(temp.number,x[j].number);
             strcpy(temp.email,x[j].email);
             temp.dob.day=x[j].dob.day;
             temp.dob.month=x[j].dob.month;
             temp.dob.year=x[j].dob.year;
             strcpy(x[j].last,x[j+1].last);
             strcpy(x[j].first,x[j+1].first);
             strcpy(x[j].address,x[j+1].address);
             strcpy(x[j].number,x[j+1].number);
             strcpy(x[j].email,x[j+1].email);
             x[j].dob.day=x[j+1].dob.day;
             x[j].dob.month=x[j+1].dob.month;
             x[j].dob.year=x[j+1].dob.year;
             strcpy(x[j+1].last,temp.last);
             strcpy(x[j+1].first,temp.first);
             strcpy(x[j+1].address,temp.address);
             strcpy(x[j+1].number,temp.number);
             strcpy(x[j+1].email,temp.email);
             x[j+1].dob.day=temp.dob.day;
             x[j+1].dob.month=temp.dob.month;
             x[j+1].dob.year=temp.dob.year;


         }
     }
 }
 for(i=0;i<num-1;i++)
 {
     for(j=0;j<num-i-1;j++)
     {
         if(strcasecmp(x[j].last,x[j+1].last)>0)
         {
             strcpy(temp.last,x[j].last);
             strcpy(temp.first,x[j].first);
             strcpy(temp.address,x[j].address);
             strcpy(temp.number,x[j].number);
             strcpy(temp.email,x[j].email);
             temp.dob.day=x[j].dob.day;
             temp.dob.month=x[j].dob.month;
             temp.dob.year=x[j].dob.year;
             strcpy(x[j].last,x[j+1].last);
             strcpy(x[j].first,x[j+1].first);
             strcpy(x[j].address,x[j+1].address);
             strcpy(x[j].number,x[j+1].number);
             strcpy(x[j].email,x[j+1].email);
             x[j].dob.day=x[j+1].dob.day;
             x[j].dob.month=x[j+1].dob.month;
             x[j].dob.year=x[j+1].dob.year;
             strcpy(x[j+1].last,temp.last);
             strcpy(x[j+1].first,temp.first);
             strcpy(x[j+1].address,temp.address);
             strcpy(x[j+1].number,temp.number);
             strcpy(x[j+1].email,temp.email);
             x[j+1].dob.day=temp.dob.day;
             x[j+1].dob.month=temp.dob.month;
             x[j+1].dob.year=temp.dob.year;


         }
     }
 }




for(i=0;i<num;i++)
{
    printf("\nFirst name:%s\nLast name:%s\nAddress:%s\nPhone number:%s\nEmail addres:%s\nDate of birth:%d-%d-%d\n\n",x[i].first,x[i].last,x[i].address,x[i].number,x[i].email,x[i].dob.day,x[i].dob.month,x[i].dob.year);
}


}
else if(ch==2)
{
    int num=count,i,j,c;
    contact temp;

 for(i=1;i<=num;i++)
 {
     for(j=0;j<num-i;j++)
     {
         if(x[j].dob.year<x[num-i].dob.year)
         {
             strcpy(temp.last,x[j].last);
             strcpy(temp.first,x[j].first);
             strcpy(temp.address,x[j].address);
             strcpy(temp.number,x[j].number);
             strcpy(temp.email,x[j].email);
             temp.dob.day=x[j].dob.day;
             temp.dob.month=x[j].dob.month;
             temp.dob.year=x[j].dob.year;
             strcpy(x[j].last,x[num-i].last);
             strcpy(x[j].first,x[num-i].first);
             strcpy(x[j].address,x[num-i].address);
             strcpy(x[j].number,x[num-i].number);
             strcpy(x[j].email,x[num-i].email);
             x[j].dob.day=x[num-i].dob.day;
             x[j].dob.month=x[num-i].dob.month;
             x[j].dob.year=x[num-i].dob.year;
             strcpy(x[num-i].last,temp.last);
             strcpy(x[num-i].first,temp.first);
             strcpy(x[num-i].address,temp.address);
             strcpy(x[num-i].number,temp.number);
             strcpy(x[num-i].email,temp.email);
             x[num-i].dob.day=temp.dob.day;
             x[num-i].dob.month=temp.dob.month;
             x[num-i].dob.year=temp.dob.year;


         }

     }
 }

     for(j=0;j<num;j++)
     {  if(x[j].dob.year==x[j+1].dob.year)

        {

        for(i=1;i<num;i++)
        {
            for(c=0;c<num-i;c++)
            {
                if(x[c].dob.year==x[num-i].dob.year)
                {



                    if(x[c].dob.month<x[num-i].dob.month)
         {
             strcpy(temp.last,x[c].last);
             strcpy(temp.first,x[c].first);
             strcpy(temp.address,x[c].address);
             strcpy(temp.number,x[c].number);
             strcpy(temp.email,x[c].email);
             temp.dob.day=x[c].dob.day;
             temp.dob.month=x[c].dob.month;
             temp.dob.year=x[c].dob.year;
             strcpy(x[c].last,x[num-i].last);
             strcpy(x[c].first,x[num-i].first);
             strcpy(x[c].address,x[num-i].address);
             strcpy(x[c].number,x[num-i].number);
             strcpy(x[c].email,x[num-i].email);
             x[c].dob.day=x[num-i].dob.day;
             x[c].dob.month=x[num-i].dob.month;
             x[c].dob.year=x[num-i].dob.year;
             strcpy(x[num-i].last,temp.last);
             strcpy(x[num-i].first,temp.first);
             strcpy(x[num-i].address,temp.address);
             strcpy(x[num-i].number,temp.number);
             strcpy(x[num-i].email,temp.email);
             x[num-i].dob.day=temp.dob.day;
             x[num-i].dob.month=temp.dob.month;
             x[num-i].dob.year=temp.dob.year;



         }
                }
            }

         }

     }
 }
for(j=0;j<num;j++)
{
    if((x[j].dob.year==x[j].dob.year)&&(x[j].dob.month==x[j].dob.month))
    {
      for(i=1;i<num;i++)
        {
            for(c=0;c<num-i;c++)
            {
                if((x[c].dob.year==x[num-i].dob.year)&&(x[c].dob.month==x[num-i].dob.month))
                {



                    if(x[c].dob.day<x[num-i].dob.day )
         {
             strcpy(temp.last,x[c].last);
             strcpy(temp.first,x[c].first);
             strcpy(temp.address,x[c].address);
             strcpy(temp.number,x[c].number);
             strcpy(temp.email,x[c].email);
             temp.dob.day=x[c].dob.day;
             temp.dob.month=x[c].dob.month;
             temp.dob.year=x[c].dob.year;
             strcpy(x[c].last,x[num-i].last);
             strcpy(x[c].first,x[num-i].first);
             strcpy(x[c].address,x[num-i].address);
             strcpy(x[c].number,x[num-i].number);
             strcpy(x[c].email,x[num-i].email);
             x[c].dob.day=x[num-i].dob.day;
             x[c].dob.month=x[num-i].dob.month;
             x[c].dob.year=x[num-i].dob.year;
             strcpy(x[num-i].last,temp.last);
             strcpy(x[num-i].first,temp.first);
             strcpy(x[num-i].address,temp.address);
             strcpy(x[num-i].number,temp.number);
             strcpy(x[num-i].email,temp.email);
             x[num-i].dob.day=temp.dob.day;
             x[num-i].dob.month=temp.dob.month;
             x[num-i].dob.year=temp.dob.year;



         }
                }
            }

         }
    }
}


for(i=0;i<num;i++)
{
    printf("\n%s\n%s\n%s\n%s\n%s\n%d\t%d\t%d\n",x[i].last,x[i].first,x[i].address,x[i].number,x[i].email,x[i].dob.day,x[i].dob.month,x[i].dob.year);
}
}
}
void save ()
{
    FILE *f=fopen("phonebook.txt","w");
    int i;
    for(i=0; i<count; i++)
    {
        fprintf(f,"%s,",x[i].first);
        fprintf(f,"%s,",x[i].last);
        fprintf(f,"%d-%d-%d,",x[i].dob.day,x[i].dob.month,x[i].dob.year);
        fprintf(f,"%s,",x[i].address);
        fprintf(f,"%s,",x[i].number);
        fprintf(f,"%s\n",x[i].email);
    }
     printf("The file has been saved.\n");
    fclose(f);
}
void Quit()
{
    exit(0);
}
void program(){


 while(1)
    {
        char x,y;
        printf("Choose your request:\n1.Load\n2.Query\n3.Add\n4.Delete\n5.Modify\n6.Print\n7.Save\n8.Quit\n");
       scanf("%s",&x);

        switch(x)
        {

        case '1':
            load();
            break;
        case '2':
            Query();
            break;
        case '3':
            add();
            break;
        case '4':
            Delete();
            break;
        case '5':
            modify();
            break;
        case '6':
            sort();
            break;
        case '7':
            save();
            break;
        case '8':
            printf("All data will be discarded (if not saved),if you still want to continue press 1 either press any number\n");
            scanf("%s",&y);
            if(y=='1')
                Quit();
            break;
        default:
            printf("Error in the entry,please enter a correct choice\n");


        }

    }
}

int main()
{
    program();

    return 0;
}
