///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceClass.h"
#include "HelperClassA.h"
#include "HelperServiceB.h"
#include <cstddef>

namespace
{
   ServiceClassInterface* globalServiceClass;
   HelperServiceBInterface* globalHelperServiceB;
}

extern "C"
{
   ServiceClassInterface* ServiceClassEntryPoint(int argc, char** argv)
   {
      globalHelperServiceB = new HelperServiceB();
      return globalServiceClass = new ServiceClass(new HelperClassA(), *globalHelperServiceB);
   }

   void ServiceClassExitPoint(ServiceClassInterface* /*serviceClass*/)
   {
      delete globalServiceClass;
      globalServiceClass = NULL;

      delete globalHelperServiceB;
      globalHelperServiceB = NULL;
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

