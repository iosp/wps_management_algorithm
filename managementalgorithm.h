#ifndef MANAGEMENTALGORITHM_H
#define MANAGEMENTALGORITHM_H

#pragma once
#include "managementalgorithm_global.h"
#include "../AlgorithmSubSystem/wpstypes.h"
#include "../AlgorithmSubSystem/algorithmsubsystem.h"


class AlgorithmSubSystem;

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
    int Cons_InitiateSensorLocationReporting(Region_Of_Mission rom, int frequency);
    int Cons_StopSensorLocationReporting();
    int Cons_StopModelConstruction();
    int Cons_PrepareForModelConstruction(Region_Of_Mission, int required_model_quality);

    int ProcessSensorLocUpdate(Calculated_Sensor_Geo_Loc_Orient);
    int UploadWPSData(Tile);
    void ProcessNotification(AlgBuildingNotificationTypes);
    int StopUdatingLocation();
    bool LoadOrthophoto(Region_Of_Mission);
    bool LoadWPSModel(Region_Of_Mission);
    DateAndTime QueryRoMLastDateAndTime(Region_Of_Mission);

};






#endif // MANAGEMENTALGORITHM_H
