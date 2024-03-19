add_executable(01_232_implement-queue-using-stacks
               01_232_implement-queue-using-stacks.cpp)
install(TARGETS 01_232_implement-queue-using-stacks
        DESTINATION 05_StackAndQueue)

add_executable(02_225_implement-stack-using-queues
               02_225_implement-stack-using-queues.cpp)
install(TARGETS 02_225_implement-stack-using-queues
        DESTINATION 05_StackAndQueue)

add_executable(03_20_valid-parentheses 03_20_valid-parentheses.cpp)
install(TARGETS 03_20_valid-parentheses DESTINATION 05_StackAndQueue)

add_executable(04_1047_remove-all-adjacent-duplicates-in-string
               04_1047_remove-all-adjacent-duplicates-in-string.cpp)
install(TARGETS 04_1047_remove-all-adjacent-duplicates-in-string
        DESTINATION 05_StackAndQueue)

add_executable(05_150_evaluate-reverse-polish-notation
               05_150_evaluate-reverse-polish-notation.cpp)
install(TARGETS 05_150_evaluate-reverse-polish-notation
        DESTINATION 05_StackAndQueue)

add_executable(06_239_sliding-window-maximum 06_239_sliding-window-maximum.cpp)
install(TARGETS 06_239_sliding-window-maximum DESTINATION 05_StackAndQueue)

add_executable(07_347_top-k-frequent-elements
               07_347_top-k-frequent-elements.cpp)
install(TARGETS 07_347_top-k-frequent-elements DESTINATION 05_StackAndQueue)
