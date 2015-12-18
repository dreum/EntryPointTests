///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "FactoryMethods.h"
#include "ServiceClass.h"
#include "HelperClassA.h"
#include <cstddef>

namespace
{
   ServiceClassInterface* globalServiceInstance;
   HelperClassAInterface* globalHelperA;
}

ServiceClassInterface* FactoryMethods::GetServiceInstance()
{
   if (NULL == globalServiceInstance) //NOT THREAD SAFE!!
   {
      globalServiceInstance = new ServiceClass(new HelperClassA());
   }
   return globalServiceInstance;
}

// C++11 so much easier
//static ServiceClassInterface* FactoryMethods::GetServiceInstance()
//{
//   static ServiceClass instance;
//   return &instance;
//}

void FactoryMethods::DestroyServiceInstance()
{
   delete globalServiceInstance; //NOT THREAD SAFE!!
   globalServiceInstance = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

