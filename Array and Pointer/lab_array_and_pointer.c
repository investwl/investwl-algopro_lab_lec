#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    // pointerrrrrrr
    // int num1 = 0;
    // int* pnum1;

    // pnum1 = &num1;
    // *pnum1 = 9;
    // // knp bisa karena reference dari ptr pnum itu juga value dari num1
    // printf("%d\n", num1);

    // array
    //list nama org yg ikut event
    char name[10][100];
    int lastIndex = 0;
    while (1){
        printf("Enter name : ");
        scanf("%[^\n]s", name[lastIndex]);
        getchar();
        if ((strcmp((name[lastIndex]), "0")) == 0){break;}
        lastIndex++;
    }
    printf("Yang ikut ultah Yosua : \n");
    for (int i = 0; i < lastIndex; i++){
        printf("- %s\n", name[i]);
    }
    
    // make strcpy, copy string
    // strcpy(destination, source)
    char firstName[256] = "";
    char secondName[256] = "John";
    
    strcpy(firstName, secondName);
    printf("%s\n", firstName);

    // sprintf, fungsi bawaan string
    // tujuannya utk membentuk satu nilai tertentu 
    //dan ditro di dalam satu variable yg kita set
    char country[3] = "ID";
    char state[4] = "JKT";
    char numberId[5] = "007";

    // result wanted = ID-JKT-007
    // bikin 1 variable tumbal utk nampung
    char resultId[11];

    // format : sprintf(destination, source)
    // sourcenya bisa dibentuk bentuk kayak mau printf
    sprintf(resultId, "%s-%s-%s", country, state, numberId);
    printf("%s\n", resultId);
    // pokoknya outputnya sesuai dengan apa yang lu tulis di dalam
    // destionation di dalam sprintf
}