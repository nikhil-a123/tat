FILE(GLOB enviromental_data_sources *.c)
target_sources(app PRIVATE ${enviromental_data_sources})

# Add enviromental data screens
add_subdirectory(simple)
add_subdirectory(test)