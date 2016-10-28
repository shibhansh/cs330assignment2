// stats.h 
//	Routines for managing statistics about Nachos performance.
//
// DO NOT CHANGE -- these stats are maintained by the machine emulation.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "utility.h"
#include "stats.h"
#include "system.h"

//----------------------------------------------------------------------
// Statistics::Statistics
// 	Initialize performance metrics to zero, at system startup.
//----------------------------------------------------------------------

Statistics::Statistics()
{
    totalTicks = idleTicks = systemTicks = userTicks = 0;
    numDiskReads = numDiskWrites = 0;
    numConsoleCharsRead = numConsoleCharsWritten = 0;
    numPageFaults = numPacketsSent = numPacketsRecvd = 0;
}

//----------------------------------------------------------------------
// Statistics::Print
// 	Print performance metrics, when we've finished everything
//	at system shutdown.
//----------------------------------------------------------------------

void
Statistics::Print()
{
    printf("Total threads = %d\n",thread_count );
    printf("Total CPU Busy Time = %d\n", total_burst );
    printf("Total CPU Execution Time = %d\n", totalTicks - system_start_time);
    printf("CPU Utilisation = %d\n",((total_burst)*100)/(totalTicks - system_start_time) );
    printf("Max Burst = %d\n", total_max_burst);
    printf("Min Burst = %d\n", total_min_burst);
    printf("Average Burst = %d\n", total_burst/total_burst_count);
    printf("Total Nummber of burst = %d\n",total_burst_count );
    printf("Average Ready Queue Wait Time = %d\n", total_ready_queue_waittime/thread_count );
    printf("Average Thread Completion Time = %d\n", total_thread_time/thread_count);
    printf("Max Thread Completion Time = %d\n",total_max_thread_time);
    printf("Min Thread Completion Time = %d\n", total_min_thread_time);


    printf("Ticks: total %d, idle %d, system %d, user %d\n", totalTicks, 
	idleTicks, systemTicks, userTicks);
    printf("Disk I/O: reads %d, writes %d\n", numDiskReads, numDiskWrites);
    printf("Console I/O: reads %d, writes %d\n", numConsoleCharsRead, 
	numConsoleCharsWritten);
    printf("Paging: faults %d\n", numPageFaults);
    printf("Network I/O: packets received %d, sent %d\n", numPacketsRecvd, 
	numPacketsSent);
}
