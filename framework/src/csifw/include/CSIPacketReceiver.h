#ifndef __CSI_PACKET_RECEIVER_H__
#define __CSI_PACKET_RECEIVER_H__

#include "csifw.h"
#include "rb.h"

CSIFW_RES csi_packet_receiver_init(CSIDataListener CSIDataCallback);
CSIFW_RES csi_packet_receiver_get_mac_addr(csifw_mac_info *mac_info);
CSIFW_RES csi_packet_receiver_start_collect(csi_action_param_t *config);
CSIFW_RES csi_packet_receiver_pause_collect(csi_action_param_t *config);
CSIFW_RES csi_packet_receiver_stop_collect(CSIFW_REASON reason, csi_action_param_t *config);
CSIFW_RES csi_packet_receiver_deinit();

#endif /* __CSI_PACKET_RECEIVER_H__ */

