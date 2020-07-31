#include <iostream>
#include <windows.h>
using namespace std;

//鼠标按键判断 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
// 左  ：KEY_DOWN(MOUSE_MOVED)
// 右  ：KEY_DOWN(MOUSE_EVENT)
//滚轮 ：KEY_DOWN(MOUSE_WHEELED)

//置顶此窗口 
void TopWindow(HWND &hWnd)
{
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

bool check(char c)
{//检测某个按键是否按下
	if(!KEY_DOWN(c))return 0;
	else return 1;
}

void f_out(int num,char c)
{
	for (int i = 0;i < num;i ++)
		cout << c;
}

void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a| BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
/*
	1	深蓝色
	2	深绿色
	3	深青色 
	4	深红色
	5	深粉色
	6	黄色
	7	深白色
	8	灰色
	9	浅蓝色
	10	浅绿色 
	11	浅青色 
	12	浅红色 
	13	浅粉色 
	14	浅黄色 
	15	浅白色 
	
	背景
	1~15		黑色 
	16~31		深蓝色 
	32~47		深绿色
	48~63		深青色
	64~79		深红色
	80~95		深粉色
	96~111		深黄色
	112~127 	深白色
	128~143 	灰色
	144~159 	浅蓝色
	160~175 	浅绿色
	176~191 	浅青色 
	192~207 	浅红色
	208~223 	浅粉色
	224~239 	浅黄色
	240~255 	浅白色
*/
}

void home_page()
{
	/*
	+------------------------------------+
	|  Q  |  W  |  E  |  left  |  right  |
	+------------------------------------+
	|  A  |  S  |  D  |  ctrl  |  shift  |
	+------------------------------------+
	*/
	
	color (10);
	cout << '+';
	f_out(30,'-');
	cout << '+';
	
	cout << endl;
	
	cout << '|';
	if (check('Q')) color(1);
	cout << " Q ";
	color (10);
	cout << '|';
	
	color (10);
	if (check('W')) color(1);
	cout << " W ";
	color (10);
	cout << '|';
	
	color (10);
	if (check('E')) color(1);
	cout << " E ";
	color (10);
	cout << '|';
	
	//鼠标按键 
	color (10);
	if (KEY_DOWN(MOUSE_MOVED)) color(1);
	cout << "  left  ";
	color (10);
	cout << '|';
	
	color (10);
	if (KEY_DOWN(MOUSE_EVENT)) color(1);
	cout << "  right  ";
	color (10);
	cout << '|';
	
	cout << endl;
	
	cout << '+';
	f_out(30,'-');
	cout << '+';
	
	cout << endl;
	
	cout << '|';
	color (10);
	if (check('A')) color(1);
	cout << " A ";
	color (10);
	cout << '|';
	
	color (10);
	if (check('S')) color(1);
	cout << " S ";
	color (10);
	cout << '|';
	
	color (10);
	if (check('D')) color(1);
	cout << " D ";
	color (10);
	cout << '|';
	
	//ctrl shift
	color (10);
	if (GetKeyState(VK_CONTROL)) color(1);
	cout << "  ctrl  ";
	color (10);
	cout << '|';
	
	color (10);
	if (GetKeyState(VK_SHIFT)) color(1);
	cout << "  shift  ";
	color (10);
	cout << '|';
	
	cout << endl;
	
	cout << '+';
	f_out(30,'-');
	cout << '+';
}

int main()
{
	POINT p;
	HANDLE hOutput;
    COORD coord={0,0};
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    
    //置顶
	HWND hWnd=GetForegroundWindow(); 
    
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	
	system("color fA");
	system("title checker");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//得到窗口句柄
	SMALL_RECT rc = {0,0,32,4}; //{Y坐标,X坐标,宽,高}
	SetConsoleWindowInfo(hOut,true ,&rc);// 重置窗口位置和大小
	
	while (1)
	{	
		Sleep (10);
		home_page();
		
		TopWindow(hWnd);
    	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
		SetConsoleCursorPosition(hOutput, coord);//清屏
	}
}
