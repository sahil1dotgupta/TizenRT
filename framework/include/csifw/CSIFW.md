# HOW TO USE CSIFW

## Asssumptions
- WIFI manager initialized at bootup (by set_app_main)

## Sequence

Application (Presence detection) will call CSI APIs in following sequence

- Application should provide the buffer of requested length when requested by framework with `get_empty_data_buffer()` callback.
- Implement the callbacks:
    1. `get_empty_data_buffer(BUF_TYPE buftype, void **buffptr, int data_size)`
    2. `upd_raw_data_listener(CSIFW_RES status, int csi_data_len, unsigned char *csi_raw_buff)`
    3. `upd_parsed_data_listener(CSIFW_RES status, int csi_data_len, float *csi_parsed_buff)`

### Functions to call
- call `csi_service_init(get_empty_data_buffer get_buf_cb, upd_raw_data_listener raw_callback, upd_parsed_data_listener parsed_callback, unsigned int interval)`
- call `csi_service_set_config(int acc)`
- call `csi_service_start()`
- call `csi_service_pause()`
- call `csi_service_resume()`
- call `csi_service_stop()`
- call `csi_service_deinit()`

### Optional calls
- call `csi_set_data_collect_interval(unsigned int interval)`