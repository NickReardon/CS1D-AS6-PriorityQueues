/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #6	: Priority Queues
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 24 / 20
 *****************************************************************************/
#include "main.h"
#include <queue>
using std::cout; using std::endl;


int main()
{

	/*
	 * HEADER OUTPUT
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/

	//std::priority_queue

	const int MAX_CARE_TIME = 25;

	ArrayMaxHeap<std::string, int> heap;
	heap.insert("Bob Bleeding", 5);
	heap.insert("Frank Feelingbad", 3);
	heap.insert("Cathy Coughing", 2);



	heap.insert("Paula Pain", 4);


	heap.insert("Alice Ailment", 7);
	heap.insert("Irene Ill", 1);
	heap.insert("Tom Temperature", 6);

	int timer = 0;
	int emergencyTimer = 0;
	bool emergency = false;


	heap.printAll(cout);

	AdmitPatient(heap, 0);
	for (int time = 0; time <= 500; time++)
	{
		if (!heap.empty())
		{


			switch (time)
			{
			case 74:
				InterruptPatient(heap, time, timer);
				heap.insert("Sam Sneezing", 1100);
				PriorityPatient(heap, time);
				emergency = true;
				break;

			case 181:
				heap.insert("Sid Sickly", 100);
				emergency = true;
				break;
			}

			if (emergency)
			{
				if (emergencyTimer == 25)
				{
					DischargePatient(heap, time);

					heap.remove();
					
					if (!heap.empty())
					{
						ResumePatient(heap, time, timer);
					}
					emergency = false;
				}


				if (emergency)
				{				
					emergencyTimer++;
				}
				else
				{
					emergencyTimer = 0;
				}
			}

			if (!emergency)
			{
				if (timer == 25)
				{
					timer = 0;

					DischargePatient(heap, time);

					heap.remove();
					if (!heap.empty())
					{
						AdmitPatient(heap, time);
					}
					

				}

				timer++;

			}
		}
	}



	system("pause");
	return 0;
}


std::string ConvertTime(int totalMinutes, int startHour, bool hours24Style)
{
	int minutes;
	int hours;
	std::string output = "";

	minutes = totalMinutes % 60;

	if (!hours24Style)
	{
		if (startHour = 12)
		{
			hours = totalMinutes / 60;
			if (hours == 0)
			{
				hours == 12;
			}
		}
		else
		{
			hours = startHour + (totalMinutes / 60);
		}
	}

	

	if ((ceil(log10(hours + 1)) == 2))
	{
		output += std::to_string(hours);
	}
	else
	{
		output += '0' + std::to_string(hours);
	}

	output += ":";

	if ((ceil(log10(minutes + 1)) == 2))
	{
		output += std::to_string(minutes);
	}
	else
	{
		output += '0' + std::to_string(minutes);
	}



	return output;

}


void DischargePatient(ArrayMaxHeap <std::string, int>& heap, int totalMinutes)
{
	
	cout << "Patient Discharge:" << endl
		<< "Name: " << heap.max() << endl
		<< "Care ended at " << ConvertTime(totalMinutes, 12, false)
		<< endl << endl;

	
}

void AdmitPatient(ArrayMaxHeap <std::string, int>& heap, int totalMinutes)
{

	cout << "Patient Admitted:" << endl
		<< "Name: " << heap.max() << endl
		<< "Care began at " << ConvertTime(totalMinutes, 12, false)
		<< endl << endl;
}

void InterruptPatient(ArrayMaxHeap <std::string, int>& heap, int totalMinutes, int currentTimer)
{

	cout << "Patient Care Interrupted:" << endl
		<< "Name: " << heap.max() << endl
		<< "Care interrupted at " << ConvertTime(totalMinutes, 12, false) << endl
		<< "Minutes in visit remaining: " << 25 - currentTimer
		<< endl << endl;
}

void ResumePatient(ArrayMaxHeap <std::string, int>& heap, int totalMinutes, int currentTimer)
{

	cout << "Patient Care Resumed:" << endl
		<< "Name: " << heap.max() << endl
		<< "Care resumed at " << ConvertTime(totalMinutes, 12, false) << endl
		<< "Minutes in visit remaining: " << 25 - currentTimer
		<< endl << endl;
}

void PriorityPatient(ArrayMaxHeap <std::string, int>& heap, int totalMinutes)
{

	cout << "High Priority Patient Recieved" << endl
		<< "Immediate attention administered:" << endl
		<< "Name: " << heap.max() << endl
		<< "Care began at " << ConvertTime(totalMinutes, 12, false)
		<< endl << endl;
}