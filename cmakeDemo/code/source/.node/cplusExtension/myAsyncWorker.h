#ifndef __MY_ASYNC_WORKER_H_
#define __MY_ASYNC_WORKER_H_

#include <napi.h>
#include <chrono>
#include <thread>

class MyAsyncWorker : public Napi::AsyncWorker {

public:
	static MyAsyncWorker* getInstance(Napi::Function& callback, int runTime)
	{
		static MyAsyncWorker* instance = new MyAsyncWorker(callback, runTime);
		return instance;
	}

public:

	MyAsyncWorker(Napi::Function& callback, int runTime);
	virtual ~MyAsyncWorker() {};

	void Execute();
	void OnOK();

private:
	int runTime;
};

#endif
