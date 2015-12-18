///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

#include "ServiceLib/ServiceClassInterface.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C"
{
   ServiceClassInterface* ServiceClassEntryPoint(int, char**);
   void ServiceClassExitPoint(ServiceClassInterface*);
   ServiceClassInterface* GetServiceInstance();
}

using namespace testing;

///////////////////////////////////////////////////////////////////////////////
TEST(EntryPointWithClassInstantiationTest, CanGetServiceInstance)
{
   char** emptyArgs;
   ServiceClassEntryPoint(0, emptyArgs);
   ServiceClassInterface* instance = GetServiceInstance();
   EXPECT_THAT(instance, NotNull());
   ServiceClassExitPoint(instance);
}

// Pros: Good for an integration test. Stands up all the real objects
// Cons: No possibility for injection.
//	Mocking external services isn't possible through injections
//		could use a link seam

///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

