/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email      : vkapadia3@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu (hub) for application
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        //case 4:
        //    removeAppointment(data->appointments, data->maxAppointments,
        //                      data->patients, data->maxPatient);  // ToDo: You will need to create this function!
        //    suspend();
        //    break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0, flag = 0;

    displayPatientTableHeader();
    for (i = 0;i < max;i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            flag = 1;
        }
    }
    putchar('\n');
    if (flag == 0)
    {
        printf("*** No records found ***\n");
    }
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)

void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        printf("\n");
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();
            break;
        }
    } while (selection != 0);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)

void addPatient(struct Patient patient[], int max)
{
    int i, index, flag = 0, number, cnt = 0;
    for (i = 0;i < max;i++)
    {
        if (patient[i].patientNumber == 0)
        {
            if (cnt < 1)
            {
                flag = 1;
                index = i;
                cnt++;
            }
        }
    }
    if (flag == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        number = nextPatientNumber(patient, max);
        patient[index].patientNumber = number;
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }

}

// Edit a patient record from the patient array
// (Copy your code from MS#2)

void editPatient(struct Patient patient[], int max)
{
    int searchnumber, index = -1;


    printf("Enter the patient number: ");
    searchnumber = inputIntPositive();

    index = findPatientIndexByPatientNum(searchnumber, patient, max);

    if (index >= 0)
    {
        putchar('\n');
        menuPatientEdit(&patient[index]);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }

}

// Remove a patient record from the patient array
// (Copy your code from MS#2)

