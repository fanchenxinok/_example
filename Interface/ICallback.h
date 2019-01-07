#ifndef ICALLBACK_H
#define ICALLBACK_H

#include <binder/IInterface.h>

namespace android 
{ 
	class ICallback : public IInterface
	{ 
		public: 
			//TODO: declare two interfaces: asInterface() and getInterfaceDescriptor()
			DECLARE_META_INTERFACE(Callback);
			//TODO: define what you want to do
			virtual int notifyCallback(int a) = 0;
	}; 
	
	class BnCallback : public BnInterface<ICallback>
	{ 
		public:
			virtual status_t onTransact( uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
	};
} 

#endif

