#include <thread>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "managementalgorithm.h"

#ifdef CODE
#endif

ManagementAlgorithm::ManagementAlgorithm()
{
    //Create AlgorithmSubSystem
    m_alg_ptr = new AlgorithmSubSystem(this);
    m_thread_id=0;
}

ManagementAlgorithm::ManagementAlgorithm(const ManagementAlgorithm &old_obj)
{
     m_alg_ptr=old_obj.m_alg_ptr;
     m_thread_id=old_obj.m_thread_id;

}

int ManagementAlgorithm::Cons_InitiateSensorLocationReporting(Region_Of_Mission rom)
{
    int ret;
    //Call algorithm module
    ret = m_alg_ptr->InitiateSensorLocationReporting(rom);
    return ret;
}

int ManagementAlgorithm::Cons_StopSensorLocationReporting()
{
    int ret;
    //Call algorithm module
    ret = m_alg_ptr->StopSensorLocationReporting();
    return ret;

}

int ManagementAlgorithm::ProcessSensorLocUpdate(Calculated_Sensor_Geo_Loc_Orient geo_loc_orient)
{
    //Propagate data to whom is interested
}

int ManagementAlgorithm::Cons_PrepareForModelConstruction(Region_Of_Mission rom, int required_model_quality)
{
    int ret;
    //Call algorithm module
    ret = m_alg_ptr->PrepareForModelConstruction(rom,required_model_quality);
    return ret;
}

int ManagementAlgorithm::Cons_StopModelConstruction()
{
    int ret;
    //Call algorithm module
    ret = m_alg_ptr->StopModelConstruction();
    return ret;

}

void ManagementAlgorithm::readPlatformLocation()
{
    //open thread according aggreed frequency and get platform sensor values
    //Pseudo code
    int thread_id;
    Platform_Location_Info location_info=0;

    thread_id=1001;
    m_thread_id = thread_id;
    m_alg_ptr->UpdateSensorLocOrient(location_info);

}

int ManagementAlgorithm::StopUdatingLoc()
{
    //close thread
    //Pseudo code

    m_thread_id = 0;
    return 1;
}

CloudQueryAnswer ManagementAlgorithm::QueryCloud(CloudQuery clq, Region_Of_Mission rom)
{
    //This function is used to find out the last updated date & time of a specific ROM

}

void ManagementAlgorithm::ProcessNotification(AlgNotificationTypes alg_type)
{
    //This method is called by the algorithm module in order to report some status
    switch (alg_type)
    {
        case AlgModReadyForConstruction: //report console
                                        break;
        case AlgModStartedForConstruction: //report console
                                        break;
        case AlgModConstructionComplete: //Bravo!! Report to the console
                                        break;
        case AlgModuleStoppedLocationReporting: //This is sent after StopSensorLocationReporting has been called
                                        break;
    default:
            std::cout << "Unknown notification " << std::endl;
    }
}

bool ManagementAlgorithm::LoadOrthophoto(Region_Of_Mission rom)
{
    //In case of need for more updated orthophoto, algo calls this method.
    //This method connects to the cloud and brings the model.
    // When model is ready, signal to the algorithm module.
    // with method or message OrthoReady()
}

bool ManagementAlgorithm::LoadWPSModel(Region_Of_Mission rom)
{
    //In case of need for more updated WPS model, algo calls this method.
    //This method connects to the cloud and brings the model.
    // When model is ready, signal to the algorithm module.
    // with method or message WPS_Ready()
}

