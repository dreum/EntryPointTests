macro(ADD_LIBRARY_SUBFOLDER LIB_NAME)
    if(NOT ${LIB_NAME} STREQUAL "")
        set(PUBLIC_DIR ${CMAKE_SOURCE_DIR}/public/${LIB_NAME})

        file(GLOB PUBLIC_INCLUDES ${PUBLIC_DIR}/*Interface.h)
        file(GLOB CPPS *.cpp)
        file(GLOB HEADERS *.h)

        add_library(ServiceLib SHARED
            ${CPPS}
            ${HEADERS}
            ${PUBLIC_INCLUDES}
        )
    else()
        message(FATAL_ERROR "incorrect arguments to ADD_LIBRARY_SUBFOLDER macro: " ${LIB_NAME})
    endif()
endmacro()