void removePatient(struct Patient patient[], int max)
{
    int removenumber, index = -1;
    char confirmation;
    printf("Enter the patient number: ");
    removenumber = inputIntPositive();
    index = findPatientIndexByPatientNum(removenumber, patient, max);
    putchar('\n');
    if (index >= 0)
    {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        scanf("%c", &confirmation);
        clearInputBuffer();
        if (confirmation == 'y')
        {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:

void viewAllAppointments(const struct ClinicData data[])
{
    int i, flag = 0;

    displayScheduleTableHeader(&data->appointments->date, 1);

    for (i = 0;i < 50;i++)
    {
        if (data[i].patients->patientNumber == data[i].appointments->patient.patientNumber)
        {
            displayScheduleData(&data[i].patients,&data[i].appointments, 1);
            flag = 1;
        }
    }
    putchar('\n');
    if (flag == 0)
    {
        printf("*** No records found ***\n");
    }
}

// View appointment schedule for the user input date
// Todo:

void viewAppointmentSchedule(const struct ClinicData data[])
{
    int yr = 0, mnth = 0, days = 0;
    int i, cnt = 0, index = 0;

    printf("Year        : ");
    yr = inputIntPositive();
    printf("Month (1-%d): ",MAX_MONTHS);
    mnth = inputIntRange(1, MAX_MONTHS);
    if ((yr % 4 == 0) && (mnth == 2))
    {
        printf("Day (1-%d)  : ", MAX_DAYS_FEB_LEAP);
        days = inputIntRange(1, MAX_DAYS_FEB_LEAP);
    }
    if ((yr % 4 != 0) && (mnth == 2))
    {
        printf("Day (1-%d)  : ", MAX_DAYS_FEB);
        days = inputIntRange(1, MAX_DAYS_FEB);
    }
    if (mnth == 1 || mnth == 3 || mnth == 5 || mnth == 7 || mnth == 8 || mnth == 10 || mnth == 12)
    {
        printf("Day (1-%d)  : ", MAX_DAYS31);
        days = inputIntRange(1, MAX_DAYS31);
    }
    if (mnth == 4 || mnth == 6 || mnth == 9 || mnth == 11)
    {
        printf("Day (1-%d)  : ", MAX_DAYS30);
        days = inputIntRange(1, MAX_DAYS30);
    }

    putchar('\n');

    for (i = 0;i < 50;i++)
    {
        if (data[i].appointments ->date.day==days && data[i].appointments->date.month==mnth && data[i].appointments->date.year==yr)
        {
            index==i;
            cnt++;
        }
    }
    if (cnt == 1)
    {
        displayScheduleTableHeader(&data[index].appointments->date, 0);
        displayScheduleData(&data[i].patients, &data[i].appointments, 0);
    }
    else if (cnt > 1)
    {
        displayScheduleTableHeader(&data[index].appointments->date, 0);
        for (i = 0;i < 50;i++)
        {
            if (data[i].appointments->date.day == days && data[i].appointments->date.month == mnth && data[i].appointments->date.year == yr)
            {
                displayScheduleData(&data[i].patients, &data[i].appointments, 0);
            }
        }
    }
    else
    {
        printf("*** No records found ***\n");
    }
    clearInputBuffer();
}

// Add an appointment record to the appointment array
// Todo:

void addAppointment(struct Appointment appoint[], int maxappoint, struct Patient patient[],int maxpatient)
{
    int patientnum, i,index, flag = 0, yr, mnth, days, hr, mins;

    do
    {
        printf("Patient Number: ");
        patientnum = inputIntPositive();
        for (i = 0;i < maxpatient;i++)
        {
            if ((patientnum == patient[i].patientNumber))//change for zero
            {
                flag = 1;
                index = i;
            }
        }
        if (flag == 0)
        {
            printf("*** No records found ***\n");
        }
    } while (flag == 0);

    printf("Year        : ");
    yr = inputIntPositive();
    printf("Month (1-%d): ", MAX_MONTHS);
    mnth = inputIntRange(1, MAX_MONTHS);
    if ((yr % 4 == 0) && (mnth == 2))
    {
        printf("Day (1-%d)  : ", MAX_DAYS_FEB_LEAP);
        days = inputIntRange(1, MAX_DAYS_FEB_LEAP);
    }
    if ((yr % 4 != 0) && (mnth == 2))
    {
        printf("Day (1-%d)  : ", MAX_DAYS_FEB);
        days = inputIntRange(1, MAX_DAYS_FEB);
    }
    if (mnth == 1 || mnth == 3 || mnth == 5 || mnth == 7 || mnth == 8 || mnth == 10 || mnth == 12)
    {
        printf("Day (1-%d)  : ", MAX_DAYS31);
        days = inputIntRange(1, MAX_DAYS31);
    }
    if (mnth == 4 || mnth == 6 || mnth == 9 || mnth == 11)
    {
        printf("Day (1-%d)  : ", MAX_DAYS30);
        days = inputIntRange(1, MAX_DAYS30);
    }
    do
    {
        flag = 0;
        printf("Hour (0-23)  : ");
        hr = inputIntPositive();
        printf("Minute (0=59): ");
        mins = inputIntPositive();
        if (hr<APPOINT_START && hr>APPOINT_END && (mins % INTERVALS == 0))
        {
            flag = 1;
        }
        if (hr == APPOINT_END && mins > 0)
        {
            flag = 1;
        }
    } while (flag == 1);
    appoint[index].date.year = yr;
    appoint[index].date.month = mnth;
    appoint[index].date.day = days;
    appoint[index].time.hour = hr;
    appoint[index].time.min = mins;
    
}

// Remove an appointment record from the appointment array
// Todo:



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int number, index = -1;
    printf("Search by patient number: ");
    number = inputIntPositive();
    putchar('\n');
    index = findPatientIndexByPatientNum(number, patient, max);
    if (index >= 0)
    {
        displayPatientData(&patient[index], FMT_FORM);
    }
    else
    {
        printf("*** No records found ***\n");
    }
}


// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)

void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char findnumber[PHONE_LEN] = { '\0' };
    int i, index, cnt = 0;
    printf("Search by phone number: ");
    scanf("%s", findnumber);
    clearInputBuffer();
    for (i = 0;i < max;i++)
    {
        if (strcmp(findnumber, patient[i].phone.number) == 0)
        {
            index = i;
            cnt++;
        }
    }
    if (cnt == 1)
    {
        printf("\n");
        displayPatientTableHeader();
        displayPatientData(&patient[index], FMT_TABLE);
    }
    else if (cnt > 1)
    {
        printf("\n");
        displayPatientTableHeader();
        for (i = 0;i < max;i++)
        {
            if (strcmp(findnumber, patient[i].phone.number) == 0)
            {
                displayPatientData(&patient[i], FMT_TABLE);
            }
        }
    }
    else
    {
        printf("\n");
        displayPatientTableHeader();
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
// (Copy your code from MS#2)

int nextPatientNumber(const struct Patient patient[], int max)
{
    int next = patient[0].patientNumber;
    int i;
    for (i = 0;i < max;i++)
    {
        if (patient[i].patientNumber > next)
        {
            next = patient[i].patientNumber;
        }
    }
    next = next + 1;
    return next;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int index = -1, i;
    for (i = 0;i < max;i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            index = i;
        }
    }
    return index;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: 0%d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)

void inputPhoneData(struct Phone* phone)
{
    int selection;
    char number[PHONE_LEN] = { '\0' };
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    selection = inputIntRange(1, 4);
    putchar('\n');
    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        printf("Contact: %s\n", phone->description);
        break;

    case 2:
        strcpy(phone->description, "HOME");
        printf("Contact: %s\n", phone->description);
        break;

    case 3:
        strcpy(phone->description, "WORK");
        printf("Contact: %s\n", phone->description);
        break;
    case 4:
        strcpy(phone->description, "TBD");
        *phone->number = 0;
        break;
    }
    if (selection == 1 || selection == 2 || selection == 3)
    {
        printf("Number : ");
        inputCString(number, 1, PHONE_LEN);
        strcpy(phone->number, number);
        putchar('\n');
    }
}

//void inputDate(struct Clinic* data)
//{
//    int yr = 0, mnth = 0, days = 0;
//    int i, cnt = 0, index = 0;
//
//    printf("Year        : ");
//    yr = inputIntPositive();
//    printf("Month (1-%d): ", MAX_MONTHS);
//    mnth = inputIntRange(1, MAX_MONTHS);
//    if ((yr % 4 == 0) && (mnth == 2))
//    {
//        printf("Day (1-%d)  : ", MAX_DAYS_FEB_LEAP);
//        days = inputIntRange(1, MAX_DAYS_FEB_LEAP);
//    }
//    if ((yr % 4 != 0) && (mnth == 2))
//    {
//        printf("Day (1-%d)  : ", MAX_DAYS_FEB);
//        days = inputIntRange(1, MAX_DAYS_FEB);
//    }
//    if (mnth == 1 || mnth == 3 || mnth == 5 || mnth == 7 || mnth == 8 || mnth == 10 || mnth == 12)
//    {
//        printf("Day (1-%d)  : ", MAX_DAYS31);
//        days = inputIntRange(1, MAX_DAYS31);
//    }
//    if (mnth == 4 || mnth == 6 || mnth == 9 || mnth == 11)
//    {
//        printf("Day (1-%d)  : ", MAX_DAYS30);
//        days = inputIntRange(1, MAX_DAYS30);
//    }
//    //return (days - mnth - yr);
//}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:

int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int countpatients = 0;
    struct Patient patient[] = {{0}};

    FILE* fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        while ((countpatients < max) && fscanf(fp, "%d|%[^|]*c|%[^|]*c|%[^\n]*c\n", &patient[countpatients].patientNumber, patient[countpatients].name, patient[countpatients].phone.description, patient[countpatients].phone.number) != EOF);
        {
            patients[countpatients] = patient[countpatients];
            countpatients++;
        }
        fclose(fp);
        fp = NULL;
    }
    else
    {
        printf("Unable to open %s file!\n\n", datafile);
    }
    return countpatients;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:

