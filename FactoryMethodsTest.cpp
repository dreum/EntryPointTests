///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "FactoryMethods.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

///////////////////////////////////////////////////////////////////////////////
TEST(FactoryMethodsTest, CanGetServiceInstance)
{
   ServiceClassInterface* instance = FactoryMethods::GetServiceInstance();
   EXPECT_THAT(instance, NotNull());
   FactoryMethods::DestroyServiceInstance();
}

// Pros: Good for an integration test. Stands up all the real objects
//    Much cleaner than an entrypoint test
// Cons: mocking still requires a link seem

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

