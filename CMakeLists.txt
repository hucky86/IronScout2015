cmake_minimum_required(VERSION 2.8.11)

project(IronScout)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

set(IronScout2015_SRCS CStation.cpp CRunner.cpp CGroup.cpp main.cpp CMainWindow.cpp CCentralWidget.cpp CTable.cpp)

# Tell CMake to create the IronScout executable
add_executable(IronScout2015 WIN32 ${IronScout2015_SRCS})

# Use the Widgets module from Qt 5.
target_link_libraries(IronScout2015 Qt5::Widgets)
