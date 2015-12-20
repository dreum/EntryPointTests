///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////
#ifndef HELPERSERVICEB_MOCK_H
#define HELPERSERVICEB_MOCK_H

#include <gmock/gmock.h>
#include "HelperServiceB/HelperServiceBInterface.h"

class HelperServiceBMock : public HelperServiceBInterface
{
public:
   HelperServiceBMock();
   virtual ~HelperServiceBMock();

   // Example Mock method:
   //MOCK_METHOD2(Bar, void(int, bool));
};

#endif // HELPERSERVICEB_MOCK_H
///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

