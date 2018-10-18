#include "stdafx.h"
#include "ListenerSetup.h"
#include "Constants.h"

ListenerSetup::ListenerSetup()
{
	SetupFormat();
}

void ListenerSetup::SetupFormat()
{
	WAVEFORMATEX format;
	format.wFormatTag = WAVE_FORMAT_PCM;
	format.nChannels = Constants::numChannels;
	format.nSamplesPerSec = Constants::sampleRate;
	format.nAvgBytesPerSec = Constants::sampleRate * Constants::numChannels * Constants::bitDepth / 8;
	format.nBlockAlign = Constants::numChannels * Constants::bitDepth / 8;
	format.wBitsPerSample = Constants::bitDepth;
	format.cbSize = 0;
	this->format = format;
}

WAVEHDR *ListenerSetup::SetupHeader(const LPSTR buffer)
{
	WAVEHDR header;
	header.lpData = buffer;
	header.dwBufferLength = Constants::sampleRate * Constants::sampleLength * 2;
	header.dwBytesRecorded = 0;
	header.dwUser = 0L;
	header.dwFlags = 0L;
	header.dwLoops = 0;
	return &header;
}

const WAVEFORMATEX *ListenerSetup::GetFormat()
{
	return &format;
}
