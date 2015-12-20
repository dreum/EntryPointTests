set(LIB_NAME ServiceLib)

ADD_LIBRARY_SUBFOLDER(${LIB_NAME})

target_link_libraries(${LIB_NAME} HelperServiceB)
