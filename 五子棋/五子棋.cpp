#include"stdio.h"
#include"windows.h"
#include"conio.h"
#define wide 21									//�궨�����̴�С
#define length 41
void game();											 //��Ϸ���е��ú�����
void drawbroad();									 //����forѭ����Ƕ�׻������̡�
int down();
int Justment();
int gamer = 1;										//��ȡ�غ���ģʽ�����ø���ұ�����				
int y = length / 2;									 //��ʼ������ָ��λ��ֵΪ�������롣		
int x = wide / 2;
int date[wide][length] = { { 0,0 } };			//����һ����ά������������Ա�ʾ���̸�λ���ϵĺڰ����Ӳ��б�ɷ����ӡ�
																 //�Ծֿ�ʼǰ�Զ�ά�����е����ݳ�ʼ������ֵΪ0��
int winner = 0;

void rest()						//�������ݳ�ʼ������������һ����Ϸ��
{

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 41; j++)
			date[i][j] = 0;
	}
	winner = 0;
	x = wide / 2;
	y = length / 2;
	gamer = 1;
	int n = MessageBox(NULL, L"�Ƿ����������һ����Ϸ?", L"������", MB_YESNO | MB_ICONQUESTION);
	switch (n)
	{
	case IDYES:game(); break;
	case IDNO:system("cls");
		printf("\n\n\n\n******************************************\n       ��Ȼ�������Ǻðɡ��´����氡��\n******************************************\n\n\n\n\n\n\n\n\n");
		system("exit");
		system("PAUSE");
		break;
	}
}
int down()												 //�ж����ӳɲ��ɹ���ʵ��һ��ֵ�ķ����ж��ܲ������ӣ�
{
	if (date[x][y] == 0 && x != 0 && x != (wide - 1) && y != 0 && y != (length - 1))
	{
		date[x][y] = gamer;
		return 1;
	}
	else return 0;
}
void main()
{
	system("mode con cols=43 lines=25  ");
	SetConsoleTitle(L"�������ս");		 //windows.h�еĺ�������ʵ�ָı����̨���⡣
	int ret = MessageBox(NULL, L"�Ƿ�ȷ����ʼ��Ϸ?", L"������", MB_YESNO | MB_ICONQUESTION);//��Ȥ�ĶԻ������������ɵ����Ի����Զ��尴ť�����ڱ��������ݣ�
	switch (ret)
	{
	case IDNO:
		system("cls");
		printf("\n\n\n\n\n\n******************************************\n       ��Ȼ�������Ǻðɡ��´����氡��\n******************************************\n\n\n\n\n\n\n\n");
		system("PAUSE");
		break;
	case IDYES:
		game();
		break;
	}
}
void drawbroad()
{
	int i, j;
	for (i = 0; i < wide; i++)
	{
		for (j = 0; j < length; j++)
		{
			if (i == x && j == y)
				printf("�w");														//��ӡ��ʾ��꣬��ʼλ�á�
			else if (i == 0 && j == 0)
				printf("��");														//���Ȼ������̵��ĸ��ǡ�
			else if (i == wide - 1 && j == 0)
				printf("��");
			else if (i == 0 && j == length - 1)
				printf("��");
			else if (i == wide - 1 && j == length - 1)
				printf("��");
			else if (i == 0)
				printf("��");
			else if (j == 0)
				printf("��");
			else if (i == wide - 1)
				printf("��");
			else if (j == length - 1)
				printf("��");
			else if (date[i][j] == 1)		//����������ʵ�����ӣ���game���������м���ֵ��ȡͨ������������ݵ�ȫ�ֱ�����ά����date[][]��ϵ������ʵ�����Ӵ�ӡ����Ӯ���㷨�жϡ�
			{
				printf("��");
				j++;								//�ؼ���һ���������б����Ӻ󣬴�ӡ���Ӳ��ԡ�j������Ӱ�죬����˺�������ӡ��ͬ�����ġ��ࡱ�������̻��ƴ��ҡ�ͻ����
			}
			else if (date[i][j] == 2)
			{
				printf("��");
				j++;
			}
			else if (j % 2 == 1)					   //�Ʊ���С��ࡱ�����ܼ�����ȫ������������̹����ܼ�������jֵ�ı仯ʵ�ּ������ո�
				printf(" ");
			else
				printf("��");                             //���ಿ���á��ࡱ��䡣

		}
		printf("\n");                                    //ÿ��ӡһ�У����С�
	}

}
void game()												//�ƶ��ı�ָ��λ�ã����Ӿ���ʾ���á�
{
	while (1)
	{
		system("cls");									//����������ѭ�����������ƴ�ӡʵ�ֶ�̬����Ч����
		drawbroad();
		printf("\n     һ��һ���غ��ƣ���Ӯ���и��·֡�\n");//ͨ��������������ʾ�ڱ�����Ϸ�����ͬʱ������ʹ�����顣
		switch (_getch())								//getch()������ʵ�ֳ�����ȡ�����ַ���������conio.hͷ�ļ�����
		{
		case 32:
			if (down() == 1)                            //�����ϵ�"�ո�"������ʵ��ͨ���ո��ʵ���������ӡ�
			{
				winner = Justment();                     //�ж���Ӯ

				gamer = 3 - gamer;						//ʵ����ҵĽ������ɡ�1������2����3-1=2��3-2=1��
			}
			else
				MessageBox(NULL, L"�˴����������ӣ������ԣ�", L"������", MB_OK | MB_ICONEXCLAMATION);		//���ӻ���������ʵ�ֵ�������������ʱ�������ӵĴ�����ʾ��
		case 75:
			y--;
			y--;											//����ͨ�����Ρ�y--�������ƽ��������λ���
			if (y < 0)y = length - 1;
			break;										//����ֵ����ʾ�����ϡ��󡱽���
		case 77:
			y++;
			y++;
			if (y > length - 1)y = 0;
			break;										//����ֵ����ʾ�����ϡ��ҡ�����
		case 72:x--;									//ͨ����ȡ����ֵ������ȫ�ֱ���x��y�ĸı�ʵ����ʾ���Ĳ�ͬλ�ô�ӡ��
			if (x < 0)x = wide - 1;
			break;										//����ֵ����ʾ�����ϡ��ϡ�����
		case 80:x++;
			if (x > wide - 1)x = 0;						//��x��y�ı仯��Χ�������ƣ����䳬�����̷�Χʱֵ��Ϊ������һ�ߣ�ʵ�ִ�Խ����Ч����
			break;										//����ֵ����ʾ�����ϡ��¡�����
		}
		if (winner == 1)
		{
			MessageBox(NULL, L"����Ӯ��", L"������", MB_OK);
			rest();
			break;
		}
		else if (winner == 2)
		{
			MessageBox(NULL, L"����Ӯ��", L"������", MB_OK);
			rest();
			break;
		}
		else continue;
	}
}
int Justment()
{
	int line = 1;                   //ˮƽ����
	int vertical = 1;               //��ֱ����
	int positive = 1;               //��б����
	int negative = 1;               //��б����
	//ˮƽ
	//�����ж�
	for (int i = 2; i < 10; i += 2)
	{
		if (y + i < length && date[x][y + i] == gamer)
			line++;
		else
			break;
	}
	//�����ж�
	for (int i = 2; i < 10; i += 2)
	{
		if (y - i > 0 && date[x][y - i] == gamer)
			line++;
		else
			break;
	}

	//��ֱ����
	for (int i = 1; i < 5; i++)//�����ж�
	{
		if (x - i > 0 && date[x - i][y] == gamer)
			vertical++;
		else
			break;
	}
	for (int i = 1; i < 5; i++)	//�����ж�
	{
		if (x + i < wide && date[x + i][y] == gamer)
			vertical++;
		else
			break;
	}
	//��б���ж�(���·�"\")
	for (int i = 1, j = 2; i < 5; i++, j += 2)							//�����ж�
	{
		if (x - i > 0 && y - j > 0 && date[x - i][y - j] == gamer)
			positive++;
		else
			break;
	}
	for (int i = 1, j = 2; i < 5; i++, j += 2)							//�����ж�
	{
		if (x + i < wide && y + j < length && date[x + i][y + j] == gamer)
			positive++;
		else
			break;
	}
	//��б���ж�(/)
	for (int i = 1, j = 2; i < 5; i++, j += 2)                            //�����ж�
	{
		if (x + i < wide && y - j > 0 && date[x + i][y - j] == gamer)
			negative++;
		else
			break;
	}
	for (int i = 1, j = 2; i < 5; i++, j += 2)                           //�����ж�
	{
		if (x - i > 0 && y + j < length && date[x - i][y + j] == gamer)
			negative++;
		else
			break;
	}
	if (vertical >= 5 || positive >= 5 || negative >= 5 || line >= 5)
		return gamer;
	else return 0;
}