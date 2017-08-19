#pragma once
#include <Windows.h>
#include <thread>

typedef struct
{
	void* pvSrc;
	void* pvDst;
	DWORD64 size;
}DATA, *PDATA;

class FastCopy
{
public:
	inline static void* memCpy(void* pvSrc, void* const pvDst, DWORD64 size)
	{
		register PBYTE pSrc = (PBYTE)pvSrc, pDst = (PBYTE)pvDst;
		if (size & 1)
		{
			pDst[0] = pSrc[0];
			pDst += 1;
			pSrc += 1;
		}
		size /= 2;
		while (size--)
		{
			pDst[0] = pSrc[0];
			pDst[1] = pSrc[1];

			pDst += 2;
			pSrc += 2;
		}

		return pvDst;
	}
	
	inline static void* threadMemCpy(void* pvSrc, void* const pvDst, DWORD64 size,size_t thread_count = 5)
	{
		register PBYTE pSrc = (PBYTE)pvSrc, pDst = (PBYTE)pvDst;
		DWORD64 gap = size / thread_count;
//----------------------------------------------------------------------------------
		DWORD *dwThreadIdArray;
		HANDLE *hThread;
		DATA *dArg;
		dwThreadIdArray = new DWORD[thread_count];
		hThread = new HANDLE[thread_count];
		dArg = new DATA[thread_count];
//----------------------------------------------------------------------------------
		for (size_t i = 0; i < thread_count; i++)
		{
			dArg[i].pvDst = pDst + i*gap;
			dArg[i].pvSrc = pSrc + i*gap;
			dArg[i].size = gap + ((!i) ? 0 : size%thread_count);
			hThread[i] = CreateThread(NULL, 0, ((LPTHREAD_START_ROUTINE)&FastCopy::copy), &dArg[i], 0, &dwThreadIdArray[i]);
		}
		WaitForMultipleObjects(thread_count, hThread, true, INFINITE);
		for (size_t i = 0; i < thread_count; i++)
		{
			CloseHandle(hThread[i]);
		}
		delete[] hThread;
		delete[] dwThreadIdArray;
		delete[] dArg;
		return pvDst;
	}
protected:
#define p ((PDATA)arg)
	inline static DWORD WINAPI copy(void* arg)
	{
		do
		{
			memcpy(p->pvDst, p->pvSrc, (size_t)p->size);
		} while (memcmp(p->pvDst, p->pvSrc, (size_t)p->size));
		return 0;
	}
#undef p
};

