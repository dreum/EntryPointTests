///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "FactoryMethods.h"

extern "C"
{
   ServiceClassInterface* ServiceClassEntryPointWithFactoryMethod(int argc, char** argv)
   {
      return FactoryMethods::GetServiceInstance();
   }

   void ServiceClassExitPointWithFactoryMethod(ServiceClassInterface* /*serviceClass*/)
   {
      FactoryMethods::DestroyServiceInstance();
   }

   ServiceClassInterface* GetServiceInstanceWithFactoryMethod()
   {
      return FactoryMethods::GetServiceInstance();
   }
}
///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

