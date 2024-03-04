add_executable(01_203_remove-linked-list-elements
               01_203_remove-linked-list-elements.cpp)
install(TARGETS 01_203_remove-linked-list-elements DESTINATION 02_LinkedList)

add_executable(02_707_design-linked-list 02_707_design-linked-list.cpp)
install(TARGETS 02_707_design-linked-list DESTINATION 02_LinkedList)

add_executable(03_206_reverse-linked-list 03_206_reverse-linked-list.cpp)
install(TARGETS 03_206_reverse-linked-list DESTINATION 02_LinkedList)

add_executable(04_24_swap-nodes-in-pairs 04_24_swap-nodes-in-pairs.cpp)
install(TARGETS 04_24_swap-nodes-in-pairs DESTINATION 02_LinkedList)

add_executable(05_19_remove-nth-node-from-end-of-list
               05_19_remove-nth-node-from-end-of-list.cpp)
install(TARGETS 05_19_remove-nth-node-from-end-of-list
        DESTINATION 02_LinkedList)

add_executable(06_intersection-of-two-linked-lists-lcci
               06_intersection-of-two-linked-lists-lcci.cpp)
install(TARGETS 06_intersection-of-two-linked-lists-lcci
        DESTINATION 02_LinkedList)

add_executable(07_142_linked-list-cycle-ii 07_142_linked-list-cycle-ii.cpp)
install(TARGETS 07_142_linked-list-cycle-ii DESTINATION 02_LinkedList)
