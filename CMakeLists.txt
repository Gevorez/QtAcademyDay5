cmake_minimum_required(VERSION 3.16)

project(Day5App VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appDay5App
    main.cpp
)

qt_add_qml_module(appDay5App
    URI Day5App
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES virtualtemperature.h virtualtemperature.cpp
    SOURCES radiatorvalvecontroller.h radiatorvalvecontroller.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appDay5App PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appDay5App
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDay5App
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appDay5App
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
