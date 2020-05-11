cmake_minimum_required(VERSION 2.4)
project(exo_struct)



SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pg -lm -lrt")
#工具类别

#工具类别结束
#共享资源

#共享资源完成


#SD格式定义体

#SD格式定义体完成

#结构架构
set(structures include/structures/plaggable_class.cpp include/structures/Shared_Data.cpp
        include/structures/Assignable_Pipe.cpp include/structures/SharedResource.cpp)
#Pipes



#pipe完成

include_directories(
        include
        


)






