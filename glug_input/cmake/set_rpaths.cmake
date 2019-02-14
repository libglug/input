# add $ORIGIN to the rpaths for the target
function (set_rpaths TARGET)
    set_target_properties(
        ${TARGET}
        PROPERTIES
            INSTALL_RPATH "$ORIGIN"
            BUILD_WITH_INSTALL_RPATH TRUE
    )
endfunction()
