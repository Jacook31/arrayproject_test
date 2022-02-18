#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));
    printf("\n\n ======== 회복약을 찾아라 ========\n\n");
    int answer;
    int potion = rand() % 4; //선택 (0~3)

    int CntShowBottle = 0; //이번 게임에 보여줄 병 갯수
    int prevCntShowBottle = 0; //앞 게임에 보여준 병 갯수
    //서로 보여 주는 병 갯수를 다르게 하여 정답률 향상 (처음 2개 -> 다음엔 3개)

    // 3번의 기회 (3번의 회복약 투여 시도)
    for (int i = 1; i <= 4; i++)
    {
        int bottle[4] = { 0, 0, 0, 0 }; //4개의 병
        do {
            CntShowBottle = rand() % 2 + 2; //보여줄 병 갯수 (0~1, +2 -> 2, 3)           
        } while (CntShowBottle == prevCntShowBottle);
        prevCntShowBottle = CntShowBottle;

        int islncluded = 0; //보여줄 병 중에 회복약이 포함되어있는지 여부 (1 : 포함 , 0 : 미포함)
        printf("> %d 번째 시도 : ", i);

        //보여줄 병 종류를 선택
        for (int j = 0; j < CntShowBottle; j++)
        {
            int randBottle = rand() % 4; // 0~3

            //아직 선택되지 않은 병이라면 , 선택 처리
            if (bottle[randBottle] == 0)
            {
                bottle[randBottle] = 1;
                if (randBottle == potion)
                {
                    islncluded = 1;
                }
            }
            //이미 선택된 병이면, 중복이므로 다시 선택
            else
            {
                j--;
            }
        }
        //사용자에게 문제 표시
        for (int k = 0; k < 4; k++)
        {
            if (bottle[k] == 1)
                printf("%d", k + 1);


        }
        printf("포션을 먹습니다.\n\n");

        if (islncluded == 1)
        {
            printf(">> 성공 ! 살았습니다 ! \n");
        }
        else {
            printf(">> 실패 ! 죽었습니다. \n");
        }
        printf("\n ...  계속 하려면 아무키나 누르세요....\n");
        getchar();
    }
    printf("\n\n 진짜포션은 몇 번 일까요? : ");
    scanf("%d", &answer);

    if (answer == potion + 1)
    {
        printf("\n >> 정답입니다!\n");
    }
    else
    {
        printf("\n >> 틀렸습니다. 정답은 %d 입니다\n", potion + 1);
    }



    return 0;
}