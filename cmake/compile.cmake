function (set_compilation_props SOURCES_LIST OS)
    if (NOT DEFINED ${OS})
        # disable source compilation

        foreach(FILE ${SOURCES_LIST})
            set_source_files_properties(${FILE} PROPERTIES HEADER_FILE_ONLY TRUE)
        endforeach()

    endif()

endfunction()

