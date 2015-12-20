///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceLib/ServiceFactory.h"
#include "HelperServiceBMock.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;

///////////////////////////////////////////////////////////////////////////////
TEST(ServiceFactoryTest, CanGetServiceInstance)
{
   HelperServiceBInterface* helperServiceB(new HelperServiceBMock());
   ServiceFactory factory(*helperServiceB);
   ServiceClassInterface* instance = factory.GetServiceInstance();
   ServiceClassInterface* instance2 = factory.GetServiceInstance();
   EXPECT_THAT(instance, NotNull());
   EXPECT_THAT(instance, Eq(instance2));

   delete helperServiceB;
}

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

