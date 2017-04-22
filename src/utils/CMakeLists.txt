# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cc")

# Generate the shared library from the sources
add_library(utils SHARED ${SOURCES})

# Specify that this library itself needs access to the folder "include" and that any other
# target which depends on this also gets similar access - i.e. use 'PUBLIC'
target_include_directories(utils PUBLIC include)