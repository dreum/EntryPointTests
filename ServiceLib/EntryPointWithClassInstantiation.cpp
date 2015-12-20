///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceClass.h"
#include "HelperClassA.h"
#include <cstddef>

namespace
{
   ServiceClassInterface* globalServiceClass = NULL; // not needed with a dependency manager
}

extern "C"
{
   HelperServiceBInterface* HelperServiceBEntryPoint(int, char**); // these would be replaced with a return feature
   HelperServiceBInterface* GetHelperServiceB();
   void HelperServiceBExitPoint(HelperServiceBInterface*);

   ServiceClassInterface* ServiceClassEntryPoint(int argc, char** argv)
   {
      HelperServiceBEntryPoint(0, NULL); // not needed with a dependency manager
      return globalServiceClass = new ServiceClass(new HelperClassA(), *GetHelperServiceB());
   }

   void ServiceClassExitPoint(ServiceClassInterface* /*serviceClass*/)
   {
      delete globalServiceClass;
      globalServiceClass = NULL;

      HelperServiceBExitPoint(NULL); // not needed with a dependency manager
   }

   ServiceClassInterface* GetServiceInstance()
   {
      return globalServiceClass;
   }
}
///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

