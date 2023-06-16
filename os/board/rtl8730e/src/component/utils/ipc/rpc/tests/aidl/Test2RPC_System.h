/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _TEST2RPC_SYSTEM_H_RPCGEN
#define _TEST2RPC_SYSTEM_H_RPCGEN

#include "rpc_struct.h"

#include "Test2RPC_System_data.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <RPCBaseDS.h>
#include <Test2RPCBaseDS.h>

#define TEST2_SYSTEM 3001
#define VERSION 0

struct REG_STRUCT *TEST2_SYSTEM_0_register(struct REG_STRUCT *rnode);
#define TEST2_RPC_ToAgent_Init 1
extern  TEST2_RPCRES_INIT *TEST2_RPC_ToAgent_Init_0(TEST2_RPC_MIC_DATA *, CLNT_STRUCT *);
extern  TEST2_RPCRES_INIT *TEST2_RPC_ToAgent_Init_0_svc(TEST2_RPC_MIC_DATA *, RPC_STRUCT *, TEST2_RPCRES_INIT *);
extern  TEST2_RPCRES_INIT *(*p_TEST2_RPC_ToAgent_Init_0_svc)(TEST2_RPC_MIC_DATA *, RPC_STRUCT *, TEST2_RPCRES_INIT *);
#define TEST2_RPC_ToAgent_Release 2
extern  HRESULT *TEST2_RPC_ToAgent_Release_0(TEST2_RPC_INSTANCE *, CLNT_STRUCT *);
extern  HRESULT *TEST2_RPC_ToAgent_Release_0_svc(TEST2_RPC_INSTANCE *, RPC_STRUCT *, HRESULT *);
extern  HRESULT *(*p_TEST2_RPC_ToAgent_Release_0_svc)(TEST2_RPC_INSTANCE *, RPC_STRUCT *, HRESULT *);
#define TEST2_RPC_ToAgent_Streaming_Process 3
extern  HRESULT *TEST2_RPC_ToAgent_Streaming_Process_0(TEST2_RPC_INSTANCE *, CLNT_STRUCT *);
extern  HRESULT *TEST2_RPC_ToAgent_Streaming_Process_0_svc(TEST2_RPC_INSTANCE *, RPC_STRUCT *, HRESULT *);
extern  HRESULT *(*p_TEST2_RPC_ToAgent_Streaming_Process_0_svc)(TEST2_RPC_INSTANCE *, RPC_STRUCT *, HRESULT *);
#define TEST2_RPC_ToAgent_Recognizer_Process 4
extern  HRESULT *TEST2_RPC_ToAgent_Recognizer_Process_0(TEST2_RPC_INSTANCE *, CLNT_STRUCT *);
extern  HRESULT *TEST2_RPC_ToAgent_Recognizer_Process_0_svc(TEST2_RPC_INSTANCE *, RPC_STRUCT *, HRESULT *);
extern  HRESULT *(*p_TEST2_RPC_ToAgent_Recognizer_Process_0_svc)(TEST2_RPC_INSTANCE *, RPC_STRUCT *, HRESULT *);
#define TEST2_RPC_ToAgent_Sync_Mic_Data 5
extern  HRESULT *TEST2_RPC_ToAgent_Sync_Mic_Data_0(TEST2_RPC_MIC_DATA *, CLNT_STRUCT *);
extern  HRESULT *TEST2_RPC_ToAgent_Sync_Mic_Data_0_svc(TEST2_RPC_MIC_DATA *, RPC_STRUCT *, HRESULT *);
extern  HRESULT *(*p_TEST2_RPC_ToAgent_Sync_Mic_Data_0_svc)(TEST2_RPC_MIC_DATA *, RPC_STRUCT *, HRESULT *);

#ifdef __cplusplus
}
#endif

#endif /* !_TEST2RPC_SYSTEM_H_RPCGEN */