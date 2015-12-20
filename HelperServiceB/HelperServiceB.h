///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////
#ifndef HELPERSERVICEB_H
#define HELPERSERVICEB_H

#include "HelperServiceB/HelperServiceBInterface.h"

class HelperServiceB : public HelperServiceBInterface
{
public:
   HelperServiceB();
   virtual ~HelperServiceB();

private:
   // Not Implemented
   HelperServiceB(const HelperServiceB& rhs);
   HelperServiceB& operator=(const HelperServiceB& rhs);
};

#endif // HELPERSERVICEB_H
///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

