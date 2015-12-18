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
   ServiceClassInterface* globalServiceClass;
}

extern "C"
{
   ServiceClassInterface* ServiceClassEntryPoint(int argc, char** argv)
   {
      return globalServiceClass = new ServiceClass(new HelperClassA());
   }

   void ServiceClassExitPoint(ServiceClassInterface* /*serviceClass*/)
   {
      delete globalServiceClass;
      globalServiceClass = NULL;
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

