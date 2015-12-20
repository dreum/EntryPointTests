///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceFactory.h"
#include <cstddef>

namespace
{
   ServiceFactory* factory;
}

extern "C"
{
   HelperServiceBInterface* HelperServiceBEntryPoint(int, char**); // these would be replaced with a return feature
   HelperServiceBInterface* GetHelperServiceB();
   void HelperServiceBExitPoint(HelperServiceBInterface*);

   ServiceClassInterface* ServiceClassEntryPointWithFactoryClass(int argc, char** argv)
   {
      HelperServiceBEntryPoint(0, NULL); // not needed with a dependency manager
      factory = new ServiceFactory(*GetHelperServiceB());
      return factory->GetServiceInstance();
   }

   void ServiceClassExitPointWithFactoryClass(ServiceClassInterface* /*serviceClass*/)
   {
      delete factory;
      HelperServiceBExitPoint(NULL); // not needed with a dependency manager
   }

   ServiceClassInterface* GetServiceInstanceWithFactoryClass()
   {
      return factory->GetServiceInstance();
   }
}

// Pros: very clean (at least with a dependency manager)

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

