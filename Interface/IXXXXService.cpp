#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <utils/Log.h>

#include "IXXXXService.h"

#define LOG_NDEBUG 0
#define LOG_TAG "chenxf: IXXXXService"

namespace android
{ 
	enum {
		SET_SOMETHING = IBinder::FIRST_CALL_TRANSACTION,
		GET_SOMETHING,
		SET_CALLBACK,
	};
		
	//------------------------------------proxy side-------------------------------- 
	class BpXXXXService : public BpInterface<IXXXXService>
	{ 
		public: 
			BpXXXXService(const sp<IBinder>& impl) : BpInterface<IXXXXService>(impl) { } 
			virtual int setSomething(int a)
			{ 
				ALOGD(" BpXXXXService::setSomething a = %d ", a);
				Parcel data, reply;
				data.writeInt32(a);
				remote()->transact(SET_SOMETHING, data, &reply);
				return reply.readInt32();
			} 

			virtual int getSomething()
			{ 
				ALOGD(" BpXXXXService::getSomething ");
				Parcel data, reply;
				data.writeInterfaceToken(IXXXXService::getInterfaceDescriptor());
				remote()->transact(GET_SOMETHING, data, &reply);
				return reply.readInt32();
			} 

			virtual int setCallback(const sp<ICallback>& cb)
			{ 
				ALOGD(" BpXXXXService::setCallback");
				Parcel data, reply;
				data.writeStrongBinder(IInterface::asBinder(cb));
				remote()->transact(SET_CALLBACK, data, &reply);
				return reply.readInt32();
			} 
	}; 

	//---------------------- interface-------------------- 
	// TODO: implement two interface: getInterfaceDescriptor() and asInterface(const android::sp<android::IBinder>& obj)
	// TODO: asInterface() mainly create a BpXXXXService(obj)
	IMPLEMENT_META_INTERFACE(XXXXService, "chenxf.binder.IXXXXService");

	//------------------------------------server side--------------------------------
	status_t BnXXXXService::onTransact ( uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
	{
		switch (code) 
		{ 
			case SET_SOMETHING:
			{ 
				ALOGD("BnXXXXService::onTransact  SET_SOMETHING ");
				reply->writeInt32(setSomething((int)data.readInt32()));
				return NO_ERROR;
			} break; 
			case GET_SOMETHING:
			{ 
				ALOGD("BnXXXXService::onTransact  GET_SOMETHING ");
				reply->writeInt32(getSomething());
				return NO_ERROR;
			} break;
			case SET_CALLBACK:
			{ 
				ALOGD("BnXXXXService::onTransact  SET_CALLBACK ");
				sp<ICallback> cb = interface_cast<ICallback>(data.readStrongBinder());
				reply->writeInt32(setCallback(cb));
				return NO_ERROR;
			} break; 
		} 
		return BBinder::onTransact(code, data, reply, flags);
	} 
	
}// end android namespace
