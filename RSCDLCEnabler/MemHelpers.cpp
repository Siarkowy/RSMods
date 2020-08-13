#include "MemHelpers.h"
#pragma warning(disable: 4805) // Mix of byte & bool

cMemHelpers MemHelpers;

byte cMemHelpers::getLowestStringTuning() {
	uintptr_t addrTuning = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_tuning, Offsets.ptr_tuningOffsets);

	if (!addrTuning)
		return NULL;

	return *(BYTE*)addrTuning;
}

float cMemHelpers::GetCurrentMusicVolume() { // Alternative to GetRTPCValue
	uintptr_t volumeAddr = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_volume, Offsets.ptr_volumeOffsets);

	if (!volumeAddr)
		return false;

	return *(float*)volumeAddr;
}

bool cMemHelpers::IsExtendedRangeSong() {
	uintptr_t addrTimer = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_timer, Offsets.ptr_timerOffsets);

	if (!addrTimer)
		return false;

	byte currentTuning = cMemHelpers::getLowestStringTuning();

	if (currentTuning != 0 && currentTuning <= (256 + Settings.GetModSetting("ExtendedRangeMode")))
		return true;
	return false;
}

std::string cMemHelpers::GetCurrentMenu(bool GameNotLoaded) {
	uintptr_t currentMenuAdr = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_currentMenu, Offsets.ptr_currentMenuOffsets, GameNotLoaded); // If game hasn't loaded, take the safer, but possibly slower route

	if (currentMenuAdr > 0x30000000) // Ghetto checks for life, if you haven't eneterd the game it usually points to 0x6XXXXXXX and if you try to dereference that, you get yourself a nice crash
		return "pre_enter_prompt";

	if (!currentMenuAdr)
		return "where are we actually";

	std::string currentMenu((char*)currentMenuAdr);

	return currentMenu;
}

void cMemHelpers::ToggleLoft() {
	
	// Old Method (Works for most builds but bugged out for some)
	//uintptr_t nearAddr = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_loft, Offsets.ptr_loft_nearOffsets);
	//if (*(float*)nearAddr == 10)
	//	*(float*)nearAddr = 10000;
	//else
	//	*(float*)nearAddr = 10;

	uintptr_t farAddr = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_loft, Offsets.ptr_loft_farOffsets);

	if (*(float*)farAddr == 10000)
		*(float*)farAddr = 1;
	else
		*(float*)farAddr = 10000;
}

void cMemHelpers::ShowSongTimer() {
	uintptr_t addrTimer = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_timer, Offsets.ptr_timerOffsets);

	if (!addrTimer)
		return;

	std::string valStr = std::to_string(*(float*)addrTimer);
	std::cout << "Current song time: " << valStr << std::endl;
}


void cMemHelpers::ShowCurrentTuning() {
	byte lowestStringTuning = cMemHelpers::getLowestStringTuning();
	if (lowestStringTuning == NULL)
		return;

	std::string valStr = std::to_string(lowestStringTuning);
	std::cout << valStr << std::endl;
}

void cMemHelpers::ToggleCB(bool enabled) {
	uintptr_t addrTimer = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_timer, Offsets.ptr_timerOffsets);
	uintptr_t cbEnabled = MemUtil.FindDMAAddy(Offsets.baseHandle + Offsets.ptr_colorBlindMode, Offsets.ptr_colorBlindModeOffsets);

	if (!addrTimer)
		return;

	if (*(byte*)cbEnabled != enabled) //JIC, no need to write the same value constantly
		*(byte*)cbEnabled = enabled;
}

void cMemHelpers::PatchCDLCCheck() {
	uint8_t* VerifySignatureOffset = Offsets.cdlcCheckAdr;

	if (VerifySignatureOffset) {
		if (!MemUtil.PatchAdr(VerifySignatureOffset + 8, (UINT*)Offsets.patch_CDLCCheck, 2))
			printf("Failed to patch verify_signature!\n");
		else
			printf("Patch verify_signature success!\n");
	}
}