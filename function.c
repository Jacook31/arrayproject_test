#include <stdio.h>

//�����Լ� ���ʿ��� ������ �ϰ� ���� �Ʒ��U�� �Ȱ��� �����
void p(int num);

//void function_without_return();

int function_with_return();
void function_without_params();
void fuction_with_params(int num1, int num2, int num3);
int apple(int total, int ate); //��ü total ���� ate���� �԰� ���� �� �� ��ȯ.

int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);

int main(void)
{

	//function

	//����
	/*int num = 2;

	p(num);

	num = num + 3;
	p(num);

	num -= 1;
	p(num);

	num *= 3;
	p(num);

	num /= 6;
	p(num);*/

	/*�Լ� ����
	��ȯ���� ���� �Լ�
	function_without_return();

	��ȯ���� �ִ� �Լ�*/
	/*int ret = function_with_return();
	p(ret);*/

	//�Ķ����(���ް�)�� ���� �Լ�
	/*function_without_params();*/

	//�Ķ���� (���ް�)�� �ִ� �Լ�
	//fuction_with_params(15, 32, 53);

	//�Ķ���͵� �ް� ��ȯ���� �ִ� �Լ�
	//int ret = apple(5, 2); //5���� ����� 2���� �Ծ���
	//printf("��� 5�� �߿� 2���� ������? %d���� ���ƿ�",ret);
	//printf("��� %d �� �߿� %d�� �� ������? %d ���� ���ƿ�\n", 10, 4, apple(10, 4));

	//���� �Լ�
	//printf("���ڿ� �����ȣ�� ���ÿ�\n");
	//scanf_s(" %d %c %d",&num1,&dja1,&num2);
	int num = 2;
	num = add(num, 3);
	p(num);

	num = sub(num, 1);
	p(num);

	num = mul(num, 4);
	p(num);

	num = div(num, 2);
	p(num);

	return 0;
}
//����
void p(int num)
{
	printf(" num �� %d �Դϴ�\n ", num);
}



//int �Լ��̸�(int num1, int num2, char c )
//{
//	return num + 4;
//}
//
//void function_without_return()
//{
//	printf("��ȯ���� ���� �Լ� �Դϴ�");
//}

function_with_return()
{
	printf("��ȯ���� �ִ� �Լ� �Դϴ�\n");
	return 10;
}

void function_without_params()
{
	printf("���ް��� ���� �Լ� �Դϴ�\n");
}

void fuction_with_params(int num1, int num2, int num3)
{
	printf("���ް��� �ִ� �Լ� �̸� ���� %d, %d, %d �Դϴ�.\n",num1,num2,num3);
}

int apple(int total, int ate)
{
	printf("���ް��� ��ȯ���� �ִ� �Լ� �Դϴ�.  \n");
	return total - ate;;
}
int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

int div(int num1, int num2)
{
	return num1 / num2;
}