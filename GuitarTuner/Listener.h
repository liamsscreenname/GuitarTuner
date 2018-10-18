#pragma once

#include <mmsystem.h>
#include "Constants.h"
#include "ListenerSetup.h"

class Listener {
private:
	short int waveIn [Constants::sampleLength * Constants::sampleRate];

	 HWAVEIN audioDevice;
	 WAVEHDR WaveInHdr;
	 MMRESULT result;
	 WAVEFORMATEX format;

	 ListenerSetup &setup;

public:
	Listener(ListenerSetup&);

	const MMRESULT GetResult() { return result; }

	void Listen();
	static void ListenCallback();
};
