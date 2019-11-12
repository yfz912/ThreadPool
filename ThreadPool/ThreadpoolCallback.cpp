#include "stdafx.h"

void CALLBACK Func(PTP_CALLBACK_INSTANCE, void* pVoid)
{
    printf("%s\n", static_cast<const char*>(pVoid));
}

int main()
{
    const char* pStrC = "Hello World";
    BOOL bRe = TrySubmitThreadpoolCallback(Func,
		const_cast<char*>(pStrC), NULL);
	assert(bRe);
    system("pause");
    return 0;
    //程序输出"Hello World"
}