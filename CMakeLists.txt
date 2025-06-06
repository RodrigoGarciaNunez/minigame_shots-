cmake_minimum_required(VERSION 3.0.0)
project(SHOTS)

add_executable(server_shots main_server.cpp server.cpp)
add_executable(client_shots main_client.cpp client.cpp)
target_link_libraries(server_shots)
target_link_libraries(client_shots)
