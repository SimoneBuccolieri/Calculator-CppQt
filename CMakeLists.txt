cmake_minimum_required(VERSION 3.30)
project(QtCalculator)

set(CMAKE_CXX_STANDARD 20)

# Percorso Qt (modifica se il tuo percorso è diverso)
set(Qt6_DIR "/opt/homebrew/opt/qt/lib/cmake/Qt6")

# Trova i moduli Qt necessari
find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

# Aggiungi i file sorgente e gli header
set(SOURCES
        main.cpp
        mainwindow.cpp
)

set(HEADERS
        mainwindow.h
)

# Genera i file MOC per le classi Qt
qt_wrap_cpp(MOC_SOURCES ${HEADERS})

# Creazione dell'eseguibile
add_executable(CGPT ${SOURCES} ${MOC_SOURCES})

# Collega le librerie Qt necessarie
target_link_libraries(CGPT Qt6::Widgets)