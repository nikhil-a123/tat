# Add applications
add_subdirectory(enviromental_data)
include_directories(enviromental_data)

target_sources(app PRIVATE ${app_sources})