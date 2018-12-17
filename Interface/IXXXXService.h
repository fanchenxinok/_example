#ifndef IXXXXService_H
#define IXXXXService_H

#include <binder/IInterface.h>

namespace android 
{ 
	class IXXXXService : public IInterface
	{ 
		public: 
			//TODO: declare two interfaces: asInterface() and getInterfaceDescriptor()
			DECLARE_META_INTERFACE(XXXXService);
			//TODO: define what you want to do
			virtual int setSomething(int a) = 0;
			virtual int getSomething() = 0;
	}; 
	
	class BnXXXXService : public BnInterface<IXXXXService>
	{ 
		public:
			virtual status_t onTransact( uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
	};
} 

#endif

