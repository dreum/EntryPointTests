///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceLib/FactoryMethods.h"
#include "HelperServiceBMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

///////////////////////////////////////////////////////////////////////////////
TEST(FactoryMethodsTest, CanGetServiceInstance)
{
   HelperServiceBInterface* helperServiceB(new HelperServiceBMock());
   ServiceClassInterface* instance = FactoryMethods::CreateServiceInstance(*helperServiceB);
   ServiceClassInterface* instance2 = FactoryMethods::GetServiceInstance();
   EXPECT_THAT(instance, NotNull());
   EXPECT_THAT(instance, Eq(instance2));
   FactoryMethods::DestroyServiceInstance();

   delete helperServiceB;
}

// Pros: Good for an integration test. Stands up all the real objects except for external services
//    Cleaner than an entrypoint test
// Cons: mocking internal objects require a link seem (could just have a unit test)
//    Can mock service objects

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

