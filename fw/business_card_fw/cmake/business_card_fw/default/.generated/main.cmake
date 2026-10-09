include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(business_card_fw_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(business_card_fw_default_default_XC8_FILE_TYPE_assemble)
add_library(business_card_fw_default_default_XC8_assemble OBJECT ${business_card_fw_default_default_XC8_FILE_TYPE_assemble})
    business_card_fw_default_default_XC8_assemble_rule(business_card_fw_default_default_XC8_assemble)
    list(APPEND business_card_fw_default_library_list "$<TARGET_OBJECTS:business_card_fw_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(business_card_fw_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(business_card_fw_default_default_XC8_assemblePreprocess OBJECT ${business_card_fw_default_default_XC8_FILE_TYPE_assemblePreprocess})
    business_card_fw_default_default_XC8_assemblePreprocess_rule(business_card_fw_default_default_XC8_assemblePreprocess)
    list(APPEND business_card_fw_default_library_list "$<TARGET_OBJECTS:business_card_fw_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(business_card_fw_default_default_XC8_FILE_TYPE_compile)
add_library(business_card_fw_default_default_XC8_compile OBJECT ${business_card_fw_default_default_XC8_FILE_TYPE_compile})
    business_card_fw_default_default_XC8_compile_rule(business_card_fw_default_default_XC8_compile)
    list(APPEND business_card_fw_default_library_list "$<TARGET_OBJECTS:business_card_fw_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(business_card_fw_default_image_e5_evpLt ${business_card_fw_default_library_list})

set_target_properties(business_card_fw_default_image_e5_evpLt PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${business_card_fw_default_output_dir}")
target_link_libraries(business_card_fw_default_image_e5_evpLt PRIVATE ${business_card_fw_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
business_card_fw_default_link_rule( business_card_fw_default_image_e5_evpLt)



