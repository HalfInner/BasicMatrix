#set(core_SRCS ADD ALL SOURCE FILES HERE)

add_executable(exe main.cc)
target_link_directories(exe PRIVATE src)
add_dependencies(exe GTestMain)