int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int countappoint = 0;
    struct Appointment appoint[] = {{0}};

    FILE* fp1 = fopen(datafile, "r");

    if (fp1 != NULL)
    {
        while ((countappoint < max) && fscanf(fp1, "%05d,%4d,%d,%d,%d,%d[^\n]\n", &appoint[countappoint].patient, &appoint[countappoint].date.year, &appoint[countappoint].date.month, &appoint[countappoint].date.day, &appoint[countappoint].time.hour, &appoint[countappoint].time.min) != EOF)
        {
            appoints[countappoint] = appoint[countappoint];
            countappoint++;
        }
        fclose(fp1);
        fp1 = NULL;
    }
    else
    {
        printf("Unable to open %s file!\n\n", datafile);
    }
    return countappoint;
}

//int importPatients(const char* datafile, struct Patient patients[], int max)
//{
//    FILE* fp;
//    int patientNum = 0, ch, count = 0;
//    char patname[NAME_LEN];
//    // char desc[30];
//    char desc[PHONE_DESC_LEN + 1];
//    char phone[PHONE_LEN + 1];
//    //char phone[30];
//
//
//
//    fp = fopen(datafile, "r");
//
//    while (!feof(fp) && count < max)
//    {
//
//        fscanf(fp, "%d", &patientNum);
//        ch = fgetc(fp);
//        patients[count].patientNumber = patientNum;
//        //  printf("%d\n", patients[count].patientNumber);
//
//        fscanf(fp, "%[^|]s%*c", patname);
//        ch = fgetc(fp);
//        strcpy(patients[count].name, patname);
//        // printf("%s\n", patients[count].name);
//
//
//        fscanf(fp, "%[^|]s%*c", desc);
//        ch = fgetc(fp);
//        strcpy(patients[count].phone.description, desc);
//        // printf("%s\n", patients[count].phone.description);
//
//        fscanf(fp, "%[^|\n]s%*c", phone);
//        ch = fgetc(fp);
//        strcpy(patients[count].phone.number, phone);
//        //printf("%s\n", patients[count].phone.number);
//
//
//        count = count + 1;
//        //printf("Count:: %d\n\n",count);
//
//
//       // ch = fgetc(fp);
//
//        phone[0] = '\0';
//
//
//    }
//
//    fclose(fp);
//
//    return count;
//}
//
//int importAppointments(const char* datafile, struct Appointment appoints[], int max)
//{
//    int patientNum = -1, year = 0, month = 0, day = 0, min = 0, hour = 0;
//    int i = 0, count = -1, ch;
//
//    FILE* fp;
//    fp = fopen(datafile, "r");
//
//    while (!feof(fp) && count < max)
//    {
//
//        fscanf(fp, "%d", &patientNum);
//        ch = fgetc(fp);
//        appoints[count].patientnum.patientNumber = patientNum;
//        //printf("%d\n", appoints[count].patientNumber);
//
//        fscanf(fp, "%d", &year);
//        ch = fgetc(fp);
//        appoints[count].date.year = year;
//        //printf("%d\n", appoints[count].date.year);
//
//        fscanf(fp, "%d", &month);
//        ch = fgetc(fp);
//        appoints[count].date.month = month;
//        // printf("%d\n", appoints[count].date.month);
//
//        fscanf(fp, "%d", &day);
//        ch = fgetc(fp);
//        appoints[count].date.day = day;
//        // printf("%d\n", appoints[count].date.day);
//
//        fscanf(fp, "%d", &hour);
//        ch = fgetc(fp);
//        appoints[count].time.hour = hour;
//        //printf("%d\n", appoints[count].time.hour);
//
//        fscanf(fp, "%d", &min);
//        ch = fgetc(fp);
//        appoints[count].time.min = min;
//        // printf("%d\n\n", appoints[count].time.min);
//
//
//        count = count + 1;
//    }
//    return count;
//}