SET(c_options "")
IF (MSVC)
    SET(c_options "/permissive-")
ENDIF ()

ADD_TARGET(
        MODE INTERFACE
        INC
        "${PROJECT_SOURCE_DIR}/include"
        C_OPTION
        ${c_options}
)