#ifndef __CSIFW_H__
#define __CSIFW_H__

#include <sys/types.h>
#include "csifw/csifw_log.h"
#include "csifw/csifw_api.h"

#define CSIFW_CSI_HEADER_LEN 43
#define CSIFW_MAX_RAW_BUFF_LEN 1024
#define CSIFW_RB_SIZE CSIFW_MAX_RAW_BUFF_LEN * 5 /* RTK has queue of 5 data packets */
/* Can store 9 packets of 527 bytes csi data OR 32 packets of 155 bytes csi data */
typedef enum _COLLECT_STATE {
	CSI_STATE_UNITIALIZED = -1,			/* NOT INIT  */
	CSI_COLLECT_STATE_STARTED = 0,			/* START CSI_STATE_STARTED  */
	CSI_COLLECT_STATE_STOPPED = 1,			/* STOP CSI_STATE_STARTED  */
	CSI_STATE_INITIALIZED = 2			/* START CSI_STATE_STARTED  */
} COLLECT_STATE;

typedef enum CSI_DRIVER_CMD {
    SET_CSI_CONFIG = 1,
    DISABLE_CSI_CONFIG = 2,
    ENABLE_CSI_CONFIG = 3,
    REGISTER_CALLBACK = 4
} CSI_DRIVER_CMD;

typedef enum CONNECTION_STATE {
	WIFI_CONNECTED,
	WIFI_DISCONNECTED
} CONNECTION_STATE;

typedef void (*CSIDataListener)(CSIFW_RES res, int csi_buff_len, unsigned char *csi_buff, int csi_data_len);
typedef void (*network_status_listener)(CONNECTION_STATE state);

#endif	/* __CSIFW_H__ */

