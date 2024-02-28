cmake_minimum_required(VERSION 3.27)
project(API)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCURL_STATICLIB ")


# Aggiungi le Poco C++ Libraries al percorso di inclusione
include_directories(${PROJECT_SOURCE_DIR}/curl/include)
# Aggiungi le Poco C++ Libraries al percorso delle librerie
link_directories(${PROJECT_SOURCE_DIR}/curl/lib)

add_executable(API main.cpp)
## Specifica le librerie Poco da linkare al tuo eseguibile
#target_link_libraries(API PUBLIC libcurl)
target_link_libraries(API ${PROJECT_SOURCE_DIR}/curl/lib/libcurl.dll.a)

#list(APPEND CMAKE_MODULE_PATH "cpprestsdk/")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCURL_STATICLIB ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCURL_STATICLIB ")
