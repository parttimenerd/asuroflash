cmake_minimum_required(VERSION 2.8)
project(asuroflash)


## Configure compiler and libraries
add_compile_options(-std=c++1y -Wno-switch-enum -Wall -Wextra)
include_directories(${PROJECT_SOURCE_DIR}/include)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

  add_compile_options(-fdiagnostics-color=auto)  
  #  set(Boost_LIBRARY_DIR $ENV{BOOST_GCC_LIB}) # if set manually

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

  add_compile_options(-stdlib=libc++)
  #set(Boost_LIBRARY_DIR $ENV{BOOST_CLANG_LIB}) # if set manually

endif()

add_custom_command(
	OUTPUT ${PROJECT_SOURCE_DIR}/src/stdlib/stdlib.hpp
	COMMAND ${PROJECT_SOURCE_DIR}/src/stdlib/build.rb
)


## Generate unit tests in ./test
#enable_testing()

#file(GLOB test_sources RELATIVE ${PROJECT_SOURCE_DIR} test/*.cpp)

#foreach(path IN LISTS test_sources)

#  get_filename_component(target ${path} NAME_WE)
#  add_executable(${target} ${path})
#  add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
#  set_property(TEST ${target} APPEND PROPERTY LABELS ${path})

#  TARGET_LINK_LIBRARIES(${target} ${Boost_LIBRARIES})

#  if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # link libc++
    #    TARGET_LINK_LIBRARIES(${target} c++)
    #  endif()
  
    #endforeach()

###############
### TARGETS ###
###############

# Collect executables in ./src
FILE(GLOB sources RELATIVE ${PROJECT_SOURCE_DIR} src/*.cpp)

FILE(GLOB library_sources RELATIVE ${PROJECT_SOURCE_DIR} src/*.cpp)
LIST(REMOVE_ITEM library_sources ${PROJECT_SOURCE_DIR} src/main.cpp)

###################
### asuroflash_library ###
###################

#ADD_LIBRARY(asuroflash_library
#	${library_sources}
#)

#SET_TARGET_PROPERTIES(asuroflash_library PROPERTIES LINKER_LANGUAGE CXX)
#SET_TARGET_PROPERTIES(asuroflash_library PROPERTIES OUTPUT_NAME asuroflash)

######################
### asuroflash_executable ###
######################

ADD_EXECUTABLE(asuroflash_executable
	${sources}
)

SET_TARGET_PROPERTIES(asuroflash_executable PROPERTIES LINKER_LANGUAGE CXX)
SET_TARGET_PROPERTIES(asuroflash_executable PROPERTIES OUTPUT_NAME asuroflash)

###################
### END TARGETS ###
###################

# Clang specific libraries

IF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # link libc++
  TARGET_LINK_LIBRARIES(asuroflash_executable c++)
  TARGET_LINK_LIBRARIES(asuroflash_library c++)
ENDIF()
