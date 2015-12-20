///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "HelperServiceB.h"
#include <cstddef>

namespace
{
   HelperServiceBInterface* globalHelperServiceB = NULL;
}

extern "C"
{
   HelperServiceBInterface* HelperServiceBEntryPoint(int argc, char** argv)
   {
      globalHelperServiceB = new HelperServiceB();
      return globalHelperServiceB;
   }

   void HelperServiceBExitPoint(HelperServiceBInterface* service)
   {
      delete globalHelperServiceB;
      globalHelperServiceB = NULL;
   }

   HelperServiceBInterface* GetHelperServiceB()
   {
      return globalHelperServiceB;
   }
}

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

