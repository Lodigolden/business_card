# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "C:\\Users\\adamh\\business_card\\fw\\out\\fw\\default.cmf"
  "C:\\Users\\adamh\\business_card\\fw\\out\\fw\\default.hex"
  "C:\\Users\\adamh\\business_card\\fw\\out\\fw\\default.hxl"
  "C:\\Users\\adamh\\business_card\\fw\\out\\fw\\default.mum"
  "C:\\Users\\adamh\\business_card\\fw\\out\\fw\\default.o"
  "C:\\Users\\adamh\\business_card\\fw\\out\\fw\\default.sdb"
  "C:\\Users\\adamh\\business_card\\fw\\out\\fw\\default.sym"
  )
endif()
