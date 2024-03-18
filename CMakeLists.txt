project(qtdemo
    LANGUAGES CXX C
   )

find_package(Qt5 COMPONENTS Widgets OpenGL Network Quick Svg REQUIRED)

message(STATUS "Found Qt5 version ${Qt5_VERSION}: ${Qt5_DIR}")

file(GLOB_RECURSE source CONFIGURE_DEPENDS *.h *.cpp *.ui)
file(GLOB_RECURSE resource CONFIGURE_DEPENDS *.qrc)

qt5_add_resources(source ${resource})

add_executable(qtdemo main.cpp testdialog.cpp testdialog.h testdialog.ui)
# Add a dependency to ensure that the resource file is deleted before being regenerated

set_property(TARGET qtdemo PROPERTY AUTOUIC ON)
set_property(TARGET qtdemo PROPERTY AUTOMOC ON)
set_property(TARGET qtdemo PROPERTY AUTORCC ON)
set_property(TARGET qtdemo PROPERTY WIN32_EXECUTABLE OFF)

target_link_libraries(qtdemo PRIVATE Qt5::Widgets Qt5::OpenGL Qt5::Svg Qt5::Network Qt5::Quick)

if (WIN32)
    target_link_libraries(qtdemo PRIVATE Dbghelp Version)
    target_link_libraries(qtdemo PRIVATE ws2_32.lib winmm.lib wldap32.lib Advapi32.lib Crypt32.lib)
endif()