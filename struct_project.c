#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 5마리의 고양이가 있다.
// 아무 키나 눌러서 랜덤으로 뽑는다.
// 5마리 모두 수집하는것 (중복 있음)

// 고양이
// 이름, 나이, 성격, 키우는난이도(레벨)

typedef struct{
    char * name;    //이름
    int age;        //나이
    char * character; //성격
    int level; //키우기 난이도 (1~5, 5가 어려움)
} CAT;

//현재까지 보유한 고양이
int collection[5] = { 0, 0, 0, 0, 0 };

// 전체 고양이 리스트
CAT cats[5];


void initCats(); //고양이 정보 초기화
void printCat(int selected);
int checkCollection();

int main(void)
{

    srand(time(NULL));

    initCats();
    while (1)
    {
        printf("고양이 뽑기! 아무키나 눌러서 확인하세요\n");
        getchar();

        int selected = rand() % 5; // 0~4 정보 반환
        printCat(selected);         // 뽑은 고양이 정보 출력
        collection[selected] = 1;   // 고양이 뽑기 처리

        int collectAll = checkCollection();
        if (collectAll == 1)
        {
            break;
        }

         
    }



    return 0;
}
void initCats()
{
    cats[0].name = "치즈냥";
    cats[0].age = 3;
    cats[0].character = "온순";
    cats[0].level = 1;

    cats[1].name = "러시안블루";
    cats[1].age = 2;
    cats[1].character = "날카롭다";
    cats[1].level = 4;

    cats[2].name = "페르시안";
    cats[2].age = 5;
    cats[2].character = "잠이많음";
    cats[2].level = 2;

    cats[3].name = "샴";
    cats[3].age = 1;
    cats[3].character = "온순";
    cats[3].level = 1;

    cats[4].name = "사바나";
    cats[4].age = 3;
    cats[4].character = "활발";
    cats[4].level = 3;  
}

void printCat(int selected)
{
    printf("\n\n=== 아래의 고양이가 걸렸어요! ====\n\n");
    printf(" 이름 : %s\n", cats[selected].name);
    printf(" 나이 : %d\n", cats[selected].age);
    printf(" 성격 : %s\n", cats[selected].character);
       //printf(" 레벨 : %d\n", cats[selected].level);
       printf(" 레벨 : ");

       for(int i = 0; i < cats[selected].level; i++)
       {
           printf("%s  ", "★");
       }
       printf("\n\n");
}

int checkCollection()
{
    // 현재 보유한 고양이 목록도 출력, 
    // 다 모았는지 여부를 반환
    int collectAll = 1;


    printf("\n\n ========== 보유한 고양이 목록 =========== \n\n");
    for (int i = 0; i < 5; i++)
    {
        if(collection[i] == 0)  // 고양이 수집 x
        {
            printf("%15s", "(빈 박스)");
            collectAll = 0; // 다 모으지 못한 상태
        }
        else // 고양이 수집 O
        {
            printf("%15s", cats[i].name);
        } 
        
        
    }
    printf("\n==============================================\n\n");

    if (collectAll)//고양이를 모두 모은 경우
        {
            printf("\n\n 축하합니다! 모든 고양이를 모았습니다. \n\n");
        }    

      return collectAll;
}