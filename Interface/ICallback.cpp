#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <utils/Log.h>

#include "ICallback.h"

#define LOG_NDEBUG 0
#define LOG_TAG "chenxf: ICallback"

namespace android
{ 
	enum {
		NOTIFY_CALLBACK,
	};
		
	//------------------------------------proxy side-------------------------------- 
	class BpCallback : public BpInterface<ICallback>
	{ 
		public: 
			BpCallback(const sp<IBinder>& impl) : BpInterface<ICallback>(impl) { } 
			virtual int notifyCallback(int a)
			{ 
				ALOGD(" BpCallback::notifyCallback, a = %d ", a);
				Parcel data, reply;
				data.writeInt32(a);
				remote()->transact(NOTIFY_CALLBACK, data, &reply);
				return reply.readInt32();
			} 
	}; 

	//---------------------- interface-------------------- 
	// TODO: implement two interface: getInterfaceDescriptor() and asInterface(const android::sp<android::IBinder>& obj)
	// TODO: asInterface() mainly create a BpXXXXService(obj)
	IMPLEMENT_META_INTERFACE(Callback, "chenxf.binder.ICallback");

	//------------------------------------server side--------------------------------
	status_t BnCallback::onTransact ( uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
	{
		switch (code) 
		{ 
			case NOTIFY_CALLBACK:
			{ 
				ALOGD("BnCallback::onTransact  --> NOTIFY_CALLBACK ");
				reply->writeInt32(notifyCallback((int)data.readInt32()));
				return NO_ERROR;
			} break; 
		} 
		return BBinder::onTransact(code, data, reply, flags);
	} 
	
}// end android namespace
