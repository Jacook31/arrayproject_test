#include <stdio.h>

void swap(int a, int b);
void swap_addr(int * a, int * b);
void changeArray(int * ptr);

int level;
int arrayFish[6];
void initData();

int main(void)
{
    //������
    //chulsu : 101ȣ
    //yonghee : 201ȣ
    //minsu : 301ȣ
    // int chulsu  = 1;    //��ȣ
    // int yonghee = 2;
    // int minsu = 3;
    // printf("ö���� �ּ� : %d, ��ȣ : %d\n", &chulsu, chulsu); 
    // printf("����� �ּ� : %d, ��ȣ : %d\n", &yonghee, yonghee);
    // printf("�μ��� �ּ� : %d, ��ȣ : %d\n", &minsu, minsu); //�޸𸮰����� �ּҸ� ��Ÿ������ &�� ���ָ��    
    //�̼�
    //ù��° �̼� : ����Ʈ�� �� ���� �湮�Ͽ� ���� ���� ��ȣ Ȯ��
    // int *mission; //pointer variable
    // mission = &chulsu;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    //  mission = &yonghee;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // mission = &minsu;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // //second mission : �� ��ȣ�� 3�� ���ض�
    // mission = &chulsu;
    // *mission = *mission * 3;
    //  printf("�̼� ��ȣ�� �ٲ۰� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // mission = &yonghee;
    // *mission = *mission * 3;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // mission = &minsu;
    // *mission = *mission * 3;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // //spy
    // //�̼��� �ٲ� ��ȣ���� 2�� ����
    // int *spy = mission;     
    // printf("\n ... spy�� �̼� �����ϴ��� ...\n\n");
    // spy = &chulsu; 
    // *spy = *spy - 2; 
    // printf("spy�� �湮�ϴ°� �ּ� : %d, ��ȣ %d\n",spy, *spy);
    //  spy = &yonghee;
    // *spy = *spy - 2; 
    // printf("spy�� �湮�ϴ°� �ּ� : %d, ��ȣ %d\n",spy, *spy);
    //  spy = &minsu;
    // *spy = *spy - 2; 
    // printf("spy�� �湮�ϴ°� �ּ� : %d, ��ȣ %d\n",spy, *spy);
    // printf(" \n... ��ȣ�� �ٲ����.\n");
    // printf("ö���� �ּ� : %d, ��ȣ : %d\n", &chulsu, chulsu); 
    // printf("����� �ּ� : %d, ��ȣ : %d\n", &yonghee, yonghee);
    // printf("�μ��� �ּ� : %d, ��ȣ : %d\n", &minsu, minsu);
    // //mision �ּҴ� &mission���� Ȯ��
    // printf("mission address : %d\n", &mission);
    // printf("spy address : %d\n", &spy);  

   //�迭 
//    int arr[3] = {5 , 10 , 15};
//    int * ptr = arr;
//    for (int i = 0; i < 3; i++)
//    {
//        printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);
//    }
//    for (int i = 0; i < 3; i++)
//    {
//        printf("������ ptr[%d]�� �� : %d\n", i,  ptr[i]);
//    }
//     ptr[0] = 100;
//     ptr[1] = 200;
//     ptr[2] = 300;
//     for (int i = 0; i < 3; i++)
//    {
//        //printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);
//        printf("�迭 arr[%d]�� �� : %d\n", i, *(arr + i)); //���ٰ� ���� ������� ���´�.
//    }
//    for (int i = 0; i < 3; i++)
//    {
//        //printf("������ ptr[%d]�� �� : %d\n", i,  ptr[i]);
//        printf("������ ptr[%d]�� �� : %d\n", i, *(ptr + i));
//    }
//     //*(arr + i) == arr[i] �Ȱ��� ǥ���̴�.
//     //arr == arr �迭�� ù��° ���� �ּҿ� ���� == &arr[0] // �ּ�= '&' �� ǥ���Ѵ�
//     printf(" arr ��ü�� ��  : %d\n",arr);
//     printf(" arr[0]�� �ּ� : %d\n", &arr[0]);
//     //
//     printf(" arr ��ü�� ���� ������ �ּ��� ���� �� : %d \n", *arr);
//     printf(" arr[0] �� ���� �� : %d\n", *&arr[0]);
//     //
//     // *& �� �ƹ��͵� ���� �Ͱ� ����. &�� �ּ��̸�, *�� �� �ּ��� ���̱� ������
//     // *&�� ���� ��Ⱑ �ȴ�.
//     printf("arr[0]�� ���� �� : %d\n",*&*&*&*&*&*&*&*&*&*&*&arr[0]);
//      printf("arr[0]�� ���� �� : %d\n", arr[0]);

    //SWAP
    // int a = 10;
    // int b = 20;
    // printf("a�� �ּ� : %d\n", &a);
    // printf("b�� �ּ� : %d\n", &b);
    // // a �� b�� ���� �ٲ۴�
    // printf("Swap �Լ� �� => a : %d, b = %d\n",a,b);
    // swap(a,b);
    // printf("Swap �Լ� �� => a : %d, b = %d\n",a,b);
    // //���� ���� ���� (Call by Value) -> ���� �����Ѵٴ� �ǹ�
    // //
    // // �ּҰ��� �ѱ��? �޸� ������ �ִ� �ּҰ� ��ü�� �ѱ��.. ö���� ó��
    // printf("(�ּҰ�����)swap �Լ� �� => a : %d, b = %d\n",a,b);
    // swap_addr(&a,&b);
    // printf("(�ּҰ�����)Swap �Լ� �� => a : %d, b = %d\n",a,b);

    //�迭�� ��, arr2 ->�ּ�
    // int arr2[3] = {10, 20, 30};
    //changeArray(arr2);
    // changeArray(&arr2[0]);
    // for( int i = 0; i < 3; i++)
    // {
    //     printf("%d\n", arr2[i]);
    // }
    //
    // scanf ���� &num �� ���� & �� ����ϴ�����

    //������Ʈ(������)
    //
    long startTime = 0; //���� ���� �ð�
    long totalElapsedTime = 0; //�� ��ȭ �ð�
    long prevElapsedTime = 0; //���� ��� �ð�  (�ֱٿ� ���� �� �ð� ����)

    int num;    //�� �� ���׿� ���� ä�������, ����� �Է�
    initData();
    



    return 0;
}

// void swap(int a, int b)
// {
//     printf("(swap �Լ� ��) a�� �ּ� : %d\n", &a);
//     printf("(swap �Լ� ��) b�� �ּ� : %d\n", &b);
//     int temp = a;
//     a = b;
//     b = temp;
//     printf("Swap �Լ� �� => a : %d, b = %d\n",a,b);
//
// }
// void swap_addr(int * a, int * b)
// {  
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("(�ּҰ�����)Swap_addr �Լ� �� => a : %d, b = %d\n", *a, *b);
//
// }     
// void changeArray(int * ptr)
// {
//     ptr[2] = 50;
// }
void initData()
{
    level = 1; //���ӷ��� (1~5)
    for(int i = 0; i < 6; i++)
    {
        arrayFish[i] = 100; //������ ������ 0~100
    }
}