# The following variables contains the files used by the different stages of the build process.
set(business_card_fw_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${business_card_fw_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${business_card_fw_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(business_card_fw_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${business_card_fw_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${business_card_fw_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(business_card_fw_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/display_mode_indicator.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config.c")
set_source_files_properties(${business_card_fw_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(business_card_fw_default_default_XC8_FILE_TYPE_link)
set(business_card_fw_default_image_name "default.elf")
set(business_card_fw_default_image_base_name "default")

# The output directory of the final image.
set(business_card_fw_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/business_card_fw")

# The full path to the final image.
set(business_card_fw_default_full_path_to_image ${business_card_fw_default_output_dir}/${business_card_fw_default_image_name})

# Potential output file extensions
set(output_extensions
    .hex
    .hxl
    .mum
    .o
    .sdb
    .sym
    .cmf)
list(TRANSFORM output_extensions PREPEND "${business_card_fw_default_output_dir}/${business_card_fw_default_image_base_name}")
