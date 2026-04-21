# Add applications
add_subdirectory(about)
add_subdirectory(enviromental_data)
add_subdirectory(hello_world)

include_directories(about)
include_directories(enviromental_data)
include_directories(hello_world)

target_sources(app PRIVATE ${app_sources})