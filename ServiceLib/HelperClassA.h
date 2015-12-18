///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////
#ifndef HELPERCLASSA_H
#define HELPERCLASSA_H

#include "ServiceLib/HelperClassAInterface.h"

class HelperClassA : public HelperClassAInterface
{
public:
   HelperClassA();
   virtual ~HelperClassA();

private:
   // Not Implemented
   HelperClassA(const HelperClassA& rhs);
   HelperClassA& operator=(const HelperClassA& rhs);
};

#endif // HELPERCLASSA_H
///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

