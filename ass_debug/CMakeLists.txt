cmake_minimum_required (VERSION 2.6)
project (template)
set(BINARY ${SOURCE})
string(FIND ${BINARY} "." POS REVERSE)
string(SUBSTRING ${BINARY} 0 ${POS} BINARY_PRUNED)
string(TOLOWER ${BINARY_PRUNED} BIN_NAME) 
add_executable(${BIN_NAME} ${SOURCE})
