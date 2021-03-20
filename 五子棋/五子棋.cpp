#include"stdio.h"
#include"windows.h"
#include"conio.h"
#define wide 21									//宏定义棋盘大小
#define length 41
void game();											 //游戏进行调用函数。
void drawbroad();									 //利用for循环的嵌套绘制棋盘。
int down();
int Justment();
int gamer = 1;										//采取回合制模式，设置个玩家变量。				
int y = length / 2;									 //初始化定义指针位置值为棋盘中央。		
int x = wide / 2;
int date[wide][length] = { { 0,0 } };			//定义一个二维数组变量，用以表示棋盘各位置上的黑白棋子并判别可否下子。
																 //对局开始前对二维数组中的数据初始化，赋值为0。
int winner = 0;

void rest()						//数组数据初始化；并进行下一局游戏。
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
	int n = MessageBox(NULL, L"是否继续进行下一场游戏?", L"五子棋", MB_YESNO | MB_ICONQUESTION);
	switch (n)
	{
	case IDYES:game(); break;
	case IDNO:system("cls");
		printf("\n\n\n\n******************************************\n       既然这样，那好吧。下次来玩啊！\n******************************************\n\n\n\n\n\n\n\n\n");
		system("exit");
		system("PAUSE");
		break;
	}
}
int down()												 //判断落子成不成功，实现一个值的返回判断能不能落子，
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
	SetConsoleTitle(L"五子棋对战");		 //windows.h中的函数，可实现改变控制台标题。
	int ret = MessageBox(NULL, L"是否确定开始游戏?", L"五子棋", MB_YESNO | MB_ICONQUESTION);//有趣的对话弹窗函数，可弹出对话框并自定义按钮及窗口标题与内容！
	switch (ret)
	{
	case IDNO:
		system("cls");
		printf("\n\n\n\n\n\n******************************************\n       既然这样，那好吧。下次来玩啊！\n******************************************\n\n\n\n\n\n\n\n");
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
				printf("╳");														//打印提示光标，初始位置。
			else if (i == 0 && j == 0)
				printf("┏");														//首先绘制棋盘的四个角。
			else if (i == wide - 1 && j == 0)
				printf("┗");
			else if (i == 0 && j == length - 1)
				printf("┓");
			else if (i == wide - 1 && j == length - 1)
				printf("┛");
			else if (i == 0)
				printf("─");
			else if (j == 0)
				printf("│");
			else if (i == wide - 1)
				printf("─");
			else if (j == length - 1)
				printf("│");
			else if (date[i][j] == 1)		//绘制棋盘中实现落子，与game（）函数中键盘值读取通过存放棋盘数据的全局变量二维数组date[][]联系起来，实现棋子打印和输赢的算法判断。
			{
				printf("○");
				j++;								//关键的一步自增！判别落子后，打印棋子不对“j”产生影响，因而此后会继续打印相同个数的“┼”导致棋盘绘制错乱、突出。
			}
			else if (date[i][j] == 2)
			{
				printf("●");
				j++;
			}
			else if (j % 2 == 1)					   //制表符中“┼”过于密集，若全部用其填充棋盘过于密集，利用j值的变化实现间隔输出空格。
				printf(" ");
			else
				printf("┼");                             //其余部分用“┼”填充。

		}
		printf("\n");                                    //每打印一行，换行。
	}

}
void game()												//移动改变指针位置，起视觉提示作用。
{
	while (1)
	{
		system("cls");									//清屏函数，循环清屏并绘制打印实现动态更新效果。
		drawbroad();
		printf("\n     一人一步回合制，输赢立判高下分。\n");//通过这样的文字提示在标明游戏规则的同时，增加使用体验。
		switch (_getch())								//getch()函数，实现持续读取键盘字符，包含于conio.h头文件库中
		{
		case 32:
			if (down() == 1)                            //键盘上的"空格"键。欲实现通过空格键实现落下棋子。
			{
				winner = Justment();                     //判断输赢

				gamer = 3 - gamer;						//实现玩家的交换：由“1”→“2”，3-1=2；3-2=1。
			}
			else
				MessageBox(NULL, L"此处不可以落子，请重试！", L"五子棋", MB_OK | MB_ICONEXCLAMATION);		//增加互动反馈，实现当棋盘上有棋子时继续落子的错误提示。
		case 75:
			y--;
			y--;											//这里通过两次“y--”将光标平移两个单位表格。
			if (y < 0)y = length - 1;
			break;										//键盘值，表示键盘上“左”建。
		case 77:
			y++;
			y++;
			if (y > length - 1)y = 0;
			break;										//键盘值，表示键盘上“右”建。
		case 72:x--;									//通过读取键盘值，并对全局变量x，y的改变实现提示光标的不同位置打印。
			if (x < 0)x = wide - 1;
			break;										//键盘值，表示键盘上”上“键。
		case 80:x++;
			if (x > wide - 1)x = 0;						//对x，y的变化范围进行限制，当其超出棋盘范围时值归为棋盘另一边，实现穿越棋盘效果。
			break;										//键盘值，表示键盘上“下”建。
		}
		if (winner == 1)
		{
			MessageBox(NULL, L"黑子赢了", L"五子棋", MB_OK);
			rest();
			break;
		}
		else if (winner == 2)
		{
			MessageBox(NULL, L"白子赢了", L"五子棋", MB_OK);
			rest();
			break;
		}
		else continue;
	}
}
int Justment()
{
	int line = 1;                   //水平方向
	int vertical = 1;               //竖直方向
	int positive = 1;               //正斜方向
	int negative = 1;               //反斜方向
	//水平
	//向右判断
	for (int i = 2; i < 10; i += 2)
	{
		if (y + i < length && date[x][y + i] == gamer)
			line++;
		else
			break;
	}
	//向左判断
	for (int i = 2; i < 10; i += 2)
	{
		if (y - i > 0 && date[x][y - i] == gamer)
			line++;
		else
			break;
	}

	//竖直方向
	for (int i = 1; i < 5; i++)//向上判断
	{
		if (x - i > 0 && date[x - i][y] == gamer)
			vertical++;
		else
			break;
	}
	for (int i = 1; i < 5; i++)	//向下判断
	{
		if (x + i < wide && date[x + i][y] == gamer)
			vertical++;
		else
			break;
	}
	//正斜向判断(右下方"\")
	for (int i = 1, j = 2; i < 5; i++, j += 2)							//左上判断
	{
		if (x - i > 0 && y - j > 0 && date[x - i][y - j] == gamer)
			positive++;
		else
			break;
	}
	for (int i = 1, j = 2; i < 5; i++, j += 2)							//右下判断
	{
		if (x + i < wide && y + j < length && date[x + i][y + j] == gamer)
			positive++;
		else
			break;
	}
	//反斜向判断(/)
	for (int i = 1, j = 2; i < 5; i++, j += 2)                            //左下判断
	{
		if (x + i < wide && y - j > 0 && date[x + i][y - j] == gamer)
			negative++;
		else
			break;
	}
	for (int i = 1, j = 2; i < 5; i++, j += 2)                           //右上判断
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