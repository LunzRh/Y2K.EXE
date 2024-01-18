/*
 * This is very useful!
*/

#include <windows.h>

namespace Functions {
	void createAndSetRegKey(HKEY key, LPCSTR subKey, LPCSTR valueName, DWORD type, const BYTE* data, DWORD size){
		HKEY hKey = nullptr;
		if (RegCreateKeyExA(key, subKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS){
			RegSetValueExA(hKey, valueName, 0, type, data, size);
			RegCloseKey(hKey);
		}
	}
	
	void setRegKey(HKEY key, LPCSTR subKey, LPCSTR valueName, DWORD type, const BYTE* data, DWORD size){
		HKEY hKey = nullptr;
		if (RegOpenKeyExA(key, subKey, 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS){
			RegSetValueExA(hKey, valueName, 0, type, data, size);
			RegCloseKey(hKey);
		}
	}
}