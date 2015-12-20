///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "FactoryMethods.h"
#include "ServiceClass.h"
#include "HelperClassA.h"
#include <HelperServiceB/HelperServiceBInterface.h>
#include <cstddef>

namespace
{
   ServiceClassInterface* globalServiceClass = NULL; //<-- requires global variable
}

ServiceClassInterface*FactoryMethods::CreateServiceInstance(HelperServiceBInterface& helperServiceB)
{
   if (NULL == globalServiceClass)
   {
      globalServiceClass = new ServiceClass(new HelperClassA(), helperServiceB);
   }
   return globalServiceClass;
}

// C++11 so much easier
//static ServiceClassInterface* FactoryMethods::GetServiceInstance()
//{
//   static ServiceClass instance;
//   return &instance;
//}

ServiceClassInterface* FactoryMethods::GetServiceInstance()
{
   return globalServiceClass;
}

void FactoryMethods::DestroyServiceInstance()
{
   delete globalServiceClass; //NOT THREAD SAFE!!
   globalServiceClass = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

