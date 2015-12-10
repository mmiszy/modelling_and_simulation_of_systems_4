cmake_minimum_required(VERSION 3.2)
project(modelling_and_simulation_of_systems)

find_package(Boost 1.59.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lboost_iostreams -Wall -O3")

set(SOURCE_FILES
    main.cpp RK2.cpp RK2.h stdfx.h)

add_executable(modelling_and_simulation_of_systems ${SOURCE_FILES})

if(Boost_FOUND)
    target_link_libraries(modelling_and_simulation_of_systems ${Boost_LIBRARIES})
endif()
