/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #6	: Priority Queues
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 24 / 20
 *****************************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_

//Standard includes
#include <iostream>
#include <iomanip>
#include <string>
#include "PrintHeader.h"

//Program Specific
#include "ArrayHeap.h"

#endif // _HEADER_H_

std::string ConvertTime(int totalMinutes, int startHour, bool hours24Style = false);

void DischargePatient(ArrayMaxHeap<std::string, int>& heap, int totalMinutes);

void AdmitPatient(ArrayMaxHeap<std::string, int>& heap, int totalMinutes);

void InterruptPatient(ArrayMaxHeap<std::string, int>& heap, int totalMinutes, int currentTimer);

void ResumePatient(ArrayMaxHeap<std::string, int>& heap, int totalMinutes, int currentTimer);

void PriorityPatient(ArrayMaxHeap<std::string, int>& heap, int totalMinutes);
