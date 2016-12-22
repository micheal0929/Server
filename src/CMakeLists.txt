SET(SRC_LIST buffer.h buffer.cpp clientInfo.h clientInfo.cpp test.cpp)
link_directories(/mnt/hgfs/All files/epoll/Server/include)
ADD_EXECUTABLE(epollserver ${SRC_LIST})
