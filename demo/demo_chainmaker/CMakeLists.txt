


set(FABRIC_DEMO_SRC         demo_chainmaker.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/demo/demo_chainmaker/runtime)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/vendor/platform/include)

add_executable(demo_chainmaker_onetime ${FABRIC_DEMO_SRC})
target_compile_options(demo_chainmaker_onetime PRIVATE -DUSE_ONETIME_WALLET)
target_link_libraries(demo_chainmaker_onetime
                        boatwallet
                        boatvendor
                        curl)

add_executable(demo_chainmaker_persist ${FABRIC_DEMO_SRC})
target_compile_options(demo_chainmaker_persist PRIVATE -DUSE_CREATE_PERSIST_WALLET)
target_link_libraries(demo_chainmaker_persist
                        boatwallet
                        boatvendor
                        curl)

add_executable(demo_chainmaker_load ${FABRIC_DEMO_SRC})
target_compile_options(demo_chainmaker_load PRIVATE -DUSE_LOAD_PERSIST_WALLET)
target_link_libraries(demo_chainmaker_load
                        boatwallet
                        boatvendor
                        curl)