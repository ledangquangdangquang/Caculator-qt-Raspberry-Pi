cmake_minimum_required(VERSION 3.5)

project(CalculatorRPI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        
        # For enter key
        MyPlainTextEdit.h	MyPlainTextEdit.cpp

        # Operation
        operation/operation.h
        operation/addoperation.h	operation/addoperation.cpp
        operation/suboperation.h	operation/suboperation.cpp
        operation/muloperation.h	operation/muloperation.cpp
        operation/divoperation.h	operation/divoperation.cpp
        operation/operationfactory.h	operation/operationfactory.cpp
        operation/sqrtoperation.h	operation/sqrtoperation.cpp
        operation/modoperation.h	operation/modoperation.cpp
        operation/powoperation.h	operation/powoperation.cpp
        operation/sinoperation.h	operation/sinoperation.cpp
        operation/cosoperation.h 	operation/cosoperation.cpp
        operation/tanoperation.h 	operation/tanoperation.cpp
        operation/cotoperation.h 	operation/cotoperation.cpp
        operation/logoperation.h	operation/logoperation.cpp
        operation/lnoperation.h 	operation/lnoperation.cpp
        operation/absoperation.h 	operation/absoperation.cpp
        operation/sinhoperation.h	operation/sinhoperation.cpp
        operation/coshoperation.h	operation/coshoperation.cpp
        operation/tanhoperation.h 	operation/tanhoperation.cpp
        operation/reoperation.h		operation/reoperation.cpp
        operation/imoperation.h 	operation/imoperation.cpp
        operation/argoperation.h 	operation/argoperation.cpp
        operation/conjoperation.h	operation/conjoperation.cpp
        # Parser
        parser/tokenizer.h	parser/tokenizer.cpp
        parser/shuntingyard.h	parser/shuntingyard.cpp
        parser/evaluator.h	parser/evaluator.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CalculatorRPI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CalculatorRPI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CalculatorRPI SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CalculatorRPI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CalculatorRPI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# Fix add Promote mainwindow.ui
# This is in step Enter key <=> equal button
# I create a header file MyPlainTextEdit.h and mainwindow.ui don't know this
# This code cleared that where is MyPlainTextEdit.h
target_include_directories(CalculatorRPI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(CalculatorRPI PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS CalculatorRPI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CalculatorRPI)
endif()
