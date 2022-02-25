#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//10���� ���� �ٸ� ī�� ã�� (�� ī�� 2�� ã�Ƽ� ���ߴ°�)
// ����ڷ� ���� 2���� �Է°��� �޾Ƽ� -> ���� ī�� ã���� ī�� ������
// ��� ī�带 ���߸� ��������
// �� ���� Ƚ�� �˷��ֱ� (����¦�� ã�� ���� Ƚ��)
int arrayCard[4][5];    //ī�� ���� (20���� ī��)
int checkCard[4][5];    // ���������� ���� Ȯ�� 
int getEmptyPosition();
char * strCard[10];
int conv_pos_x(int x);
int conv_pos_y(int y);
int foundAllCard();

void initCardArray();
void initCardName();
void shuffleCard();
void printCards();   
void printfQuestion();

int main(void)
{
    srand(time(NULL));

    initCardArray();
    initCardName();

    shuffleCard();

    int failCount = 0; //���� Ƚ��

    while (1)
    {
        int select1 = 0;    // ����ڰ� ������ ó�� ��
        int select2 = 0;    // ����ڰ� ������ �ι�° ��

        printCards();       //ī�� ��ġ ���
        printfQuestion();   //���� ��� (ī�� ����)
        printf("������ ī�带 2�� ������ : ");
        scanf("%d %d", &select1, &select2);

        if(select1 == select2) //���� ī�� ���ý� ��ȿ
            continue;
        
        
        // ��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ Ȯ��
        // ���� ��ǥ�� (x,y)�� ��ȯ
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        // ���� ī���� ���
        if ((checkCard[firstSelect_x][firstSelect_y] == 0 
            && checkCard[secondSelect_x][secondSelect_y] == 0)
            &&
            (arrayCard[firstSelect_x][firstSelect_y] 
            == arrayCard[secondSelect_x][secondSelect_y]))
         // �� ���ĺ��� ������
         {
             printf("\n\n �¾ҽ��ϴ� : %s �߰� \n\n", strCard[arrayCard[firstSelect_x][firstSelect_y]]);
             checkCard[firstSelect_x][firstSelect_y] = 1;
             checkCard[secondSelect_x][secondSelect_y] = 1;
         }
         // �ٸ� ���ĺ��� ���
         else
         {
             printf("\n\n Ʋ�Ȱų�, �̹� ������ ī���Դϴ�. \n");
             printf("%d : %s\n", select1, strCard[arrayCard[firstSelect_x][firstSelect_y]]);
             printf("%d : %s\n", select2, strCard[arrayCard[secondSelect_x][secondSelect_y]]);
             printf("\n\n");

             failCount++;
         }
        
        // ��� ī�带 ã�Ҵ��� ����, 1 : �� , 0 : ����
        if (foundAllCard() == 1)
        {
            printf(" \n\n ���ī�带 �� ã�ҽ��ϴ�. \n");
            printf("���ݱ��� �� %d�� �Ǽ� �Ͽ����ϴ�.\n",failCount);
            break;
        }


    }


    return 0;
}

void initCardArray()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrayCard[i][j] = -1;
        }
    }
}
void initCardName()
{
    strCard[0] = "������";
    strCard[1] = "������";
    strCard[2] = "�ڳ���";
    strCard[3] = "Ÿ��";
    strCard[4] = "�ϸ�";

    strCard[5] = "����";
    strCard[6] = "�����";
    strCard[7] = "ȣ����";
    strCard[8] = "����";
    strCard[9] = "�⸰";

}

void shuffleCard()
{
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayCard[x][y] = i;
        }
    }
}

//��ǥ���� �� ���� ã��
int getEmptyPosition() //�ݺ��۾��� ���̱����� int�� ��� ����ü ����Ҽ� ����.
{
        //���������� 0  1  2  3  4  ->5�� �����ٸ� 0 0 0 0 0
        //���������� 5  6  7  8  9  -> 1 1 1 1 1
        //���������� 10 11 12 13 14  -> 2 2 2 2 2
        //���������� 15 16 17 18 19 -> 3 3 3 3 3
    while(1)
    {
        int randPos = rand() % 20; //0~19 ������ ���� ��ȯ
        // 19 -> (3,4)
        int x = conv_pos_x(randPos);    
        int y = conv_pos_y(randPos);

        if(arrayCard[x][y] == -1)
        {
            return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x)
{
     // 19 -> (3,4)
     return x / 5;
}
int conv_pos_y (int y)
{
        // 19 -> 19 / 5 = ���� 3, ������ 4
    return y % 5;   // y�� 5�� ���� ������ ��
}

void printCards() 
{
    printf("\n============== Ȯ���ϱ�� =================\n");
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%8s", strCard[arrayCard[i][j]]);
        }
        printf("\n");
    }
    printf("\n=========================================\n");
}    
void printfQuestion()
{
    printf("\n\n(����)\n");
    int seq = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            // ī�带 ����� ������ �������� 'ī�� ����'
            if(checkCard[i][j] != 0)
            {
                printf("%8s", strCard[arrayCard[i][j]]);
            }
            // ���� ������ �������� (������ ����������) �޸� -> ��ġ�� ��Ÿ���� ����
            else
            {
                printf("%8d",seq);
            }
            seq++;
        }
         printf("\n");
    }
}

int foundAllCard()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if (checkCard[i][j] == 0)
            {
            return 0;
            }
        }
    }
    return 1; // ��� �� ã��
}