cmake_minimum_required(VERSION 3.16)
project(ty-1)

# Используем C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем Geant4
find_package(Geant4 REQUIRED ui_all vis_all)

# Подключаем настройки Geant4
include(${Geant4_USE_FILE})

# Указываем папки с исходниками и заголовками
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc ${PROJECT_SOURCE_DIR}/main.cc)

# Создаём исполняемый файл
add_executable(main ${sources})

# Линкуем библиотеки Geant4
target_link_libraries(main ${Geant4_LIBRARIES})

# Копируем макросы в build при сборке
file(GLOB macros ${PROJECT_SOURCE_DIR}/*.mac)
foreach(_file ${macros})
  configure_file(${_file} ${PROJECT_BINARY_DIR} COPYONLY)
endforeach()