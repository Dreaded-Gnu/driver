
AC_DEFUN([BOLTHUR_DRIVER_SET_HOST], [
  # General define templates
  case "${host_cpu}" in
  arm)
    # Add sysroot to path
    AC_SUBST(PATH, "/opt/bolthur/sysroot/arm/bin:${PATH}")

    case "${DEVICE}" in
    rpi2_b_rev1)
      CFLAGS="${CFLAGS} -march=armv7-a -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard"
      ;;
    rpi_zero_w)
      CFLAGS="${CFLAGS} -march=armv6zk -mtune=arm1176jzf-s -mfpu=vfpv2 -mfloat-abi=hard"
      ;;
    rpi3_b)
      CFLAGS="${CFLAGS} -march=armv8-a -mtune=cortex-a53 -mfpu=neon-vfpv4 -mfloat-abi=hard"
      ;;
    *)
      AC_MSG_ERROR([unsupported host platform])
      ;;
    esac
    ;;
  aarch64)
    # Add sysroot to path
    AC_SUBST(PATH, "/opt/bolthur/sysroot/aarch64/bin:${PATH}")

    case "${DEVICE}" in
    rpi3_b)
      CFLAGS="${CFLAGS} -march=armv8-a -mtune=cortex-a53"
      ;;
    *)
      AC_MSG_ERROR([unsupported host platform])
      ;;
    esac
    ;;
  *)
    AC_MSG_ERROR([unsupported host CPU])
    ;;
  esac
])
