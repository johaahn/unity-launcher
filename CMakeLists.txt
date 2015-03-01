project(qtpanel C CXX)
cmake_minimum_required(VERSION 2.8)

# Default install location. Must be set here, before setting the project.
if (NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE PATH "" FORCE)
endif()

# Do not accept in-tree build
if(${PROJECT_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR})
   message(FATAL_ERROR "In-tree build attempt detected, aborting. Set your build dir outside your source dir, delete CMakeCache.txt from source root and try again.")
endif()

# Standard install paths
include(GNUInstallDirs)
include(FindPkgConfig)

# Check dependencies
find_package(Qt5Core 5.2 REQUIRED)
find_package(Qt5Qml 5.2 REQUIRED)
find_package(Qt5Quick 5.2 REQUIRED)
find_package(Qt5Gui 5.2 REQUIRED)
find_package(Qt5DBus 5.2 REQUIRED)
find_package(Qt5Concurrent 5.2 REQUIRED)
find_package(Qt5Sql 5.2 REQUIRED)
find_package(Qt5X11Extras 5.2 REQUIRED)
find_package(X11 REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Add Cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# enable QML debugging
string(TOLOWER "${CMAKE_BUILD_TYPE}" cmake_build_type_lower) # Build types should always be lowercase but sometimes they are not.
if(cmake_build_type_lower MATCHES "debug")
    add_definitions(-DQT_QML_DEBUG)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-permissive -pedantic -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# gtk and unity-core (actually sigc++) do not like Qt defining macros named
# "signals" and "slots"
#add_definitions(-DQT_NO_KEYWORDS)

# Save a few container detach and conversions
add_definitions(-DQT_STRICT_ITERATORS)

add_definitions(${Qt5Widgets_DEFINITIONS})


#include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
#qt4_wrap_ui(qtpanel_UI_HEADERS ${qtpanel_UIS})
#qt4_wrap_cpp(qtpanel_MOC_OUTPUT ${qtpanel_MOC_HEADERS})
include_directories(${CMAKE_BINARY_DIR})

set(SHELL_APP_DIR ${CMAKE_INSTALL_DATADIR}/unity8)
set(SHELL_PRIVATE_LIBDIR ${CMAKE_INSTALL_LIBDIR}/unity8)

#qt5_wrap_ui(UI_HEADERS panelapplicationsettings.ui)
add_subdirectory(libunity8-private)
add_subdirectory(include)

#Addede include to all build
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/include
)
include_directories(${Qt5Widgets_INCLUDES})

# Add Unity plugins
set(qtpanel_UIS
	panelapplicationsettings.ui
)
set(qtpanel_HEADERS
)

file(GLOB_RECURSE QML_FILES
    ${CMAKE_SOURCE_DIR}/qml/*
)
set(qtpanel_MOC_HEADERS
	menu_window_exemple.h
	x11support.h
	panelapplication.h
	panelwindow.h
)
set(qtpanel_SOURCES
	menu_window_exemple.cpp
	x11support.cpp
	main.cpp
	panelapplication.cpp
	panelwindow.cpp
)

# Add Unity plugins
add_subdirectory(qml)
add_subdirectory(libs)
add_subdirectory(plugins)

# Create Qt panel executable

add_executable(qtpanel ${qtpanel_SOURCES} ${qtpanel_MOC_OUTPUT} ${qtpanel_HEADERS} ${qtpanel_UI_HEADERS} ${UI_HEADERS} ${QML_FILES})
target_link_libraries(qtpanel ${Qt5Widgets_LIBRARIES} ${Qt5X11Extras_LIBRARIES} ${X11_LIBRARIES} ${X11_Xcomposite_LIB} ${X11_Xdamage_LIB})
qt5_use_modules(qtpanel Gui Qml Quick)
