set(LIB_NAME ServiceLib)

set(PUBLIC_DIR ${CMAKE_SOURCE_DIR}/public/${LIB_NAME})

set(PUBLIC_INCLUDES
    ${PUBLIC_DIR}/HelperClassAInterface.h
    ${PUBLIC_DIR}/HelperServiceBInterface.h
    ${PUBLIC_DIR}/ServiceClassInterface.h
)

add_library(ServiceLib SHARED
    EntryPointWithClassInstantiation.cpp
    EntryPointWithFactoryMethod.cpp
    FactoryMethods.cpp
    FactoryMethods.h
    HelperClassA.cpp
    HelperClassA.h
    HelperServiceB.cpp
    HelperServiceB.h
    ServiceClass.cpp
    ServiceClass.h
)
