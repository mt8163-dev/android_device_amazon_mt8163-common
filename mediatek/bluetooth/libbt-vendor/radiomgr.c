/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2014. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */


#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#include "bt_mtk.h"


/**************************************************************************
 *                  G L O B A L   V A R I A B L E S                       *
***************************************************************************/

extern BT_INIT_VAR_T btinit[1];
extern BT_INIT_CB_T btinit_ctrl;

/**************************************************************************
 *                          F U N C T I O N S                             *
***************************************************************************/

extern VOID *GORM_FW_Init_Thread(VOID *ptr);
extern VOID *GORM_SCO_Init_Thread(VOID *ptr);
extern VOID thread_exit(INT32 signo);


BOOL BT_InitDevice(
    UINT32  chipId,
    PUCHAR  pucNvRamData,
    UINT32  u4Baud,
    UINT32  u4HostBaud,
    UINT32  u4FlowControl,
    SETUP_UART_PARAM_T setup_uart_param
    )
{
    LOG_DBG("BT_InitDevice\n");

    memset(btinit, 0, sizeof(BT_INIT_VAR_T));
    btinit_ctrl.worker_thread_running = FALSE;

    btinit->chip_id = chipId;
    /* Copy configuration data */
    memcpy(btinit->bt_nvram.raw, pucNvRamData, sizeof(ap_nvram_btradio_struct));
    /* Save init variables, which are used on standalone chip */
    btinit->bt_baud = u4Baud;
    btinit->host_baud = u4HostBaud;
    btinit->flow_ctrl = u4FlowControl;
    btinit->host_uart_cback = setup_uart_param;

    if (SIG_ERR == signal(SIGRTMIN, thread_exit)) {
        LOG_ERR("Register signal handler fails errno(%d)\n", errno);
    }

    if (pthread_create(&btinit_ctrl.worker_thread, NULL, \
          GORM_FW_Init_Thread, NULL) != 0) {
        LOG_ERR("Create FW init thread fails\n");
        return FALSE;
    }
    else {
        btinit_ctrl.worker_thread_running = TRUE;
        return TRUE;
    }
}

BOOL BT_InitSCO(VOID)
{
    LOG_DBG("BT_InitSCO\n");

    if (pthread_create(&btinit_ctrl.worker_thread, NULL, \
          GORM_SCO_Init_Thread, NULL) != 0) {
        LOG_ERR("Create SCO init thread fails\n");
        return FALSE;
    }
    else {
        btinit_ctrl.worker_thread_running = TRUE;
        return TRUE;
    }
}

BOOL BT_DeinitDevice(VOID)
{
    LOG_DBG("BT_DeinitDevice\n");
    /* Do nothing on combo chip */
    return TRUE;
}

VOID BT_Cleanup(VOID)
{
    /* Cancel any remaining running thread */
    if (btinit_ctrl.worker_thread_running) {
        pthread_kill(btinit_ctrl.worker_thread, SIGRTMIN);
        /* Wait until thread exit */
        pthread_join(btinit_ctrl.worker_thread, NULL);
        btinit_ctrl.worker_thread_running = FALSE;
    }
    if (SIG_ERR == signal(SIGRTMIN, SIG_DFL)) {
        LOG_ERR("Restore signal handler fails errno(%d)\n", errno);
    }
    return;
}