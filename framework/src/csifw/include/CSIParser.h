#ifndef __CSI_PARSER_H__
#define __CSI_PARSER_H__
#include "csifw.h"

void logReceivedData(int csi_data_len, unsigned char *csi_buff, int accuracy);

/**
 * @brief Parses raw csi data.
 * It should be called before calling any other CSI service APIs.
 * 
 * @param[in] rawDatabuff Raw csi data buffer.
 * @param[in] raw_csi_buff_len Raw csi buffer length.
 * @param[in] config Configuration parameters for the CSI service..
 * @param[out] parsedDatabuff Parsed csi data buffer to save parsed data.
 * @param[out] parsed_csi_buff_len Parsed csi buffer length.
 *
 * @return
 */
void getParsedData(unsigned char *rawDatabuff, int raw_csi_buff_len, csi_action_param_t *config, float *parsedDatabuff, uint16_t *parsed_csi_buff_len);

#endif /* __CSI_PARSER_H__ */

