///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceClass.h"
#include "ServiceClassInterface.h"
#include <cstddef>

namespace
{
   ServiceClassInterface* globalServiceClass;
}

extern "C" ServiceClassInterface* ServiceClassEntryPoint(int argc, char** argv)
{
   return globalServiceClass = new ServiceClass();
}

extern "C" void ServiceClassExitPoint(ServiceClassInterface* /*serviceClass*/)
{
   delete globalServiceClass;
   globalServiceClass = NULL;
}

extern "C" ServiceClassInterface* GetServiceInstance()
{
   return globalServiceClass;
}

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

