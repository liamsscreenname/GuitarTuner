#pragma once

#include <mmsystem.h>

static class ListenerSetup {
private:
	static WAVEFORMATEX format;

public:
	ListenerSetup();

	void SetupFormat();
	const WAVEFORMATEX *GetFormat();
	WAVEHDR *SetupHeader(const LPSTR);
};
