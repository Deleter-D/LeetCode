get_filename_component(current_dir_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB current_dir_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
include("${CMAKE_SOURCE_DIR}/cmake/StringUtils.cmake")

foreach(file_name ${current_dir_sources})
GetFileBaseName(${file_name} file_base_name 4)
add_executable(${file_base_name} ${file_name})
install(TARGETS ${file_base_name} DESTINATION ${current_dir_name})
endforeach()
