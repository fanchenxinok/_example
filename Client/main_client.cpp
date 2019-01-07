#include <stdio.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include "../Interface/IXXXXService.h"
#include "../Interface/ICallback.h"

#define LOG_NDEBUG 0 
#define LOG_TAG "chenxf: Client-main"

using namespace android;

sp<IXXXXService> mXXXXService;

class Callback: public BnCallback
{
	public:
		virtual int notifyCallback(int a);
};

int Callback::notifyCallback(int a)
{
	ALOGD(" Callback::notifyCallback() be called, a = %d", a);
	return 0;
}

void initXXXXServiceClient()
{ 
	int count = 10;
	if (mXXXXService == 0) { 
		sp<IServiceManager> sm = defaultServiceManager();
		sp<IBinder> binder;
		do {
			binder = sm->getService(String16("XXXXService"));
			if (binder != 0) break;
			ALOGW("XXXXService not published, waiting...");
			sleep(1); // 1 s 
			count++;
		} while (count < 20);

		mXXXXService = interface_cast<IXXXXService>(binder); // is equal to return IXXXXService::asInterface(binder);
	} 
} 

int main(int argc, char* argv[])
{ 
	initXXXXServiceClient();
	if(mXXXXService ==NULL) {
		ALOGW("cannot find XXXXService");
		return 0;
	} 

	sp<Callback> cb = new Callback();
	mXXXXService->setCallback(cb);

	while(1) {
		mXXXXService->setSomething(1);
		sleep(1);
		ALOGD("getSomething %d", mXXXXService->getSomething());
	}
	return 0; 
}

