# ============================================================================
#
# This file hosts all tests.
#
# If INCLUDE_PILE_SOURCES_DIRECTLY is ON then LINKEDLIST_SOURCES and
# LINKEDLIST_HEADERS are defined we add them to the executable. LINKEDLIST_LIBRARY
# is empty.
#
# On the other hand if INCLUDE_PILE_SOURCES_DIRECTLY is
# OFF then LINKEDLIST_SOURCES and LINKEDLIST_HEADERS are empty and we link
# against LINKEDLIST_LIBRARY that is now the name of the target that
# builds the library.
#
# ============================================================================

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if (NOT INCLUDE_PILE_SOURCES_DIRECTLY)
    set (LINKEDLIST_LIBRARY linkedlist)
endif()

add_executable(test_basic
    ${LINKEDLIST_SOURCES}
    ${LINKEDLIST_HEADERS}
    basic.cc)

target_link_libraries(test_basic
    ${GTEST_BOTH_LIBRARIES}
    ${LINKEDLIST_LIBRARY})

add_test(
    NAME test_basic
    COMMAND $<TARGET_FILE:test_basic>)
