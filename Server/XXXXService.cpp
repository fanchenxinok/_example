#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <binder/Parcel.h>
#include <binder/IPCThreadState.h>
#include <utils/threads.h>
#include <cutils/properties.h>

#include "XXXXService.h"

#define LOG_NDEBUG (0)
#define LOG_TAG "chenxf: XXXXService"

namespace android
{ 
	XXXXService::XXXXService() { myParam = 0; }

	int XXXXService::setSomething(int a) {
		ALOGD(" XXXXService::setSomething a = %d myParam %d", a, myParam);
		myParam += a;
		return 0;//OK
	} 

	int XXXXService::getSomething() { 
		ALOGD("#XXXXService::getSomething myParam = %d", myParam); 
		return myParam; 
	} 
}

