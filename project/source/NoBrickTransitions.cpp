
#include <Windows.h>
#include <Psapi.h>

#include "RedoBlHooks.hpp"

bool init ()
{
	BlInit;

	ADDR BlScanHex (addr_fxDTSBrick__prepRenderImage, "55 8B EC 83 E4 F8 81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 53 56 8B 35 ? ? ? ?");
	BlPatchBytes (6, addr_fxDTSBrick__prepRenderImage + 1939, "\xE9\x7D\x00\x00\x00\x90");

	BlPrintf ("NoBrickTransitions: Successfully disabled brick transitions.");

	return true;
}

int __stdcall DllMain (HINSTANCE hInstance, unsigned long reason, void* reserved)
{
	switch ( reason )
	{
		case DLL_PROCESS_ATTACH:
			return init ();

		case DLL_PROCESS_DETACH:
			return true;

		default:
			return true;
	}
}
