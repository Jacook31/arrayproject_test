#include <stdio.h>

int main(void) 
{
	/*int age;
	printf("���̰� ����ΰ���?");
	scanf(" %d", &age);
	printf("%d�� �Դϴ�", age);

	

	double one, two, three;
	printf("3���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &one, &two, &three);
	printf("ù��° �� : %d\n", one);
	printf("�ι�° �� : %d\n", two);
	printf("����° �� : %d\n", three);

	char c = 'A';
	printf("%c\n", c);*/
	

	//������Ʈ
	//�̸�? ����? ������? Ű? ���˸�?
	char name[256];
	printf("�̸��� �����Դϱ�?");
	scanf("%s", &name, sizeof(name));
	
	int age;
	printf("���̰� ��� �˴ϱ�?"); 
	scanf("%d", &age);

	float weight;
	printf("�����԰� ��kg �˴ϱ�?");
	scanf("%f", &weight);
	
	double height;
	printf("Ű�� ��cm �Դϱ�?"); 
	scanf("%lf", &height);

	
	char crime[256];
	printf("���˸��� �����Դϱ�?");
	scanf("%s", &crime, sizeof(crime));

	//���
	printf("\n --- ������ ���� ---\n\n");
	printf(" �̸�    : %s \n", name);
	printf(" ����    : %d \n", age);
	printf(" ������  : %.1f \n", weight);
	printf(" Ű      : %.2lf \n", height);
	printf(" ����    : %s \n", crime);

	

	
	
	


	return 0;
}