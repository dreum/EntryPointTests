///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceFactory.h"
#include "ServiceClass.h"
#include "HelperClassA.h"
#include <cstddef>

///////////////////////////////////////////////////////////////////////////////
ServiceFactory::ServiceFactory(HelperServiceBInterface& helperServiceB)
   : Service(new ServiceClass(new HelperClassA(), helperServiceB))
{
   // for full encapsulation make ServiceFactory a friend class inside the service class
   // then make the ServiceClass constructor private
}

///////////////////////////////////////////////////////////////////////////////
ServiceFactory::~ServiceFactory()
{
   delete Service;
   Service = NULL;
}

ServiceClassInterface* ServiceFactory::GetServiceInstance()
{
   return Service;
}

// Pros: Differentiate between instantiation and getting

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

