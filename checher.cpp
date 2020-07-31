#include <iostream>
#include <windows.h>
using namespace std;

//��갴���ж� 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
// ��  ��KEY_DOWN(MOUSE_MOVED)
// ��  ��KEY_DOWN(MOUSE_EVENT)
//���� ��KEY_DOWN(MOUSE_WHEELED)

//�ö��˴��� 
void TopWindow(HWND &hWnd)
{
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

bool check(char c)
{//���ĳ�������Ƿ���
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
	1	����ɫ
	2	����ɫ
	3	����ɫ 
	4	���ɫ
	5	���ɫ
	6	��ɫ
	7	���ɫ
	8	��ɫ
	9	ǳ��ɫ
	10	ǳ��ɫ 
	11	ǳ��ɫ 
	12	ǳ��ɫ 
	13	ǳ��ɫ 
	14	ǳ��ɫ 
	15	ǳ��ɫ 
	
	����
	1~15		��ɫ 
	16~31		����ɫ 
	32~47		����ɫ
	48~63		����ɫ
	64~79		���ɫ
	80~95		���ɫ
	96~111		���ɫ
	112~127 	���ɫ
	128~143 	��ɫ
	144~159 	ǳ��ɫ
	160~175 	ǳ��ɫ
	176~191 	ǳ��ɫ 
	192~207 	ǳ��ɫ
	208~223 	ǳ��ɫ
	224~239 	ǳ��ɫ
	240~255 	ǳ��ɫ
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
	
	//��갴�� 
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
    
    //�ö�
	HWND hWnd=GetForegroundWindow(); 
    
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	
	system("color fA");
	system("title checker");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//�õ����ھ��
	SMALL_RECT rc = {0,0,32,4}; //{Y����,X����,��,��}
	SetConsoleWindowInfo(hOut,true ,&rc);// ���ô���λ�úʹ�С
	
	while (1)
	{	
		Sleep (10);
		home_page();
		
		TopWindow(hWnd);
    	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
		SetConsoleCursorPosition(hOutput, coord);//����
	}
}
