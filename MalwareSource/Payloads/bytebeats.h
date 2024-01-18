/*
 * Every bytebeat is here!
*/

#include <windows.h>
#include <math.h>

namespace Bytebeat {
	
	// Setup
	char buffer[8000 * 20];
	DWORD buff_size = sizeof(buffer);
	DWORD waveHdr_size = sizeof(WAVEHDR);
	
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = {WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0};

	// Plays bytebeat
	void run(){
		waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
		
		WAVEHDR hdr = {buffer, buff_size, 0, 0, 0, 0, 0, 0};
		waveOutPrepareHeader(hwo, &hdr, waveHdr_size);
		waveOutWrite(hwo, &hdr, waveHdr_size);
		waveOutUnprepareHeader(hwo, &hdr, waveHdr_size);
		waveOutClose(hwo);
		
		Sleep(20000);
	}
	
	/* 
		Bytebeats 
	*/
	void beat1(){
		
		for (DWORD t = 0; t < buff_size; t++)
			buffer[t] = static_cast<char>(tan((t % 120) | (t * 10)));
	
		run();
		
	}
	
	void beat2(){
		
		for (DWORD t = 0; t < buff_size; t++)
			buffer[t] = static_cast<char>((t % 255 & t) << 2 & t);
		
		run();
		
	}
	
	void beat3(){
		
		for (DWORD t = 0; t < buff_size; t++)
			buffer[t] = static_cast<char>((t / 100) * t);
		
		run();
		
	}
	
	void beat4(){
		
		for (DWORD t = 0; t < buff_size; t++)
			buffer[t] = static_cast<char>(t >> t / 4);
		
		run();
		
	}
	
	void beat5(){
		
		for (DWORD t = 0; t < buff_size; t++)
			buffer[t] = static_cast<char>((t >> 1 + t % 5) ^ (t << 3));
		
		run();
		
	}
	
	void beat6(){
		
		for (DWORD t = 0; t < buff_size; t++)
			buffer[t] = static_cast<char>((t * 2) * sin(t));
		
		run();
		
	}
	
	void beat7(){
		
		for (DWORD t = 0; t < buff_size; t++)
			buffer[t] = static_cast<char>((t / 1000) * t);
		
		run();
		
	}
	
	void beat8(){
		
		for (DWORD t = 0; t < buff_size; t++)
			buffer[t] = static_cast<char>((t / 10) * t);
		
		run();
		
	}
}