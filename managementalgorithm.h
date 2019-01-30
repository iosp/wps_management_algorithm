#ifndef MANAGEMENTALGORITHM_H
#define MANAGEMENTALGORITHM_H

#pragma once
#include "managementalgorithm_global.h"
#include "../AlgorithmSubSystem/wpstypes.h"
#include "../AlgorithmSubSystem/algorithmsubsystem.h"


//class AlgorithmSubSystem;

class MANAGEMENTALGORITHMSHARED_EXPORT ManagementAlgorithm
{

private:
    AlgorithmSubSystem* m_alg_ptr;
    int m_thread_id;
    void readPlatformLocation();
public:
    ManagementAlgorithm();
    ManagementAlgorithm(const ManagementAlgorithm &old_obj);

public:
    int Cons_InitiateSensorLocationReporting(Region_Of_Mission rom);
    int Cons_StopSensorLocationReporting();
    int ProcessSensorLocUpdate(Calculated_Sensor_Geo_Loc_Orient);

    bool LoadOrthophoto(Region_Of_Mission);
    bool LoadWPSModel(Region_Of_Mission);
    int Cons_PrepareForModelConstruction(Region_Of_Mission, int required_model_quality);
    void ProcessNotification(AlgNotificationTypes);
    CloudQueryAnswer QueryCloud(CloudQuery, Region_Of_Mission);
    int Cons_StopModelConstruction();
    int StopUdatingLoc();
    int Al_StoreWPS_ModelData(CloudDataExchangeSpecification);
    //int Al_UpdateSensorLocOrient(Platform_Location_Info);
    int Al_UploadWPSData(CloudDataExchangeSpecification);
};



//#define Region_Of_Mission int
//#define CloudDataExchangeSpecification int
//#define Platform_Location_Info int

//enum AlgNotificationTypes {
//    AlgNull=0,
//    AlgModReadyForConstruction=1,
//    AlgModStartedForConstruction,
//    AlgModConstructionComplete,
//    MM_FinishedDownloadingCloudModel,
//    MM_FinishedDownloadingOrthoPhoto,
//    AlgModuleStoppedLocationReporting

//};


#endif // MANAGEMENTALGORITHM_H
