#include <binder/BinderService.h>
#include "../Interface/IXXXXService.h"
#include "../Interface/ICallback.h"

namespace android
{ 
	class XXXXService : public BinderService<XXXXService>, public BnXXXXService
	{ 
		public: 
			XXXXService();
			static const char* getServiceName() { return "XXXXService"; }  //will be the service name
			virtual int setSomething(int a);
			virtual int getSomething();
			virtual int setCallback(const sp<ICallback>& cb);
		protected:
			int myParam;
			sp<ICallback> mCallback;
	}; 
	
}

