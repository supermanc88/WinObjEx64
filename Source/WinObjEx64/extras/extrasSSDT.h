/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2015 - 2019
*
*  TITLE:       EXTRASSSDT.H
*
*  VERSION:     1.81
*
*  DATE:        18 Oct 2019
*
*  Common header file for Service Table dialog.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/
#pragma once

typedef struct _SERVICETABLEENTRY {
    ULONG ServiceId;
    ULONG_PTR Address;
    WCHAR Name[MAX_PATH + 1];
} SERVICETABLEENTRY, *PSERVICETABLEENTRY;

extern PSERVICETABLEENTRY g_pSDT;
extern PSERVICETABLEENTRY g_pSDTShadow;

typedef enum _SSDT_DLG_MODE {
    SST_Ntos = 0,
    SST_Win32k = 1,
    SST_Max
} SSDT_DLG_MODE;

typedef struct _W32K_API_SET_TABLE_HOST {
    PWCHAR HostName;
    PCHAR TableName;
    PCHAR TableSizeName;
    ULONG HostEntriesCount;
} W32K_API_SET_TABLE_HOST, *PW32K_API_SET_TABLE_HOST;

typedef struct _W32K_API_SET_TABLE_ENTRY {
    PVOID HostEntriesArray;
    W32K_API_SET_TABLE_HOST *Host;
} W32K_API_SET_TABLE_ENTRY, *PW32K_API_SET_TABLE_ENTRY;

VOID extrasCreateSSDTDialog(
    _In_ HWND hwndParent,
    _In_ SSDT_DLG_MODE Mode);
