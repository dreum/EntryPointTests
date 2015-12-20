///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "FactoryMethods.h"
#include <cstddef>

extern "C"
{
   HelperServiceBInterface* HelperServiceBEntryPoint(int, char**); // these would be replaced with a return feature
   HelperServiceBInterface* GetHelperServiceB();
   void HelperServiceBExitPoint(HelperServiceBInterface*);

   ServiceClassInterface* ServiceClassEntryPointWithFactoryMethod(int argc, char** argv)
   {
      HelperServiceBEntryPoint(0, NULL); // not needed with a dependency manager
      return FactoryMethods::CreateServiceInstance(*GetHelperServiceB()); // return feature
   }

   void ServiceClassExitPointWithFactoryMethod(ServiceClassInterface* /*serviceClass*/)
   {
      FactoryMethods::DestroyServiceInstance();
      HelperServiceBExitPoint(NULL); // not needed with a dependency manager
   }

   ServiceClassInterface* GetServiceInstanceWithFactoryMethod()
   {
      return FactoryMethods::GetServiceInstance();
   }
}

// Pros: very clean (at least with a dependency manager)

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

