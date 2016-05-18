# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 06-03-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
cmake_minimum_required(VERSION 3.0)
project(AUT_CoDesign)

# Set porject imformation
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory(src)

configure_file(keys ${CMAKE_CURRENT_BINARY_DIR}/keys COPYONLY)
configure_file(etalon.txt ${CMAKE_CURRENT_BINARY_DIR}/etalon.txt COPYONLY)
configure_file(refText.txt ${CMAKE_CURRENT_BINARY_DIR}/refText.txt COPYONLY)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -O0 -g -DDEBUG")
