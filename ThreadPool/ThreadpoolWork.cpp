#include "stdafx.h"

void CALLBACK Func(PTP_CALLBACK_INSTANCE, void* pVoid, PTP_WORK)
{
	printf("%s\n", static_cast<const char*>(pVoid));
}

int main()
{
	const char* pStrC = "Hello World";
	PTP_WORK pWork = CreateThreadpoolWork(Func,
		const_cast<char*>(pStrC), NULL);
	assert(pWork);

	SubmitThreadpoolWork(pWork);
	SubmitThreadpoolWork(pWork);
	WaitForThreadpoolWorkCallbacks(pWork, FALSE);
	CloseThreadpoolWork(pWork);
	system("pause");
	/*
	输出:
	"Hello World"
	"Hello World"
	*/
}