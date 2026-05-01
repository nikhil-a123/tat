FILE(GLOB ui_sources *.c)
target_sources(app PRIVATE ${ui_sources})

add_subdirectory(fonts)