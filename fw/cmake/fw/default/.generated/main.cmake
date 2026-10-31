include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(fw_default_library_list )

set(OUTPUT_SUFFIX elf)
# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(fw_default_default_XC8_FILE_TYPE_assemble)
add_library(fw_default_default_XC8_assemble OBJECT ${fw_default_default_XC8_FILE_TYPE_assemble})
    fw_default_default_XC8_assemble_rule(fw_default_default_XC8_assemble)
    list(APPEND fw_default_library_list "$<TARGET_OBJECTS:fw_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(fw_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(fw_default_default_XC8_assemblePreprocess OBJECT ${fw_default_default_XC8_FILE_TYPE_assemblePreprocess})
    fw_default_default_XC8_assemblePreprocess_rule(fw_default_default_XC8_assemblePreprocess)
    list(APPEND fw_default_library_list "$<TARGET_OBJECTS:fw_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(fw_default_default_XC8_FILE_TYPE_compile)
add_library(fw_default_default_XC8_compile OBJECT ${fw_default_default_XC8_FILE_TYPE_compile})
    fw_default_default_XC8_compile_rule(fw_default_default_XC8_compile)
    list(APPEND fw_default_library_list "$<TARGET_OBJECTS:fw_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(fw_default_image_7VxbsBfP ${fw_default_library_list})

set_target_properties(fw_default_image_7VxbsBfP PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${fw_default_output_dir}")
target_link_libraries(fw_default_image_7VxbsBfP PRIVATE ${fw_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
fw_default_link_rule( fw_default_image_7VxbsBfP)



