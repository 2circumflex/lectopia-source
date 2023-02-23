// ����26 �Ҽ� ��� ���α׷�
// ���α׷��� : �����Ǿ� ������ ����

#include<stdio.h>

int prime_number(int);
int main()
{
    int i, cnt=0, num;  // cnt : �Ҽ��� ������ count�ϴ� ����
	
    printf("# �������� �ϳ� �Է��Ͻÿ� : ");
    scanf("%d", &num);
    for(i=2; i<=num; i++)
	{ 
		if(prime_number(i)==1) // �˻��� i�� ���� �Ҽ��̸�
		{ 
			printf("%6d", i);
			if(++cnt%5==0) printf("\n");  // ���ٿ� 5���� �Ҽ��� ����ϴ� ǥ��
		}
    }
    printf("\n1~%d ������ �� �Ҽ��� ������ %d���̴�\n", num, cnt);

	return 0;
}

int prime_number(int num) // �Ҽ��̸� 1, �ƴϸ� 0�� �����ϴ� �Լ�
{
    int i;
    for(i=2; i<=sqrt(num); i++)  // num�� �˻��� �����̰� 2���� num�� sqrt���� �ش��ϴ� ���ڱ����� ���� 
	{  
		if(num%i==0)  // ������ �������°��� �˻��Ѵ�.
		{  
			return 0;     // ���̻� �˻��� �ʿ䰡 �����Ƿ� 0�� return�� 
		}
    }
    return 1; // for�� �߰����� return���� �ʾ����� �� ��� ���ε� ������ �������� �����Ƿ� �Ҽ���
}