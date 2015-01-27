cmake_minimum_required(VERSION 2.8.11)

project(IronScout)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

set(IronScout2015_SRCS CStationInterface.h CStationInterface.cpp CRunnerInterface.h CRunnerInterface.cpp CGroupInterface.h CGroupInterface.cpp main.cpp CMainWindow.h CMainWindow.cpp CCentralAbstractInterface.h CCentralAbstractInterface.cpp CCentralStationInterface.h CCentralStationInterface.cpp CCentralRunnerInterface.h CCentralRunnerInterface.cpp CGroup.h CGroup.cpp CAnalysis.h CAnalysis.cpp CAnalysisRunner.h CAnalysisRunner.cpp CRunner.h CRunner.cpp)

# Tell CMake to create the IronScout executable
add_executable(IronScout2015 WIN32 ${IronScout2015_SRCS})

# Use the Widgets module from Qt 5.
target_link_libraries(IronScout2015 Qt5::Widgets)
