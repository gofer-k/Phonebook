
project(Phonebook)

add_library(${PROJECT_NAME} STATIC
  Implementation/Address.cpp
  Implementation/Contact.cpp
)

target_include_directories(${PROJECT_NAME} 
  # EXpose Interface folder as public library interface
  PUBLIC Interface
  # hide library implementation from ouside
  PRIVATE Implementation)

target_link_libraries(${PROJECT_NAME}
  # add any thrid party library which is referenced in test defined in this project
)

# Installation folder. Run 'make install' to install this project in specified folder
install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${BINARY_DESTINATION_DIRECTORY})

# add_subdirectory(test)