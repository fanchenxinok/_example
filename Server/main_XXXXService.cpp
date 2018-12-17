#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "XXXXService.h"

#define LOG_NDEBUG (0)
#define LOG_TAG "chenxf: XXXXService-main"
#define EASY_START_BINDER_SERVICE (0)

using namespace android;

// 功能是启动XXXServer服务
int main(int argc, char** argv)
{ 
	#if EASY_START_BINDER_SERVICE
	XXXXService::publishAndJoinThreadPool();//使用了父类BinderService的函数 
	#else
	sp<ProcessState> proc(ProcessState::self()); //主要是创建ProcessState对象，并打开/dev/binder设备
	sp<IServiceManager> sm(defaultServiceManager()); // interface_cast<IServiceManager>(new BpBinder(0)) 实际返回的是BpServiceManager对象 它的remote对象是BpBinder.
	sm->addService(String16(XXXXService::getServiceName()), new XXXXService()); //将 XXXXService添加到ServiceManager列表中
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool(); //启动 XXXXService的服务 执行executeCommand()->BnXXXXService::onTransact()
	#endif
	return 0;
}

