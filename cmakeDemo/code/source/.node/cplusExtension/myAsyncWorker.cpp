#include "myAsyncWorker.h"

#include <chrono>
#include <thread>



MyAsyncWorker::MyAsyncWorker(Napi::Function& callback, int runTime)
	: AsyncWorker(callback), runTime(runTime) {};

void MyAsyncWorker::Execute() {
	std::this_thread::sleep_for(std::chrono::seconds(runTime));
	if (runTime == 4) SetError("asyncCall : Oops! Failed after 'working' 4 seconds.");
}

void MyAsyncWorker::OnOK() {

	std::string msg = "asyncCall : MyAsyncWorker returning after 'working' " +
		std::to_string(runTime) + " seconds.";
	Callback().Call({ Env().Null(), Napi::String::New(Env(), msg) });
}

