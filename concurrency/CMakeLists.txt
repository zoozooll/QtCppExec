cmake_minimum_required(VERSION 3.14)

project(CppApplication LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

include_directories("include")

file(GLOB concurrency_SRC
        src/android/os/*.cpp
        include/android/os/*.h
        )


add_executable(Android_Message_Concurrency_Test
    Test.cpp
    ${concurrency_SRC}
)

target_link_libraries(Android_Message_Concurrency_Test Qt${QT_VERSION_MAJOR}::Core)


add_executable(Android_Message_Concurrency_AsyncTaskExample
    AsyncTaskExample.cpp
    ${concurrency_SRC}
)

target_link_libraries(Android_Message_Concurrency_AsyncTaskExample Qt${QT_VERSION_MAJOR}::Core)

add_executable(Android_Message_Concurrency_DelegateExample
    DelegateExample.cpp
    ${concurrency_SRC}
)

target_link_libraries(Android_Message_Concurrency_DelegateExample Qt${QT_VERSION_MAJOR}::Core)

add_executable(Android_Message_Concurrency_LooperThreadExample
    LooperThreadExample.cpp
    ${concurrency_SRC}
)

target_link_libraries(Android_Message_Concurrency_LooperThreadExample Qt${QT_VERSION_MAJOR}::Core)

add_executable(Android_Message_Concurrency_RefCountingTest
    RefCountingTest.cpp
    ${concurrency_SRC}
)

target_link_libraries(Android_Message_Concurrency_RefCountingTest Qt${QT_VERSION_MAJOR}::Core)

