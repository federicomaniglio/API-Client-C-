cmake_minimum_required(VERSION 3.27)
project(API)

set(CMAKE_CXX_STANDARD 17)


link_directories(curl/include/curl)

# Aggiungi le Poco C++ Libraries al percorso di inclusione
include_directories(${CMAKE_SOURCE_DIR}/curl/include)
include_directories(${CMAKE_SOURCE_DIR}/curl/include/curl)

# Aggiungi le Poco C++ Libraries al percorso delle librerie
link_directories(${CMAKE_SOURCE_DIR}/curl/lib)

add_executable(API main.cpp)
## Specifica le librerie Poco da linkare al tuo eseguibile
#target_link_libraries(API PUBLIC libcurl)
target_link_libraries(API ${CMAKE_SOURCE_DIR}/curl/lib/libcurl.a)

#list(APPEND CMAKE_MODULE_PATH "cpprestsdk/")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCURL_STATICLIB ")