///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////
#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

class ServiceClassInterface;
class HelperServiceBInterface;

class ServiceFactory
{
public:
   ServiceFactory(HelperServiceBInterface& helperServiceB);
   virtual ~ServiceFactory();

   ServiceClassInterface* GetServiceInstance();

private:
   ServiceClassInterface* Service;
   // Not Implemented
   ServiceFactory(const ServiceFactory& rhs);
   ServiceFactory& operator=(const ServiceFactory& rhs);
};

#endif // SERVICEFACTORY_H
///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Deere & Company as an unpublished work
// THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.  ALL USE,
// DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY DEERE &
// COMPANY IS PROHIBITED.
///////////////////////////////////////////////////////////////////////////////

