#include "stdafx.h"
#include "Listener.h"

Listener::Listener(ListenerSetup &s) : setup(s){}

void Listener::Listen()
{
	if (waveInGetNumDevs > 0) {
		result = waveInOpen(&audioDevice, WAVE_MAPPER, setup.GetFormat(), (DWORD_PTR)&ListenCallback, 0L, CALLBACK_FUNCTION);
		waveInPrepareHeader(audioDevice, setup.SetupHeader((LPSTR)waveIn), sizeof(WAVEHDR));
		result = waveInAddBuffer(audioDevice, setup.SetupHeader((LPSTR)waveIn), sizeof(WAVEHDR));
		result = waveInStart(audioDevice);
		do {} while (waveInUnprepareHeader(audioDevice, setup.SetupHeader((LPSTR)waveIn), sizeof(WAVEHDR)) == WAVERR_STILLPLAYING);
		waveInStop(audioDevice);
	}
	else {
		OutputDebugStringA("No audio devices found!");
	}
}

void Listener::ListenCallback()
{
}

