cmake_minimum_required(VERSION 3.0.0)
project(SHOTS)

add_executable(server_shots server_side/main_server.cpp server_side/server.cpp)
add_executable(client_shots client_side/main_client.cpp client_side/client.cpp)
target_link_libraries(server_shots)
target_link_libraries(client_shots)
