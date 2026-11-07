# The following variables contains the files used by the different stages of the build process.
set(fw_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${fw_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${fw_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(fw_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${fw_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${fw_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(fw_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../app/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../app/state_machine.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/bsp/business_card.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/hw_drivers/sseg_display.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/hw_drivers/tmp_snsr.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/mcu_drivers/gpio.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/mcu_drivers/i2c.c")
set_source_files_properties(${fw_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(fw_default_default_XC8_FILE_TYPE_link)
set(fw_default_image_name "default.elf")
set(fw_default_image_base_name "default")

# The output directory of the final image.
set(fw_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/fw")

# The full path to the final image.
set(fw_default_full_path_to_image ${fw_default_output_dir}/${fw_default_image_name})

# Potential output file extensions
set(output_extensions
    .hex
    .hxl
    .mum
    .o
    .sdb
    .sym
    .cmf)
list(TRANSFORM output_extensions PREPEND "${fw_default_output_dir}/${fw_default_image_base_name}")
