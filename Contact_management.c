#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct contact{
    long ph;
    char name[20];
    } list;
char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;

//main
int main(){
contact:
    system("cls");

    printf("\n\t ~~~~ Welcome to Contact Management System ~~~~");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=====================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch){
    case 0:
        printf("\n\n\t\tAre you sure you want to exit?");
        break;

    case 1:
        system("cls");

        fp=fopen("contact.dll","a");
        for (;;){
            fflush(stdin);
            printf("\nTo exit enter blank space in the name input\nName:");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("Phone:");*ft;
            scanf("%ld",&list.ph);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
         break;

    case 2:
        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\n=======================================================\n\n");
        for(i=97; i<=122; i=i+1){
            fp=fopen("contact.dll","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fp)==1){
                if(list.name[0]==i || list.name[0]==i-32){
                    printf("\nName\t: %s\nPhone\t: %ld\n",list.name,list.ph);
                    found++;
                }
            }
            if(found!=0){
                printf("======================================================= [%c]-(%d)\n\n",i-32,found);
                getch();
            }
            fclose(fp);
        }
        break;
    case 3:
        system("cls");

        do
        {
            found=0;
            printf("\n\n\tCONTACT SEARCH\n\t===========================\n\tName of contact to search: ");
            fflush(stdin);
            scanf("%[^\n]",&query);
            l=strlen(query);
            fp=fopen("contact.dll","r");
            system("cls");
            printf("\n\nSearch result for '%s'\n ===================================================\n",query);
            while(fread(&list,sizeof(list),1,fp)==1){
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,query)==0){
                    printf("\nName\t: %s\nPhone\t: %ld\n",list.name,list.ph);
                    found++;
                    if (found%4==0){
                        printf("Press any key to continue...");
                        getch();
                    }
                }
            }
            if(found==0)
                printf("\nNo match found!");
            else
                printf("\n%d match(s) found!",found);
            fclose(fp);
            printf("\nTry again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
        while(ch==1);
        break;

    case 4:
        system("cls");

        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("\n\n\tEdit contact\n\t===============================\n\n\tEnter the name of contact to edit:");
        scanf("%[^\n]",name);
        while(fread(&list,sizeof(list),1,fp)==1){
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\nEditing '%s'\n\n",name);
        printf("Name:");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("Phone:");
        scanf("%ld",&list.ph);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;

    case 5:
        system("cls");

        fflush(stdin);
        printf("\n\n\tDELETE A CONTACT\n\t==========================\n\tEnter the name of contact to delete:");
        scanf("%[^\n]",&name);
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;

    default:
        printf("Invalid choice");
        break;

    }

    printf("\n\n\nEnter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {

    case 1:
        goto contact;

    case 0:
        break;

    default:
        printf("Invalid choice");
        break;
    }
    return 0;
}
