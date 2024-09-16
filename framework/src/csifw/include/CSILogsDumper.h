#ifndef __CSI_LOGS_DUMPER__
#define __CSI_LOGS_DUMPER__

#include "csifw.h"

#ifdef CONFIG_CSI_DATA_DUMP_OVER_NETWORK
#define CSI_DUMP_DATA_QUEUE_NAME "/dev/csidump_data"

typedef enum EVENT {
	STOP_DUMP,
	START_DUMP
} EVENT;

CSIFW_RES csi_logs_dumper_init();
CSIFW_RES csi_logs_dumper_deinit();

typedef void (*csiDataDumpListener)(EVENT event);
void set_event_listener(csiDataDumpListener listener);
#endif

#endif  /* __CSI_LOGS_DUMPER__ */
