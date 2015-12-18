///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceClassInterface.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" ServiceClassInterface* ServiceClassEntryPoint(int, char**);
extern "C" void ServiceClassExitPoint(ServiceClassInterface*);
extern "C" ServiceClassInterface* GetServiceInstance();

using namespace testing;

///////////////////////////////////////////////////////////////////////////////
TEST(EntryPointWithClassInstantiationTest, FailingTest)
{
   char** emptyArgs;
   ServiceClassEntryPoint(0, emptyArgs);
   ServiceClassInterface* instance = GetServiceInstance();
   EXPECT_THAT(instance, NotNull());
   ServiceClassExitPoint(instance);
}

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

