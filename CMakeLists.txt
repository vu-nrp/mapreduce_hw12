cmake_minimum_required(VERSION 3.16)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(mapreduce VERSION ${PROJECT_VERSION})

# lib
add_library(${PROJECT_NAME} SHARED
    lib/functions.h
    lib/functions.cpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}/lib
    ${CMAKE_BINARY_DIR}
)

include(GenerateExportHeader)

generate_export_header(${PROJECT_NAME})

# executable mapper stage
add_executable(mapper
    mapper.cpp
)

target_link_libraries(mapper PRIVATE
    ${PROJECT_NAME}
)

# executable reducer stage
add_executable(reducer
    reducer.cpp
)

target_link_libraries(reducer PRIVATE
    ${PROJECT_NAME}
)

# set compiller flags
set_target_properties(${PROJECT_NAME} mapper reducer PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

#
target_sources(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/input/AB_NYC_2019.csv
    ${CMAKE_CURRENT_SOURCE_DIR}/mapreduce.sh
)
install(TARGETS ${PROJECT_NAME} mapper reducer ${EX_FILES} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT vu-nrp@yandex.ru)
include(CPack)
