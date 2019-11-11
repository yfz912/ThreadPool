//控制台应用程序的入口点。
#include "stdafx.h"
#include "ThreadPool.h"

class Task
{
public:
	static int TaskFunc(PVOID p) 
	{
		int i = 10;
		while (i > 0)
		{
			printf("%d: %d\n", (int)p, i);
			Sleep(100);
			i--;
		}
		return i;
	}
};

class TaskCallback
{
public:
	static void TaskCallbackFunc(PVOID p, int result)
	{
		printf("%d cb: %d\n", (int)p, result);
	}
};

int main()
{
	ThreadPool threadPool(2, 10);
	threadPool.QueueTaskItem(Task::TaskFunc, (PVOID)0,
		TaskCallback::TaskCallbackFunc, TRUE);	
	for (size_t i = 1; i < 30; i++)
	{
		threadPool.QueueTaskItem(Task::TaskFunc, (PVOID)i,
			TaskCallback::TaskCallbackFunc);	
	}
	int c = getchar();
    return 0;
}

