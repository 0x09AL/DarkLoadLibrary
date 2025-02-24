#include <windows.h>

#include "pebutils.h"
#include "darkloadlibrary.h"

#define RVA(type, base_addr, rva) (type)((ULONG_PTR) base_addr + rva)

#define FILL_STRING(string, buffer) \
	string.Length = (USHORT)strlen(buffer); \
	string.MaximumLength = string.Length; \
	string.Buffer = buffer

typedef BOOL(WINAPI * DLLMAIN)(HINSTANCE, DWORD, LPVOID);
typedef NTSTATUS(WINAPI *LDRGETPROCADDRESS)(HMODULE, PANSI_STRING, WORD, PVOID*);

BOOL IsValidPE(PBYTE pbData);
BOOL MapSections(PDARKMODULE pdModule);