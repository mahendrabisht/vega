ADD_LIBRARY(backup_file SHARED backup_file.c)

INSTALL(TARGETS backup_file LIBRARY DESTINATION lib/vega-ppp)

