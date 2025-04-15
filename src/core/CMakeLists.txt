SET(c_options "")
IF (MSVC)
    LIST(APPEND c_options "/permissive-")
ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    LIST(APPEND c_options "-fconstexpr-steps=16777216") # for long type_name
ELSEIF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    #
ENDIF ()

ADD_TARGET(
        MODE INTERFACE
        INC
        "${PROJECT_SOURCE_DIR}/include"
        C_OPTION
        ${c_options}
)