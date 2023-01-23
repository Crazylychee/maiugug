# include<stdio.h>
#include<windows.h>
int main()
{
	HWND  hwnd = FindWindow(0, "");
	for (int i = 0; i < 200; i++){
		SendMessage(hwnd, WM_PASTE, 0, 0);
		SendMessage(hwnd, WM_KEYDOWN,VK_RETURN,0);

	}

	return 0;
}