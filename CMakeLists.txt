cmake_minimum_required(VERSION 3.14)

project(CppApplication LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

include_directories(".")

add_executable(CppApplication
  main.cpp
  jsonexec.h
  jsonexec.cpp
  modelbeanlist.h
  modelbeanlist.cpp
  json_exercise2.h
  json_exercise2.cpp
)

target_link_libraries(CppApplication Qt${QT_VERSION_MAJOR}::Core)

add_executable(ThreadHandlerApplication
    threadhandler/cthread.h
    threadhandler/cthread.cpp
    threadhandler/main.cpp

)

target_link_libraries(ThreadHandlerApplication Qt${QT_VERSION_MAJOR}::Core)

add_executable(GLThreadApplication
    glthread/eglhelper.h
    glthread/eglhelper.cpp
    glthread/glthread.h
    glthread/glthread.cpp
    glthread/main.cpp
)

target_link_libraries(GLThreadApplication Qt${QT_VERSION_MAJOR}::Core)

#add_executable(Android_Message_Concurrency
#    concurrency/main.cpp
#)

#target_link_libraries(Android_Message_Concurrency Qt${QT_VERSION_MAJOR}::Core)

#set(json_resource_files
#    "model_list.json"
#)

add_subdirectory("concurrency" ${CMAKE_CURRENT_BINARY_DIR}/concurrency)

qt6_add_resources(CppApplication "jsons"
    PREFIX
        "/"
    FILES
        ${json_resource_files}
)

install(TARGETS CppApplication
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
