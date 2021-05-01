cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME Project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp EventHandler.h Snapshot.cpp Snapshot.h History.cpp History.h MouseEvents.cpp MouseEvents.h KeyboardShortcuts.cpp KeyboardShortcuts.h Cursor.cpp Cursor.h TextBox.cpp TextBox.h Typing.cpp Typing.h TextInput.cpp TextInput.h States.cpp States.h GUI_components.cpp GUI_components.h Node.h LinkedList.cpp LinkedList.h Stack.cpp Stack.h Label.cpp Label.h Letter.cpp Letter.h Item.cpp Item.h ItemList.cpp ItemList.h InputBox.cpp InputBox.h DropdownMenu.cpp DropdownMenu.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()