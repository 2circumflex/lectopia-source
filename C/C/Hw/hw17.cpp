/* ��¥ : 2012�� 2�� 8��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �ָ޴� 5�� ���, ���޴�ȭ�� ���� */
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#pragma warning (disable : 4996)
char menu();
void input();
void output();
void search();
void mydelete();
void mistake();
void end();
int main()
{
	char m_res;	

	do
	{
		m_res = menu();

		if(m_res == '5')
		{
			end();
			break;
		}		
		else if(m_res == '1')
		{
			input();
		}
		else if(m_res == '2')
		{
			output();
		}
		else if(m_res == '3')
		{
			search();
		}
		else if(m_res == '4')
		{
			mydelete();
		}
		else
		{
			mistake();			
		}
				
	}while(1);

	return 0;
}
char menu()
{
	char m_num;

	system("cls");
	printf("\n\n\n\t\t\t\t1. �Է��ϱ�\n\n");
	printf("\t\t\t\t2. ����ϱ�\n\n");
	printf("\t\t\t\t3. �˻��ϱ�\n\n");
	printf("\t\t\t\t4. �����ϱ�\n\n");
	printf("\t\t\t\t5. ��    ��\n\n");
	printf("\t\t\t\t#�޴��� �����ϼ��� : ");
	fflush(stdin);
	m_num = getchar();
	
	return m_num;
}
void input()
{
	system("cls");
	printf("\n\n\n\t\t\t\t1�� �Է��ϱ� �޴��Դϴ�.\n\n");
	printf("\n\n\n\t\t\t# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
	getch();

	return;
}
void output()
{
	system("cls");
	printf("\n\n\n\t\t\t\t2�� ����ϱ� �޴��Դϴ�.\n\n");
	printf("\n\n\n\t\t\t# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
	getch();

	return;
}
void search()
{
	system("cls");
	printf("\n\n\n\t\t\t\t3�� �˻��ϱ� �޴��Դϴ�.\n\n");
	printf("\n\n\n\t\t\t# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
	getch();

	return;
}
void mydelete()
{
	system("cls");
	printf("\n\n\n\t\t\t\t4�� �����ϱ� �޴��Դϴ�.\n\n");
	printf("\n\n\n\t\t\t# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
	getch();

	return;
}
void mistake()
{
	system("cls");
	printf("\n\n\n\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n\n");
	printf("\n\n\n\t\t\t# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
	getch();

	return;
}
void end()
{
	system("cls");
	printf("\n\n\n\t\t\t\t�����մϴ�.\n\n");

	return;
}