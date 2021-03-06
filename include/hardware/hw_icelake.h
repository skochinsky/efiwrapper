/*
 * Copyright (c) 2017, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer
 *      in the documentation and/or other materials provided with the
 *      distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __HW_ICELAKE__
#define __HW_ICELAKE__

#include "hw_pci_uart.h"

/* PCI device id of OTG */
#define XDCI_PID         0x9D30
#define XHCI_PID         0x9D2F

/* PCI device id of EMMC controller */
#define EMMC_DEVICEID    0x34C4

/* UFS */
#define UFS_PCI_DID    0x34FA

/* serial port base address */
#ifndef EFIWRAPPER_USE_EC_UART
#define ICL_PCI_EXPRESS_BASE_ADDR                     0xC0000000
#define ICL_PCI_FUNCTION_NUMBER_PCH_SERIAL_IO_UART2   2
#define ICL_DEFAULT_UART_BASEADDR                     0x8334D000
static inline uint32_t IclGetPciUartBase(void)
{
    uint32_t base;

    base = GetPciUartBase(ICL_PCI_EXPRESS_BASE_ADDR, ICL_PCI_FUNCTION_NUMBER_PCH_SERIAL_IO_UART2);
    if (base == 0)
        base = ICL_DEFAULT_UART_BASEADDR;

    return base;
}

#define SERIAL_BASEADDR  IclGetPciUartBase()
#define HW_SERIAL_TYPE        CB_SERIAL_TYPE_MEMORY_MAPPED
#define HW_SERIAL_REG_WIDTH   4

#else /* EFIWRAPPER_USE_EC_UART */

#define SERIAL_BASEADDR       0x3f8
#define HW_SERIAL_TYPE        CB_SERIAL_TYPE_IO_MAPPED
#define HW_SERIAL_REG_WIDTH   1

#endif /* EFIWRAPPER_USE_EC_UART */

#endif /* __HW_ICELAKE__ */

