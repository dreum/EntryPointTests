///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////
#ifndef SERVICECLASS_H
#define SERVICECLASS_H

#include "ServiceClassInterface.h"

class HelperClassAInterface;

class ServiceClass : public ServiceClassInterface
{
public:
   ServiceClass(HelperClassAInterface& helperA);
   virtual ~ServiceClass();

private:
   HelperClassAInterface& HelperA;
   // Not Implemented
   ServiceClass(const ServiceClass& rhs);
   ServiceClass& operator=(const ServiceClass& rhs);
};

#endif // SERVICECLASS_H
///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

