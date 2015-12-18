///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "FactoryMethods.h"
#include "ServiceClass.h"
#include "HelperClassA.h"
#include "HelperServiceB.h"
#include <cstddef>

namespace
{
   ServiceClassInterface* globalServiceClass;
   HelperServiceBInterface* globalHelperServiceB;
}


ServiceClassInterface* FactoryMethods::GetServiceInstance()
{
   if (NULL == globalServiceClass)
   {
      globalHelperServiceB = new HelperServiceB();
      globalServiceClass = new ServiceClass(new HelperClassA(), *globalHelperServiceB);
   }
   return globalServiceClass;
}

// C++11 so much easier
//static ServiceClassInterface* FactoryMethods::GetServiceInstance()
//{
//   static ServiceClass instance;
//   return &instance;
//}

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

