cmake_minimum_required(VERSION 3.15)

# Политика для отладочной информации в MSVC
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Поиск Gnuplot (исправлено для переносимости)
find_package(Gnuplot)

if(NOT GNUPLOT_FOUND)
    find_program(GNUPLOT_EXECUTABLE
        NAMES gnuplot.exe gnuplot
        PATHS "C:/Program Files/gnuplot/bin"
              "C:/Program Files (x86)/gnuplot/bin"
              "$ENV{ProgramFiles}/gnuplot/bin"
              "$ENV{ProgramW6432}/gnuplot/bin"
        DOC "Path to gnuplot executable"
    )
    if(GNUPLOT_EXECUTABLE)
        message(STATUS "Gnuplot found at: ${GNUPLOT_EXECUTABLE}")
        set(GNUPLOT_FOUND TRUE)
    else()
        message(WARNING "Gnuplot not found. Install from: http://www.gnuplot.info/")
    endif()
endif()

# Имя проекта
project("ooplab1")

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Автоматическая загрузка Matplot++ через FetchContent ---
include(FetchContent)

FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
    GIT_TAG        v1.2.1     # зафиксированная стабильная версия
    GIT_SHALLOW    TRUE       # не тянуть всю историю, только нужный тег
)

# Отключаем лишние компоненты Matplot++ для ускорения сборки
set(MATPLOT_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(MATPLOT_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(MATPLOT_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(MATPLOT_INSTALL_UTILS  OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(matplotplusplus)

if(MSVC)
    target_compile_options(matplot PRIVATE /wd4834)
    add_compile_definitions(_HAS_STD_BYTE=0)
endif()

# Исходные файлы проекта
set(SOURCES
    ooplab1.cpp
    ooplab1.h
    figure.cpp
    figure.h "user.h" "user.cpp")

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES})

# Линковка с matplotplusplus
target_link_libraries(${PROJECT_NAME} PUBLIC matplot)

# Настройка путей включения
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Передача пути к Gnuplot в код (если нужно в рантайме)
if(GNUPLOT_EXECUTABLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        GNUPLOT_PATH="${GNUPLOT_EXECUTABLE}"
    )
endif()

# Настройка выходной директории (опционально)
# set_target_properties(${PROJECT_NAME} PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../.."
# )