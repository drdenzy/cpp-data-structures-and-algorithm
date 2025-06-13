function(add_llvm_coverage_target target_name binary_path output_dir)
    find_program(LLVM_PROFDATA_EXECUTABLE llvm-profdata)
    find_program(LLVM_COV_EXECUTABLE llvm-cov)

    if (NOT LLVM_PROFDATA_EXECUTABLE OR NOT LLVM_COV_EXECUTABLE)
        message(FATAL_ERROR "llvm-profdata or llvm-cov not found.")
    endif()

    # Use target-specific file names
    set(PROFRAW_FILE "${CMAKE_BINARY_DIR}/default_${target_name}.profraw")
    set(PROFDATA_FILE "${CMAKE_BINARY_DIR}/default_${target_name}.profdata")

    add_custom_target(${target_name}
            COMMAND LLVM_PROFILE_FILE=${PROFRAW_FILE} ${binary_path}
            COMMAND ${LLVM_PROFDATA_EXECUTABLE} merge -sparse ${PROFRAW_FILE} -o ${PROFDATA_FILE}
            COMMAND ${LLVM_COV_EXECUTABLE} show ${binary_path}
            -instr-profile=${PROFDATA_FILE}
            -format=html
            -output-dir=${output_dir}
            -Xdemangler c++filt
            -path-equivalence=${CMAKE_BINARY_DIR},${CMAKE_SOURCE_DIR}
            -ignore-filename-regex='.*_deps.*|.*tests.*|/usr/include/.*'
            COMMENT "📊 Generating ${target_name} coverage report in ${output_dir}"
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            USES_TERMINAL
    )
endfunction()







