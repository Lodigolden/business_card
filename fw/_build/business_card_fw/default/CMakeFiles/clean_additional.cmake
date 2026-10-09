# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "C:\\Users\\adamh\\business_card\\fw\\out\\business_card_fw\\default.cmf"
  "C:\\Users\\adamh\\business_card\\fw\\out\\business_card_fw\\default.hex"
  "C:\\Users\\adamh\\business_card\\fw\\out\\business_card_fw\\default.hxl"
  "C:\\Users\\adamh\\business_card\\fw\\out\\business_card_fw\\default.mum"
  "C:\\Users\\adamh\\business_card\\fw\\out\\business_card_fw\\default.o"
  "C:\\Users\\adamh\\business_card\\fw\\out\\business_card_fw\\default.sdb"
  "C:\\Users\\adamh\\business_card\\fw\\out\\business_card_fw\\default.sym"
  )
endif()
