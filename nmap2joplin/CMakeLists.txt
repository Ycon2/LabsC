cmake_minimum_required(VERSION 3.10)
project(nmap2joplin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
  pugixml
  GIT_REPOSITORY https://github.com/zeux/pugixml.git
  GIT_TAG v1.11.4
)

FetchContent_GetProperties(pugixml)
if(NOT pugixml_POPULATED)
  FetchContent_Populate(pugixml)
  add_subdirectory(${pugixml_SOURCE_DIR} ${pugixml_BINARY_DIR})
endif()

include_directories(${PROJECT_SOURCE_DIR}/src/headers)
include_directories(${PROJECT_SOURCE_DIR}/src/cpp)
include_directories(${pugixml_SOURCE_DIR})

add_executable(nmap2joplin 
    src/cpp/main.cpp 
    src/cpp/PortInfo.cpp 
    src/cpp/NmapXmlParser.cpp 
    src/cpp/FileService.cpp 
    src/cpp/CommandLineParser.cpp 
    src/cpp/Utils.cpp 
)

target_link_libraries(nmap2joplin pugixml)
