/* ��¥ : 2012�� 2�� 6��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : Pay ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int hour, chour, gpay, tx, npay;


	while(1)
	{
		printf("* 1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
		scanf("%d", &hour);
				
		if(hour>40)
		{
			chour = hour - 40;
			chour = (int)(chour * 3000 * 1.5);
			gpay = 40 * 3000 + chour;		
		}
		else
		{
			gpay = hour * 3000;
		}

		if(gpay > 100000)
		{
			tx = 15000 + (int)((gpay - 100000) * 0.25);				
			npay = gpay - tx;
		}
		else
		{
			tx = (int)(gpay * 0.15);
			npay = gpay - tx;
		}
	
		printf("# �Ѽ��� : %6d��\n", gpay);
		printf("# ��  �� : %6d��\n", tx);
		printf("# �Ǽ��� : %6d��\n\n", npay);
	}

	return 0;
}