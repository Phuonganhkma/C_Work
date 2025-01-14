/*viet chuong trinh su du�ng kieu nhap xuat nhi phan voi tep la DU_LIEU.C
so lieu ban hang co cau truc gom cac thanh phan : Ten_Hang,
Don_Gia, So_Luong,Thanh_Tien. sau do dem noi dung tep theo hinh danh
                       SO LIEU BAN HANG
STT          Ten Hang           SO Luong          Thanh Tien
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char Ten_Hang[30];
    int Don_Gia;
    int SO_Luong;
}Hang_Hoa;

void writeFile()
{
    FILE *f;
    f = fopen("DU_LIEU.C", "wb");
    Hang_Hoa H;
    int n;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("nhap hang hoa %d\n", i+1);
        printf("Ten Hang: ");
        fflush(stdin);
        gets(H.Ten_Hang);
        printf("Don Gia: ");
        scanf("%d", &H.Don_Gia);
        printf("So Luong: ");
        scanf("%d", &H.SO_Luong);
        fwrite(&H, sizeof(Hang_Hoa),1, f);
    }
    f
    fclose(f);
}

void readFile()
{
    FILE *f;
    f = fopen("DU_LIEU.C", "rb");
    Hang_Hoa H;

    printf("%5s|%20s|%10s|%10s|%10s\n", "STT", "Ten Hang", "So Luong", "Don Gia", "Thanh Tien");
    fread(&H, sizeof(Hang_Hoa),1, f);
    while(!feof(f)){
        int i;
        printf("%5d|%20s|%10d|%10d|%10d\n",++i, H.Ten_Hang, H.Don_Gia, H.SO_Luong, H.Don_Gia * H.SO_Luong);
        fread(&H, sizeof(Hang_Hoa),1, f);
    }
    fclose(f);
}
void menu()
{
   printf("1. nhap\n");
   printf("2. xuat\n");
   printf("3. thoat\n");
   printf("Lua chon: ");
}

int main()
{
   int c;
   do {
    menu();
    scanf("%d", &c);
    switch(c)
    {
    case 1:
        writeFile();
        getch();
        system("cls");
        break;
    case 2:
        readFile();
        getch();
        system("cls");
        break;
    case 3:
        exit(0);
    default:
        printf("chi nhap tu 1 den 3");
    }
   }while( c>0 && c<4);
   return 0;
}
