#include <stdio.h>

struct GameInfo
 {   
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame // ���� ��ü ����

};

typedef struct 
 {   
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame // ���� ��ü ����
} GAME_INFO;
int main(void)
{
    // ����ü ���
    struct  GameInfo gameInfo1;
    gameInfo1.name = "��������";
    gameInfo1.year = 2017;
    gameInfo1.price = 50;
    gameInfo1.company = "����ȸ��";

    // ����ü ���
    printf("--  ���� ��� ���� --\n");
    printf("  ���Ӹ�   : %s\n", gameInfo1.name);
    printf("  �߸ų⵵ : %d\n", gameInfo1.year);
    printf("  ����     : %d\n", gameInfo1.price);
    printf("  ����ȸ�� : %s\n", gameInfo1.company);
    
    // ����ü�� �迭ó�� �ʱ�ȭ
    struct  GameInfo gameInfo2 = {"�ʵ�����", 2017, 100, "�ʵ�ȸ��"};
    printf("\n--  ���� ��� ����2 --\n");
    printf("  ���Ӹ�   : %s\n", gameInfo2.name);
    printf("  �߸ų⵵ : %d\n", gameInfo2.year);
    printf("  ����     : %d\n", gameInfo2.price);
    printf("  ����ȸ�� : %s\n", gameInfo2.company);

    // ����ü �迭
    struct GameInfo gameArray[2] ={

     {"��������", 2017, 50, "����ȸ��"},
     {"�ʵ�����", 2017, 100, "�ʵ�ȸ��"}
    };

    // ����ü ������
    struct GameInfo * gamePtr; //�̼Ǹ�
    gamePtr = &gameInfo2;
    // printf("\n\n--  �̼Ǹǰ��� ��� ���� --\n");
    // printf("  ���Ӹ�   : %s\n", (*gamePtr).name);
    // printf("  �߸ų⵵ : %d\n", (*gamePtr).year);
    // printf("  ����     : %d\n", (*gamePtr).price);
    // printf("  ����ȸ�� : %s\n", (*gamePtr).company);
    printf("\n\n--  �̼Ǹǰ��� ��� ���� --\n");
    printf("  ���Ӹ�   : %s\n", gamePtr->name);
    printf("  �߸ų⵵ : %d\n", gamePtr->year);
    printf("  ����     : %d\n", gamePtr->price);
    printf("  ����ȸ�� : %s\n", gamePtr->company);

    // ����ü ���� ����ü (���� ��ü ����)
    gameInfo1.friendGame = &gameInfo2;
    printf("\n\n--  ���� ��ü ���� ��� ���� --\n");
    printf("  ���Ӹ�   : %s\n", gameInfo1.friendGame->name);
    printf("  �߸ų⵵ : %d\n", gameInfo1.friendGame->year);
    printf("  ����     : %d\n", gameInfo1.friendGame->price);
    printf("  ����ȸ�� : %s\n", gameInfo1.friendGame->company);

    // typedef
    // �ڷ����� ���� ����  
    // int i = 1;
    // typedef int ����;  
    // ���� �������� = 3;          // int �������� = 3;
    // printf("�������� : %d\n\n", ��������);
    // �� ���� ���������� vscode ����
    
    // typedef struct GameInfo ��������;
    // �������� game1;
    // game1.name = "�ѱ� ����";
    // game1.year = 2015;
    // game1.price = 100;
    // game1.company = "�ѱ� ȸ��";

    // GAME_INFO game2;
    // game2.name = "�ѱ� ����2"
    // game2.year = 2015;
    // game2.price = 100;
    // game2.company = "�ѱ� ȸ��2";

    //  struct GameInfomation game3;
    //  game3.name = "�ѱ� ����3"

    return 0;
}