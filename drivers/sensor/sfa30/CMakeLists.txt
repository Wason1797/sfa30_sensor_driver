zephyr_library()
zephyr_library_sources_ifdef(CONFIG_SFA30 sfa30.c)
zephyr_include_directories(../sensirion_lib)