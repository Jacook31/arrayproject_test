#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));
    printf("\n\n ======== ȸ������ ã�ƶ� ========\n\n");
    int answer;
    int potion = rand() % 4; //���� (0~3)

    int CntShowBottle = 0; //�̹� ���ӿ� ������ �� ����
    int prevCntShowBottle = 0; //�� ���ӿ� ������ �� ����
    //���� ���� �ִ� �� ������ �ٸ��� �Ͽ� ����� ��� (ó�� 2�� -> ������ 3��)

    // 3���� ��ȸ (3���� ȸ���� ���� �õ�)
    for (int i = 1; i <= 4; i++)
    {
        int bottle[4] = { 0, 0, 0, 0 }; //4���� ��
        do {
            CntShowBottle = rand() % 2 + 2; //������ �� ���� (0~1, +2 -> 2, 3)           
        } while (CntShowBottle == prevCntShowBottle);
        prevCntShowBottle = CntShowBottle;

        int islncluded = 0; //������ �� �߿� ȸ������ ���ԵǾ��ִ��� ���� (1 : ���� , 0 : ������)
        printf("> %d ��° �õ� : ", i);

        //������ �� ������ ����
        for (int j = 0; j < CntShowBottle; j++)
        {
            int randBottle = rand() % 4; // 0~3

            //���� ���õ��� ���� ���̶�� , ���� ó��
            if (bottle[randBottle] == 0)
            {
                bottle[randBottle] = 1;
                if (randBottle == potion)
                {
                    islncluded = 1;
                }
            }
            //�̹� ���õ� ���̸�, �ߺ��̹Ƿ� �ٽ� ����
            else
            {
                j--;
            }
        }
        //����ڿ��� ���� ǥ��
        for (int k = 0; k < 4; k++)
        {
            if (bottle[k] == 1)
                printf("%d", k + 1);


        }
        printf("������ �Խ��ϴ�.\n\n");

        if (islncluded == 1)
        {
            printf(">> ���� ! ��ҽ��ϴ� ! \n");
        }
        else {
            printf(">> ���� ! �׾����ϴ�. \n");
        }
        printf("\n ...  ��� �Ϸ��� �ƹ�Ű�� ��������....\n");
        getchar();
    }
    printf("\n\n ��¥������ �� �� �ϱ��? : ");
    scanf("%d", &answer);

    if (answer == potion + 1)
    {
        printf("\n >> �����Դϴ�!\n");
    }
    else
    {
        printf("\n >> Ʋ�Ƚ��ϴ�. ������ %d �Դϴ�\n", potion + 1);
    }



    return 0;
}